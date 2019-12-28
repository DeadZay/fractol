/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tfractol_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:25:06 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/28 13:32:12 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 			reset_fractol(t_fractol *fractol)
{
	const t_win		*twin = fractol->view->twin;
	const char		letter = fractol->letter;
	t_view 			*view;

	destroy_tfractol(fractol);
	if (!(view = get_tview((t_win *)twin))
		|| !(fractol = get_tfractol(view, letter)))
		exit(EXIT_FAILURE);
	cycle(fractol);
}

void			init_cpower(t_fractol *fractol)
{
	fractol->cpower.r = 9;
	fractol->cpower.g = 9;
	fractol->cpower.b = 9;
	fractol->cpower.a = 0;
}

void			init_i_array(t_fractol *fractol)
{
	size_t		i;

	i = 0;
	while (i < HEIGHT * WIDTH)
		fractol->i[i++] = 0;
}

void 			event_set(t_fractol *fractol)
{
	void		*win;

	win = fractol->view->twin->win;
	mlx_hook(win, EVENT_KEY_PRESS, MASK_KEY_PRESS, e_key_press, fractol);
	mlx_hook(win, EVENT_MOUSE_MOVE, MASK_MOUSE_MOVE, e_mouse_move, fractol);
	mlx_hook(win, EVENT_MOUSE_BUTTON_PRESS, MASK_MOUSE_BUTTON_PRESS,
			 e_mouse_press, fractol);
	mlx_hook(win, EVENT_CLOSE, MASK_CLOSE, e_close, fractol);
}
