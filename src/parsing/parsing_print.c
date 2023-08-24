/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:06:09 by sbzizal           #+#    #+#             */
/*   Updated: 2023/08/17 13:16:46 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    print_array(t_data *data)
{
    int i = 0;
    
    while(data->map_array[i])
    {
        printf("%s\n", data->map_array[i]);
        i++;
    }
}

void    print_map(t_data *data)
{
    int i = 0;
    
    printf("*************** map ***************\n\n");
    while(data->map_path[i])
    {
        printf("%s\n", data->map_path[i]);
        i++;
    }
    printf("\n***********************************\n");
}