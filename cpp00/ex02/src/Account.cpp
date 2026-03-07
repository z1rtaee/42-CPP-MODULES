#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

//reverse engineering of the class Account, we can see that it has a lot of static members and functions, which means that they are shared among all instances of the class. The class also has a constructor and a destructor, which are used to initialize and clean up the resources of the class. The class also has some member functions that are used to perform operations on the accounts, such as making deposits and withdrawals, checking the amount, and displaying the status of the account. The class also has a private static function that is used to display the timestamp of the operations.

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
    std::time_t result = std::time(NULL);
    std::tm *timeinfo = std::localtime(&result);
    std::cout << "["
        <<(timeinfo->tm_year + 1900)
        << std::setw(2) << std::setfill('0') << (timeinfo->tm_mon + 1)
        << std::setw(2) << std::setfill('0') << timeinfo->tm_mday
        << "_"
        << std::setw(2) << std::setfill('0') << timeinfo->tm_hour
        << std::setw(2) << std::setfill('0') << timeinfo->tm_min
        << std::setw(2) << std::setfill('0') << timeinfo->tm_sec
        << "]";
    std::cout << std::setfill(' ');

}

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts: " << getNbAccounts() 
        << "; total: " << getTotalAmount() 
        << "; deposits: " << getNbDeposits() 
        << "; withdrawals: " << getNbWithdrawals() 
        << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) 
{
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index: " << _accountIndex 
        << "; amount: " << _amount 
        << ";created"
        << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index: " << _accountIndex 
        << "; amount: " << _amount 
        << "; closed"
        << std::endl;
}

void Account::makeDeposit(int deposit) {
	int p_amount = _amount;

	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << '\n';
}

bool Account::makeWithdrawal(int withdrawal) {
	int p_amount = _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";";

	if (withdrawal <= _amount) {
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;

		std::cout << "withdrawal:" << withdrawal
				  << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals
				  << '\n';
		return true;
	} 
    else {
		std::cout << "withdrawal:refused" << '\n';
		return false;
	}
}

int Account::checkAmount(void) const {
	return _amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << '\n';
}