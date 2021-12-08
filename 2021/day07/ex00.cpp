/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex00.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:39:22 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/08 14:02:19 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int		ft_atoi(std::string str, char split)
{
	int	res = 0;
	int	i = 0;

	while (str[i] == split)
		i++;
	while (i < str.size() && str[i] != split)
	{
		res += str[i] - '0';
		res *= 10;
		i++;
	}
	return (res / 10);
}

std::vector<int>	parse_line(std::string buffer)
{
	size_t				i = 0;
	size_t				prev = 0;
	std::vector<int>	res;

	do
	{
		res.push_back(ft_atoi(&buffer[i], ','));
		prev = i;
		i = buffer.find(',', i) + 1;
	} while (prev <= i && i != std::string::npos);
	return (res);
}

int		main(void)
{
	std::ifstream		input;
	std::string			buffer;
	std::vector<int>	pos_list;
	int					furthest_out = 0;
	int					expended_fuel;
	int					res = 0;

	input.open("input.txt");
	getline(input, buffer);
	pos_list = parse_line(buffer);
	for (int i = 0; i < pos_list.size(); i++)
	{
		if (pos_list[i] > furthest_out)
			furthest_out = pos_list[i];
	}
	for (int i = 0; i <= furthest_out; i++)
	{
		expended_fuel = 0;
		for (int j = 0; j < pos_list.size(); j++)
		{
			expended_fuel += abs(pos_list[j] - i);
		}
		if (res == 0 || expended_fuel < res)
			res = expended_fuel;
	}
	std::cout << res << std::endl;
	return (0);
}