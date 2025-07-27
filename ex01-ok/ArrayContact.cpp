/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-barr <hde-barr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:04:39 by hde-barr          #+#    #+#             */
/*   Updated: 2025/07/27 21:35:04 by hde-barr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
        const int ArrayContact::n = 8;
        Contact ArrayContact::_arr[8];

        Contact& ArrayContact::operator[](int index)
        {
            return _arr[index];
        }
        const Contact& ArrayContact::operator[](int index) const 
        {
            return _arr[index];
        }
        int ArrayContact::size() const 
        {
            return n;
        }
        Contact* ArrayContact::begin()
        {
            return _arr;
        }
        Contact* ArrayContact::end()
        {
            return _arr + n;
        }
        const Contact* ArrayContact::begin() const
        {
            return _arr;
        }
        const Contact* ArrayContact::end() const
        {
            return _arr + n;
        }