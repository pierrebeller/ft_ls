/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:34:20 by heinfalt          #+#    #+#             */
/*   Updated: 2017/10/12 13:34:27 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

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
# include "libft/includes/libft.h"

typedef struct winsize	t_ws;

typedef struct dirent	t_dir;

typedef struct stat		t_stat;

typedef struct passwd	t_pwd;

typedef struct group	t_grp;

typedef struct	s_pad
{
	int			n_uid;
	int			n_gid;
	int			b_size;
}				t_pad;

int				ft_closedir(DIR *op_dir);
int				ft_isdir(const char *path);
int				ft_nbrdir(const char **input, int argc);
int				ft_nbrfile(const char *path, int a);
DIR				*ft_opendir(const char *path);

int				ft_error(const char *msg, int usage);
void			ft_perror(const char *msg);
int				ft_check_input(const char *path, char *flags);

int				ft_pos_last_dir(const char **input, int argc);
int				ft_llnbrlen(long long nbr);

int				ft_flag(const char **args, char **flag);
int				ft_disp_dir(const char *path, char *flags, int nbr_dir);

void			ft_print_sort(char **tab, char *flags, int single);
void			ft_print_large(const char *path, char *flags, t_pad padding);

int				ft_a_or_f(char *flags);
int				ft_is_l(const char *path);
int				ft_is_bc(const char *path);
char			ft_data_type(mode_t type);

int				ft_get_winsize(void);
t_pad			ft_padding(char **tab);

int				ft_lenmax_name(char **tab);
int				ft_len_min_max(const char *path);
int				ft_data_minor(const char *path);
int				ft_data_major(const char *path);

long			ft_data_mtime(const char *path);
char			*ft_data_date(const char *path);

char			*ft_data_wrx(const char *path);
int				ft_data_nlink(const char *path);

char			*ft_data_name(const char *path);
char			*ft_data_uid(const char *path, int len);
char			*ft_data_gid(const char *path, int len);

long			ft_file_size(const char *path);
char			*ft_data_size(const char *path, int len);

void			ft_insert(char **tab, char *str);
char			**ft_init_tab(int size);
char			**ft_put_in_tab(char **tab, const char *path, char *name);
void			ft_free_tab(char **tab);
char			**ft_sort_tab(char **tab, char *flags);

#endif
