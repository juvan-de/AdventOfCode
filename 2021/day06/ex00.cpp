/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex00.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 13:26:35 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/07 14:27:07 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int>	parse_input(std::string input)
{
	std::vector<int>	res;
	size_t				i = 0;
	
	for (int i = 0; i < input.size(); i += 2)
		res.push_back((int)(input[i] - '0'));
	return (res);
}

int		main(void)
{
	std::string	buffer;
	std::ifstream	input;
	std::vector<int>		fish_list;
	size_t	size;

	input.open("input.txt");
	getline(input, buffer);
	fish_list = parse_input(buffer);
	size = fish_list.size();
	for (int i = 1; i < 81; i++)
	{
		size = fish_list.size();
		for (int j = 0; j < size; j++)
		{
			if (fish_list[j] == 0)
			{
				fish_list[j] = 6;
				fish_list.push_back(8);
			}
			else
				fish_list[j]--;
		}
	}
	std::cout << fish_list.size() << std::endl;
	return (0);
}