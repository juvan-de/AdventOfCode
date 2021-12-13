/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex01.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 14:06:20 by julesvander   #+#    #+#                 */
/*   Updated: 2021/12/09 15:12:24 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

struct		t_basin
{
	std::vector<int>	nums;
};

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

std::vector<int>	make_basin(std::vector<std::vector<int> >	array, int x, int y)
{
	std::vector<int>	res;

	

	
}

int	main(void)
{
	std::ifstream				input;
	std::string					buffer;
	std::vector<std::vector<int> >	array;
	std::vector<std::vector<int> >	basins;
	std::vector<int>				temp;
	int							size = 0;

	input.open("input.txt");
	while (getline(input, buffer))
	{
		array.push_back(parse_input((buffer)));
	}
	for (int y = 0; y < array.size(); y++)
	{
		for (int x = 0; x < array[y].size(); x++)
		{
			temp = make_basin(array, x, y);
			if (check_dupe(basins, temp))
				basins.push_back(temp);
		}
	}
	std::cout << std::endl;
	return (0);
}