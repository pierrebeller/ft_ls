/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 00:58:20 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/06 00:58:21 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_putwstr(wint_t *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_putwchar(str[i++]) < 0)
			return (-1);
	}
	return (ft_wstrlen(str));
}
