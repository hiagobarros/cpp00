/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-barr <hde-barr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:36:04 by hde-barr          #+#    #+#             */
/*   Updated: 2025/06/13 17:36:08 by hde-barr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <cstring>

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        for(int i = 1; i < argc; i++)
            for(int j = 0; j < (int)std::strlen(argv[i]); j++)
                std::cout<<(char)toupper(argv[i][j]);
        std::cout<<std::endl;
    }
    else
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
    return (0);
}