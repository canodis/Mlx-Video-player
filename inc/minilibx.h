#ifndef MINILIBX_H
# define MINILIBX_H

#include "../mlx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define WINDOW_X 1920
#define WINDOW_Y 1080

typedef struct s_data {
	int		*addr;
	void	*img;
}	t_data;

typedef struct s_app {
	void	*mlx;
	void	*window;
	t_data	data;
	FILE	*pipein;
	FILE	*pipeout;
	bool	invert;
	bool	stop;
	int		speed;
}	t_app;

int	keyhook(int keycode, t_app *app);

#endif