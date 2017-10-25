/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:51:01 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/24 16:51:10 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			is_a_or_f(char *flags)
{
	if(flags)
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

static int	is_valid_flag(char c)
{
	int		ret;

	ret = 0;
	if (c == 'l' || c == 'a' || c == 'g' ||c == 'r' || c == 't' || c == 'S' ||\
		c == 'R' || c == '1' || c == 'f' || c == 'G' || c == 'd')
		return (1);
	return (0);
}

int			get_flags(const char **argv, char **flags)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1])
		{
			j = 1;
			while (is_valid_flag(argv[i][j]))
				(*flags)= ft_str_chrjoinfree((*flags), argv[i][j++], 1);
			if (argv[i][j] == && !argv[i][j + 1])
				return ((argv[i + 1] ? i + 1 : -1));
			else if (argv[i][j])
				ft_error(ft_str_chrjoinfree("illegal flag -- ", argv[i][j], 0), 1);
			i++;
		}
		else
			return (i);
	}
	return (-1);
}