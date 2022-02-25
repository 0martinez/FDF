

#include "../../my_fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, float x, float y, int color)
{
	char	*dst;

	dst = fdf->img_addr + ((int)y * fdf->line_length + (int)x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}