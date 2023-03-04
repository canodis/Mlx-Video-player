#include "../inc/minilibx.h"


int	keyhook(int keycode, t_app *app)
{
	if (keycode == 65307)
	{
		app->stop = true;
		sleep(1);
		mlx_destroy_window(app->mlx, app->window);
		mlx_loop_end(app->mlx);
	}
	if (keycode == 105)
		app->invert = !app->invert;
	if (keycode == 97)
		app->speed < 15000 ? app->speed += 1000 : 2000;
	if (keycode == 100)
		app->speed > 2000 ? app->speed -= 1000 : 2000;
	if (keycode == 32)
		app->stop = !app->stop;
}