#include <stdio.h>
#include <stdlib.h>

typedef struct s_canvas
{
	int       width;
	int       height;
	char      base;
	char	  **canvas;
}               t_canvas;

typedef struct s_draw
{
	char	fill;
	float	X;
	float	Y;
	float	width;
	float	height;
	char	target;
}               t_draw;

int    print_error(int err)
{
	if (err == 0)
		printf("Error: argument\n");
	else if (err == 1)
		printf("Error: Operation file corrupted\n");
	return (1);
}

int	draw_base(FILE *f, t_canvas *canvas)
{
	if (fscanf(f, "%d %d %c\n", &canvas->width, &canvas->height, &canvas->base) != 3)
		return (1);
	if (canvas->width < 0 || canvas->width > 300 || canvas->height < 0 || canvas->height > 300)
		return (1);
	canvas->canvas = (char**)calloc(canvas->height + 1, sizeof(char *));
	for (int i = 0; i < canvas->height; i++)
	{
		canvas->canvas[i] = (char*)calloc(canvas->width + 1, sizeof(char));
		for (int j = 0; j < canvas->width; j++)
		{
			canvas->canvas[i][j] = canvas->base;
		}
	}
	return (0);
}

void	draw_R(t_canvas *canvas, t_draw *draw)
{
	for (int i = (int)draw->Y; i <= draw->height + draw->Y ; i++)
	{
		for (int j = (int)draw->X; j <= draw->width + draw->X ; j++)
		{
			if (i >= draw->Y && j >= draw->X && i < canvas->height && j < canvas->width && i >= 0 && j >= 0)
			{	
				printf("%f %f %d %d %c %d %d \n", draw->X, draw->Y, canvas->height, canvas->width, draw->target, i , j);
				canvas->canvas[i][j] = draw->target;
			}
		}
	}
}

void	draw_r(t_canvas *canvas, t_draw *draw)
{
	int i;
	int j;
	
	i = (int)(draw->Y);
	if (draw->Y > (int)(draw->Y))
		i += 1;
	for (; i <= (int)(draw->height + draw->Y); i++)
	{
		j = (int)(draw->X);
		if (draw->X > (int)(draw->X))
			j += 1;
		for (; j <= (int)(draw->width + draw->X); j++)
		{	
			if ((i == (int)draw->Y || i == (int)draw->Y + 1 || i == (int)(draw->Y + draw->height)) && i <= canvas->height && j <= canvas->width && i >= 0 && j >= 0)
			{
				canvas->canvas[i][j] = draw->target;
			}
			if ((j == (int)draw->X || j == (int)(draw->X) + 1 || j == (int)(draw->X + draw->width)) && i <= canvas->height && j <= canvas->width && i >= 0 && j >= 0)
			{
				canvas->canvas[i][j] = draw->target;
			}
		}
	}
}

int	draw_rac(FILE *f, t_canvas *canvas, t_draw *draw)
{
	while (42)
	{
		if (fscanf(f, "%c %f %f %f %f %c\n", &draw->fill, &draw->X, &draw->Y, &draw->width, &draw->height, &draw->target) == 6)
		{
			if (draw->height <= 0 || draw->width <= 0)
				return (1);
			if (draw->fill == 'R')
			{
				draw_R(canvas, draw);
			}
			else if (draw->fill == 'r')
			{
				draw_r(canvas, draw);
			}
			else
				return (1);
		}
		else
			return (0);
	}
}

void	ft_free(t_canvas *canvas)
{
	for (int i = 0; i < canvas->width; i++)
	{
		free(canvas->canvas[i]);
	}
	free(canvas->canvas);
}

int main(int argc, char **argv)
{
	FILE		*f;
	t_canvas	canvas;
	t_draw		draw;

	if (argc != 2)
		return (print_error(0));
	f = fopen(argv[1], "r");
	if (f == NULL)
		return (print_error(1));
	if (draw_base(f, &canvas) == 1)
		return (print_error(1));
	if (draw_rac(f, &canvas, &draw) == 1)
		return (print_error(1));
	for (int i = 0; i < canvas.height; i++)
	{
		for (int j = 0; j < canvas.width; j++)
		{
			printf("%c", canvas.canvas[i][j]);
		}
		printf("\n");
	}
	//ft_free(&canvas);
	fclose(f);
	return (0);
}