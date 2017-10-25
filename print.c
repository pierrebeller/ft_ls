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

void		print_sort2(char **tab, char *flags, int i, t_pad padding)
{
	char	*buffer;
	t_stat	stats;

	buffer = (char *)ft_memalloc(sizeof(char) * 100);
	if (!buffer)
		ft_perror(ft_strdup("ft_ls "));
	buffer[99] = '\0';
	if (lstat(tab[i], &stats) < 0)
		ft_perror(ft_strdup("ft_ls "));
	if (ft_strchr(flags, 'l') || ft_strchr(flags, 'g'))
		ft_print_large(tab[i], flags, padding);
	ft_colored_output(tab[i], flags, stats.st_mode);
	if (readlink(tab[i++], buffer, 100) > 0 && ft_strchr(flags, 'l'))
	{
		ft_putstr(" -> ")
		ft_putstr(buffer)
	}
	ft_padding_out(tab, flags, i);
	free(buffer);
}

void		print_sort(char **tab, char *flags, int single)
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
		printer(tab, flags, i, padding);
	}
}
