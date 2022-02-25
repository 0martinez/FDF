

#include "../../my_fdf.h"

void	apply_zoom(t_axes *first, t_axes *second, t_fdf *fdf)
{
	first->x *= fdf->zoom;
	first->y *= fdf->zoom;
	second->x *= fdf->zoom;
	second->y *= fdf->zoom;
}