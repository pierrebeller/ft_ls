/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 01:27:26 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/06 01:27:39 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			flag_conv(const char **fmt, va_list *args, char *flag, int *tab)
{
	char	*lm;
	char	*ret;

	lm = ft_strdup("");
	if (ft_islm(**fmt))
		flag_lm(fmt, &lm);
	else
		ft_memdel((void **)&lm);
	if (ft_isflag(**fmt))
		flag = join_flag(flag, flag_flag(fmt, 0));
	if (ft_isconv(**fmt))
	{
		flag = ft_chrjoin_free(flag, **fmt, 1);
		(*fmt)++;
		return (ft_ret_free(flag, convert(args, flag, lm, tab)));
	}
	else if (**fmt == '%')
	{
		ft_putstr((ret = add_flag(ft_strdup("%"), flag, '%', tab)));
		free(flag);
		(*fmt)++;
		return (ft_ret_free(lm, ft_ret_free(ret, ft_strlen(ret))));
	}
	return (ft_ret_free(lm, ft_ret_free(flag, no_conv(fmt, flag, tab[0]))));
}

int			flag_minw(const char **format)
{
	char	*conv;
	int		ret;

	ret = 0;
	conv = NULL;
	if (!ft_isdigit(**format))
		return (0);
	else
	{
		ret = ft_atoi(*format);
		conv = ft_itoa(ret);
		*format += ft_ret_free(conv, ft_strlen(conv));
		return (ret);
	}
}

int			flag_pre(const char **format)
{
	int		pre;
	char	find;

	find = 0;
	pre = 0;
	if (**format != '.')
		return (-1);
	while (**format == '.')
	{
		(*format)++;
		if (ft_isdigit(**format))
		{
			if (!find)
			{
				pre = (ft_atoi(*format) <= 0 ? 0 : ft_atoi(*format));
				*format += ft_nbrlen(pre);
			}
			else
				*format += ft_nbrlen(ft_atoi(*format));
		}
		else
			pre = 0;
		find = 1;
	}
	return (pre);
}

int			ft_isflag(const char format)
{
	int		ret;

	ret = 0;
	ret += (format == '#' ? 1 : 0);
	ret += (format == '-' ? 1 : 0);
	ret += (format == '+' ? 1 : 0);
	ret += (format == ' ' ? 1 : 0);
	ret += (format == '0' ? 1 : 0);
	return (ret);
}

char		*flag_flag(const char **format, int f)
{
	char	*ret;

	ret = ft_strdup("");
	while (ft_isflag(**format))
	{
		if (ft_strchr(ret, **format))
			(*format)++;
		else
		{
			ret = ft_chrjoin_free(ret, **format, 1);
			(*format)++;
		}
	}
	if (!f)
		return (ret);
	free(ret);
	return (NULL);
}
