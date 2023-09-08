#include <iostream>
#include <iomanip>
#include <ctime>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout   << " accounts:" << _nbAccounts
                << ";total:" << _totalAmount
                << ";deposits:" << _totalNbDeposits
                << ";withdrawals:" << _totalNbWithdrawals
                << std::endl;
}

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
    this->_totalAmount += this->_amount;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    this->_totalAmount += deposit;

    _displayTimestamp();
    std::cout   << " index:" << this->_accountIndex
                << ";p_amount:" << this->_amount
                << ";deposit:" << deposit;
    this->_amount += deposit;
    std::cout   << ";amount:" << this->_amount
                << ";nb_deposits:" << this->_nbDeposits
                << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout   << " index:" << this->_accountIndex
                << ";p_amount:" << this->_amount
                << ";withdrawal:";
    if (this->_amount >= withdrawal)
    {
        this->_nbWithdrawals++;
        this->_totalNbWithdrawals++;
        this->_amount -= withdrawal;
        this->_totalAmount -= withdrawal;
        std::cout   << withdrawal
                    << ";amount:" << this->_amount
                    << ";nb_withdrawals:" << this->_nbDeposits;
    }
    else
        std::cout   << "refused";
    std::cout << std::endl;
    return (this->_amount >= withdrawal);
}

int		Account::checkAmount(void) const
{
    return this->_amount;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout   << " index:" << this->_accountIndex
                << ";amount:" << this->_amount
                << ";deposits:" << this->_nbDeposits
                << ";withdrawals:" << this->_nbWithdrawals
                << std::endl;
}

void	Account::_displayTimestamp(void)
{
    std::time_t now = time(0);
    std::tm     *lt = std::gmtime(&now);
    std::cout   << "["
                << lt->tm_year + 1900
                << std::setfill('0') << std::setw(2) << lt->tm_mon + 1
                << std::setfill('0') << std::setw(2) << lt->tm_mday
                << "_"
                << std::setfill('0') << std::setw(2) << lt->tm_hour
                << std::setfill('0') << std::setw(2) << lt->tm_min
                << std::setfill('0') << std::setw(2) << lt->tm_sec
                << "]";
}

Account::Account(void)
{
    Account(0);
}
