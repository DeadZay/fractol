/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpowl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 18:12:54 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/27 18:12:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex 		ft_cpowl(t_complex c0, long double n)
{
	long double		fi;
	long double		argz;

	fi = atan2l(c0.im, c0.re);
	argz = powl(ft_cabsl(c0), n);
	return ((t_complex){argz * cosl(n * fi), argz * sinl(n * fi)});
}
