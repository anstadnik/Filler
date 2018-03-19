#include "visual.h"

void	*mlx_ptr;
void	*win_ptr;
t_data	data;
char	stop;

static void	put_rect(t_point pos, int color)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while(i < 10)
			mlx_pixel_put(mlx_ptr, win_ptr,
					(pos.x * 10) + i++, j + (pos.y * 10), color);
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
				put_rect(cur, 0x00ff0000);
			else if (ft_tolower(d.field[cur.y * d.width + cur.x]) == 'x')
				put_rect(cur, 0x0000ff00);
			else
				put_rect(cur, 0x000000ff);
		}
	}
}

/* void	print_map(t_data d) */
/* { */
/* 	size_t	j; */

/* 	ft_dprintf(2, "MAP\nplayer - %c\nheight - %d\nwidth - %d\n", */
/* 			d.player, d.height, d.width); */
/* 	j = 0; */
/* 	while ((int)j < d.width * d.height) */
/* 	{ */
/* 		ft_dprintf(2, "%c", d.field[j]); */
/* 		if (j && !((j + 1) % d.width)) */
/* 			ft_dprintf(2, "\n"); */
/* 		j++; */
/* 	} */
/* 	ft_dprintf(2, "TOKEN\ntok_height - %d\ntok_width - %d\n", */
/* 			d.tok_height, d.tok_width); */
/* 	j = 0; */
/* 	while ((int)j < d.tok_width * d.tok_height && d.token[j]) */
/* 	{ */
/* 		ft_dprintf(2, "%c", d.token[j]); */
/* 		if (j && !((j + 1) % d.tok_width)) */
/* 			ft_dprintf(2, "\n"); */
/* 		j++; */
/* 	} */
/* } */
int	f()
{
	if (!stop)
	{
		usleep(10000);
		stop = get_input(&data);
		if (stop)
			return (0);
		/* print_map(data); */
		/* mlx_clear_window (mlx_ptr, win_ptr); */
		show_map(data);
	}
	else
		printf("hehey");
	return (0);
}

int exit_c(void)
{
	exit(1);
}

int	main()
{
	mlx_ptr = mlx_init();
	stop = 0;
	initialize(&data, &win_ptr, mlx_ptr);
	mlx_hook(win_ptr, 17, 1L << 17, exit_c, NULL);
	mlx_loop_hook(mlx_ptr, &f, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
