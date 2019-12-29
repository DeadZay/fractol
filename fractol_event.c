/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:29:26 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/29 13:25:34 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				e_close(void *param)
{
	destroy_tfractol(param);
	exit(EXIT_SUCCESS);
}

int				e_key_press(int keycode, void *param)
{
	t_fractol	*fractol;

	if (keycode == KEY_ESCAPE)
		return (e_close(param));
	fractol = param;
	if (keycode == KEY_R || keycode == KEY_G || keycode == KEY_B)
		change_color(fractol, keycode);
	if (keycode == KEY_NUM_CLEAR || keycode == KEY_DELETE
	|| keycode == KEY_FORWARDDELETE)
		reset_fractol(fractol);
	if (keycode >= KEY_LEFTARROW && keycode <= KEY_UPARROW)
		change_view(fractol, keycode);
	if (keycode == KEY_NUM_PLUS || keycode == KEY_NUM_MINUS)
		change_zoom(fractol, MOUSE_EVENT_NONE, keycode);
	return (EXIT_SUCCESS);
}

int				e_mouse_press(int button, int x, int y, void *param)
{
	t_fractol	*fractol;

	(void)x;
	(void)y;
	fractol = param;
	if (button == MOUSE_EVENT_LBUTTON)
		fractol->move = !fractol->move;
	if (button >= MOUSE_EVENT_LBUTTON && button < MOUSE_EVENT_SCROLL)
		fractol->view->mouse.button[button] = TRUE;
	if (button == MOUSE_EVENT_SCROLL_UP || button == MOUSE_EVENT_SCROLL_DOWN)
		change_zoom(fractol, button, EVENT_NONE);
	return (EXIT_SUCCESS);
}

int				e_mouse_move(int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (fractol->move && fractol->letter == FRACTOL_JULIA)
	{
		fractol->view->mouse.point_a = (t_point){
				(x - fractol->view->attr.width2) * 0.0015L,
				(y - fractol->view->attr.height2) * 0.0015L};
		cycle(fractol);
	}
	return (EXIT_SUCCESS);
}
