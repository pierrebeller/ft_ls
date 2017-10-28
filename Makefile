

NAME = ft_ls

SRC 	= 	src/data_id.c\
			src/data_rights.c\
			src/data_size.c\
			src/data_time.c\
			src/data_type.c\
			src/directories.c\
			src/error.c\
			src/file.c\
			src/flags.c\
			src/ft_ls.c\
			src/padding.c\
			src/print_large.c\
			src/print_sort.c\
			src/sort.c\
			src/tab.c

GREEN = \033[32m
RED = \033[31m
CYAN = \033[36m
BLUE = \033[34m
YELLOW = \033[33m
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

OBJ 	= 	$(patsubst src/%.c, obj/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ echo "$(BLUE)Compil Libft $(NORMAL)"
	@ make -C libft
	@ echo "$(GREEN)Libft compiled $(NORMAL)"
	@ echo "$(BLUE)Compil Ft_ls $(NORMAL)"
	@ echo "$(GREEN)Ft_ls Objects created $(NORMAL)"
	@ gcc $(CFLAGS) $(OBJ) $(FT_INC) $(FT_LIB) -o $(NAME)
	@ echo "$(GREEN)ft_ls compiled $(NORMAL)"

obj/%.o: src/%.c
	@ mkdir -p obj
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@ rm -rf $(OBJ)
	@ echo "$(RED)ft_ls Objects destroyed $(NORMAL)"
	@ make -C $(FT) clean
	@ echo "$(RED)Libft Objects destroyed $(NORMAL)"

fclean: clean
	@ rm -rf $(NAME)
	@ echo "$(RED)ft_ls destroyed $(NORMAL)"
	@ make -C $(FT) fclean	

re: fclean all

.PHONY: clean, fclean, re, all