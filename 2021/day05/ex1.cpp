/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex1.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 14:21:18 by julesvander   #+#    #+#                 */
/*   Updated: 2021/12/06 17:53:13 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

struct	t_vector
{
	int	x_start;
	int	x_end;
	int	y_start;
	int	y_end;
};

int		ft_atoi(std::string str, char split, int start)
{
	int	res = 0;
	int	i = start;

	while (str[i] == split)
		i++;
	while (i < str.size() && str[i] >= 48 && str[i] <= 57)
	{
		res += str[i] - '0';
		res *= 10;
		i++;
	}
	return (res / 10);
}

t_vector	make_vector(std::string input)
{
	t_vector	res;
	res.x_start = ft_atoi(input, ',', 0);
	res.y_start = ft_atoi(input, ' ', input.find(',') + 1);
	res.x_end = ft_atoi(input, ',', input.find('>') + 2);
	res.y_end = ft_atoi(input, ' ', input.find_last_of(',') + 1);
	return (res);
}

bool	diagonal_intersect(t_vector vector, int x, int y)
{
	if (x - vector.x_start == y - vector.y_start && vector.x_start <= x && x <= vector.x_end && vector.y_start <= y && y <= vector.y_end)
		return (true);
	else if (x - vector.x_end == y - vector.y_end && vector.x_start >= x && x >= vector.x_end && vector.y_start >= y && y >= vector.y_end)
		return (true);
	else if (x - vector.x_start == -1* (y - vector.y_start) && vector.x_start <= x && x <= vector.x_end && vector.y_start <= y && y <= vector.y_end)
		return (true);
	else if (x - vector.x_end == -1* (y - vector.y_end) && vector.x_start >= x && x >= vector.x_end && vector.y_start >= y && y >= vector.y_end)
		return (true);
	return (false);
}

int		vec_intersect(std::vector<t_vector>	vector_arr, int x, int y)
{
	int vecs = 0;

	for (int i = 0; i < vector_arr.size(); i++)
	{
		if (vector_arr[i].x_start <= x && x <= vector_arr[i].x_end && vector_arr[i].y_end == y)
			vecs++;
		else if(vector_arr[i].x_end <= x && x <= vector_arr[i].x_start && vector_arr[i].y_end == y)
			vecs++;
		else if(vector_arr[i].y_start <= y && y <= vector_arr[i].y_end && vector_arr[i].x_end == x)
			vecs++;
		else if(vector_arr[i].y_end <= y && y <= vector_arr[i].y_start && vector_arr[i].x_end == x)
			vecs++;
		else if (diagonal_intersect(vector_arr[i], x, y))
			vecs++;
		if (vecs > 1)
			return (1);
	}
	return (0);
}

int		main(void)
{
	std::ifstream	input;
	std::string		buffer;
	std::vector<t_vector>	vector_arr;
	int	res = 0;

	input.open("input.txt");

	while (getline(input, buffer))
	{
		vector_arr.push_back(make_vector(buffer));
	}
	for(int x = 1; x < 991; x++)
	{
		for(int y = 1; y < 991; y++)
		{
			res += vec_intersect(vector_arr, x, y);
		}
	}
	std::cout << res << std::endl;
}
