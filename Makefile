NAME = canodis
SRC = ./src
CC = gcc -g
MLXDIR = mlx-linux

all:
	$(CC) $(SRC)/*.c -o $(NAME) $(MLXDIR)/libmlx.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

clean :
	rm -rf $(NAME)

MINILIBX:
	make -C $(MLXDIR) --silent
	@echo "MINILIBX compiled !"

re: clean all
