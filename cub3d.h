/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 04:00:30 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/08/19 08:50:50 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1024
# define HEIGHT 633

# include <math.h>
# include <unistd.h>
# include <stdlib.h>    
# include <stdio.h>
# include <fcntl.h>
// # include "/Users/aaoutem-/MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	char		**map;
	float		pposx;
	float		pposy;
	float		p_angle;
}				t_data;

/*________________________*/
void	init(t_data *data);
/*________________________*/

# endif