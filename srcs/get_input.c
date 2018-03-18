/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:15:34 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/18 10:59:44 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		initialize(t_data *data)
{
	char	*buf;

	get_next_line(0, &buf);
	data->player = buf[10] == 1 ? 'o' : 'x';
	data->opponent = buf[10] != 1 ? 'o' : 'x';
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
	data->widht = ft_atoi(buf + i);
	data->field = ft_memalloc(data->widht * data->height);
	data->token = ft_memalloc(data->widht * data->height);
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
	data->tok_widht = ft_atoi(buf + i);
	free(buf);
	ft_bzero(data->token, data->widht * data->height);
	i = -1;
	while ((int)++i < data->tok_height)
	{
		get_next_line(0, &buf);
		ft_memcpy(data->token + i * data->tok_widht, buf, data->tok_widht);
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
	ft_bzero(data->field, data->widht * data->height);
	while ((int)++i < data->height)
	{
		get_next_line(0, &buf);
		ft_memcpy(data->field + i * data->widht, buf + 4, data->widht);
		free(buf);
	}
	get_token(data);
}
