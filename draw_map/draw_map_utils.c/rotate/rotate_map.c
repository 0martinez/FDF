

#include "../../../my_fdf.h"

void	apply_rotation(t_axes *first, t_axes *second, t_fdf *fdf)
{
	rotate_x_exe(first, second, fdf);
	rotate_y_exe(first, second, fdf);
	rotate_z_exe(first, second, fdf);
}