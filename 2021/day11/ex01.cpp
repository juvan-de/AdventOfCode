/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex01.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/11 10:24:19 by julesvander   #+#    #+#                 */
/*   Updated: 2021/12/11 11:31:29 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

std::vector<int>	parse_input(std::string buffer)
{
	std::vector<int>	res;
	int i = 0;

	while (buffer[i])
	{
		res.push_back(buffer[i] - '0');
		i++;
	}
	return (res);
}

int		flash_octopi(std::vector<std::vector<int> > &octo)
{
	int		res = 0;
	bool	change = true;
	for (int i = 0; i < octo.size(); i++)
	{
		for (int j = 0; j < octo[i].size(); j++)
		{
			octo[i][j]++;
		}
	}
	while (change == true)
	{
		change = false;
		for (int i = 0; i < octo.size(); i++)
		{
			for (int j = 0; j < octo[i].size(); j++)
			{
				if (octo[i][j] > 9 && octo[i][j] < 1000)
				{
					change = true;
					res++;
					octo[i][j] = 1000;
					for (int dy = -1; dy < 2; dy++)
					{
						for (int dx = -1; dx < 2; dx++)
						{
							if (i + dy < octo.size() && i + dy >= 0 && j + dx < octo[i].size() && j + dx >= 0)
								octo[i + dy][j + dx]++;
						}
					}
				}
			}
		}
	}
	if (res == 100)
		return (true);
	for (int i = 0; i < octo.size(); i++)
	{
		for (int j = 0; j < octo[i].size(); j++)
		{	
			if (octo[i][j] >= 1000)
				octo[i][j] = 0;
		}
	}
	return (false);
}

int		main(void)
{
	std::ifstream	input;
	std::string		buffer;
	std::vector<std::vector<int> >	array;
	int				res = 1;

	input.open("input.txt");
	while (getline(input, buffer))
		array.push_back(parse_input(buffer));
	while (1)
	{
		if (flash_octopi(array))
		{
			std::cout << res << std::endl;
			return (0);
		}
		res++;
		//for (int y = 0; y < array.size(); y++)
		//{
		//	for (int x = 0; x < array[y].size(); x++)
		//	{
		//		std::cout << array[y][x];
		//	}
		//	std::cout << std::endl;
		//}
		//std::cout << std::endl;
	}
	std::cout << res << std::endl;
	return (0);
}