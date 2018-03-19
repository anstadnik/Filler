/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 20:27:03 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/18 18:24:33 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_pos(const t_data data, t_point cur)
{
	t_point	offs;
	char	inters;
	char	p;

	offs.y = -1;
	inters = 0;
	while (++offs.y < data.tok_height)
	{
		offs.x = -1;
		while (++offs.x < data.tok_width)
		{
			if (data.token[offs.y * data.tok_width + offs.x] == '.')
				continue ;
			if (cur.y + offs.y < 0 || cur.x + offs.x < 0 || cur.x + offs.x >= data.width || cur.y + offs.x >= data.height)
				return (0);
			p = ft_tolower(data.field[(cur.y + offs.y) * data.width + cur.x + offs.x]);
			if (p == '.')
				continue ;
			if (p == data.player && !inters)
				inters++;
			else
				return (0);
		}
	}
	return ((int)inters);
}

static ssize_t	pifagor(t_data data, size_t y, size_t x)
{
	t_point	cur;
	size_t	min;
	size_t	tmp;

	min = data.height * data.width;
	cur.y = -1;
	while (++cur.y < data.height)
	{
		cur.x = -1;
		while (++cur.x < data.width)
		{
			if (ft_tolower(data.field[cur.y * data.width + cur.x]) == data.opponent)
			{
				tmp = ft_pow(cur.x - x, 2) + ft_pow(cur.y - y, 2);
				if (tmp < min)
					min = tmp;
			}
		}
	}
	return (min);
}

static size_t	calc_len(t_data data, t_point cur)
{
	t_point	offs;
	ssize_t	min;
	ssize_t	tmp;

	min = data.height * data.width;
	offs.y = -1;
	while (++offs.y < data.tok_height)
	{
		offs.x = -1;
		while (++offs.x < data.tok_width)
		{
			if (data.token[offs.y * data.tok_width + offs.x] == '.')
				continue ;
			if ((tmp = pifagor(data, cur.y + offs.y, cur.x + offs.x)) < min)
				min = (size_t)tmp;
		}
	}
	return (min);
}

char		algo(const t_data data)
{
	size_t	min;
	size_t	tmp;
	t_point	best;
	t_point	cur;

	cur.y = -data.tok_height;
	min = data.height * data.width;
	while (cur.y++ < data.height)
	{
		cur.x = -data.tok_width;
		while (cur.x++ < data.width)
		{
			if (!check_pos(data, cur))
				continue ;
			if ((tmp = calc_len(data, cur)) < min)
			{
				min = tmp;
				best = cur;
			}
		}
	}
	ft_printf("%d %d\n", best.y, best.x);
	ft_dprintf(2, "%d %d\n", best.y, best.x);
	return (min != (size_t)data.height * data.width);
}
