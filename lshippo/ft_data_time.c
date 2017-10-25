/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:13:00 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/12 13:13:04 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long		ft_data_mtime(const char *path)
{
	t_stat	stats;

	if (lstat(path, &stats) < 0)
		ft_perror(ft_strdup("ft_ls "));
	return ((long)stats.st_mtimespec.tv_sec);
}

static char	*ft_years(char *date)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 4;
	ret = (char *)ft_memalloc(sizeof(char) * 13);
	while (j < 11)
		ret[i++] = date[j++];
	j = (int)ft_strlen(date) - 5;
	while (date[j + 1])
		ret[i++] = date[j++];
	ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}

static char	*ft_hours(char *date)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 4;
	ret = (char *)ft_memalloc(sizeof(char) * 13);
	while (j < 16)
		ret[i++] = date[j++];
	ret[i] = '\0';
	return (ret);
}

char		*ft_data_date(const char *path)
{
	t_stat	stats;
	time_t	*nowaday;
	char	*date;

	nowaday = NULL;
	if (lstat(path, &stats) < 0)
		ft_perror(ft_strdup("ft_ls "));
	date = ctime(&stats.st_mtimespec.tv_sec);
	if ((long)time(nowaday) - (long)stats.st_mtimespec.tv_sec > 15778800)
		return (ft_years(date));
	if ((long)stats.st_mtimespec.tv_sec - (long)time(nowaday) > 15778800)
		return (ft_years(date));
	return (ft_hours(date));
}
