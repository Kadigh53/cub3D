/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:35:44 by sbzizal           #+#    #+#             */
/*   Updated: 2023/09/25 10:32:35 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	render_map(t_data *data)
{
	castrays(data);
	mini_map(data);
	mini_player(data);
	mouse_move(data);
}
