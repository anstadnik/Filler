/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:15:34 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/20 14:26:30 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		initialize(t_data *data)
{
	char	*buf;

	get_next_line(0, &buf);
	data->player = buf[10] == '1' ? 'o' : 'x';
	data->opponent = buf[10] != '1' ? 'o' : 'x';
	free(buf);
}

static void	get_size_and_malloc(t_data *data, char *buf)
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
}

static void	get_token(t_data *data)
{
	char	*buf;
	size_t	i;

	get_next_line(0, &buf);
	i = 0;
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
		free(buf);
	}
}

void		get_input(t_data *data)
{
	char	*buf;
	size_t	i;

	get_next_line(0, &buf);
	if (!data->field)
		get_size_and_malloc(data, buf);
	free(buf);
	get_next_line(0, &buf);
	free(buf);
	i = -1;
	ft_bzero(data->field, data->width * data->height);
	while ((int)++i < data->height)
	{
		get_next_line(0, &buf);
		ft_memcpy(data->field + i * data->width, buf + 4, data->width);
		free(buf);
	}
	get_token(data);
}
