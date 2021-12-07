/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   puzzle1.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 20:51:56 by julesvander   #+#    #+#                 */
/*   Updated: 2021/12/01 21:25:22 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

size_t	ft_atoi(std::string str)
{
	size_t	res;
	for (int i = 0; i < str.size(); i++)
	{
		res += str[i] - '0';
		res *= 10;
	}
	res /= 10;
	return (res);
}

void	move_values(size_t	*values)
{
	if (values[2])
		values[3] = values[2];
	values[2] = values[1];
}

int	main(void)
{
	std::ifstream	input;
	std::string		buffer;
	size_t			values[3];
	size_t			sum;
	size_t			increases = 0;
	size_t			prev = 0;
	values[0] = 0;
	values[1] = 0;
	values[2] = 0;
	input.open("input.txt");
	while (getline(input, buffer))
	{
		values[0] = ft_atoi(buffer);
		if (values[2])
		{
			sum = values[0] + values[1] + values[2];
			if (sum > prev)
				increases++;
			prev = sum;
		}
		if (values[1])
			values[2] = values[1];
		values[1] = values[0];
	}
	std::cout << increases << std::endl;
	return (0);
}