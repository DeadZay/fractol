#include "fractol.h"

long double		ft_cabsl(t_complex c)
{
	return (sqrtl(c.re * c.re + c.im * c.im));
}

t_complex 		ft_cpowl(t_complex c0, long double n)
{
	long double		fi;
	long double		argz;

	fi = atan2l(c0.im, c0.re);
	argz = powl(ft_cabsl(c0), n);
	return ((t_complex){argz * cosl(n * fi), argz * sinl(n * fi)});
}

t_complex		ft_cdiv(t_complex c1, t_complex c2)
{
	long double		fi1;
	long double		fi2;
	long double		modz;

	fi1 = atan2l(c1.im, c2.re);
	fi2 = atan2l(c2.im, c2.re);
	modz = ft_cabsl(c1) / ft_cabsl(c2);
	return ((t_complex){modz * cosl(fi1 - fi2), modz * sinl(fi1 - fi2)});
}

t_complex		ft_cadd(t_complex c, t_complex n)
{
	return ((t_complex){c.re + n.re, c.im + n.im});
}

t_complex 		ft_cmul(t_complex c1, t_complex c2)
{
	return ((t_complex){c1.re * c2.re - c1.im * c2.im,
					 c1.re * c2.im + c1.im * c2.re});
}

t_complex 		ft_csub(t_complex c1, t_complex c2)
{
	return ((t_complex){c1.re - c2.re, c1.im - c2.im});
}

size_t 			spider(t_complex c)
{
	size_t		i;
	t_complex	z;

	i = 0;
	z = (t_complex){c.re * 0.01L, c.im * 0.01L};
	while (i < I_MAX)
	{
		z = ft_cpowl(z, 2.0L);
		z = ft_cadd(z, c);
		c = (t_complex){c.re / 2L + z.re, c.im / 2L + z.im};
		if (powl(z.re, 2.0L) + powl(z.im, 2.0L) >= 4.0L)
			break ;
		i++;
	}
	return (i);
}

t_complex 		newton_calc(t_complex z)
{
	t_complex		c1;
	t_complex 		c2;
	t_complex		c3;

	c3 = ft_cpowl(z, 2.0L);
	c1 = ft_cmul(c3, (t_complex){3.0L, 0.0L});
	c2 = ft_cpowl(z, 3.0L);
	c2 = ft_csub(c2, (t_complex){1.0L, 0.0L});
	c3 = ft_cdiv(c1, c2);
	c1 = ft_csub(z, c3);
	return (c1);
}

// http://zonakoda.ru/padenie-v-bassejny-nyutona.html
size_t			newton3(t_complex c)
{
	size_t 		i;
	t_complex	z;
	t_complex	t;

	i = 0;
	z = (t_complex){c.re * 0.1L, c.im * 0.1L};
	while (i < I_MAX)
	{
		t = z;
		z = ft_cmul(z, (t_complex){0.8L, 0.0L});
		z = ft_cadd(z, (t_complex){0.2L, 0.0L});
		z = ft_cmul(z, ft_cpowl(z, -4));
		if (ft_cabsl(z) - ft_cabsl(t) >= 0.1L)
			break ;
		i++;
	}
	return (i);
}

size_t			newton2(t_complex c)
{
	size_t		i;
	t_complex	z;
	t_complex	z0;

	i = 0;
	z = (t_complex){c.re * 0.005L, c.im * 0.005L};
	while (i < I_MAX)
	{
		z0 = z;
		z = ft_cadd(ft_cmul(z0, (t_complex){0.8L, 0.0L}),
				ft_cmul(	ft_cpowl(z0, -4.0L),(t_complex){0.2L, 0.0L}));
		z0 = ft_csub(z, z0);
		if (ft_cabsl(ft_csub(z, z0)) <= 0.1L)
			break ;
		i++;
	}
	return (i);
}

// http://grafika.me/node/35
size_t			newton1(t_complex c)
{
	size_t			i;
	t_complex		z;
	t_complex 		d;
	t_complex 		t;
	long double		p;
	long double max  = 1e+6;
	long double min  = 1e-6;

	z = (t_complex){c.re * 0.005L, c.im * 0.005L};
	d = z;
	i = 0;
	while (i < I_MAX)
	{
		t = z;
		p = sqrtl(t.re) + sqrtl(t.im);
		z.re = 2.0L / 3.0L * t.re + (sqrtl(t.re) - sqrtl(t.im)) / (3 * p);
		z.im = 2.0L / 3.0L * t.im * (1 - t.re / p);
		d.re = fabsl(t.re - z.re);
		d.im = fabsl(t.im - z.im);
		if ((sqrtl(z.re) + sqrtl(z.im) < max)
		&& (sqrtl(d.re) + sqrtl(d.im) >	min))
			break ;
		i++;
	}
	return (i);
}

size_t			mandelbrot(t_complex c)
{
	size_t		i;
	t_complex	z;

	i = 0;
	z = (t_complex){0, 0};
	while (i < I_MAX)
	{
		z = ft_cpowl(z, 2.0L);
		z = ft_cadd(z, c);
		if (powl(z.re, 2.0L) + powl(z.im, 2.0L) >= 4.0L)
			break ;
		i++;
	}
	return (i);
}

size_t			julia(t_complex z, t_complex c)
{
	size_t		i;

	i = 0;
	while (i < I_MAX)
	{
		z = ft_cpowl(z, 2.0L);
		z = ft_cadd(z, c);
		if (powl(z.re, 2.0L) + powl(z.im, 2.0L) >= 4.0L)
			break ;
		i++;
	}
	return (i);
}

size_t			burningship(t_complex c)
{
	size_t		i;
	t_complex	z;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i < I_MAX)
	{
		z = ft_cpowl(z, 2.0L);
		z.im = fabsl(z.im);
		z = ft_cadd(z, c);
		if (powl(z.re, 2.0L) + powl(z.im, 2.0L) >= 4.0L)
			break ;
		i++;
	}
	return (i);
}

void	*start(void *ptr)
{
	return (ptr);
}

int 	main(int argc, char **argv)
{
	const long double   dcolor = 255.0L / 100.0L;
	const long double	di = (long double)I_MAX / 100.0L;
	int					x;
	int					y;
	size_t	i = 0;
	t_win		*twin = get_twin(WIDTH, HEIGHT, "fractol");
	void				*ptr;
	pthread_t 			*thread;

	check_arguments(argc, argv);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			i = newton3((t_complex){
					CX(x),
					CY(y)}
					);
			twin->data[x + y * WIDTH] = ((((i * 6) % 255) << 16) + ((
					(i * 1) %
					255) << 8) + (i * 5) % 255);
			//twin->data[x + y * WIDTH] = 255 - ((i / di) * dcolor);
					//0xFFFFFF - (0x00 + (int)((i / di) *	dcolor));
			x++;
		}
		y++;
	}
	twin->data[320 + 240 * 640] = 0xFF0000;
	mlx_put_image_to_window(twin->mlx, twin->win, twin->img, 0, 0);
	mlx_loop(twin->mlx);
	return (EXIT_SUCCESS);
}