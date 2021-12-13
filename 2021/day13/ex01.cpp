/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex01.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 10:03:14 by julesvander   #+#    #+#                 */
/*   Updated: 2021/12/13 12:39:06 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

struct	t_coordinate
{
	int	x;
	int	y;
};

int		ft_atoi(std::string str, char split)
{
	int	res = 0;
	int	i = 0;

	while (str[i] == split)
		i++;
	while (i < str.size() && str[i] != split)
	{
		res += str[i] - '0';
		res *= 10;
		i++;
	}
	return (res / 10);
}

t_coordinate	parse_input(std::string input)
{
	t_coordinate	res;

	res.x = ft_atoi(input, ',');
	res.y = ft_atoi(&(input[input.find(',')]), ',');
	return (res);
}

void	fold_along_y(std::vector<t_coordinate> &cords, int foldline)
{
	for (int i = 0; i < cords.size(); i++)
	{
		if (cords[i].y > foldline)
		{
			cords[i].y -= 2 * (cords[i].y - foldline);
		}
	}
}

void	fold_along_x(std::vector<t_coordinate> &cords, int foldline)
{
	for (int i = 0; i < cords.size(); i++)
	{
		if (cords[i].x > foldline)
		{
			cords[i].x -= 2 * (cords[i].x - foldline);
		}
	}
}

bool	check_for_dupes(std::vector<t_coordinate> cords, t_coordinate cord, int num)
{
	for (int i = 0; i < cords.size(); i++)
	{
		if (i != num && cord.x == cords[i].x && cord.y == cords[i].y)
			return (true);
	}
	return (false);
}

int		main(void)
{
	std::ifstream		input;
	std::string			buffer;
	std::vector<t_coordinate>	cords;
	int	dupes = 0;
	int	i;
	t_coordinate		largest;
	
	input.open("input.txt");
	while (getline(input, buffer) && buffer.size() != 0)
	{
		cords.push_back(parse_input(buffer));
	}
	while (getline(input, buffer))
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '=' && buffer[i - 1] == 'y')
				fold_along_y(cords, ft_atoi(&(buffer[i + 1]), ' '));
			else if (buffer[i] == '=' && buffer[i - 1] == 'x')
				fold_along_x(cords, ft_atoi(&(buffer[i + 1]), ' '));
			i++;
		}
	}
	largest.x = 0;
	largest.y = 0;
	for (int i = 0; i < cords.size() ; i++)
	{
		if (cords[i].x > largest.x)
			largest.x = cords[i].x;
		if (cords[i].y > largest.y)
			largest.y = cords[i].y;
	}
	std::cout << largest.x << "\t" << largest.y << std::endl;
	char	output[largest.y + 1][largest.x + 1];
	for (int y = 0; y < largest.y + 1; y++)
	{
		for (int x = 0; x < largest.x + 1; x++)
		{
			output[y][x] = '.';
		}
	}
	for (int i = 0; i < cords.size(); i++)
	{
		output[cords[i].y][cords[i].x] = '#';
	}
	for (int y = 0; y < largest.y +1; y++)
	{
		for (int x = 0; x < largest.x + 1; x++)
		{
		//	std::cout << x << "\t" << y << std::endl;
			std::cout << output[y][x];
		}
		std::cout << std::endl;
	}
}