/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   day3_2.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/03 13:44:23 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/07 12:50:42 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

int	count_ones()
{
	if (in[i
	])
}

int		main(void)
{
	std::string			buffer;
	std::ifstream		input;
	size_t				remaining = 2998;
	bool				in[2998];

	for (int i = 0; i < 2998; i++)
	{
		in[i] = true;
	}
	input.open("input.txt");
	int		count[12];
	int		out[12];
	while (getline(input, buffer))
	{
		for (int i = 0; i < 12; i++)
		{
			count[i] += buffer[i] - '0';
		}
	}
	for (int i = 0; i < 12; i++)
	{
		if (count[i] >= remaining / 2)
	}
	return (0);
}