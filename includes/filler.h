/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:07:22 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/18 11:07:58 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef	struct s_data t_data;
typedef	struct s_point t_point;

struct	s_point
{
	int	x;
	int	y;
};

struct	s_data
{
	char	player;
	char	opponent;
	int		widht;
	int		height;
	char	*field;
	int		tok_widht;
	int		tok_height;
	char	*token;
};

void	initialize(t_data *data);
void	get_input(t_data *data);
char	algo(t_data data);
void	print_map(t_data data);

#endif
