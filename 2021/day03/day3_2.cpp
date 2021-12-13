/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day3_2.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/03 13:44:23 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/13 15:11:30 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int>	parse_input(std::string input)
{
	std::vector<int>	res;
	int i = 0;

	while (input[i])
	{
		res.push_back(input[i] - '0');
		i++;
	}
	return (res);
}

void	print_array(std::vector<std::vector<int> > array)
{
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array[i].size(); j++)
		{
			std::cout << array[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int		find_most_common(int index, std::vector<std::vector<int> > & array)
{
	int	ones = 0;
	int	zeroes = 0;
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i][index] == 1)
			ones++;
		else if (array[i][index] == 0)
			zeroes++;
	}
	if (zeroes <= ones)
		return (1);
	return (0);
}

int		find_least_common(int index, std::vector<std::vector<int> > & array)
{
	int	ones = 0;
	int	zeroes = 0;
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i][index] == 1)
			ones++;
		else if (array[i][index] == 0)
			zeroes++;
	}
	if (zeroes > ones)
		return (1);
	return (0);
}

void	delete_uncommons(int ref, std::vector<std::vector<int> > & array, int index)
{
	int	len = array.size();
	for (int i = 0; i < len; i++)
	{
		if (ref != array[i][index])
		{
			if (array.size() > 1)
			{
				array.erase(array.begin() + i);
				len--;
				i--;
			}
			else
				return ;
		}
	}
}

void	empty_array(std::vector<std::vector<int> > & array)
{
	while (array.size() > 0)
	{
		array.erase(array.begin());
	}
}

int		main(void)
{
	std::string	buffer;
	std::ifstream	input;
	std::ifstream	input2;
	input.open("input.txt");
	input2.open("input.txt");
	std::vector<std::vector<int> >	array;
	int					most_common;
	int					least_common;
	while (getline(input, buffer))
	{
		array.push_back(parse_input(buffer));
	}
	for (int i = 0; i < array[0].size(); i++)
	{
		most_common = find_most_common(i, array);
		delete_uncommons(most_common, array, i);
		if (array.size() <= 1)
			break ;
	}
	for (int i = 0;i < array[0].size(); i++)
		std::cout << array[0][i];
	std::cout << std::endl;
	empty_array(array);

	while (getline(input2, buffer))
	{
		array.push_back(parse_input(buffer));
	}
	for (int i = 0; i < array[0].size(); i++)
	{
		least_common = find_least_common(i, array);
		delete_uncommons(least_common, array, i);
		if (array.size() <= 1)
			break ;
	}
	for (int i = 0;i < array[0].size(); i++)
		std::cout << array[0][i];
	std::cout << std::endl;

	std::cout << 673 * 2397 << std::endl;
	return (0);
}