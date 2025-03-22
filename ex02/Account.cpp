#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp()
{
	time_t		now;
	struct tm	*ts;
	char		buf[80];

	now = time(NULL);
	ts = localtime(&now);
	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", ts);
	std::cout << buf;
}

Account::Account(int initial_deposit)
{
    Account::_displayTimestamp();
    this->_amount = initial_deposit;
    this->_accountIndex = Account::_nbAccounts;
    std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
    Account::_nbAccounts++;
    Account::_totalAmount += this->_amount;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
}

void Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << Account::_nbDeposits << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
    this->_amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    this->_nbDeposits++;
    std::cout << ";withdrawal:" << deposit << ";amount:" << this->_amount << ";nb_diposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
    if(this->_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return 0;
    }
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    this->_nbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return 1;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

