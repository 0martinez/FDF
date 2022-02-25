

#include "../../my_fdf.h"

void	move_map(t_axes *first, t_axes *second, t_fdf *fdf)
{
	first->x += fdf->move_x;
	first->y += fdf->move_y;
	second->x += fdf->move_x;
	second->y += fdf->move_y;
}