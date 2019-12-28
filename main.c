/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:37:56 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/28 13:37:56 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

_Bool 				cycle(t_fractol *fractol)
{
	size_t			current;
	t_point2d		point;
	t_win			*twin;

	twin = fractol->view->twin;
	point.y = 0;
	while (point.y < HEIGHT)
	{
		point.x = 0;
		while (point.x < WIDTH)
		{
			current = point.x + point.y * WIDTH;
			if (!fractol->refresh_color)
				fractol->i[current] =
						escape(fractol, get_fpoint(fractol, point));
			twin->data[current] = get_color(fractol, fractol->i[current],
					(t_point){point.x, point.y});
			point.x++;
		}
		point.y++;
	}
	fractol->refresh_color ? (fractol->refresh_color = FALSE) : FALSE;
	mlx_put_image_to_window(twin->mlx, twin->win, twin->img, 0, 0);
	return (TRUE);
}

int 	main(int argc, char **argv)
{
	t_fractol	*fractol;

	check_arguments(argc, argv);
	if (!(fractol = get_tfractol(NULL, *argv[1]))
	|| !(cycle(fractol)))
		return (EXIT_FAILURE);
	mlx_loop(fractol->view->twin->mlx);
	return (EXIT_SUCCESS);
}