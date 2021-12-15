/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex00.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:15:46 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/14 15:07:38 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct	t_instruction
{
	std::string	pair;
	char		insertion;
};

t_instruction	parse_input(std::string input)
{
	t_instruction	res;
	int i = 0;
	res.pair = input.substr(0, 2);
	res.insertion = input[6];
	return (res);
}

void	run_insertions(std::string & string, std::vector<t_instruction> instructions)
{
	size_t j = 0;
	size_t	j2 = 1;
	bool	changed;
	while (string[j2])
	{
		changed = false;
		for (int i = 0; i < instructions.size(); i++)
		{
			if (string[j2] && string[j] == instructions[i].pair[0] && string[j2] == instructions[i].pair[1])
			{
				string.insert(string.begin() + j2, instructions[i].insertion);
				j += 2;
				j2 += 2;
				changed = true;
			}
		}
		if (!changed)
		{
			j++;
			j2++;
		}
	}
}

int		calc_score(std::string ref)
{
	size_t biggest = 0;
	size_t smallest = 100000;
	int i = 0;
	size_t	count;
	char	cur;
	
	std::sort (ref.begin(), ref.end());
	cur = ref[0];
	while (ref[i])
	{
		count = 0;
		while (ref[i] == cur)
		{
			count++;
			i++;
		}
		if (count > biggest)
			biggest = count;
		else if (count < smallest)
			smallest = count;
		cur = ref[i];
	}
	return (biggest - smallest);
}

int		main(void)
{
	std::ifstream				input;
	std::string					buffer;
	std::string					polymer;
	std::vector<t_instruction>	instructions;

	input.open("input.txt");
	getline(input, buffer);
	polymer = buffer;
	while (getline(input, buffer))
	{
		if (buffer.size() > 0)
			instructions.push_back(parse_input(buffer));
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << std::endl;
		run_insertions(polymer, instructions);
	}
	std::cout << calc_score(polymer) << std::endl;
	return (0);
}
