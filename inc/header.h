#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "minilibx.h"

#define W 1280
#define H 720

char	*getRandomName(void);
unsigned long createRGB(int r, int g, int b, t_app *app);
char	*ft_strdup(char *str);
char	*getFile(char *file);
void	init_all(t_app *app, char *av);

#endif


// int newFile = open(getName(), O_WRONLY | O_APPEND | O_CREAT, 0644);
// invert  colors
// frame[y][x][0] = 255 - frame[y][x][0]; // red
// frame[y][x][1] = 255 - frame[y][x][1]; // green
// frame[y][x][2] = 255 - frame[y][x][2]; // blue
// game.pipeout = popen("ffmpeg -y -f rawvideo -vcodec rawvideo -pix_fmt rgb24 -s 1280x720 -r 25 -i - -f mp4 -q:v 5 -an -vcodec mpeg4 outputs/output.mp4", "w");