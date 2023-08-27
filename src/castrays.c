/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 08:09:27 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/08/27 12:40:27 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// find the minimum of the horizontal and vertical distance
int	percise_ycrdnt(double ray_angle)
{
	if (sin(ray_angle) > 0)
		return (64);
	return (-1);
}

int	percise_xcrdnt(double ray_angle)
{
	if (cos(ray_angle) > 0)
		return (64);
	return (-1);
}

int	xray_direction(double ray_angle)
{
	int	a;

	a = fabs(cos(ray_angle)) / cos(ray_angle);
	return(a);
}

int	yray_direction(double ray_angle)
{
	int a;

	a = fabs(sin(ray_angle)) / sin(ray_angle);
	return(a);
}

// find the vertical intersections
double	find_vintersecto(t_data *data, double ray_angle)
{
	double	xinter;
	double	yinter;

	xinter = floor(data->pposx / 64) * 64 + percise_xcrdnt(ray_angle);
	yinter = data->pposy + (fabs((xinter - data->pposx) * tan(ray_angle)) * yray_direction(ray_angle));
	while (1)
	{
		if (data->map[(int)(yinter / 64)][(int)(xinter / 64)] == '1')
		{
			// printf("v\n");
			// printf("%f,%f\n",(xinter),(yinter));
			// printf("%f,%f\n",(xinter)/64, (yinter)/64);
			// printf("(%d,%d)\n\n", (int)(xinter / 64),(int)(yinter / 64));
			return (fabs((data->pposy - yinter) / sin(ray_angle)));
		}
		xinter += (64 * xray_direction(ray_angle));
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

	yinter = (floor(data->pposy / 64) * 64) + percise_ycrdnt(ray_angle);
	xinter = data->pposx + (fabs((yinter - (long)data->pposy) / tan(ray_angle)) * xray_direction(ray_angle));
	while(1)
	{
		if (data->map[(int)(yinter / 64)][(int)(xinter / 64)] == '1')
		{
			hintersectdist = fabs((data->pposx - xinter) / cos(ray_angle));
			vintersectdist = find_vintersecto(data, ray_angle);
			// printf("h\n");
			// printf("%f,%f\n",(xinter)/64, (yinter)/64);
			// printf("(%d,%d)\n\n", (int)(xinter / 64),(int)(yinter / 64));
			// printf("hintersectdist :\t %lf\n",hintersectdist);
			// printf("vintersectdist :\t %lf\n",vintersectdist);
			return (ft_min(hintersectdist, vintersectdist));
		}
		yinter += (64 * yray_direction(ray_angle));
		xinter += (fabs(64 / tan(ray_angle)) * xray_direction(ray_angle));
	}
}
	// yinter = data->pposy + (ray_direction(ray_angle) * (64 - (data->pposy % 64)));
	// xinter = data->pposx + (ray_direction(ray_angle) * ((64 - (data->pposy % 64)) / tan(ray_angle)));

	// yinter = data->pposy + (64 - (data->pposy % 64) / tan(ray_angle));
	// xinter = data->pposx + (64 - (data->pposy % 64));
	// vintersectdist = sqrt(pow((xinter - data->pposx), 2) + pow((yinter - data->pposy), 2));

void	project_dawall(t_data *data, double ray_angle, double ray_dist, int i)
{
	double	ray_disty;
	double	wp_height;

	ray_disty = fabs(ray_dist * sin(ray_angle));
	printf("%lf", ray_disty);
	// wp_height = (data->pp_dist / ray_disty) * 64;

	// go to window and draw the first half and the other half 
	// render();
}

void	castrays(t_data *data)
{
	int	i;
	double	ray_step;
	double	ray_angle;
	double	ray_dist;

	i = 0;
	ray_step = (M_PI / 3) / WIDTH;
	ray_angle = data->p_angle - (M_PI / 6);
	// ray_dist = find_intersecto(data, ray_angle);
	// printf("%f", ray_angle*180/M_PI);
	// return;
	while(i < WIDTH)
	{
		ray_dist = find_intersecto(data, ray_angle);
		project_dawall(data, ray_dist, ray_angle, i);
		ray_angle += ray_step;
		i++;
	}
}