NAME		=	scrabble

DIR_SRC		=	src/

DIR_UTIL	=	util/

CC		=	gcc

RM		=	rm -f

SRCS		=	$(DIR_SRC)main.c \
			$(DIR_SRC)init.c \
			$(DIR_SRC)ask_user.c \
			$(DIR_SRC)game_core.c \
			$(DIR_SRC)menu.c \
			$(DIR_SRC)config_pre_game.c \
			$(DIR_UTIL)read_entry.c \
			$(DIR_UTIL)xfunc.c

OBJS		=	$(SRCS:.c=.o)

CPPFLAGS	=	-Wall -Wextra -g3 -I include/ -DDEBUG_FLAG #-Werror

$(NAME)		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

all		:	$(NAME)

clean		:	
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
