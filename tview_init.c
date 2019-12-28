/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tview_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:21:12 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/28 13:21:22 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void			init_tmouse(t_view *view)
{
	int 		i;

	view->mouse.point_a = (t_point){0.4L, -0.4L};
	view->mouse.point_b = (t_point){0.0L, 0.0L};
	i = 0;
	while (i < BUTTON_COUNT)
		view->mouse.button[i++] = FALSE;
}

void			init_tkeyboard(t_view *view)
{
	size_t		i;

	view->keyboard.current_pressed = 0;
	i = 0;
	while (i < KEY_COUNT)
		view->keyboard.key[i++] = FALSE;
}

void			init_tview_attr(t_view *view)
{
	view->attr.dx = 0;
	view->attr.dy = 0;
	view->attr.height2 = (long double)HEIGHT * 0.5L;
	view->attr.width2 = (long double)WIDTH * 0.5L;
	view->attr.zoom = WIDTH > HEIGHT ? (long double)HEIGHT / 5.0L
									 : (long double)WIDTH / 5.0L;
	view->attr.zoom_count = 0;
}