/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:43:56 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/25 13:43:57 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		ft_data_type(mode_t type)
{
	if (type == S_IFDIR)
		return ('d');
	else if (type == S_IFCHR)
		return ('c');
	else if (type == S_IFLNK)
		return ('l');
	else if (type == S_IFBLK)
		return ('b');
	else if (type == S_IFSOCK)
		return ('s');
	else if (type == S_IFIFO)
		return ('p');
	else if (type == S_IFREG)
		return ('-');
	return (0);
}

int			is_b_or_c(const char *path)
{
	t_stat	stats;

	if (lstat(path, &stats) < 0)
		ft_perror(ft_strdup("ft_ls "));
	if (ft_data_type(stats.st_mode & S_IFMT) == 'b')
		return (1);
	if (ft_data_type(stats.st_mode & S_IFMT) == 'c')
		return (1);
	return (0);
}

int			is_link(const char *path)
{
	t_stat	stats;

	if (lstat(path &stats) < 0)
		ft_perror(ft_strdup("ft_ls "));
	if (ft_data_type(stats.st_mode & S_IFMT) == 'l')
		return(1)
	return (0);
}

int			is_dir(const char *path)
{
	DIR		*is_dir;

	is_dir = opendir(path);
	if (!is_dir)
	{
		closedir(is_dir);
		return (1);
	}
	if (errno == EACCES)
		return (1);
	return (0);
}
