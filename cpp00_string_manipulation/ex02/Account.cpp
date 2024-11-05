#include "Account.hpp"
#include <iostream>
#include <chrono> 
#include <ctime> 

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
    time_t now;
    std::time(&now);
    // std::cout <<  now << " ";
    struct tm datetime = *localtime(&now);
    // datetime.tm_mon = 0;
    char output[100];
    strftime(output, 50, "%Y%m%d_%H%M%S", &datetime);
    std::cout << "[" << output << "] ";
}

Account::Account( int initial_deposit )
{
    _nbAccounts += 1;
	_totalAmount += initial_deposit;
	_totalNbDeposits += 1;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 1;
	_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
