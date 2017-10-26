/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:30:23 by pbeller           #+#    #+#             */
/*   Updated: 2017/10/26 13:30:25 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <uuid/uuid.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include <unistd.h>

typedef	struct	winsize	t_ws;

typedef	struct	dirent	t_dir;

typedef	struct	stat	t_stat;

typedef	struct	passwd	t_pwd;

typedef	struct	group	t_grp;

typedef struct	s_pad
{
	int			n_uid;
	int			n_gid;
	int			b_size;
}				t_pad;

int			ft_data_nlink(const char *path);

char		ft_data_type(mode_t type);
int			ft_lenmax_name(char **tab);
char		*ft_data_name(const char *path);
char		*ft_data_uid(const char *path, int len);
char		*ft_data_gid(const char *path, int len);

char		*ft_data_wrx(const char *path);

int			ft_file_size(const char *path);
int			ft_len_min_max(const char *path);
int			ft_data_minor(const char *path);
int			ft_data_major(const char *path);
char		*ft_data_size(const char *path, int len);

long		ft_data_mtime(const char *path);
char		*ft_data_date(const char *path);

char		ft_data_type(mode_t type);
int			is_b_or_c(const char *path);
int			is_link(const char *path);
int			is_dir(const char *path);

int			last_dir_pos(const char **av, int ac);
char		**put_in_tab(char **tab, const char *path, char *name);
int			disp_dir(const char *path, char *flags, int dir_nrb);

int			ft_error(const char *str, int usage);
int			check_input(const char *path, char *flags);
void		ft_perror(const char *str);

int			llnbr_len(long long nbr);
int			ft_nbrdir(const char **av, int ac);
int			nbr_file(const char *path, int a);
DIR			*ft_opendir(const char *path);
int			ft_closedir(DIR *op_dir);

void		free_tab(char **tab);
char		**tab_init(int size);
void		ft_stock(char **tab, char *str);

char		**tab_sort(char **tab, char *flags);

void		print_sort(char **tab, char *flags, int single);
void		print_sort2(char **tab, char *flags, int i, t_pad padding);
void		print_pad_4d(int data);

int			is_a_or_f(char *flags);
int			get_flags(const char **argv, char **flags);

void		ft_print_large(const char *path, char *flags, t_pad padding);
void		print_bc(const char *path, t_pad padding);
int			ft_putnbr_ret(int nbr);
int			ft_putnbr_ret_space(int nbr);
void		ft_colored_output(const char *path, char *flags, mode_t st_mode);

t_pad		ft_padding(char **tab);
int			get_win_size(void);

#endif
