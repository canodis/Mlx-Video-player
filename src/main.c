#include "../inc/header.h"
#include "../inc/minilibx.h"

int count = 0;
unsigned char frame[H][W][3] = {0};

int	loophook(t_app *app)
{
	if (app->stop)
		return 0;
	count = fread(frame, 1, H*W*3, app->pipein);
		
	if (count != H*W*3) mlx_loop_end(app->mlx);
		
	for (int y=0 ; y<H ; ++y)
	{
		for (int x=0 ; x<W ; ++x)
			app->data.addr[(y * W) + x] = createRGB(frame[y][x][0], frame[y][x][1], frame[y][x][2], app);
	}
	usleep(app->speed);
	mlx_put_image_to_window(app->mlx, app->window, app->data.img, 0, 0);
	mlx_string_put(app->mlx, app->window, W - 150, H - 75, 0xffffff, "Slow : A");
	mlx_string_put(app->mlx, app->window, W - 150, H - 60, 0xffffff, "Fast : D");
	mlx_string_put(app->mlx, app->window, W - 150, H - 46, 0xffffff, "Stop : SPACE");
	mlx_string_put(app->mlx, app->window, W - 150, H - 30, 0xffffff, "Invert colors : I");
	return (0);
}

int main(int ac, char **av)
{
	t_app	app;
	int x;

	if (ac != 2)
	{
		printf("Wrong arguments !\nUsage: canodis ./videos/[VideoName]\n");
		return (1);
	}
	init_all(&app, av[1]);

	mlx_loop_hook(app.mlx, loophook, &app);
	mlx_key_hook(app.window, keyhook, &app);
	mlx_loop(app.mlx);

	fflush(app.pipein);
	pclose(app.pipein);
}
