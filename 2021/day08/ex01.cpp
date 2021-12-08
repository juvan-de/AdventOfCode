/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex01.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 14:09:44 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/08 18:24:22 by juvan-de      ########   odam.nl         */
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
	int start = 0;
	while (i < 15)
	{
		space = input.find(' ', start);
		res.push_back(input.substr(start, space - start));
		start = space + 1;
		i++;
	}
	return (res);
}

std::string	determine_three(std::string reference, std::vector<std::string> string)
{
	std::string res;
	int			j;
	for (int i = 0; i < string.size(); i++)
	{
		if (string[i].size() == 5)
		{
			j = 0;
			while (j < 3)
			{
				if (string[i].find(reference[j]) == std::string::npos)
					break ;
				j++;
			}
			if (j == 3)
				return (string[i]);
		}
	}
	return ("");
}

std::string	determine_five_two(std::string reference, std::vector<std::string> string, int num, std::string three)
{
	std::string res;
	int			similarities;
	for (int i = 0; i < string.size(); i++)
	{
		if (string[i].size() == 5)
		{
			similarities = 0;
			for (int j = 0; j < reference.size(); j++)
			{
				if (string[i].find(reference[j]) != std::string::npos)
					similarities++;
			}
			if ((similarities == 3 && num == 5 && string[i] != three) || (similarities == 2 && num == 2))
				return (string[i]);
		}
	}
	return ("");
}

std::string	determine_six_nine(std::string reference, std::vector<std::string> string, int num, std::string zero)
{
	std::string res;
	int			similarities;
	for (int i = 0; i < string.size(); i++)
	{
		if (string[i].size() == 6)
		{
			similarities = 0;
			for (int j = 0; j < reference.size(); j++)
			{
				if (string[i].find(reference[j]) != std::string::npos)
					similarities++;
			}
			if ((similarities == 2 && num == 6 && string[i] != zero) || (similarities == 3 && num == 9 && string[i] != zero))
				return (string[i]);
		}
	}
	return ("");
}

std::string	determine_zero(std::string reference, std::vector<std::string> string)
{
	std::string res;
	int			similarities;
	for (int i = 0; i < string.size(); i++)
	{
		if (string[i].size() == 6)
		{
			similarities = 0;
			for (int j = 0; j < reference.size(); j++)
			{
				if (string[i].find(reference[j]) != std::string::npos)
					similarities++;
			}
			if (similarities == 4)
				return (string[i]);
		}
	}
	return ("");
}

bool	is_num(std::string one, std::string two)
{
	int similarities = 0;
	if (one.size() != two.size())
		return (false);
	for (int i = 0; i < one.size(); i++)
	{
		if (two.find(one[i]) != std::string::npos)
			similarities++;
	}
	if (similarities == one.size())
		return (true);
	return (false);
}

int		add_end(std::vector<std::string> string)
{
	std::string	reference[10];
	int			res = 0;
	int			temp;

	for (int i = 0; i < string.size(); i++)
	{
		if (string[i].size() == 2)
			reference[1] = string[i];
		else if (string[i].size() == 3)
			reference[7] = string[i];
		else if (string[i].size() == 4)
			reference[4] = string[i];
		else if (string[i].size() == 7)
			reference[8] = string[i];
	}
	reference[3] = determine_three(reference[7], string);
	reference[5] = determine_five_two(reference[4], string, 5, reference[3]);
	reference[2] = determine_five_two(reference[4], string, 2, reference[3]);
	reference[0] = determine_zero(reference[5], string);
	reference[6] = determine_six_nine(reference[7], string, 6, reference[0]);
	reference[9] = determine_six_nine(reference[7], string, 9, reference[0]);
	for (int i = 0; i < 10; i++)
	{
		if (is_num(string[11], reference[i]))
			res += i * 1000;
		if (is_num(string[12], reference[i]))
			res += i * 100;
		if (is_num(string[13], reference[i]))
			res += i * 10;
		if (is_num(string[14], reference[i]))
			res += i * 1;
	}
	return (res);
}

int		main(void)
{
	std::ifstream				input;
	std::string					buffer;
	std::vector<std::vector<std::string> >	split_string;
	std::string	reference[10];
	int res = 0;
	
	input.open("input.txt");
	while (getline(input, buffer))
		split_string.push_back(stringsplit(buffer));
	for (int i = 0; i < split_string.size(); i++)
	{
		res += add_end(split_string[i]);
	}
	std::cout << res << std::endl;
	return (0);
}