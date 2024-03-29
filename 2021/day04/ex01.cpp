/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex01.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/05 13:43:09 by julesvander   #+#    #+#                 */
/*   Updated: 2021/12/06 13:54:34 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

struct bingonum
{
	int num;
	bool ticked;
};

size_t	first_char(std::string buffer)
{
	int i = 0;

	while (buffer[i] == ' ')
		i++;
	return (i);
}

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

std::vector<int>	parse_first_line(std::string buffer)
{
	size_t				i = 0;
	size_t				prev = 0;
	std::vector<int>	res;

	do
	{
		res.push_back(ft_atoi(&buffer[i], ','));
		prev = i;
		i = buffer.find(',', i) + 1;
	} while (prev <= i && i != std::string::npos);
	return (res);
}

std::vector<bingonum>	make_bingo_vec(std::ifstream & input)
{
	std::string				buffer;
	size_t					prev = 0;
	std::vector<bingonum>	res;
	bingonum				temp;

	temp.ticked = false;
	while (res.size() != 25)
	{
		getline(input, buffer);
		size_t	i = first_char(buffer);
		do
		{
			temp.num = ft_atoi(&buffer[i], ' ');
			res.push_back(temp);
			prev = i;
			i = buffer.find(' ', i) + 1;
			if (buffer[i] == ' ')
				i++;
		} while (i != std::string::npos && prev <= i);
	}
	return (res);
}

void	tick_number(int num, std::vector<std::vector<bingonum> > & boards)
{
	for (int i = 0; i < boards.size(); i++)
	{
		for (int j = 0; j < boards[i].size(); j++)
		{
			if (boards[i][j].num == num)
				boards[i][j].ticked = true;
		}
	}
}

bool	check_column(std::vector<bingonum> & card, int row_start)
{
	int	start = row_start % 5;
	for (int i = 0; i < 5; i++)
	{
		if (card[start + (i * 5)].ticked == false)
			return (false);
	}
	return (true);	
}

bool	check_row(std::vector<bingonum> & card, int row_start)
{
	int	row = (row_start / 5) * 5;
	for (int i = 0; i < 5; i++)
	{
		if (card[row + i].ticked == false)
			return (false);
	}
	return (true);
}

int		check_for_bingo(std::vector<std::vector<bingonum> > & boards)
{
	int bingonum = 0;
	for (int i = 0; i < boards.size(); i++)
	{
		for (int j = 0; j < 25; j += 6)
		{
			if (boards[i][j].ticked == true)
			{
				if (check_row(boards[i], j) || check_column(boards[i], j))
				{
					bingonum++;
					break ;
				}
			}
		}
	}
	return (bingonum);
}

int		last_non_bingo(std::vector<std::vector<bingonum> >	&boards)
{
	int res = -1;
	for (int i = boards.size() - 1; i > 0 ; i--)
	{
		int tries = 5;
		for (int j = 0; j < 25; j += 6)
		{
			if (check_row(boards[i], j) == false && check_column(boards[i], j) == false)
			{
				tries--;
			}
		}
		if (tries == 0)
		{
			res = i;
		}
	}
	if (res)
		return (res);
	return (-1);
}

bool	is_bingo(std::vector<bingonum> &board)
{
	for (int i = 0; i < 25; i += 6)
	{
		if (check_row(board, i) || check_column(board, i))
			return (true);
	}
	return (false);
}

int		calc_score(std::vector<std::vector<bingonum> >	&boards, std::vector<int> &vec_input, int vec_index)
{
	int lastbingonum = 0;
	int res = 0;
	int bingo;
	std::vector<bingonum> board;


	lastbingonum = last_non_bingo(boards);
	while (!(is_bingo(boards[lastbingonum])))
	{
		tick_number(vec_input[vec_index], boards);
		vec_index++;
	}
	vec_index--;
	board = boards[lastbingonum];
	for (int i = 0; i < 25; i++)
	{
		if (board[i].ticked == false)
		{
			res += board[i].num;
		}
	}
	return (res * vec_input[vec_index]);
}

int		main(void)
{
	std::ifstream						input;
	std::string							buffer;
	std::vector<int>					vec_input;
	std::vector<std::vector<bingonum> >	boards;
	int									bingo_num = 0;

	input.open("input.txt");
	getline(input, buffer);
	vec_input = parse_first_line(buffer);
	while (getline(input, buffer))
		boards.push_back(make_bingo_vec(input));
	for (int i = 0; i < vec_input.size(); i++)
	{
		tick_number(vec_input[i], boards);
		if (i >= 4)
		{
			bingo_num = check_for_bingo(boards);
			if (bingo_num == boards.size() - 1)
			{
				std::cout << bingo_num << std::endl;
				std::cout << calc_score(boards, vec_input, i) << std::endl;
				return (0);
			}
		}
	}
	return (0);
}
