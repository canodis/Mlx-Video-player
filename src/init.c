#include "../inc/header.h"

void	init_all(t_app *app, char *av)
{
	int x;

	app->mlx = mlx_init();
	app->window = mlx_new_window(app->mlx, W, H, "CANODIS :)");
	app->data.img = mlx_new_image(app->mlx, W, H);
	app->data.addr = (int *)mlx_get_data_addr(app->data.img, &x, &x, &x);
	app->invert = false;
	app->stop = false;
	app->speed = 5000;
	app->pipein = popen(getFile(av), "r");
}