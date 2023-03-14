#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
    _loadQuotationFile(&_quotation, CSV_FILENAME);
    _end = _quotation.end();
}

BitcoinExchange::~BitcoinExchange() {}

void    BitcoinExchange::execute(const char *input_filename) {
    std::ifstream   file;
    s_input_type    input_data;

    file.open(input_filename, std::ios::in);
    if (file.is_open()) {
        t_database_iterator it;
        std::string         line;

        std::getline(file, line);
        while (std::getline(file, line)) {
            input_data = _getDataFromLine(line);
            if (!input_data.error.empty()) {
                std::cout << input_data.error << "\n";
            } else {
                it = _quotation.find(input_data.date);
                if (it == _end) {
                    it = _quotation.upper_bound(input_data.date);
                }
                std::cout << input_data.date << " => " << input_data.amount
                            << " = " << (input_data.amount * it->second)
                            << "\n";
            }
        }
        file.close();
    } else {
        std::cout << "Could not open input file\n";
    }
}

void    BitcoinExchange::_loadQuotationFile(t_database* storage,
                                            const char *filename) {
    std::ifstream   file;
    std::string     line;
    std::string     date;
    double          price;
    size_t          comma_pos;

    file.open(filename, std::ios::in);
    if (file.is_open()) {
        std::getline(file, line);
        while (std::getline(file, line)) {
            comma_pos   = line.find_first_of(',');
            date        = line.substr(0, comma_pos);
            price       = atof(line.substr(comma_pos + 1).c_str());
            _strtrim(&date);

            storage->insert(std::make_pair(date, price));
        }
        file.close();
    } else {
        throw std::ifstream::failure("Could not open csv file\n");
    }
}

BitcoinExchange::s_input_type    BitcoinExchange::_getDataFromLine(
                                                    const std::string& line) {
    s_input_type    ret;
    std::string     date;
    size_t          pipe_pos;
    long            value_nbr;

    pipe_pos    = line.find_first_of('|');
    date        = line.substr(0, pipe_pos);
    value_nbr   = atof(line.substr(pipe_pos + 1).c_str());
    _strtrim(&date);

    if (date.find_first_not_of("0123456789- .\t") != std::string::npos) {
        ret.error = "Error: Invalid characters";
    } else if (!_isValidDate(date)) {
        ret.error = "Error: Bad input => " + date;
    } else if (value_nbr < 0) {
        ret.error = "Error: not a positive number.";
    } else if (value_nbr > 1000) {
        ret.error = "Error: too large number.";
    } else {
        ret.date  = date;
        ret.amount = value_nbr;
    }
    return ret;
}

bool        BitcoinExchange::_isValidDate(const std::string& date) {
    int         day, month, year;
    size_t      pos;

    year = _getDate(date, 0);

    pos = date.find_first_of("-") + 1;
    month = _getDate(date, pos);

    pos = date.find_first_of("-", pos) + 1;
    day = _getDate(date, pos);

    if (year > MAX_VALID_YR || year < MIN_VALID_YR) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }
    if (month == 2) {
        if (_isLeapYear(year)) {
            return day <= 29;
        } else {
            return day <= 28;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return (day <= 30);
    }
    return true;
}

int         BitcoinExchange::_getDate(const std::string& date, size_t pos) {
    return atoi(date.substr(pos, date.find_last_of("0123456789")).c_str());
}

bool        BitcoinExchange::_isLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

void        BitcoinExchange::_strtrim(std::string* s) {
    s->erase(s->find_last_not_of(SPACE) + 1);
    s->erase(0, s->find_first_not_of(SPACE));
}
