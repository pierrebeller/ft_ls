/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directories.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 11:44:04 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/25 11:44:06 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

static char	*add_path_tab(char *dest, const char *p, const char *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	dest = (char *)ft_x_malloc(sizeof(char) * ft_strlen(p) + ft_strlen(d) + 2);
	while (p[i])
		dest[j++] = p[i++];
	dest[j++] = '/';
	i = 0;
	while (d[i])
		dest[j++] = d[i++];
	dest[j++] = '\0';
	return (dest);
}

static void	rec_disp(char **tab, char *flags, int dir_nrb)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (!is_link(tab[i]) && is_dir_stat(tab[i]) && ft_strcmp(ft_data_name(\
			tab[i]), ".") && ft_strcmp(ft_data_name(tab[i]), ".."))
		{
			ft_putchar('\n');
			ft_putstr(tab[i]);
			ft_putstr(":\n");
			disp_dir(tab[i], flags, dir_nrb);
		}
		i++;
	}
}

int			last_dir_pos(const char **av, int ac)
{
	DIR		*is_dir_stat;
	int		pos;
	int		i;

	i = 0;
	pos = 0;
	while (i < ac)
	{
		if ((is_dir_stat = opendir(av[i])))
		{
			closedir(is_dir_stat);
			pos = i;
		}
		i++;
	}
	return (pos);
}

char		**put_in_tab(char **tab, const char *path, char *name)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	tab[i] = add_path_tab(tab[i], path, name);
	return (tab);
}

int			disp_dir(const char *path, char *flags, int dir_nrb)
{
	DIR		*rep;
	t_dir	*file;
	char	**tab;
	int		i;

	i = 0;
	if (!(rep = opendir(path)))
		return (0);
	tab = tab_init(nbr_file(path, is_a_or_f(flags)));
	if (nbr_file(path, is_a_or_f(flags)) == 0)
		ft_putstr("(empty directory)\n");
	else
	{
		while ((file = readdir(rep)))
		{
			if (file->d_name[0] == '.' && !is_a_or_f(flags))
				continue;
			put_in_tab(tab, path, file->d_name);
		}
		print_sort(tab_sort(tab, flags), flags, 0);
		if (ft_strchr(flags, 'R'))
			rec_disp(tab, flags, dir_nrb);
	}
	free_tab(tab);
	return (ft_closedir(rep));
}
