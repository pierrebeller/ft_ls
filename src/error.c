/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:14:05 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/25 14:14:06 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			ft_error(const char *str, int usage)
{
	ft_putstr("ft_ls : ");
	ft_putstr(str);
	ft_putchar('\n');
	if (usage)
		ft_putstr("usage : ft_ls [-1adfgGlrRSt] [file ...]\n");
	exit(EXIT_FAILURE);
}

int			check_input(const char *path, char *flags)
{
	DIR		*check;

	check = opendir(path);
	if (check)
		ft_closedir(check);
	else
	{
		if (ft_strchr(flags, 'd') || errno == ENOTDIR)
			return (1);
		else if (errno == EACCES)
		{
			ft_putstr("ft_ls : ");
			perror(path);
			return (0);
		}
		else
		{
			ft_putstr("ft_ls : ");
			perror(path);
			return (0);
		}
	}
	return (1);
}

void		ft_perror(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int			ft_ret_perror(const char *str)
{
	perror(str);
	return (0);
}

int			ft_stats(const char *path)
{
	t_stat	stats;

	if (lstat(path, &stats) < 0)
		return (0);
	return (1);
}
