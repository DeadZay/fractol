/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tview.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:20:17 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/28 13:20:36 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void			destroy_tview(t_view *view)
{
	if (!view)
		return ;
	if (view->twin)
	{
		free(view->twin);
		view->twin = NULL;
	}
	free(view);
}

t_view 			*new_tview(void)
{
	t_view		*view;

	if (!(view = (t_view *)malloc(sizeof(t_view))))
		return (NULL);
	view->twin = NULL;
	return (view);
}

t_view 			*get_tview(t_win *twin)
{
	t_view		*view;

	if (!(view = new_tview())
		|| !(view->twin = twin ? twin : get_twin(WIDTH, HEIGHT, TITLE)))
	{
		view ? destroy_tview(view) : FALSE;
		return (NULL);
	}
	init_tmouse(view);
	init_tkeyboard(view);
	init_tview_attr(view);
	return (view);
}