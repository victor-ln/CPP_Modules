#include "Account.hpp"

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_nbAccounts << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std::cout << "created" << std::endl;
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_nbAccounts++;
}

Account::~Account() {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	Account::_nbAccounts--;
	std::cout << "amount:" << this->_amount << ";";
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << ++this->_nbDeposits << std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal <= this->checkAmount()) {
		std::cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
	}
	else {
		std::cout << "withdrawal:" << "refused" << std::endl;
		return (false);
	}
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	return (true);
}

int		Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::_displayTimestamp(void) {
	time_t tt = std::time(0);
	tm local_tm = *localtime(&tt);

	std::cout << "[";
	std::cout << local_tm.tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << local_tm.tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << local_tm.tm_mday << "_";
	std::cout << std::setw(2) << std::setfill('0') << local_tm.tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << local_tm.tm_min;
	std::cout << std::setw(2) << std::setfill('0') << local_tm.tm_sec;
	std::cout << "] ";
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
