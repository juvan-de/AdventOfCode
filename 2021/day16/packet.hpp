/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   packet.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 16:19:08 by juvan-de      #+#    #+#                 */
/*   Updated: 2021/12/16 19:29:37 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKET_HPP
# define PACKET_HPP

# include <string>
# include <iostream>
# include <vector>

class	Packet
{
	private:

	std::string				bit_values;
	std::string				hex_values;
	bool					is_literal;
	size_t						value;
	size_t						version;
	size_t						packet_num;
	size_t						packet_size;
	size_t						ID;
	std::vector<Packet>		sub_packets;

	public:

	Packet(std::string hex);
	size_t		read_bit_value(std::string bits);
	Packet& operator=(const Packet& ref);
	size_t		get_version() const;
	void	print_subpackets() const;
	size_t		calculate();
	
	~Packet();
};

#endif
