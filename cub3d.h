/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 04:00:30 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/09/05 14:21:53 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 24
# define HEIGHT 632


# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
// # include <mlx.h>
# include "/home/aaoutem-/MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	char		**map;
	float		pposx;
	float		pposy;
	double		p_angle;
	double		pp_dist;
	mlx_image_t	*img;
}				t_data;

/*________________________*/
void	init(t_data *data);
/*__________ray casting______________*/
void	castrays(t_data *data);
/*____________tabaqa lkadi7a 3awd hhhhhh______________*/
double	ft_min(double val1, double val2);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);

# endif