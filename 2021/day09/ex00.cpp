/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex00.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 14:06:20 by julesvander   #+#    #+#                 */
/*   Updated: 2021/12/09 14:49:22 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

std::vector<int>	parse_input(std::string	string)
{
	std::vector<int>	res;
	int i = 0;
	while (string[i])
	{
		res.push_back(string[i] - '0');
		i++;
	}
	return (res);
}

bool	check_if_lowest(std::vector<std::vector<int> >	array, int x, int y)
{
	bool	lowest = true;

	if (x != 0)
		if (array[y][x - 1] <= array[y][x])
			lowest = false;
	if (y != 0)
		if (array[y - 1][x] <= array[y][x])
			lowest = false;
	if (x != array[y].size() - 1)
		if (array[y][x + 1] <= array[y][x])
			lowest = false;
	if (y != array.size() - 1)
		if (array[y + 1][x] <= array[y][x])
			lowest = false;
	return (lowest);
}

int	main(void)
{
	std::ifstream				input;
	std::string					buffer;
	std::vector<std::vector<int> >	array;
	int							risk_level = 0;

	input.open("input.txt");
	while (getline(input, buffer))
	{
		array.push_back(parse_input((buffer)));
	}
	for (int y = 0; y < array.size(); y++)
	{
		for (int x = 0; x < array[y].size(); x++)
		{
			if (check_if_lowest(array, x, y))
				risk_level += 1 + array[y][x];
		}
	}
	std::cout << risk_level << std::endl;
	return (0);
}