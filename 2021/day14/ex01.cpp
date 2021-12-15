/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex01.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:15:46 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/15 15:41:51 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

struct	t_instruction
{
	std::string	pair;
	char		insertion;
	size_t			occur;
};

t_instruction	parse_input(std::string input)
{
	t_instruction	res;
	int i = 0;
	res.pair = input.substr(0, 2);
	res.insertion = input[6];
	res.occur = 0;
	return (res);
}

size_t		occurences(std::string string, t_instruction instruction)
{
	size_t size = 0;
	int i = 0;
	while (string[i + 1])
	{
		if (instruction.pair[0] == string[i] && instruction.pair[1] == string[i + 1])
			size++;
		i++;
	}
	return (size);
}

void	calc_start_occur(std::vector<t_instruction> & instructions, std::string string)
{
	for (int i = 0; i < instructions.size(); i++)
	{
		instructions[i].occur += occurences(string, instructions[i]);
	}
}

void	inc_occur(char a, char b, char c, std::vector<t_instruction> & instructions, size_t occur)
{
	bool one = false, two = false, three = false;
	for (int i = 0; i < instructions.size(); i++)
	{
		if (one == false && instructions[i].pair[0] == a && instructions[i].pair[1] == b)
		{
			instructions[i].occur += occur;
			one = true;
		}
		if (two == false && instructions[i].pair[0] == a && instructions[i].pair[1] == c)
		{
			instructions[i].occur -= occur;
			two = true;
		}
		if (three == false && instructions[i].pair[0] == b && instructions[i].pair[1] == c)
		{
			instructions[i].occur += occur;
			three = true;
		}
		if (one && two && three)
			return ;
	}
}

void	run_insertions(std::vector<t_instruction> & instructions, std::map<char, size_t> & chars)
{
	std::vector<t_instruction> copy = instructions;
	for (int i = 0; i < copy.size(); i++)
	{
		if (copy[i].occur != 0)
		{
			inc_occur(instructions[i].pair[0], instructions[i].insertion, instructions[i].pair[1], instructions, copy[i].occur);
			chars[copy[i].insertion] += copy[i].occur;
		}
	}
}

void	init_chars(std::map<char, size_t> & chars, std::string input)
{
	int i = 0;
	while (input[i])
	{
		chars[input[i]]++;
		i++;
	}
}

size_t	calc_score(std::map<char, size_t>  chars)
{
	size_t biggest = 1;
	size_t smallest = 1;
	std::map<char, size_t>::iterator a = chars.begin();
	std::map<char, size_t>::iterator b = ++chars.begin();
	if (a->second > b->second)
	{
		biggest = a->second;
		smallest = b->second;
	}
	else
	{
		biggest = b->second;
		smallest = a->second;
	}
	for (std::map<char, size_t>::iterator c = ++(++chars.begin()); c != chars.end(); c++)
	{
		if (c->second > biggest)
			biggest = c->second;
		else if (c->second < smallest)
			smallest = c->second;
	}
	return (biggest - smallest);
}

int		main(void)
{
	std::ifstream				input;
	std::string					buffer;
	std::string					polymer;
	std::vector<t_instruction>	instructions;
	std::map<char, size_t>			chars;

	input.open("input.txt");
	getline(input, buffer);
	polymer = buffer;
	while (getline(input, buffer))
	{
		if (buffer.size() > 0)
			instructions.push_back(parse_input(buffer));
	}
	init_chars(chars, polymer);
	calc_start_occur(instructions, polymer);
	for (int i = 0; i < 40; i++)
	{
		run_insertions(instructions, chars);
	}
	std::cout << calc_score(chars) << std::endl;
	return (0);
}


