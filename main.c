/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 04:00:05 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/08/30 15:15:34 by aaoutem-         ###   ########.fr       */
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
	void	*mlx;
	void	*mlx_win;
	t_data	*data = malloc(sizeof(t_data));

	mlx = mlx_init();
	data->map = malloc(8 * sizeof(char *));
	(void)ac;
	(void)av;
	data->map[0] = "111111111";
	data->map[1] = "100000001";
	data->map[2] = "1000S0001";
	data->map[3] = "100000001";
	data->map[4] = "100101001";
	data->map[5] = "100000001";
	data->map[6] = "100000001";
	data->map[7] = "111111111";
	init(data);
	// printf("pposx : %f , pposy : %f\n",data->pposx/64,data->pposy/64);
	castrays(data);
	mlx_win = mlx_new_window(mlx, 1024, 633, "Hello world!");
	mlx_loop(mlx);
	return(0);
	// while (1);
	// printf("xinter : %f , yinter : %f",data->pposx,data->pposy);
}
