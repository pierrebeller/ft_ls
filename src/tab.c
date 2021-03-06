/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:25:00 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/27 19:25:02 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_stock(char **tab, char *str)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	tab[i] = ft_strdup(str);
}

char		**tab_init(int size)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
	{
		perror("ft_ls : ");
		exit(-1);
	}
	while (i < size)
		tab[i++] = NULL;
	tab[i] = NULL;
	return (tab);
}

void		free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab[i])
	{
		while (tab[i])
			ft_memdel((void **)&tab[i++]);
		ft_memdel((void **)&tab[i]);
		free(tab);
		tab = NULL;
	}
}
