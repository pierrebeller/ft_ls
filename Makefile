.PHONY: clean, fclean, re, all

NAME = ft_ls

SRC 	= 	data_id.c\
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

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FT = ./libft/
FT_LIB = $(addprefix $(FT),libft.a))
FT_INC = -I ./libft
FT_LNK = -L ./libft -l ft

SRCDIR = ./src/
INCDIR = ./includes/
OBJDIR = ./obj/

all: obj $(FT_LIB) $(NAME)

obj: 
		mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
		make -C $(FT)

$(NAME) : $(OBJ)
	$(CC) -g3 -fsanitize=address $(OBJ) $(FT_LNK) -lm -o $(NAME)
	
clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean
	

re: fclean all