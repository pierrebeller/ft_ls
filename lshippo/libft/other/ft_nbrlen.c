/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 06:12:05 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/29 15:37:10 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_nbrlen(int nbr)
{
	int count;

	count = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		if (nbr != 0)
			count++;
		else
			break ;
	}
	return (count);
}
