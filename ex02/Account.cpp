/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-barr <hde-barr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:51:04 by hde-barr          #+#    #+#             */
/*   Updated: 2025/07/29 20:14:00 by hde-barr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
    _amount = initial_deposit;
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _nbDeposits=0;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";created"<<std::endl;
}
Account::~Account( void )
{
    _displayTimestamp();
    std::cout<<"index;"<<_accountIndex<<";amount:"<<_amount<<";closed"<<std::endl;
}

int	    Account::getNbAccounts( void )
{
    return(_nbAccounts);
}
int	    Account::getTotalAmount( void )
{
    return (_totalAmount);
}
int	    Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}
int	    Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    
    std::cout<<"accounts:"<<_nbAccounts<<";total:"<<getTotalAmount()<<";deposits:"<<_totalNbDeposits<<";withdrawals:"<<_totalNbWithdrawals<<std::endl;
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::makeDeposit( int deposit )
{
   // _amount = deposit;
    _displayTimestamp();

    _nbDeposits++;
	_totalNbDeposits++;
    std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";deposit:"<<deposit<<";amount:"<<_amount + deposit<<";nb_deposits:"<<_nbDeposits<<std::endl;
    _amount += deposit;
    _totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if(_amount > withdrawal)
    {
    _displayTimestamp();
        
        _nbWithdrawals++;
		_totalNbWithdrawals++;
        std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:"<<withdrawal<<";amount:"<<_amount - withdrawal<<";nb_withdrawals:"<<_nbWithdrawals<<std::endl;
        _totalAmount -= withdrawal;
        _amount -= withdrawal;
        return(true);
    }
    else
    {
        _displayTimestamp();
        std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:refused"<<std::endl;
        return (false);
    }
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<<std::endl;
}

void Account::_displayTimestamp(void)
{
    char timestamp[20];
    std::time_t now;
    
    std::time(&now);
    std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", std::localtime(&now));
    std::cout<<"["<<timestamp<<"] ";
}