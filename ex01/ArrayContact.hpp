/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayContact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-barr <hde-barr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:34:20 by hde-barr          #+#    #+#             */
/*   Updated: 2025/07/27 21:03:56 by hde-barr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ARRAY_CONTACT_HPP
#define ARRAY_CONTACT_HPP

#include "main.hpp"

class Contact;

class ArrayContact
{
    private:
        static const int n;
        static Contact _arr[8];
    public:
        Contact& operator[](int index);
        const Contact& operator[](int index) const;
        int size() const;
        Contact* begin();
        Contact* end();
        const Contact* begin() const;
        const Contact* end() const;
};

#endif

