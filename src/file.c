/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:10:14 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/25 13:10:15 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		llnbr_len(long long nbr)
{
	int	ret;

	ret = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		if (nbr != 0)
			ret++;
		else
			break;
	}
	return (ret);
}

int		ft_nbrdir(const char **av, int ac)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = 0;
	while (i < ac)
	{
		if(is_dir(av[i]) || !av[i])
			nbr++;
		i++;
	}
	return (nbr);
}

int		nbr_file(const char *path, int a)
{
	int		nbr;
	DIR		*rep;
	t_dir	*file;

	nbr = 0;
	rep = opendir(path);
	if (!rep)
		exit(EXIT_FAILURE);
	while ((file = readdir(rep)))
	{
		if (file->d_name[0] == '.' && a == 0)
			continue;
		nbr++;
	}
	if (closedir(rep) < 0)
		exit (EXIT_FAILURE);
	return (nbr);
}

DIR		*ft_opendir(const char *path)
{
	DIR	*ret;

	ret = opendir(path);
	if(!ret)
	{
		if (errno == EACCES)
		{
			ft_putstr("ft_ls : ");
			perror(path);
			return (NULL);
		}
		if (errno == ENOTDIR)
			return (NULL);
		ft_putstr("ft_ls : ");
		perror(path);
		exit(EXIT_FAILURE);
	}
	return (ret);
}

int		ft_closedir(DIR *op_dir)
{
	if (closedir(op_dir) < 0)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	return (0);
}
