/* Copyright © 2023 Victor Nunes, Licensed under the MIT License. */

#ifndef MODULE_09_EX00_INCLUDES_BITCOINEXCHANGE_HPP_
#define MODULE_09_EX00_INCLUDES_BITCOINEXCHANGE_HPP_

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>

#define MAX_VALID_YR    2022
#define MIN_VALID_YR    2009
#define CSV_FILENAME    "data.csv"
#define SPACE           " \t\n\r\f\v"

class BitcoinExchange {
 public:
    BitcoinExchange(void);
    ~BitcoinExchange();

    void    execute(const char *input_filename);

 private:
    struct s_input_type {
        std::string error;
        std::string date;
        double      amount;
    };

    typedef std::map<std::string, double>              t_database;
    typedef std::map<std::string, double>::iterator    t_database_iterator;
    typedef std::pair<std::string, double>             t_database_pair;

    t_database              _quotation;
    t_database_iterator     _end;

    void            _loadQuotationFile(t_database*, const char*);
    s_input_type    _getDataFromLine(const std::string&);
    bool            _isValidDate(const std::string&);
    int             _getDate(const std::string&, size_t);
    bool            _isLeapYear(int);
    void            _strtrim(std::string*);
};  /* class BitcoinExchange */

#endif  /* MODULE_09_EX00_INCLUDES_BITCOINEXCHANGE_HPP_ */
