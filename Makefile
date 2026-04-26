NAME := minirt
CC = @cc
HEADERS = libs/minirt.h

MLX_DIR = ./libs/minilibx-linux

CFLAGS = -g -I. -I./libs/minilibx-linux

LDFLAGS =  -L./libs/minilibx-linux -lmlx -lXext -lX11 -lm -lbsd

SRC := main.c\


OBJS := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@cc $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

tidy: all clean

clean:
	@rm -f $(OBJS)

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all