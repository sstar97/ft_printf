NAME		=	libftprintf.a
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
AR			=	ar -rcs
RM			=	rm -rf
INC			=	ft_printf.h
SRC			=	ft_printf.c
OBJ			=	$(SRC:%.c=%.o)
$(NAME)		:	$(OBJ)
			$(AR) $(NAME) $(OBJ)
%.o			:	%.c $(INC)
			$(CC) $(FLAGS) -c  $< -o $@ $(FLAGS)
all			:	$(NAME)
clean		:
			$(RM) $(OBJ)
fclean		:	clean
			$(RM) $(NAME)
re			:	fclean all
.PHONY		:	all, clean, fclean, re