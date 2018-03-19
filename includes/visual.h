/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <astadnik@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 12:45:30 by astadnik          #+#    #+#             */
/*   Updated: 2018/03/19 14:31:38 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H
# include "mlx.h"
# include "../libft/includes/libft.h"

typedef struct s_data	t_data;
typedef struct s_point	t_point;

struct					s_point
{
	int	x;
	int	y;
};

struct					s_data
{
	char				player;
	char				opponent;
	int					width;
	int					height;
	char				*field;
	int					tok_width;
	int					tok_height;
	char				*token;
};

void					initialize(t_data *data, void **win_ptr, void *mlx_ptr);
char					get_input(t_data *data);

#endif
