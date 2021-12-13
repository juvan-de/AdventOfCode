/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex01.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 13:51:21 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/10 15:38:09 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <stack>
#include <map>
#include <list>

size_t		get_score(std::map<char, int> table, std::stack<char> queue)
{
	size_t res = 0;
	while (queue.size() > 0)
	{
		res = res * 5 + table[queue.top()];
		queue.pop();
	}
	return (res);
}

size_t		find_unfinished(std::string input)
{
	std::stack<char>		queue;
	std::map<char, char>	pairs;
	std::map<char, int>		ret;
	int	i = 0;
	size_t	res = 0;
	
	pairs['('] = ')';
	pairs['['] = ']';
	pairs['<'] = '>';
	pairs['{'] = '}';
	ret['('] = 1;
	ret['['] = 2;
	ret['{'] = 3;
	ret['<'] = 4;

	while (input[i])
	{
		if (pairs.find(input[i]) != pairs.end())
			queue.push(input[i]);
		else 
			if (pairs[queue.top()] == input[i])
				queue.pop();
			else
				return (0);
		i++;
	}
	res = get_score(ret, queue);
	return (res);
}

int main(void)
{
	std::string			buffer;
	std::ifstream		input;
	size_t					res = 0;
	std::list<size_t>	results;
	
	input.open("input.txt");
	while (getline(input, buffer))
	{
		res = find_unfinished(buffer);
		if (res != 0)
			results.push_back(res);
	}
	results.sort();
	std::list<size_t>::iterator it=results.begin();
	for (int i = 0; i < (results.size() / 2); i++)
		it++;
	std::cout << *it << std::endl;
	return (0);
}