/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:51:13 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/26 11:51:14 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			ft_data_nlink(const char *path)
{
	t_stat	stats;
	int		ret;

	if (lstat(path, &stats) < 0)
		ft_perror(ft_strdup("ft_ls data nlink "));
	ret = (int)stats.st_nlink;
	return (ret);
}

int			ft_lenmax_name(char **tab)
{
	int		len;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (tab[i])
	{
		len = ft_strlen(ft_data_name(tab[i++]));
		if (ret < len)
			ret = len;
	}
	return (ret);
}

char		*ft_data_name(const char *path)
{
	char	*ret;
	int		i;

	i = ft_strlen(path);
	while (path[i - 1] != '/' && i != 0)
		i--;
	ret = (char *)(path + i);
	return (ret);
}

char		*ft_data_uid(const char *path, int len)
{
	t_stat	stats;
	t_pwd	*usr;
	char	*ret;
	int		i;

	if (lstat(path, &stats) < 0)
		ft_perror(ft_strdup("ft_ls data uid "));
	i = 0;
	if (!(usr = getpwuid(stats.st_uid)))
	{
		len -= (int)(ft_strlen(ret = ft_itoa((int)stats.st_uid)));
		ret = ft_strjoinfree(ret, ft_strchain(' ', len), 'b');
		return (ret);
	}
	ret = (char *)ft_memalloc(sizeof(char) * len + 1);
	while (usr->pw_name[i] && i < len)
	{
		ret[i] = usr->pw_name[i];
		i++;
	}
	while (i < len)
		ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}

char		*ft_data_gid(const char *path, int len)
{
	t_stat	stats;
	t_grp	*grp;
	char	*ret;
	int		i;

	if (lstat(path, &stats) < 0)
		ft_perror(ft_strdup("ft_ls data gid "));
	i = 0;
	if (!(grp = getgrgid(stats.st_gid)))
	{
		len -= (int)(ft_strlen(ret = ft_itoa((int)stats.st_gid)));
		ret = ft_strjoinfree(ret, ft_strchain(' ', len), 'b');
		return (ret);
	}
	ret = (char *)ft_memalloc(sizeof(char) * len + 1);
	while (grp->gr_name[i] && i < len)
	{
		ret[i] = grp->gr_name[i];
		i++;
	}
	while (i < len)
		ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}
