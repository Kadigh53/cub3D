#include "../cub3d.h"

// find the minimum of the horizontal and vertical distance
int	ray_direction(float ray_angle)
{
	if (ray_angle >= 0 && ray_angle <= M_PI)
		return (1);
	else
		return (-1);
}

void	min_ofhv_dist(t_data *data, float xinter, float yinter)
{
	float	hintersectdist;
	float	vintersectdist;

	hintersectdist = sqrt(pow((xinter - data->pposx), 2) + pow((yinter - data->pposy), 2));
}
// find the first horizental intersection
void	find_intersecto(t_data *data, float ray_angle)
{
	float	xinter;
	float	yinter;

	yinter = data->pposy + ((64 - (data->pposy % 64)));
	xinter = data->pposx + (((64 - (data->pposy % 64)) / tan(ray_angle)));
	// yinter = data->pposy + (ray_direction(ray_angle) * (64 - (data->pposy % 64)));
	// xinter = data->pposx + (ray_direction(ray_angle) * ((64 - (data->pposy % 64)) / tan(ray_angle)));
	while(1)
	{
		if (data->map[int(yinter / 64)][int(xinter / 64)] == '1')
		{
			min_ofhv_dist(data ,xinter, yinter);
			render();
			return ;
		}
		yinter += 64;
		xinter += 64 / tan(ray_angle);
	}
	// yinter = data->pposy + (64 - (data->pposy % 64) / tan(ray_angle));
	// xinter = data->pposx + (64 - (data->pposy % 64));
	// vintersectdist = sqrt(pow((xinter - data->pposx), 2) + pow((yinter - data->pposy), 2));
}

void	castrays(t_data *data)
{
	int	i;
	float	ray_step;
	float	ray_angle;

	i = -1;
	ray_step = (M_PI / 3) / WIDTH;
	ray_angle = data->p_angle + (M_PI / 6);
	while(++i < WIDTH)
	{
		find_intersecto(data, ray_angle);
		ray_angle -= ray_step;
		i++;
	}
}