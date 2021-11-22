/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:26:54 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/20 16:28:31 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	*g_mlx_ptr;
void	*g_win_ptr;
t_data	g_data;
char	g_stop;

static void	put_rect(t_point pos, int color)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < 9)
	{
		i = 0;
		while (i < 9)
			mlx_pixel_put(g_mlx_ptr, g_win_ptr,
					(pos.x * 10) + (int)i++, (int)j + (pos.y * 10), color);
		j++;
	}
}

static void	show_map(t_data d)
{
	t_point	cur;

	cur.y = -1;
	while (cur.y++ < d.height)
	{
		cur.x = -1;
		while (cur.x++ < d.width)
		{
			if (ft_tolower(d.field[cur.y * d.width + cur.x]) == 'o')
				put_rect(cur, 0x00AD1457);
			else if (ft_tolower(d.field[cur.y * d.width + cur.x]) == 'x')
				put_rect(cur, 0x00ff9800);
			else
				put_rect(cur, 0x00009688);
		}
	}
}

int			f(void)
{
	if (!g_stop)
	{
		g_stop = get_input(&g_data);
		if (g_stop) {
			mlx_destroy_window(g_mlx_ptr, g_win_ptr);
			return (0);
		}
		mlx_clear_window(g_mlx_ptr, g_win_ptr);
		show_map(g_data);
	}
	return (0);
}

int			exit_c(void)
{
	exit(1);
}

int			main(void)
{
	g_mlx_ptr = mlx_init();
	g_stop = 0;
	initialize(&g_data, &g_win_ptr, g_mlx_ptr);
	mlx_hook(g_win_ptr, 17, 1L << 17, exit_c, NULL);
	mlx_loop_hook(g_mlx_ptr, &f, NULL);
	mlx_loop(g_mlx_ptr);
	return (0);
}
