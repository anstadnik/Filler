/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:01:15 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/18 18:19:35 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_map(t_data d)
{
	size_t	j;

	ft_dprintf(2, "MAP\nplayer - %c\nheight - %d\nwidth - %d\n",
			d.player, d.height, d.width);
	j = 0;
	while ((int)j < d.width * d.height)
	{
		ft_dprintf(2, "%c", d.field[j]);
		if (j && !((j + 1) % d.width))
			ft_dprintf(2, "\n");
		j++;
	}
	ft_dprintf(2, "TOKEN\ntok_height - %d\ntok_width - %d\n",
			d.tok_height, d.tok_width);
	j = 0;
	while ((int)j < d.tok_width * d.tok_height && d.token[j])
	{
		ft_dprintf(2, "%c", d.token[j]);
		if (j && !((j + 1) % d.tok_width))
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
		if (!algo(data))
			return (0);
	}
	return (0);
}
