/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_clrd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:28:13 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/12 13:28:15 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_putstr_clrd(char *str, char *color)
{
	if (str && color)
	{
		ft_putstr(color);
		ft_putstr(str);
		ft_putstr("\033[0m");
	}
}
