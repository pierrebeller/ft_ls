/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:38:34 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/25 14:38:36 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	rev_sort(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[j + 1])
		j++;
	while (i < j)
		ft_swap_char(&tab[i++], &tab[j--]);
}

static void	size_sort(char **tab)
{
	long	size_f;
	long	tmp;
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = i;
		tmp = ft_file_size(tab[i]);
		while (tab[j])
		{
			if (tmp < (size_f = ft_file_size(tab[j])))
			{
				tmp = size_f;
				ft_swap_char(&tab[i], &tab[j]);
			}
			j++;
		}
		i++;
	}
}

static void	alpha_sort(char **tab)
{
	char	*a_file;
	char	*b_file;
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = i;
		a_file = ft_data_name(tab[i]);
		while (tab[j])
		{
			b_file = ft_data_name(tab[j]);
			if (0 < ft_strcmp(a_file, b_file))
			{
				a_file = b_file;
				ft_swap_char(&tab[i], &tab[j]);
			}
			j++;
		}
		i++;
	}
}

static void	time_sort(char **tab)
{
	long	time_f;
	long	tmp;
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = i;
		tmp = ft_data_mtime(tab[i]);
		while (tab[j])
		{
			if (tmp < (time_f = ft_data_mtime(tab[j])))
			{
				tmp = time_f;
				ft_swap_char(&tab[i], &tab[j]);
			}
			j++;
		}
		i++;
	}
}

char		**tab_sort(char **tab, char *flags)
{
	if (!ft_strchr(flags, 'f'))
	{
		alpha_sort(tab);
		if (ft_strchr(flags, 't'))
			time_sort(tab);
		if (ft_strchr(flags, 'S'))
			size_sort(tab);
		if (ft_strchr(flags, 'r'))
			rev_sort(tab);
	}
	return (tab);
}
