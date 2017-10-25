/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:13:32 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/12 13:13:35 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_a_or_f(char *flags)
{
	if (flags)
	{
		if (ft_strchr(flags, 'a'))
			return (1);
		else if (ft_strchr(flags, 'f'))
			return (1);
		else
			return (0);
	}
	return (0);
}

static int	ft_is_flag(char c)
{
	int		ret;

	ret = 0;
	ret += (c == 'l' || c == 'a' || c == 'g' ? 1 : 0);
	ret += (c == 'r' || c == 't' || c == 'S' ? 1 : 0);
	ret += (c == 'R' || c == '1' || c == 'f' ? 1 : 0);
	ret += (c == 'd' || c == 'G' ? 1 : 0);
	return (ret);
}

int			ft_flag(const char **args, char **flag)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (args[i]) //parcourt argv
	{
		if (args[i][0] == '-' && args[i][1]) //si '-' et un flag apres
		{
			while (ft_is_flag(args[i][j])) // tant que c est un flag valide
				(*flag) = ft_chrjoin_free((*flag), args[i][j++], 1); // cherche le flag, join, free==>libft
			if (args[i][j] == '-' && !args[i][j + 1]) // cas particulier '--' permet de gerer les fichier et dossiers commencant par -
			{
				// *flag = ft_retstr_free((*flag), ft_strdup("")); juste virer la ligne
				return ((args[i + 1] ? i + 1 : -1));
			}
			else if (args[i][j]) //illegal flag
				ft_error(ft_chrjoin_free("illegal flag -- ", args[i][j], 0), 1);
			i++;
			j = 1;
		}
		else 
			return (i);
	}
	return (-1); // pas de fichier à traiter
}
