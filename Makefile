CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror

NAME_A	= 	client
NAME_B 	=	server

INC_DIR	=	-I ./

INC		=	$(addprefix $(INC_DIR),	client.h \
									server.h)

SRC_A	=	client.c \
			libft/ft_atoi.c \
			libft/ft_strlen.c

SRC_B	=	server.c \
			libft/ft_strlen.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putstr_fd.c

OBJ_A	=	$(SRC_A:%.c=%.o)
OBJ_B	=	$(SRC_B:%.c=%.o)

RM		=	rm -f

all		:	$(NAME_A) $(NAME_B)


%.o : %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

$(NAME_A)	:	$(OBJ_A)
	$(CC) $(CFLAGS) -o $@ $(OBJ_A)


$(NAME_B)	:	$(OBJ_B)
	$(CC) $(CFLAGS) -o $@ $(OBJ_B)

clean	:
	$(RM) $(OBJ_A) $(OBJ_B)

fclean	: clean
	$(RM) $(NAME_A) $(NAME_B)

re :
	make fclean
	make all

.PHONY : all clean fclean re