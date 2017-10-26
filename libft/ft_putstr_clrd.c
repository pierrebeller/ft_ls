/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_clrd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:05:01 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/26 16:05:02 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_clrd(char *str, char *color)
{
	if (str && color)
	{
		ft_putstr(color);
		ft_putstr(str);
		ft_putstr("\033[0m");
	}
}
