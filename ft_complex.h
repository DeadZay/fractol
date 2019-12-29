/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:02:20 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/29 14:30:57 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

# include "math.h"

typedef struct		s_complex
{
	long double		re;
	long double		im;
}					t_complex;

t_complex			ft_cpowl(t_complex c0, long double n);
long double			ft_cabsl(t_complex c);
t_complex			ft_cdiv(t_complex c1, t_complex c2);
t_complex			ft_cadd(t_complex c, t_complex n);
t_complex			ft_cmul(t_complex c1, t_complex c2);
t_complex			ft_csub(t_complex c1, t_complex c2);

#endif
