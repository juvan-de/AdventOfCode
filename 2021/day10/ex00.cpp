/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex00.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 13:51:21 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/10 14:43:12 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <stack>
#include <map>

int	find_incorrect_char(std::string input)
{
	std::stack<char>		queue;
	std::map<char, char>	pairs;
	std::map<char, int>		ret;
	int	i = 0;
	
	pairs['('] = ')';
	pairs['['] = ']';
	pairs['<'] = '>';
	pairs['{'] = '}';
	ret[')'] = 3;
	ret[']'] = 57;
	ret['}'] = 1197;
	ret['>'] = 25137;

	while (input[i])
	{
		if (pairs.find(input[i]) != pairs.end())
			queue.push(input[i]);
		else 
			if (pairs[queue.top()] == input[i])
				queue.pop();
			else
				return (ret[input[i]]);
		i++;
	}
	return (0);
}

int main(void)
{
	std::string	buffer;
	std::ifstream	input;
	int				res = 0;
	

	input.open("input.txt");
	while (getline(input, buffer))
	{
		res += find_incorrect_char(buffer);
	}
	std::cout << res << std::endl;
	return (0);
}