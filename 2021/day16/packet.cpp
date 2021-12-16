/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   packet.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 16:19:10 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/16 19:30:17 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "packet.hpp"

size_t			g_index = 0;

Packet::Packet(std::string bit_values)
{
	this->version = read_bit_value(bit_values.substr(g_index, 3));
	g_index += 3;
	this->ID = read_bit_value(bit_values.substr(g_index, 3));
	if (read_bit_value(bit_values.substr(g_index, 3)) == 4)
	{
		std::string	stringvalue;
		bool is_last = false;
		g_index += 3;
		this->is_literal = true;
		this->packet_num = 0;
		this->packet_size = 0;
		while (!(is_last))
		{
			if (bit_values[g_index] == '0')
				is_last = true;
			g_index++;
			if (stringvalue.size() == 0)
				stringvalue = bit_values.substr(g_index, 4);
			else 
				stringvalue.append(bit_values.substr(g_index, 4));
			g_index += 4;
			this->value = this->read_bit_value(stringvalue);
		}
	}
	else
	{
		this->is_literal = false;
		this->value = 0;
		g_index += 3;
		if (bit_values[g_index] == '0')
		{
			g_index++;
			this->packet_size = read_bit_value(bit_values.substr(g_index, 15));
			this->packet_num = 0;
			g_index += 15;
			size_t endsize = g_index + this->packet_size;
			while (g_index < endsize)
			{
				this->sub_packets.push_back(Packet(bit_values));
			}
		}
		else
		{
			g_index++;
			this->packet_size = 0;
			this->packet_num = read_bit_value(bit_values.substr(g_index, 11));
			g_index += 11;
			size_t endsize = g_index + this-> packet_size;
			for (size_t i = 0; i < this->packet_num; i++)
			{
				this->sub_packets.push_back(Packet(bit_values));
			}
		}
	}
}

size_t		Packet::read_bit_value(std::string bits)
{
	size_t res = 0, i = 0;
	while (bits[i])
	{
		res *= 2;
		res += bits[i] - '0';
		i++;
	}
	return (res);
}

size_t		Packet::get_version() const
{
	size_t res = this->version;
	for (size_t i = 0; i < this->sub_packets.size(); i++)
	{
		res += this->sub_packets[i].get_version();
	}
	return (res);
}

void		Packet::print_subpackets() const
{
	for(size_t i = 0; i < this->sub_packets.size(); i++)
	{
		std::cout << sub_packets[i].value << "\t" << sub_packets[i].ID << std::endl;
	}
}

size_t		Packet::calculate()
{
	if (this->ID == 4)
		return (this->value);
	else if (this->ID == 0)
	{
		size_t res = 0;
		for (size_t i = 0; i < this->sub_packets.size(); i++)
		{
			res += this->sub_packets[i].calculate();
		}
		return (res);
	}
	else if (this->ID == 1)
	{
		size_t res = 1;
		for (size_t i = 0; i < this->sub_packets.size(); i++)
		{
			res *= this->sub_packets[i].calculate();
		}
		return (res);
	}
	else if (this->ID == 2)
	{
		size_t res = (size_t)-1;
		for (size_t i = 0; i < this->sub_packets.size(); i++)
		{
			if (this->sub_packets[i].calculate() < res)
				res = this->sub_packets[i].calculate();
		}		
		return (res);
	}
	else if (this->ID == 3)
	{
		size_t res = 0;
		for (size_t i = 0; i < this->sub_packets.size(); i++)
		{
			if (this->sub_packets[i].calculate() > res)
				res = this->sub_packets[i].calculate();
		}		
		return (res);
	}
	else if (this->ID == 5)
	{
		if (this->sub_packets[0].calculate() > this->sub_packets[1].calculate())
			return (1);
		return (0);
	}
	else if (this->ID == 6)
	{
		if (this->sub_packets[0].calculate() < this->sub_packets[1].calculate())
			return (1);
		return (0);
	}
	else if (this->ID == 7)
	{
		if (this->sub_packets[0].calculate() == this->sub_packets[1].calculate())
			return (1);
		return (0);
	}
	return (*(size_t*)"je moeder");
}

Packet::~Packet()
{

}
