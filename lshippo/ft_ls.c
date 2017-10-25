/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:13:42 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/12 13:13:45 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_single(const char *path, char *flags)
{
	char	**tab;
	t_pad	padding;

	if (ft_strchr(flags, 'l'))
	{
		tab = ft_init_tab(1); //==>tab.c
		tab[0] = ft_strdup(path);
		padding = ft_padding(tab); //==> padding.c
		ft_print_large(path, flags, padding); //==> print.c
		ft_free_tab(tab);
	}
	if (ft_strchr(flags, 'G'))
		ft_putstr("\033[36m.\033[0m\n");
	else
		ft_putstr(".\n");
}

static int	ft_get_file(const char **input, char *flags, int nbr, int pos)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (pos + i < nbr)
	{
		if ((!ft_isdir(input[pos + i]) || ft_strchr(flags, 'd') ||\
		(ft_is_l(input[pos + i]) && ft_strchr(flags, 'l'))) && input[pos + i]) //==>data_type.c
			ret++;	
		i++;
	}
	return (ret);
}

static void	ft_single_file(const char **input, char *flags, int nbr, int pos) // traite fichiers simples
{
	char	**tab;
	int		size;
	int		i;

	i = 0;
	size = ft_get_file(input, flags, nbr, pos); // calcule le nombre de fichiers
	if (size)
	{
		tab = ft_init_tab(size); // initialise le tableau, stock des fichiers ==>tab.c
		while (pos + i < nbr)
		{
			if ((!ft_isdir(input[pos + i]) || ft_strchr(flags, 'd') || (ft_is_l\
			(input[pos + i]) && ft_strchr(flags, 'l'))) && input[pos + i])
				ft_insert(tab, (char *)(input[pos + i])); // ecrit le fichier dans le tab ==>tab.c
			i++;
		}
		ft_print_sort(ft_sort_tab(tab, flags), flags, 1); //imprime ==>print.c fichiers triés ==>sort.c
		if (nbr - pos > size && tab[0])
			ft_putchar('\n');
		ft_free_tab(tab); // ==>tab.c
	}
}

static void	ft_find(const char **input, char *flags, int nbr_arg, int pos) // traite les fichier avec flags
{
	int		i;

	i = 0;
	//CHECK
	while (input[pos + i])
	{
		if (!ft_check_input(input[pos + (i++)], flags)) // ==>ft_error.c
			input[pos + (i - 1)] = NULL;
	}
	//SINGLE
	ft_single_file(input, flags, nbr_arg, pos); // traite dossier courant avc flags
	//PRINT
	if (!ft_strchr(flags, 'd'))
	{
		while (pos < nbr_arg)
		{
			if (ft_isdir(input[pos]) && !(ft_is_l(input[pos]) &&\ // si dossier et si pas de flag l, print et traite les dossiers ==>data_type.c
			ft_strchr(flags, 'l')))
			{
				ft_printf("%s:\n", input[pos]);
				ft_disp_dir(input[pos], flags, ft_nbrdir(input, nbr_arg)); //traite le dossier ==>file.c
				if (pos++ < ft_pos_last_dir(input, nbr_arg)) // ==>dir.c
					ft_putchar('\n');
			}
			else
				pos++;
		}
	}
}

int			main(int argc, const char **argv)
{
	char	*flags;
	int		dir;

	flags = ft_strdup("");
	// dir = pos du premier arg apres flags
	dir = 0;
	if (argc < 2)
	{
		ft_disp_dir(".", flags, 0); //traite dossier courant sans flags ==> ft_dir.c
		return (ft_ret_free(flags, 0)); //retourne 0 et free flags ==> libft
	}
	else 
		dir = ft_flag(argv, &flags); // set les flags + nbre de dossiers ==> ft_flags.c
	if (dir < 0) // si pas de fichiers apres les flags
	{
		if (ft_strchr(flags, 'd')) //bonus
			ft_print_single(".", flags); //bonus
		else
			ft_disp_dir(".", flags, 0); //traite dossier courant avec flags ==> ft_dir.c
	}
	else
		ft_find(argv, flags, argc, dir); // traite les fichiers avec les flags
	return (ft_ret_free(flags, 0)); // retourne 0 et free flags ==>libft
}
