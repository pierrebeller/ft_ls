/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 01:02:48 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/06 01:02:49 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_wstrlen(wint_t *str)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
		count += ft_wcharlen(str[i++]);
	return (count);
}
