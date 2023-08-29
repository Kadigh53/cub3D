/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 04:00:30 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/08/29 11:46:29 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 12
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
	double		p_angle;
	double		pp_dist;
}				t_data;

/*________________________*/
void	init(t_data *data);
/*__________ray casting______________*/
void	castrays(t_data *data);
/*____________tabaqa lkadi7a 3awd hhhhhh______________*/
double	ft_min(double val1, double val2);

# endif