#ifndef FT_MLX_H
# define FT_MLX_H
# include <mlx.h>

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	void			*img;
	int 			*data;
}					t_win;

void				destroy_twin(
						t_win *twin
						);
t_win 				*get_twin(
						int width,
						int height,
						char *title
						);

#endif
