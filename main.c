#include "fractol.h"

_Bool 				cycle(t_fractol *fractol);
void				destroy_fractol(t_fractol *fractol);
t_fractol 			*get_tfractol(t_view *view, char fractol_letter);

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

void			init_tpoint(t_fractol *fractol)
{
	const size_t		width_x_height = WIDTH * HEIGHT;
	size_t		i;

	i = 0;
	while (i < width_x_height)
		fractol->point[i++] = (t_point){0.0L, 0.0L};
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

void			change_zoom(t_fractol *fractol, int button, int keycode)
{
	if (button == MOUSE_EVENT_SCROLL_UP || keycode == KEY_NUM_PLUS)
	{
		fractol->view->attr.zoom_count++;
		fractol->view->attr.zoom /= 0.9L;
		fractol->i_max /= 0.9L;
	}
	else if ((button == MOUSE_EVENT_SCROLL_DOWN || keycode == KEY_NUM_MINUS))
	{
		if (fractol->view->attr.zoom_count == 0)
			return ;
		fractol->view->attr.zoom_count--;
		fractol->view->attr.zoom *= 0.9L;
		fractol->i_max *= 0.9L;
	}
	cycle(fractol);
}

#include <stdio.h>

int 			e_close(void *param) //TODO exit free (without mlx)
{
	destroy_fractol(param);
	exit(EXIT_SUCCESS);
}

void			change_color(t_fractol *fractol, int keycode)
{
	fractol->refresh_color = TRUE;
	if (keycode == KEY_R)
		fractol->cpower.r = fractol->cpower.r > 9 ? 0 : fractol->cpower.r + 1;
	if (keycode == KEY_G)
		fractol->cpower.g = fractol->cpower.g > 9 ? 0 : fractol->cpower.g + 1;
	if (keycode == KEY_B)
		fractol->cpower.b = fractol->cpower.b > 9 ? 0 : fractol->cpower.b + 1;
	cycle(fractol);
}

void 			reset_fractol(t_fractol *fractol)
{
	const t_win		*twin = fractol->view->twin;
	const char		letter = fractol->letter;
	t_view 			*view;

	destroy_fractol(fractol);
	if (!(view = get_tview((t_win *)twin))
	|| !(fractol = get_tfractol(view, letter)))
		exit(EXIT_FAILURE);
	cycle(fractol);
}

void			change_view(t_fractol *fractol, int keycode)
{
	const long double	dx = 10L / fractol->view->attr.zoom;
	const long double	dy = 10L / fractol->view->attr.zoom;

	if (keycode == KEY_UPARROW)
		fractol->view->attr.dy += dy;
	if (keycode == KEY_DOWNARROW)
		fractol->view->attr.dy -= dy;
	if (keycode == KEY_LEFTARROW)
		fractol->view->attr.dx += dx;
	if (keycode == KEY_RIGHTARROW)
		fractol->view->attr.dx -= dx;
	cycle(fractol);
}

int 			e_key_press(int keycode, void *param)
{
	t_fractol	*fractol;
	t_view		*view;

	if (keycode == KEY_ESCAPE)
		return (e_close(param));
	fractol = param;
	view = ((t_fractol *)param)->view;
	if (keycode == KEY_R || keycode == KEY_G || keycode == KEY_B)
		change_color(fractol, keycode);
	if (keycode == KEY_NUM_CLEAR)
		reset_fractol(fractol);
	if (keycode >= KEY_LEFTARROW && keycode <= KEY_UPARROW)
		change_view(fractol, keycode);
	if (!view->keyboard.key[keycode])
	{
		view->keyboard.key[keycode] = TRUE;
		view->keyboard.current_pressed++;
	}
	if (keycode == KEY_NUM_PLUS || keycode == KEY_NUM_MINUS)
		change_zoom(fractol, MOUSE_EVENT_NONE, keycode);
	return (EXIT_SUCCESS);
}

int				e_key_release(int keycode, void *param)
{
	t_view		*view;

	if (keycode == KEY_ESCAPE)
		return (e_close(param));
	view = ((t_fractol *)param)->view;
	if (view->keyboard.key[keycode])
	{
		view->keyboard.key[keycode] = FALSE;
		view->keyboard.current_pressed--;
	}
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

int				e_mouse_release(int button, int x, int y, void *param)
{
	t_fractol	*fractol;

	(void)x;
	(void)y;
	fractol = param;
	if (button >= MOUSE_EVENT_LBUTTON && button <= MOUSE_EVENT_SCROLL)
		fractol->view->mouse.button[button] = FALSE;
	return (EXIT_SUCCESS);
}

int				e_mouse_move(int x, int y, void *param)
{
	t_fractol		*fractol;

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

void 		event_set(t_fractol *fractol)
{
	void		*win;

	win = fractol->view->twin->win;
	mlx_hook(win, EVENT_KEY_PRESS, MASK_KEY_PRESS, e_key_press, fractol);
	mlx_hook(win, EVENT_KEY_RELEASE, MASK_KEY_RELEASE, e_key_release, fractol);
	mlx_hook(win, EVENT_MOUSE_MOVE, MASK_MOUSE_MOVE, e_mouse_move, fractol);
	mlx_hook(win, EVENT_MOUSE_BUTTON_PRESS, MASK_MOUSE_BUTTON_PRESS,
			 e_mouse_press, fractol);
	mlx_hook(win, EVENT_MOUSE_BUTTON_RELEASE, MASK_MOUSE_BUTTON_RELEASE,
			 e_mouse_release, fractol);
	mlx_hook(win, EVENT_CLOSE, MASK_CLOSE, e_close, fractol);
}

void		destroy_fractol(t_fractol *fractol)
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

t_fractol 	*new_tfractol(void)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		return (NULL);
	fractol->view = NULL;
	fractol->letter = '\0';
	return (fractol);
}

void		init_cpower(t_fractol *fractol)
{
	fractol->cpower.r = 9;
	fractol->cpower.g = 9;
	fractol->cpower.b = 9;
	fractol->cpower.a = 0;
}

void		init_i_array(t_fractol *fractol)
{
	size_t		i;

	i = 0;
	while (i < HEIGHT * WIDTH)
		fractol->i[i++] = 0;
}

t_fractol 	*get_tfractol(t_view *view, char fractol_letter)
{
	t_fractol		*fractol;

	if (!(fractol = new_tfractol())
	|| !(fractol->view = view ? view : get_tview(NULL)))
	{
		destroy_fractol(fractol);
		return (NULL);
	}
	init_tpoint(fractol);
	init_cpower(fractol);
	init_i_array(fractol);
	fractol->letter = fractol_letter;
	fractol->i_max = 25;
	fractol->move = TRUE;
	fractol->refresh_color = FALSE;
	event_set(fractol);
	return (fractol);
}

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
	const t_mouse	mouse = fractol->view->mouse;
	const size_t 	i_max = fractol->i_max;

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

_Bool 				cycle(t_fractol *fractol)
{
	size_t			current;
	t_point2d		point;
	t_win			*twin;

	twin = fractol->view->twin;
	point.y = 0;
	while (point.y < HEIGHT)
	{
		point.x = 0;
		while (point.x < WIDTH)
		{
			current = point.x + point.y * WIDTH;
			if (!fractol->refresh_color)
				fractol->i[current] =
						escape(fractol, get_fpoint(fractol, point));
			twin->data[current] = get_color(fractol, fractol->i[current],
					(t_point){point.x, point.y});
			point.x++;
		}
		point.y++;
	}
	fractol->refresh_color = FALSE;
	mlx_put_image_to_window(twin->mlx, twin->win, twin->img, 0, 0);
	return (TRUE);
}

int 	main(int argc, char **argv)
{
	t_fractol	*fractol;

	check_arguments(argc, argv);
	if (!(fractol = get_tfractol(NULL, *argv[1]))
	|| !(cycle(fractol)))
		return (EXIT_FAILURE);
	mlx_loop(fractol->view->twin->mlx);
	return (EXIT_SUCCESS);
}