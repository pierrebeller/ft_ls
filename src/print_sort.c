/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:52:15 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/25 17:52:17 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_padding_out(char **tab, char *flags, int i)
{
	static char	**tab_add;
	static int	len;
	static int	output;

	if (ft_strchr(flags, 'l') || ft_strchr(flags, '1') || ft_strchr(flags, 'g'))
		ft_putchar('\n');
	else
	{
		if (tab_add != tab)
		{
			tab_add = tab;
			len = ft_lenmax_name(tab) + 2;
			if (!(output = get_win_size() / len))
				output = 1;
		}
		if (i % output == 0 && tab[i])
			ft_putchar('\n');
		else
			ft_putxchar(' ', len - ft_strlen(ft_data_name(tab[i - 1])));
		if (tab[i] == NULL && output != 1)
			ft_putchar('\n');
	}
}

static int		ft_total_blocks(char **tab)
{
	t_stat		stats;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	while (tab[i])
	{
		if (lstat(tab[i], &stats) >= 0)
			ret += (int)stats.st_blocks;
		i++;
	}
	return (ret);
}

void			print_pad_4d(int data)
{
	int	len;

	len = ft_size_int(data);
	if (len == 0)
		ft_putstr("    ");
	if (len == 1)
	{
		ft_putstr("   ");
		ft_putnbr(data);
	}
	if (len == 2)
	{
		ft_putstr("  ");
		ft_putnbr(data);
	}
	if (len == 3)
	{
		ft_putstr(" ");
		ft_putnbr(data);
	}
	if (len == 4)
		ft_putnbr(data);
	ft_putchar(' ');
}

void			print_sort2(char **tab, char *flags, int i, t_pad padding)
{
	char	*buffer;
	t_stat	stats;
	int		len;

	len = ft_strlen(tab[i]);
	buffer = (char *)ft_memalloc(sizeof(char) * len + 1);
	if (!buffer)
		ft_perror(ft_strdup("ft_ls "));
	buffer[len] = '\0';
	if (lstat(tab[i], &stats) < 0)
		ft_perror(ft_strdup("ft_ls "));
	if (ft_strchr(flags, 'l') || ft_strchr(flags, 'g'))
		ft_print_large(tab[i], flags, padding);
	ft_colored_output(tab[i], flags, stats.st_mode);
	if (readlink(tab[i++], buffer, len) > 0 && ft_strchr(flags, 'l'))
	{
		ft_putstr(" -> ");
		ft_putstr(buffer);
	}
	ft_padding_out(tab, flags, i);
	free(buffer);
}

void			print_sort(char **tab, char *flags, int single)
{
	t_pad	padding;
	int		i;

	i = 0;
	if (ft_strchr(flags, 'l') && !single)
	{
		ft_putstr("total ");
		ft_putnbr(ft_total_blocks(tab));
		ft_putchar('\n');
	}
	padding = ft_padding(tab);
	while (tab[i])
	{
		if (ft_stats(tab[i]))
			print_sort2(tab, flags, i, padding);
		i++;
	}
}
