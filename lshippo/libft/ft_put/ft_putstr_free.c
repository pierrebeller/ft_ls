/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:28:32 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/12 13:28:34 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_putstr_free(char *str, int f)
{
	if (str)
	{
		write(1, str, ft_strlen(str));
		if (f)
			free(str);
	}
}
