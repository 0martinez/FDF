

#include "../../my_fdf.h"

int	apply_palette(float y, float x, t_fdf *fdf)
{
	if (fdf->palette == 0)
		return (fdf->color_matrix[(int)y][(int)x]);
	else
		return (0x00ff00);
}