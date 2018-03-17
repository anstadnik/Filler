/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:01:15 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/17 22:43:50 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_map(t_data data)
{
	size_t	j;

	j = 0;
	ft_dprintf(2, "MAP\nplayer - %c\nheight - %d\nwidth - %d\n",
			data.player, data.height, data.widht);
	while ((int)j < data.widht * data.height)
	{
		ft_dprintf(2, "%c", data.field[j]);
		if (j && !((j + 1) % data.widht))
			ft_dprintf(2, "\n");
		j++;
	}
	ft_dprintf(2, "TOKEN\ntok_height - %d\ntok_width - %d\n",
			data.tok_height, data.tok_widht);
	j = 0;
	while ((int)j < data.tok_widht * data.tok_height && data.token[j])
	{
		ft_dprintf(2, "%c", data.token[j]);
		if (j && !((j + 1) % data.tok_widht))
			ft_dprintf(2, "\n");
		j++;
	}
}

int	main()
{
	t_data	data;

	initialize(&data);
	data.field = NULL;
	while (42)
	{
		get_input(&data);
		/* print_map(data); */
		ft_dprintf(2, "12 13\n");
		ft_printf("12 13\n");
		/* print_sol(data); */
	}
	return (0);
}
