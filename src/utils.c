#include "../inc/header.h"
#include <sys/time.h>

static int	randomRange(void)
{
	struct timeval t;

	gettimeofday(&t, 0);
	srand(t.tv_sec + t.tv_usec);
	return (rand() % 100000);
}

static int	intLen(int n)
{
	int res = 0;

	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return res;
}

static int	getDigit(int n, int step)
{
	for (int i = 0; i < step; i++)
		n/=10;
	return n % 10;
}

char	*ft_strdup(char *str)
{
	char *res = malloc(sizeof(char) * strlen(str) + 1);
	int i = 0;
	for (; str[i]; i++)
		res[i] = str[i];
	res[i] = 0;
	return (res);
}

char	*getRandomName(void)
{
	char	name[100];
	int		idx = 7;
	int		number = randomRange();
	int		len = intLen(number);

	strcpy(name, "output_");
	for (int i = 0; i < len; i++)
		name[idx++] = getDigit(number, len - i - 1) + 48;
	name[idx] = 0;
	return (ft_strdup(name));
}

unsigned long createRGB(int r, int g, int b, t_app *app)
{
	if (app->invert)
	{
		r = 255 - r;
		g = 255 - g;
		b = 255 - b;
	}
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

char	*getFile(char *file)
{
	char	arr[500];

	strcpy(arr, "ffmpeg -i ");
	strcpy(&arr[10], file);
	strcpy(&arr[10 + strlen(file)], " -f image2pipe -vcodec rawvideo -pix_fmt rgb24 -");
	return (ft_strdup(arr));
}
