/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 20:27:03 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/17 22:35:49 by astadnik         ###   ########.fr       */
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
		while (++offs.x < data.tok_widht)
		{
			if (data.token[offs.y * data.tok_widht + offs.x] == '.')
				continue ;
			if (cur.y + offs.y < 0 || cur.x + offs.x < 0 || inters)
				return (0);
			p = ft_tolower(data.field[(cur.y + offs.y) * data.widht + cur.x + offs.x]);
			if (p == '.')
				continue ;
			if (p == (data.player == 'x' ? 'x' : 'o'))
				inters++;
			else
				return (0);
		}
	}
	return ((int)inters);
}

/* static int	calc_len(t_data data, size_t y, size_t x) */
/* { */

/* } */

// TODO: add return value to show if it's time to free
void		print_sol(const t_data data)
{
	size_t	dist;
	t_point	cur;

	cur.y = -data.tok_height;
	dist = data.height * data.widht;
	/* ft_dprintf(2, "HEHEY\n"); */
	while (cur.y++ < data.height - data.tok_height)
	{
		cur.x = -data.tok_widht;
		while (cur.x++ < data.widht - data.tok_widht)
		{
			/* ft_dprintf(2, "h = %d w = %d\n", cur.y, cur.x); */
			if (!check_pos(data, cur))
				continue ;
			ft_dprintf(2, "%d %d\n", cur.x, cur.y);
			ft_printf("%d %d\n", cur.y, cur.x);
			return ;
		}
	}
}
