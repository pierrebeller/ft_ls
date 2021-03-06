/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:20:01 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/26 16:23:45 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_char(char **chr1, char **chr2)
{
	char *swap;

	swap = *chr1;
	*chr1 = *chr2;
	*chr2 = swap;
}
