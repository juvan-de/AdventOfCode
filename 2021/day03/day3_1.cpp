/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day3_1.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/03 13:44:23 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/13 13:13:30 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

int		main(void)
{
	std::string	buffer;
	std::ifstream	input;
	input.open("input.txt");
	int		count[12];
	int		gamma[2][12];
	int		gammadec[2];
	while (getline(input, buffer))
	{
		for (int i = 0; i < 12; i++)
		{
			count[i] += buffer[i] - '0';
		}
	}
	for (int i = 0; i < 12; i++)
	{
		if (count[i] < 2998 / 2)
		{
			gamma[0][i] = 0;
			gamma[1][i] = 1;
		}
		else
		{
			gamma[0][i] = 1;
			gamma[1][i] = 0;
		}
	}
	for (int i = 0; i < 12; i++)
	{
		if (gamma[0][i] == 1)
			gammadec[0] += pow(2, 11 - i);
		else
			gammadec[1] += pow(2, 11 - i);
	}
	std::cout << gammadec[0] * gammadec[1] << std::endl;
	return (0);
}