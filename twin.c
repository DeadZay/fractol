#include "ft_mlx.h"
#include <stdlib.h>

void		destroy_twin(t_win *twin)
{
	if (!twin)
		return ;
	if (twin->img)
	{
		if (twin->data)
		{
			free(twin->data);
			twin->data = NULL;
		}
		mlx_destroy_image(twin->mlx, twin->img);
		twin->img = NULL;
	}
	if (twin->win)
	{
		mlx_destroy_window(twin->mlx, twin->win);
		twin->win = NULL;
	}
	if (twin->mlx)
	{
		free(twin->mlx);
		twin->mlx = NULL;
	}
	free(twin);
	twin = NULL;
}

t_win		*new_twin(void)
{
	t_win	*twin;

	if (!(twin = (t_win *)malloc(sizeof(t_win))))
		return (NULL);
	twin->mlx = NULL;
	twin->win = NULL;
	twin->img = NULL;
	twin->data = NULL;
	return (twin);
}

t_win 		*get_twin(
		int width,
		int height,
		char *title
		)
{
	t_win 	*twin;
	int 	x;

	twin = NULL;
	if (width <= 0 || height <= 0 || !title
	|| !(twin = new_twin())
	|| !(twin->mlx = mlx_init())
	|| !(twin->win = mlx_new_window(twin->mlx, width, height, title))
	|| !(twin->img = mlx_new_image(twin->mlx, width, height))
	|| !(twin->data = (int *)mlx_get_data_addr(twin->img, &x, &x, &x)))
	{
		twin ? destroy_twin(twin) : NULL;
		return (NULL);
	}
	return (twin);
}
