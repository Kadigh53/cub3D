/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 04:42:31 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/08/26 11:48:14 by aaoutem-         ###   ########.fr       */
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
	else
		return (0);
}

void	player_position(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while(data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'S')
			{
				data->p_angle = player_angle(data, i, j);
				data->pposx = (j + 0.5) * 64.0;
				data->pposy = (i + 0.5) * 64.0;
			}
		}
	}
}


void	init(t_data *data)
{
	player_position(data);
}
