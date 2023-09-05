/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 08:09:27 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/09/05 14:21:24 by aaoutem-         ###   ########.fr       */
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
	// double rayenn= ray_angle*180/M_PI;
	// double a= (xinter - data->pposx);
	// double tr= tan(ray_angle);
	// double yd= fabs((xinter - data->pposx) * tan(ray_angle));
	yinter = data->pposy + (fabs((xinter - data->pposx) * tan(ray_angle)) * yray_direction(ray_angle));
	while (1)
	{
		if ((yinter > (7 * 64)) || yinter < 0 || xinter < 0 || (xinter > (8 * 64))) // if the coordinates exceed the x y coordinates 
			return (floor(-1));
		if (data->map[(int)(yinter) >> 6][(int)(xinter) >> 6] == '1')
		{
			// printf("v\n");
			// printf("%f,%f\n",(xinter),(yinter));
			// printf("%f,%f\n",(xinter)/64, (yinter)/64);
			// printf("(%d,%d)\n\n", (int)(xinter / 64),(int)(yinter / 64));
			// return (fabs((data->pposy - yinter) / sin(ray_angle)));
			return (sqrt(pow(data->pposy - yinter, 2) + pow(data->pposx - xinter, 2)));
		}
		xinter += (64 * xray_direction(ray_angle));
		yinter += 64 * fabs(tan(ray_angle)) * yray_direction(ray_angle);
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
		if (yinter  > (7 * 64) || yinter < 0 || xinter < 0 || (xinter > (8 * 64))) // if the coordinates exceed the x y coordinates 
			return (find_vintersecto(data, ray_angle));
		if (data->map[(int)(yinter / 64)][(int)(xinter / 64)] == '1')
		{
			hintersectdist = sqrt(pow(data->pposx - xinter, 2) + pow(data->pposy - yinter ,2));
			vintersectdist = find_vintersecto(data, ray_angle);
			if (vintersectdist == floor(-1))
				return (hintersectdist);
			return (ft_min(hintersectdist, vintersectdist));
			// printf("h\n");
			// printf("%f,%f\n",(xinter)/64, (yinter)/64);
			// printf("(%d,%d)\n\n", (int)(xinter / 64),(int)(yinter / 64));
			// printf("hintersectdist :\t %lf\n",hintersectdist);
			// printf("vintersectdist :\t %lf\n",vintersectdist);
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

void	put_wall(t_data *data, int wp_height, int i)
{
	int	j;
	int	w;

	j = 0;
	w = (int)(HEIGHT / 2) - (int)(wp_height / 2);
	if (w < 0)
		w = 0;
	while (j <(wp_height))
	{
		mlx_put_pixel(data->img, i, w + j, 0x00FF00FF);
		j++;
	}
}

void	project_dawall(t_data *data, double ray_dist, int i)
{
	double	ray_disty;
	double	wp_height;
	double	ray_step;
	double	destortion_angle;

	ray_step = (M_PI / 3) / WIDTH;
	destortion_angle = (M_PI / 6) - (i * ray_step);
	ray_disty = ray_dist * fabs(cos(destortion_angle));
	wp_height = (data->pp_dist / ray_disty) * 64;
	printf("%f\n", wp_height);
	put_wall(data, wp_height, i);
}

void	castrays(t_data *data)
{
	int	i;
	double	ray_step;
	double	ray_angle;
	double	ray_dist;
	double rayenn;

	i = 0;
	ray_step = (M_PI / 3) / WIDTH;
	ray_angle = data->p_angle - (M_PI / 6);
	// ray_angle = M_PI_4 - (M_PI / 6);
	rayenn = ray_angle*180/M_PI;
	// ray_dist = find_intersecto(data, ray_angle);
	// return;
	while(i < WIDTH)
	{
		ray_dist = find_intersecto(data, ray_angle);
		printf("%f\t", ray_angle*180/M_PI);
		// printf("%lf\n", ray_dist);
		if (ray_dist == floor(-1))
			break;
			// 	continue;
		// }
		project_dawall(data, ray_dist, i);
		ray_angle += ray_step;
		rayenn = ray_angle*180/M_PI;
		i++;
	}
}