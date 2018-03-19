/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_inp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 12:46:32 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/19 15:30:12 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	*get_size_and_malloc(t_data *data, char *buf, void *mlx_ptr)
{
	while (ft_isalpha(*buf) || ft_isspace(*buf))
		buf++;
	data->height = ft_atoi(buf);
	while (ft_isdigit(*buf))
		buf++;
	data->width = ft_atoi(buf);
	data->field = ft_memalloc((size_t)(data->width * data->height));
	data->token = ft_memalloc((size_t)(data->width * data->height));
	return (mlx_new_window(mlx_ptr, (data->width) * 10,
				(data->height) * 10, "Filler"));
}

static char	q(char **buf, char n)
{
	free(*buf);
	return (n);
}

static char	skip(void)
{
	char	*buf;

	while (42)
	{
		get_next_line(0, &buf);
		if (!ft_memcmp(buf, "    01234", 8))
			return (q(&buf, 0));
		if (!ft_memcmp(buf, "==", 2))
		{
			free(buf);
			get_next_line(0, &buf);
			return (q(&buf, 1));
		}
		if (ft_memcmp(buf, "Plateau", 7) && ft_memcmp(buf, "Piece", 5) &&
				ft_memcmp(buf, "<got ", 4) && *buf != '.' && *buf != '*')
			return (q(&buf, 1));
		free(buf);
	}
}

void		initialize(t_data *data, void **win_ptr, void *mlx_ptr)
{
	char	*buf;
	size_t	i;
	char	tmp;

	i = 0;
	while (i < 9)
	{
		read(0, &tmp, 1);
		if (tmp == '\n')
			i++;
	}
	get_next_line(0, &buf);
	*win_ptr = get_size_and_malloc(data, buf, mlx_ptr);
	free(buf);
	skip();
}

char		get_input(t_data *data)
{
	char	*buf;
	ssize_t	i;

	i = -1;
	while ((int)++i < data->height)
	{
		get_next_line(0, &buf);
		ft_memcpy(data->field + i * data->width, buf + 4, data->width);
		free(buf);
	}
	return (skip());
}
