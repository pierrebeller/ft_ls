/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:12:44 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/25 15:12:45 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	padding_uid(char **tab)
{
	t_stat	stats;
	t_pwd	*usr;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (tab[i])
	{
		if (lstat(tab[i++], &stats) < 0)
			i++;
		usr = getpwuid(stats.st_uid);
		if (!usr)
		{
			if (ret < ft_size_int((int)stats.st_uid))
				ret = ft_size_int((int)stats.st_uid);
		}
		else if (ret < (int)ft_strlen(usr->pw_name))
			ret = (int)ft_strlen(usr->pw_name);
	}
	return (ret);
}

static int	padding_gid(char **tab)
{
	t_stat	stats;
	t_grp	*grp;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (tab[i])
	{
		if (lstat(tab[i++], &stats) < 0)
			i++;
		grp = getgrgid(stats.st_gid);
		if (!grp)
		{
			if (ret < ft_size_int((int)stats.st_gid))
				ret = ft_size_int((int)stats.st_gid);
		}
		else if (ret < (int)ft_strlen(grp->gr_name))
			ret = (int)ft_strlen(grp->gr_name);
	}
	return (ret);
}

static int	pad_size(char **tab)
{
	t_stat	stats;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (tab[i])
	{
		if (lstat(tab[i], &stats) < 0)
			i++;
		if (!tab[i])
			break ;
		if (is_b_or_c(tab[i]))
		{
			if (ret < ft_len_min_max(tab[i]))
				ret = ft_len_min_max(tab[i]);
		}
		else if (ret < llnbr_len(stats.st_size))
			ret = llnbr_len(stats.st_size);
		i++;
	}
	return (ret);
}

int			get_win_size(void)
{
	t_ws	win;

	if (ioctl(0, TIOCGWINSZ, &win) < 0)
		ft_perror("ioctl");
	return ((win.ws_col == 0 ? 1 : win.ws_col));
}

t_pad		ft_padding(char **tab)
{
	t_pad	padding;

	padding.n_uid = padding_uid(tab);
	padding.n_gid = padding_gid(tab);
	padding.b_size = pad_size(tab);
	return (padding);
}
