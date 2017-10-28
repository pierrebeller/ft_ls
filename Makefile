

NAME = ft_ls

SRCS 	= 	data_id.c\
			data_rights.c\
			data_size.c\
			data_time.c\
			data_type.c\
			directories.c\
			error.c\
			file.c\
			flags.c\
			ft_ls.c\
			padding.c\
			print_large.c\
			print_sort.c\
			sort.c\
			tab.c

GREEN = \033[32m
RED = \033[31m
NORMAL = \033[0m

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FT = ./libft/
FT_LIB = $(addprefix $(FT),libft.a)
FT_INC = -I ./libft
FT_LNK = -L ./libft -l ft

SRCDIR = ./src/
INCDIR = ./includes/
OBJDIR = ./obj/

SRC 	= 	$(addprefix $(SRCDIR),$(SRCS))
OBJ 	= 	$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@ make -C libft
	@ echo "$(GREEN)Libft compiled $(NORMAL)"
	@ gcc $(CFLAGS) -c $(FT_INC) $(SRC)
	@ echo "$(GREEN)Objects created $(NORMAL)"
	@ gcc $(CFLAGS) $(OBJ) $(FT_INC) $(FT_LIB) -o $(NAME)
	@ echo "$(GREEN)ft_ls compiled $(NORMAL)"
clean:
	@ rm -rf $(OBJ)
	@ echo "$(RED)Objects ft_ls destroyed $(NORMAL)"
	@ make -C $(FT) clean
	@ echo "$(RED)Objects Libft destroyed $(NORMAL)"

fclean: clean
	@ rm -rf $(NAME)
	@ echo "$(RED)ft_ls destroyed $(NORMAL)"
	@ make -C $(FT) fclean
	

re: fclean all

.PHONY: clean, fclean, re, all