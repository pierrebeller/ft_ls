/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:57:25 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/26 15:57:28 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>

char		*ft_chrjoinfree(char *s, const char c, int flag)
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	new = (char *)ft_x_malloc(sizeof(char) * (ft_strlen(s) + 2));
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	if (flag == 1)
		free(s);
	return (new);
}
