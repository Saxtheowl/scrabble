NAME		=	scrabble

DIR_SRC		=	src/

DIR_UTIL	=	util/

DIR_AI		=	src/ai/

CC		=	gcc

RM		=	rm -f

SRCS		=	$(DIR_SRC)main.c \
			$(DIR_SRC)pre_init.c \
			$(DIR_SRC)init.c \
			$(DIR_SRC)game_core.c \
			$(DIR_SRC)menu.c \
			$(DIR_SRC)config_pre_game.c \
			$(DIR_SRC)output.c \
			$(DIR_SRC)check.c \
			$(DIR_SRC)play.c \
			$(DIR_SRC)board.c \
			$(DIR_SRC)rack.c \
			$(DIR_SRC)score.c \
			$(DIR_UTIL)util.c \
			$(DIR_UTIL)xfunc.c \
			$(DIR_AI)word.c

OBJS		=	$(SRCS:.c=.o)

DEBUG		=	-DDEBUG_FLAG

CPPFLAGS	=	-Wall -Wextra -g3 -I include/ $(DEBUG) #-Werror

$(NAME)		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

all		:	$(NAME)

clean		:	
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
