# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 12:59:15 by heinfalt          #+#    #+#              #
#    Updated: 2016/12/05 12:47:28 by heinfalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PHONY allow rules to be done even w/ files w/ the same name in the dir.

.PHONY: clean, fclean, re, open, reset, all, cleared

#~~~~~~~~~~~~~~~~COLORS~~~~~~~~~~~~~~

FONT_NOIR = \033[40m
BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
CYAN = \033[36m
GREY = \033[37m

NORMAL = \033[0m

#Includes

INC = includes/

HEADERS = libft.h ft_printf.h

#Name of the build (here a lib)

NAME = libft.a

#Compiler

CC = gcc

#Path of the location of every .c files

VPATH = ft_is:ft_mem:ft_put:ft_str:ft_lst:conv:other:ft_printf

#Path of the location of every .o files

OBJDIR = objfiles

#Objs will be the fills we need to create to do the lib

SRCO_MEM =	ft_bzero.o ft_memcpy.o ft_memchr.o ft_memcmp.o ft_memset.o		\
			ft_memdel.o ft_memccpy.o ft_memmove.o ft_memalloc.o

SRCO_STR =	ft_strlen.o ft_strdup.o ft_strcpy.o ft_strcat.o ft_strchr.o		\
			ft_strstr.o ft_strcmp.o ft_strrev.o ft_strnew.o ft_strdel.o		\
			ft_strclr.o ft_strmap.o ft_strequ.o ft_strsub.o ft_strncat.o	\
			ft_strlcat.o ft_toupper.o ft_tolower.o ft_strncpy.o ft_strrchr.o\
			ft_strnstr.o ft_strncmp.o ft_striter.o ft_strmapi.o ft_strnequ.o\
			ft_strjoin.o ft_strtrim.o ft_striteri.o ft_strsplit.o			\
			ft_chrjoin_free.o ft_strjoin_free.o ft_strdup_free.o			\
			ft_strchange.o ft_strchain.o

SRCO_IS =	ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
			ft_is_wstring.o ft_is_white_space.o	ft_is_wchar.o

SRCO_PUT =	ft_putstr.o ft_putnbr.o ft_putlnbr.o ft_putwstr.o ft_putendl.o	\
			ft_putchar.o ft_putnstr.o ft_putwchar.o ft_putxchar.o			\
			ft_putstr_fd.o ft_putnbr_fd.o ft_putendl_fd.o ft_putchar_fd.o	\
			ft_ret_putchar.o ft_putstr_free.o ft_putstr_clrd.o

SRCO_LST =	ft_lstnew.o ft_lstdel.o ft_lstadd.o ft_lstmap.o ft_lstiter.o	\
			ft_lstappend.o ft_lstdelone.o

SRCO_CONV =	ft_itoa.o ft_atoi.o ft_litoa.o ft_dbltoa.o ft_ulitoa.o			\
			ft_initmod.o ft_initlmod.o ft_bin_to_dec.o ft_dec_to_bin.o		\
			ft_dec_to_hex.o ft_dec_to_sci.o ft_hex_to_dec.o ft_ptr_to_hex.o	\
			ft_dec_to_base.o ft_ldec_to_bin.o ft_ldec_to_hex.o				\
			ft_ldec_to_base.o

SRCO_OTHR =	ft_charswap.o ft_pow.o ft_swap.o ft_wstrlen.o ft_wcharlen.o		\
			ft_ret_free.o ft_nbrlen.o ft_retstr_free.o ft_swap_chr.o

SRCO_PRINTF =	check_wsc.o flag.o flag_flag.o ft_printf.o lenmod.o			\
				operation.o operation_2.o other.o

#Compiler flags

CFLAGS = -Wall -Wextra -Werror

# ---------------------------------------
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#				   RULES
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# ---------------------------------------

#Master rule : "One Rule to rule them all !!"

all: $(NAME)

#Those ones display colored infos

reset_init:
	@ echo "$(BLUE)$(FONT_NOIR)Reseting the library }~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$(NORMAL)"

reset_cmpl:
	@ echo "$(BLUE)$(FONT_NOIR)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{ Reset Complete[$(GREEN)\xe2\x9c\x94$(BLUE)]$(NORMAL)"

cleared:
	@ echo "$(YELLOW)$(FONT_NOIR)libft : $(RED).o files destruction\t\t[$(GREEN)\xe2\x9c\x94$(RED)]$(NORMAL)"

full_clean:
	@ echo "$(YELLOW)$(FONT_NOIR)libft : $(RED).a file destruction\t\t[$(GREEN)\xe2\x9c\x94$(RED)]$(NORMAL)"

#Those rules create .o from .c if the obj is older than the src

$(OBJDIR)/%.o: %.c
	@ mkdir -p $(OBJDIR)
	@ $(CC) $(CFLAGS) -c $^
	@ mv ./$(notdir $@) ./$(OBJDIR)/
	
#This one build the lib

$(NAME): $(addprefix $(OBJDIR)/, $(SRCO_MEM) $(SRCO_STR) $(SRCO_PUT) $(SRCO_LST) $(SRCO_IS) $(SRCO_CONV) $(SRCO_OTHR) $(SRCO_PRINTF))
	@ echo "$(PINK)$(FONT_NOIR)Compilation of the library\t\t[$(GREEN)\xe2\x9c\x94$(PINK)]$(NORMAL)"
	@ ar rc $(NAME) $^ && ranlib $(NAME)

# ---------------------------------------
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#				  CLEANING
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# ---------------------------------------

#Cleaning obj files

clean: cleared
	@ rm -f $(addprefix $(OBJDIR)/, $(SRCO_MEM) $(SRCO_STR) $(SRCO_PUT) $(SRCO_LST) $(SRCO_IS) $(SRCO_CONV) $(SRCO_OTHR) $(SRCO_PRINTF))

#Cleaning obj files and the lib

fclean: full_clean clean
	@ rm -f $(NAME)

#Reset the compil : "Cleaning to rebuild everything better"

re: reset_init fclean all reset_cmpl
