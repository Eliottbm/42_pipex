# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 14:26:10 by ebengtss          #+#    #+#              #
#    Updated: 2024/07/31 11:09:17 by ebengtss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 		+=	--no-print-directory

NAME			=	libft.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I
AR				=	ar rcs

SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/
INCS_DIR		=	incs

SRCS_FILES		=	ft_isascii.c		ft_isprint.c		ft_strlen.c			\
					ft_isalnum.c		ft_bzero.c			ft_atoi.c			\
					ft_memcpy.c			ft_split.c			ft_memchr.c			\
					ft_calloc.c			ft_strmapi.c		ft_putnbr_fd.c		\
					ft_memmove.c		ft_strlcat.c		ft_toupper.c		\
					ft_memset.c		 	ft_memcmp.c			ft_strjoin.c		\
					ft_strnstr.c		ft_striteri.c		ft_strdup.c			\
					ft_putchar_fd.c		ft_tolower.c		ft_strchr.c			\
					ft_strlcpy.c		ft_itoa.c			ft_putendl_fd.c		\
					ft_strrchr.c		ft_strncmp.c		ft_substr.c			\
					ft_strtrim.c		ft_putstr_fd.c		ft_isalpha.c		\
					ft_isdigit.c		ft_lstadd_back.c	ft_lstadd_front.c	\
					ft_lstclear.c		ft_get_next_line.c	ft_lstsize.c		\
					ft_lstlast.c		ft_putuns_len.c		ft_gnl_utils.c		\
					ft_lstnew.c			ft_printf.c			ft_putaddress.c		\
					ft_putchar_len.c	ft_puthex_len.c		ft_putnbr_len.c		\
					ft_putstr_len.c
					

OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))

DEF_COLOR		=	\033[0;39m
GREEN			=	\033[0;92m
DEF_STYLE		=	\e[0m
BOLD_OPACITY	=	\e[1m\e[2m
RESET_LINE		=	\033[A\033[K

OBJSF			=	.cache_exists

all				:	$(NAME)

$(NAME)			:	$(OBJS)
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ LIBFT ]$(DEF_STYLE)	compiling:	$(GREEN) ✔ $(DEF_COLOR)"
	@$(AR) $@ $?
	@echo "$(BOLD_OPACITY)[ LIBFT ]$(DEF_STYLE)	make:		$(GREEN) ✔ $(DEF_COLOR)"

$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.c | $(OBJSF)
	@$(CC) $(CFLAGS) $(INCS_DIR) -c $< -o $@
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ LIBFT ]$(DEF_STYLE)	compiling:	$(GREEN) $< $(DEF_COLOR)"

$(OBJSF)	:
	@echo "$(BOLD_OPACITY)[ LIBFT ]$(DEF_STYLE)	nothing to do"
	@mkdir -p $(OBJS_DIR)

clean			:
	@rm -rf $(OBJS_DIR)
	@echo "$(BOLD_OPACITY)[ LIBFT ]$(DEF_STYLE)	clean:		$(GREEN) ✔ $(DEF_COLOR)"

fclean			:	clean
	@rm -f $(NAME)
	@echo "$(BOLD_OPACITY)[ LIBFT ]$(DEF_STYLE)	fclean:		$(GREEN) ✔ $(DEF_COLOR)"

re				:	fclean all

.PHONY			:	all clean fclean re bonus
