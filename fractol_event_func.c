/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_event_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:30:25 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/29 12:45:33 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			change_zoom(t_fractol *fractol, int button, int keycode)
{
	if (button == MOUSE_EVENT_SCROLL_UP || keycode == KEY_NUM_PLUS)
	{
		fractol->view->attr.zoom_count++;
		fractol->view->attr.zoom /= 0.9L;
		fractol->i_max /= 0.9L;
	}
	else if ((button == MOUSE_EVENT_SCROLL_DOWN || keycode == KEY_NUM_MINUS))
	{
		if (fractol->view->attr.zoom_count == 0)
			return ;
		fractol->view->attr.zoom_count--;
		fractol->view->attr.zoom *= 0.9L;
		fractol->i_max *= 0.9L;
	}
	cycle(fractol);
}

void			change_color(t_fractol *fractol, int keycode)
{
	fractol->refresh_color = TRUE;
	if (keycode == KEY_R)
		fractol->cpower.r = fractol->cpower.r > 9 ? 0 : fractol->cpower.r + 1;
	if (keycode == KEY_G)
		fractol->cpower.g = fractol->cpower.g > 9 ? 0 : fractol->cpower.g + 1;
	if (keycode == KEY_B)
		fractol->cpower.b = fractol->cpower.b > 9 ? 0 : fractol->cpower.b + 1;
	cycle(fractol);
}

void			change_view(t_fractol *fractol, int keycode)
{
	const long double	dx = 10L / fractol->view->attr.zoom;
	const long double	dy = 10L / fractol->view->attr.zoom;

	if (keycode == KEY_UPARROW)
		fractol->view->attr.dy += dy;
	if (keycode == KEY_DOWNARROW)
		fractol->view->attr.dy -= dy;
	if (keycode == KEY_LEFTARROW)
		fractol->view->attr.dx += dx;
	if (keycode == KEY_RIGHTARROW)
		fractol->view->attr.dx -= dx;
	cycle(fractol);
}
