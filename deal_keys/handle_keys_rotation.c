

#include "../my_fdf.h"

void	handle_key_rotation(t_fdf *fdf, int key)
{
	if (key == 'z')
		fdf->x_rot -= 0.05;
	if (key == 'x')
		fdf->x_rot += 0.05;
	if (key == 'a')
		fdf->y_rot += 0.05;
	if (key == 's')
		fdf->y_rot -= 0.05;
	if (key == 'q')
		fdf->z_rot += 0.05;
	if (key == 'w')
		fdf->z_rot -= 0.05;
}