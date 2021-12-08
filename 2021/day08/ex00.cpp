/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex00.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 14:09:44 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/08 16:43:55 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string>	stringsplit(std::string input)
{
	std::vector<std::string> res;
	int i = 0;
	int	space;
	int start = input.find('|') + 2;
	while (i < 4)
	{
		space = input.find(' ', start);
		res.push_back(input.substr(start, space - start));
		start = space + 1;
		i++;
	}
	return (res);
}

int		main(void)
{
	std::ifstream				input;
	std::string					buffer;
	std::vector<std::string>	input_list;
	std::vector<std::vector<std::string> >	split_string;
	int res = 0;
	
	input.open("input.txt");
	while (getline(input, buffer))
		input_list.push_back(buffer);
	for (int i = 0; i < input_list.size(); i++)
		split_string.push_back(stringsplit(input_list[i]));
	for (int i = 0; i < split_string.size(); i++)
	{
		for (int j = 0; j < split_string[i].size(); j++)
		{
			if (split_string[i][j].length() == 2 || split_string[i][j].length() == 3 || split_string[i][j].length() == 4 || split_string[i][j].length() == 7)
				res++;
		}
	}
	std::cout << res << std::endl;
	return (0);
}