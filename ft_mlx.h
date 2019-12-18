#ifndef FT_MLX_H
# define FT_MLX_H
# include <mlx.h>
# include "libft.h"

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	void			*img;
	int 			*data;
}					t_win;

void				destroy_twin(
						t_win *twin,
						_Bool destroy_mlx
						);
t_win 				*get_twin(
						int width,
						int height,
						char *title
						);
t_win 				*get_twin_mlx(
						int width,
						int height,
						char *title,
						void *mlx
						);
void				show_usage(void);

#endif
