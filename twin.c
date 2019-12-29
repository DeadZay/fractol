/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:38:09 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/29 14:30:57 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void			destroy_twin(t_win *twin, _Bool destroy_mlx)
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
	if (twin->mlx && destroy_mlx)
		free(twin->mlx);
	twin->mlx = NULL;
	free(twin);
}

t_win			*new_twin(void *mlx)
{
	t_win		*twin;

	if (!(twin = (t_win *)malloc(sizeof(t_win))))
		return (NULL);
	twin->mlx = mlx;
	twin->win = NULL;
	twin->img = NULL;
	twin->data = NULL;
	return (twin);
}

t_win			*get_twin_mlx(int width, int height, char *title, void *mlx)
{
	t_win		*twin;
	int			x;

	if (!(twin = new_twin(mlx))
	|| !(twin->win = mlx_new_window(twin->mlx,
			width > 0 ? width : WIDTH,
			height > 0 ? height : HEIGHT,
			title ? title : TITLE))
	|| !(twin->img = mlx_new_image(twin->mlx, width, height))
	|| !(twin->data = (int *)mlx_get_data_addr(twin->img, &x, &x, &x)))
	{
		twin ? destroy_twin(twin, TRUE) : NULL;
		return (NULL);
	}
	return (twin);
}

t_win			*get_twin(int width, int height, char *title)
{
	void		*mlx;

	if (!(mlx = mlx_init()))
		return (NULL);
	return (get_twin_mlx(width, height, title, mlx));
}
