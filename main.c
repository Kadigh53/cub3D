/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 04:00:05 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/09/05 14:21:13 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
int this case 
i cast a ray 
	data->map[0] = "111111111";
	data->map[1] = "100000001";
	data->map[2] = "1001S1001";
	data->map[3] = "110001011";
	data->map[4] = "111000111";
	data->map[5] = "111100111";
	data->map[6] = "111010111";
	data->map[7] = "111111111";
*/

// dimension of projection plane width x height
// angle between two subsequent rays (in radians) FOV/ width

#include <string.h>
int main(int ac, char **av)
{
	mlx_t	*mlx;
	t_data	*data = malloc(sizeof(t_data));

	// mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH,HEIGHT,"mokaaab", false);
	data->map = malloc(9 * sizeof(char *));
	(void)ac;
	(void)av;
	data->map[0] = "111111111";
	data->map[1] = "100000001";
	data->map[2] = "1000S0001";
	data->map[3] = "100000001";
	data->map[4] = "100000001";
	data->map[5] = "100101001";
	data->map[6] = "100000001";
	data->map[7] = "111111111";
	data->map[8] = NULL;
	init(data);
	data->img = mlx_new_image(mlx, 1024, 633);
	mlx_image_to_window(mlx, data->img, 0, 0);
	// int i = 0;
	// while (i < 600)
	// {
	// 	mlx_put_pixel(data->img, 512, i, 0xFF0000FF);
	// 	i++;
	// }
	castrays(data);
	mlx_loop(mlx);
	return(0);
}
