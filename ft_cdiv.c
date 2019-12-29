/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdiv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 18:13:18 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/27 18:13:47 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex			ft_cdiv(t_complex c1, t_complex c2)
{
	long double		fi1;
	long double		fi2;
	long double		modz;

	fi1 = atan2l(c1.im, c2.re);
	fi2 = atan2l(c2.im, c2.re);
	modz = ft_cabsl(c1) / ft_cabsl(c2);
	return ((t_complex){modz * cosl(fi1 - fi2), modz * sinl(fi1 - fi2)});
}
