#include "../cub3d.h"

// find the minimum of the horizontal and vertical distance

int	xray_direction(double ray_angle)
{
	return(abs(cos(ray_angle)) / cos(ray_angle));
}

int	yray_direction(double ray_angle)
{
	return(abs(sin(ray_angle)) / sin(ray_angle));
}

void	min_ofhv_dist(t_data *data, double xinter, double yinter)
{
	double	hintersectdist;
	double	vintersectdist;

	hintersectdist = sqrt(pow((xinter - data->pposx), 2) + pow((yinter - data->pposy), 2));
}
// find the vertical intersections
double	find_vintersecto(t_data *data, double ray_angle)
{
	double	xinter;
	double	yinter;

	xinter = data->pposx + (64 - ((long)data->pposx % 64) * xray_direction(ray_angle));
	yinter = data->pposy + (64 - ((((long)data->pposx % 64)) * tan(ray_angle)) * yray_direction(ray_angle));
	while (1)
	{
		if (data->map[(int)yinter][(int)xinter] == '1')
		{
			return (abs(data->pposy - yinter) / sin(ray_angle));
		}
		xinter += 64 * xray_direction(ray_angle);
		yinter += 64 * tan(ray_angle) * yray_direction(ray_angle);
	}
	
}
// find the first horizental intersection
double	find_intersecto(t_data *data, double ray_angle)
{
	double	xinter;
	double	yinter;
	double	vintersectdist;
	double	hintersectdist;

	yinter = data->pposy + (64 - (((long)data->pposy % 64) * yray_direction(ray_angle)));
	xinter = data->pposx + (64 - ((((long)data->pposy % 64)) / tan(ray_angle) * xray_direction(ray_angle)));
	// yinter = data->pposy + (ray_direction(ray_angle) * (64 - (data->pposy % 64)));
	// xinter = data->pposx + (ray_direction(ray_angle) * ((64 - (data->pposy % 64)) / tan(ray_angle)));
	while(1)
	{
		if (data->map[(int)(yinter / 64)][(int)(xinter / 64)] == '1')
		{
			hintersectdist = abs(data->pposx - xinter) / cos(ray_angle);
			vintersectdist = find_vintersecto(data, ray_angle);
			// min_ofhv_dist(xinter, yinter);
			printf("%f,%f\n",(xinter),(yinter));
			printf("%f,%f",(xinter)/64, (yinter)/64);
			// render();
			return (ft_min(hintersectdist, vintersectdist));
		}
		// yinter += 64 * yray_direction(ray_angle);
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
	double	ray_step;
	double	ray_angle;
	double	ray_dist;

	i = -1;
	ray_step = (M_PI / 3) / WIDTH;
	ray_angle = data->p_angle - (M_PI / 6);
	find_intersecto(data, ray_angle);
	return ;
	while(++i < WIDTH)
	{
		ray_dist = find_intersecto(data, ray_angle);
		ray_angle += ray_step;
		i++;
	}
}