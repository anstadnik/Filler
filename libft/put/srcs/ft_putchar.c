/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astadnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:02:16 by astadnik          #+#    #+#             */
/*   Updated: 2017/11/09 13:14:33 by astadnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the character c to the standard output.
*/

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
