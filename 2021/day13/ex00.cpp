/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex00.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 10:03:14 by julesvander   #+#    #+#                 */
/*   Updated: 2021/12/13 12:23:39 by julesvander   ########   odam.nl         */
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
	int dupes = 0;
	int	i = 0;
	
	input.open("input.txt");
	while (getline(input, buffer) && buffer.size() != 0)
	{
		cords.push_back(parse_input(buffer));
	}
	getline(input, buffer);
	while (buffer[i])
	{
		if (buffer[i] == '=' && buffer[i - 1] == 'y')
			fold_along_y(cords, ft_atoi(&(buffer[i + 1]), ' '));
		else if (buffer[i] == '=' && buffer[i - 1] == 'x')
			fold_along_x(cords, ft_atoi(&(buffer[i + 1]), ' '));
		i++;
	}
	std::cout << cords.size() << std::endl;
	for (int i = 0; i < cords.size(); i++)
	{
//		std::cout << cords[i].x << "\t" << cords[i].y << std::endl;
		if (check_for_dupes(cords, cords[i], i))
			dupes++;
//		std::cout << cords[i].x << "\t" << cords[i].y << std::endl;
	}
	std::cout << cords.size() - (dupes / 2) << std::endl;
}