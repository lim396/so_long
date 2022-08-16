CC = gcc
#CFLAGS = -Wall -Wextra -Werror -L/usr/X11R6/lib -lmlx -lX11 -lXext -framework OpenGL -framework AppKit #-framework OpenGL -framework Appkit
# -Lmlx necessary?
NAME = so_long
LIBFT = ./libft/libft.a
#HEADER = ./minilibx-linux/mlx.h
#MINILIBX = ./minilibx-linux/libmlx.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -I /opt/X11/include -c $< -o $@ 
	#-L minilibx-linux

	#-L /usr/X11/include/../lib 
	#-l Xext -l X11 -I minilibx-linux -L minilibx-linux -lmlx_Darwin -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -g -I /opt/X11/include -L /usr/X11/include/../lib -l Xext -l X11 -I minilibx-linux -L minilibx-linux -lmlx_Darwin -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C ./libft

#$(NAME): $(OBJS) $(MINILIBX)
#	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MINILIBX)

#$(MINILIBX):
#	$(MAKE) -C ./minilibx-linux

clean:
	$(MAKE) clean -C ./libft
	$(RM) *.o
#	$(MAKE) clean -C ./minilibx-linux

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
