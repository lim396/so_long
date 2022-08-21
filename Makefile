CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g -I /usr/X11/include
NAME = so_long
LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)


ifeq ($(shell uname), Linux)
	LDFLAGS := -Wl,-start-group -I/usr/X11/include -L/usr/X11/include/../lib -lXext -lX11 -I minilibx-linux -L minilibx-linux -lmlx_Linux
	MINILIBX = ./minilibx-linux/libmlx_Linux.a -Wl,-end-group
else
	LDFLAGS := -I/usr/X11/include -L/usr/X11/include/../lib -lXext -lX11 -I minilibx-linux -L minilibx-linux -lmlx_Darwin
	MINILIBX = ./minilibx-linux/libmlx_Darwin.a
endif


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX) 

$(LIBFT):
	$(MAKE) -C ./libft

$(MINILIBX):
	$(MAKE) -C ./minilibx-linux

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx-linux
	$(RM) *.o

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
