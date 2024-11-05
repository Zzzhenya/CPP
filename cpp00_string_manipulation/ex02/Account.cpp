#include "Account.hpp"
#include <iostream>
#include <ctime> 

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

/*
Insert this to test:
    datetime.tm_year = 1992 - 1900;
    datetime.tm_mon = 0;
    datetime.tm_mday = 4;
    datetime.tm_hour = 9;
    datetime.tm_min = 15;
    datetime.tm_sec = 32;
*/
//19920104_091532
void	Account::_displayTimestamp( void )
{
    time_t now;
    std::time(&now);
    struct tm datetime = *localtime(&now);
    // Insert here and get diff to test
    char output[18];
    strftime(output, 18, "%Y%m%d_%H%M%S", &datetime);
    std::cout << "[" << output << "] ";
}

//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void    Account::makeDeposit( int deposit )
{
        _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    _amount += deposit;
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    _totalAmount += deposit;
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

//[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    if (checkAmount() - withdrawal >= 0)
    {
        std::cout << "withdrawal:" << withdrawal << ";";
        _amount -= withdrawal;
        _nbWithdrawals += 1;
        _totalNbWithdrawals += 1;
        _totalAmount -= withdrawal;
        std::cout << "amount:" << _amount << ";";
        std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
    else
    {
        std::cout << "withdrawal:refused" << std::endl;
        return(false);
    }
}

Account::Account( int initial_deposit )
{
    _nbAccounts += 1;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

//[19920104_091532] index:0;amount:47;closed
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}
