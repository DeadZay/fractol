/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:33:51 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/28 13:34:03 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fpoint		get_fpoint(t_fractol *fractol, t_point2d point)
{
	const t_view_attr		attr = fractol->view->attr;

	return ((t_fpoint){
			(((long double)point.x - attr.width2) / attr.zoom) + attr.dx,
			(((long double)point.y - attr.height2) / attr.zoom) + attr.dy
	});
}

size_t			escape(t_fractol *fractol, t_fpoint point)
{
	const t_mouse		mouse = fractol->view->mouse;
	const size_t 		i_max = fractol->i_max;

	if (fractol->letter == FRACTOL_MANDELBROT)
		return (mandelbrot((t_complex){point.x, point.y}, i_max));
	if (fractol->letter == FRACTOL_JULIA)
		return (julia((t_complex){point.x, point.y}, (t_complex){
				mouse.point_a.x, mouse.point_a.y}, i_max));
	if (fractol->letter == FRACTOL_BURNINGSHIP)
		return (burningship((t_complex){point.x, point.y}, i_max));
	if (fractol->letter == FRACTOL_SPIDER)
		return (spider((t_complex){point.x, point.y}, i_max));
	return (0);
}

int 			get_color(t_fractol *fractol, size_t i, t_point point)
{
	const t_color_power		cpower = fractol->cpower;

	if (point.x < WIDTH && point.y < HEIGHT && i < fractol->i_max)
		return ((((i * cpower.r) % 255) << 16)
				+ (((i * cpower.g) % 255) << 8)
				+ (i * cpower.b) % 255);
	return (0);
}