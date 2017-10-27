/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 10:34:58 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/26 10:34:59 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_colored_output(const char *path, char *flags, mode_t st_mode)
{
	char		type;

	if (ft_strchr(flags, 'G'))
	{
		type = ft_data_type(st_mode & S_IFMT);
		if (type == 'd')
			ft_putstr_clrd(ft_data_name(path), "\033[36m");
		else if (type == 'l')
			ft_putstr_clrd(ft_data_name(path), "\033[35m");
		else if (type == 'b')
			ft_putstr_clrd(ft_data_name(path), "\033[34m\033[46m");
		else if (type == 'c')
			ft_putstr_clrd(ft_data_name(path), "\033[34m\033[43m");
		else if (type == 'p')
			ft_putstr_clrd(ft_data_name(path), "\033[33m");
		else if (type == 's')
			ft_putstr_clrd(ft_data_name(path), "\033[32m");
		else if (type == '-' && (S_IEXEC & st_mode))
			ft_putstr_clrd(ft_data_name(path), "\033[31m");
		else
			ft_putstr(ft_data_name(path));
	}
	else
		ft_putstr(ft_data_name(path));
}

int			ft_putnbr_ret_space(int nbr)
{
	int		ret;
	char	*str;
	int		i;

	i = 1;
	str = ft_itoa(nbr);
	ret = ft_strlen(str);
	ft_putchar(' ');
	ft_putstr(str);
	free(str);
	return (ret);
}

int			ft_putnbr_ret(int nbr)
{
	int		ret;
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(nbr);
	ret = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

void		print_bc(const char *path, t_pad padding)
{
	int	ret;

	ret = ft_putnbr_ret(ft_data_major(path));
	ft_putxchar(' ', (padding.b_size / 2) - 1 - ret);
	ft_putchar(',');
	ret = ft_putnbr_ret_space(ft_data_minor(path));
	ft_putxchar(' ', (padding.b_size / 2) + (padding.b_size % 2) - ret);
}

void		ft_print_large(const char *path, char *flags, t_pad padding)
{
	ft_putstr_free(ft_data_wrx(path), 1);
	print_pad_4d(ft_data_nlink(path));
	if (!ft_strchr(flags, 'g'))
	{
		ft_putstr_free(ft_data_uid(path, padding.n_uid), 1);
		ft_putchar(' ');
	}
	ft_putstr_free(ft_data_gid(path, padding.n_gid), 1);
	ft_putchar(' ');
	if (is_b_or_c(path))
		print_bc(path, padding);
	else
	{
		ft_putstr_free(ft_data_size(path, padding.b_size), 1);
		ft_putchar(' ');
	}
	ft_putstr_free(ft_data_date(path), 1);
	ft_putchar(' ');
}
