/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tfractol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:22:15 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/29 14:30:57 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				destroy_tfractol(t_fractol *fractol)
{
	if (!fractol)
		return ;
	if (!fractol->view)
	{
		destroy_tview(fractol->view);
		fractol->view = NULL;
	}
	free(fractol);
}

t_fractol			*new_tfractol(void)
{
	t_fractol		*fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		return (NULL);
	fractol->view = NULL;
	fractol->letter = '\0';
	return (fractol);
}

t_fractol			*get_tfractol(t_view *view, char fractol_letter)
{
	t_fractol		*fractol;

	if (!(fractol = new_tfractol())
	|| !(fractol->view = view ? view : get_tview(NULL, WIDTH, HEIGHT, TITLE))
	|| !(fractol->iarray = init_i_array(WIDTH * HEIGHT)))
	{
		destroy_tfractol(fractol);
		return (NULL);
	}
	init_cpower(fractol);
	fractol->letter = fractol_letter;
	fractol->i_max = 25;
	fractol->move = TRUE;
	fractol->refresh_color = FALSE;
	fractol->power = 2.0L;
	event_set(fractol);
	return (fractol);
}
