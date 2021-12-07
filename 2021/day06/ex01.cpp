/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex01.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 13:26:35 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/07 17:18:46 by juvan-de      ########   odam.nl         */
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
	size_t			array[9] = {0,0,0,0,0,0,0,0,0};
	size_t			temp;

	input.open("input.txt");
	getline(input, buffer);
	fish_list = parse_input(buffer);
	size_t	res = 0;
	for (int i = 0; i < fish_list.size(); i++)
	{
		array[fish_list[i]]++;
	}
	for (int i = 0; i < 256; i++)
	{
		temp = array[0];
		for (int j = 0; j < 8; j++)
		{
			array[j] = array[j + 1];
		}
		array[6] += temp;
		array[8] = temp;
	}
	for (int i = 0; i < 9; i++)
		res += array[i];
	std::cout << res << std::endl;
	return (0);
}