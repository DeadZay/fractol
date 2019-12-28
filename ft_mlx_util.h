/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 02:32:09 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/28 04:13:42 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_UTIL_H
# define FT_MLX_UTIL_H

typedef enum 		e_color_method
{
	COLOR_METHOD_ITERATION =	0,
	COLOR_METHOD_DI_DCOLOR =	1,
	COLOR_METHOD_PERCENT =		2,
	COLOR_METHOD_INVERT =		3
}					t_color_method;

#endif
