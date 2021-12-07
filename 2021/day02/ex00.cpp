/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex00.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 13:07:29 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/03 13:48:15 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(void)
{
	size_t 	depth = 0;
	size_t	horizontal = 0;
	size_t	aim = 0;
	std::string	pos;
	std::string	buffer;
	std::ifstream	input;
	input.open("input.txt");
	while (getline(input, buffer))
	{
		size_t space = buffer.find(' ');
		if (buffer[0] == 'd')
		{
			aim += (size_t)buffer[space + 1] - '0';
		}
		else if(buffer[0] == 'u')
		{
			aim -= (size_t)buffer[space + 1] - '0';
		}
		else if (buffer[0] == 'f')
		{
			horizontal += (size_t)buffer[space + 1] - '0';
			depth += (((size_t)buffer[space + 1] - '0') * aim);
		}
	}
	std::cout << horizontal << " " << depth << std::endl;
	std::cout << depth * horizontal << std::endl;
	return (0);
}
