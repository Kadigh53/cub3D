/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 04:00:05 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/08/27 12:35:33 by aaoutem-         ###   ########.fr       */
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
	t_data	*data = malloc(sizeof(t_data));
	data->map = malloc(8 * sizeof(char *));

	data->map[0] = "111111111";
	data->map[1] = "111110001";
	data->map[2] = "1001S1001";
	data->map[3] = "111111111";
	data->map[4] = "111001111";
	data->map[5] = "111000111";
	data->map[6] = "111010111";
	data->map[7] = "111111111";
	init(data);
	// printf("pposx : %f , pposy : %f\n",data->pposx/64,data->pposy/64);
	castrays(data);
	// printf("xinter : %f , yinter : %f",data->pposx,data->pposy);
}
