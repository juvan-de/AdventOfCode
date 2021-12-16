/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex00.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 12:51:53 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/16 19:35:47 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

#include "packet.hpp"

// std::vector<t_packet>	parse_subpackets(t_packet & packet)
// {
// 	std::vector<t_packet>	res;
// 	int						packet_nums = packet.packet_num;
// 	while (packet_nums > 0)
// 	{
		
// 		packet_nums--;
// 	}
// 	if (packet.is_literal)
// 	{
		
// 	}
// }


// int		add_versions(t_packet packet)
// {
// 	int res = read_bit_value(packet.bit_values.substr(0, 3));
// 	std::cout << res << std::endl;
// }

// void	calc_score(std::string buffer)
// {
// 	t_packet	packet;

// 	packet = parse_packet(buffer);
// }
std::string	hex_to_bits(std::string hex)
{
	std::string	bit_values;
	std::string	array = "0123456789ABCDEF";
	int i = 0;
	int value;
	while (hex[i])
	{
		value = array.find(hex[i]);
		if (value - 8 >= 0)
		{
			bit_values.append("1");
			value -= 8;
		}
		else
			bit_values.append("0");
		if (value - 4 >= 0)
		{
			bit_values.append("1");
			value -= 4;
		}
		else
			bit_values.append("0");
		if (value - 2 >= 0)
		{
			bit_values.append("1");
			value -= 2;
		}
		else
			bit_values.append("0");
		if (value - 1 >= 0)
		{
			bit_values.append("1");
			value -= 1;
		}
		else
			bit_values.append("0");
		i++;
	}
	return (bit_values);
}

int		main(void)
{
	std::ifstream		input;
	std::string			buffer;
	std::string			bits;
	int					res = 0;
	input.open("input.txt");
	getline(input, buffer);
	bits = hex_to_bits(buffer);
	Packet				packet(bits);
}
