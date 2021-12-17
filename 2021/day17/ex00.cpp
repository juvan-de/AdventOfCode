/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex00.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 13:28:38 by julesvander   #+#    #+#                 */
/*   Updated: 2021/12/17 20:12:51 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

struct	t_target
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
};

struct	t_probe
{
	int x_pos;
	int y_pos;
	int x_sped;
	int y_sped;
	bool	hit;
};

int			ft_atoi(std::string input)
{
	int res = 0;
	int i = 0;
	int sign = 1;
	if (input[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (input[i] >= 48 && input[i] <= 57)
	{
		res += input[i] - '0';
		res *= 10;
		i++;
	}
	return ((res / 10) * sign);
}

t_target	parse_target(std::string input)
{
	int			i = input.find('x') + 2;
	t_target	res;
	res.x_min = ft_atoi(&input[i]);
	i = input.find('.') + 2;
	res.x_max = ft_atoi(&input[i]);
	i = input.find('y') + 2;
	res.y_max = ft_atoi(&input[i]);
	i = input.rfind('.') + 1;
	res.y_min = ft_atoi(&input[i]);
	return (res);
}

t_probe	probe_init(t_target target)
{
	t_probe	res;
	res.x_pos = 0;
	res.y_pos = 0;
	if (target.x_min > 0)
		res.x_sped = 1;
	else
		res.x_sped = -1;
	res.y_sped = 1;
	res.hit = false;
	return (res);
}

int	probe_hit(t_probe probe, t_target target)
{
	int max_height = 0;
	while (probe.y_pos >= target.y_max)
	{
		if (probe.x_pos >= target.x_min && probe.x_pos <= target.x_max && probe.y_pos <= target.y_min && probe.y_pos >= target.y_max)
			return (max_height);
		probe.x_pos += probe.x_sped;
		probe.y_pos += probe.y_sped;
//		std::cout << "sped[" << probe.y_sped << "]" << std::endl;
		if (probe.x_sped > 0)
			probe.x_sped--;
		if (probe.x_sped < 0)
			probe.x_sped++;
		probe.y_sped--;
		if (probe.y_sped == 0)
			max_height = probe.y_pos;
	}
	return (0);
}

int		main(void)
{
	std::ifstream		input;
	std::string			buffer;
	t_target			target;
	t_probe				probe;
	int					hit_highest;
	int					hitheight = 1;

	input.open("input.txt");
	getline(input, buffer);
	target = parse_target(buffer);
	probe = probe_init(target);
	probe.x_sped = 1;
	hit_highest = hitheight;
//	std::cout << probe.x_sped << "\t" << target.x_max << std::endl;
	while (probe.x_sped < target.x_max)
	{
		probe.y_sped = 2;
		probe.x_sped++;
		hitheight = 1;
		while (probe.y_sped < 100)
		{
			probe.y_sped++;
			hitheight = probe_hit(probe, target);
		//	std::cout << probe.y_sped << "\t" <<hitheight << std::endl;
			if (hit_highest < hitheight)
			{
				hit_highest = hitheight;
			}
		}
	}
	std::cout << hit_highest << std::endl;
	return (0);
}
