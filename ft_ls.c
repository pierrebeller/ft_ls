/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:18:10 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/24 16:18:52 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	print_simple(const char *path, char *flags)
{
	char	**tab;
	t_pad	padding;

	if (ft_strchr(flags, 'l'))
	{
		tab = tab_init(1);
		tab[0] = ft_strdup(path);
		padding = ft_padding(tab);
		print_large(path, flags, padding);
		free_tab(tab);
	}
	if (ft_strchr(flags, 'G'))
		ft_putstr("\033[36m.\033[0m\n");
	else
		ft_putstr(".\n");
}

static int	file_number(const char **av, int ac, char *flags, int index)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (index + i < ac)
	{
		if ((!isdir(av[index + i]) || ft_strchr(flags, 'd') ||(is_link\
			(av[index + i]) && ft_strchr(flags, 'l'))) && av[index + 1])
			len++;
		i++;
	}
	return (len);
}

static void	single_file(const char **av, int ac, char *flags, int index)
{
	char	**tab;
	int		len;
	int		i;

	i = 0;
	len = file_number(av, ac, flags, index);
	if (len != 0)
	{
		tab = tab_init(len);
		while (index + i < ac)
		{
			if ((!is_dir(av[index + i]) || ft_strchr(flags, 'd')|| (is_link\
				(av[index + i]) && ft_strchr(flags, 'l'))) && av[index + i])
				ft_stock(tab, (char *)(av[index + i]));
			i++;
		}
		print_sort(tab_sort(tab, flags), flags, 1);
		if (ac - index > len && tab[0])
			ft_putchar('\n');
		free_tab(tab);
	}
}

static void	find_files(const char *av, int ac, char *flags, int n)
{
	int		i;

	i = 0;
	while (av[n + i])
	{
		if (!check_input(av[n + (i++)], flags))
			av[n + i - 1] == NULL;
	}
	single_file(av, ac, flags, n);
	if (!ft_strchr(flags, 'd'))
	{
		while (n < ac)
		{
			if (isdir(av[n]) && !(is_link(av[n]) && ft_strchr(flags, 'l')))
			{
				ft_putstr(av[n]);
				ft_putchar('\n');
				disp_dir(av[n], flags, ft_nbrdir(av, ac));
				if (n++ < last_dir_pos(av, ac))
					ft_putchar('\n');
			}
			else
				n++;
		}
	}
}

int			ft_ls(int ac, const char **av)
{
	char	*flags;
	int		dir;

	dir = 0;
	flags = ft_strdup("");
	if (ac < 2)
	{
		disp_dir(".", flags, 0);
		return (free_ret(flags, 0));
	}
	else 
		dir = get_flags(argv, &flags);
	if (dir < 0)
	{
		if (ft_strchr(flags, 'd'))
			print_simple(".", flags)
		else
			disp_dir(".", flags, 0);
	}
	else
		find_files(argv, argc, flags, dir);
	return (free_ret(flags, 0));
}
