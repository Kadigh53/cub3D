/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 04:00:05 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/08/19 07:59:18 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


#include <string.h>
int main()
{
	t_data	*data = malloc(sizeof(t_data));
	data->map = malloc(6 * sizeof(char *));

	init(data);
}
