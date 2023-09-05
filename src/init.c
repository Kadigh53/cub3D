/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 04:42:31 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/09/04 23:55:32 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	player_angle(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N')
		return (3 * M_PI_2);
	else if (data->map[i][j] == 'S')
		return (M_PI_2);
	else if (data->map[i][j] == 'W')
		return (M_PI);
	else if (data->map[i][j] == 'E')
		return (0.0);
	return (-1);
}

void	player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while(data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'S')
			{
				data->p_angle = player_angle(data, i, j);
				data->pposx = (j + 0.5) * 64.0;
				data->pposy = (i + 0.5) * 64.0;
			}
			j++;
		}
		i++;
	}
}

void	init(t_data *data)
{
	player_position(data);
	data->pp_dist = 512 / tan(M_PI / 6);
}
