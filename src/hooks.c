#include "../inc/minilibx.h"
#include "../inc/header.h"

typedef struct LGBT {
	int r;
	int g;
	int b;
} RGB;

RGB colorConverter(unsigned long hexValue)
{
	RGB rgbColor;

	rgbColor.r = ((hexValue >> 16) & 0xFF) / 255.0;
	rgbColor.g = ((hexValue >> 8) & 0xFF) / 255.0;
	rgbColor.b = ((hexValue) & 0xFF) / 255.0;

	return rgbColor; 
}

static void invert_colors(t_app *app)
{
	RGB rgb;
	int *addr = app->data.addr;

	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			rgb = colorConverter(addr[(y * W) + x]);
			addr[(y * W) + x] = createRGB(rgb.r, rgb.g, rgb.b, app);
		}
	}
}

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
	{
		app->invert = !app->invert;
		if (app->stop && app->invert)
		{
			invert_colors(app);
			mlx_put_image_to_window(app->mlx, app->window, app->data.img, 0, 0);
		}
	}
	if (keycode == 97)
		app->speed < 25000 ? app->speed += 1000 : 2000;
	if (keycode == 100)
		app->speed > 1000 ? app->speed -= 1000 : 2000;
	if (keycode == 32)
		app->stop = !app->stop;
}