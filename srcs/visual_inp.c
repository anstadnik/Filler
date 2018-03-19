/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_inp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 12:46:32 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/18 17:52:43 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	*get_size_and_malloc(t_data *data, char *buf, void *mlx_ptr)
{
	size_t	i;

	i = 0;
	while (ft_isalpha(buf[i++]))
		;
	data->height = ft_atoi(buf + i);
	while (ft_isdigit(buf[i++]))
		;
	data->width = ft_atoi(buf + i);
	data->field = ft_memalloc(data->width * data->height);
	data->token = ft_memalloc(data->width * data->height);
	return (mlx_new_window(mlx_ptr, data->width * 10, data->height * 10, "Filler"));
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
}

static char	get_token(t_data *data)
{
	char	*buf;
	size_t	i;

	get_next_line(0, &buf);
	i = 0;
		ft_printf("hehey2%s\n", buf);
	while (ft_isalpha(buf[i++]))
		;
	data->tok_height = ft_atoi(buf + i);
	while (ft_isdigit(buf[i++]))
		;
	data->tok_width = ft_atoi(buf + i);
	free(buf);
	ft_bzero(data->token, data->width * data->height);
	i = -1;
	while ((int)++i < data->tok_height)
	{
		get_next_line(0, &buf);
		ft_memcpy(data->token + i * data->tok_width, buf, data->tok_width);
		ft_printf("hehey3%s\n", buf);
		free(buf);
	}
	get_next_line(0, &buf);
	free(buf);
	get_next_line(0, &buf);
	free(buf);
	return (0);
}

char		get_input(t_data *data)
{
	char	*buf;
	size_t	i;

	get_next_line(0, &buf);
	if (buf[1] == '=')
		return (1);
	ft_printf("hehey0%s\n", buf);
	free(buf);
	i = -1;
	while ((int)++i < data->height)
	{
		get_next_line(0, &buf);
		ft_printf("hehey1%s\n", buf);
		ft_memcpy(data->field + i * data->width, buf + 4, data->width);
		free(buf);
	}
	return (get_token(data));
}
