/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fill2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:12:20 by sbzizal           #+#    #+#             */
/*   Updated: 2023/08/18 21:43:30 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int ft_count_comma(char *str)
{
    int i = 0;
    int count = 0;

    while(str[i])
    {
        if (str[i] == ',')
            count++;
        i++;
    }
    return(count);
}

char *ft_get_color(char *path)
{
    char **new_path = NULL;
    char *data_path = NULL;
    
    int i = 0;
    int comma= ft_count_comma(path);

    new_path = ft_split(path, ',');
    while(new_path[i])
    {
        new_path[i] = ft_strtrim(new_path[i], " ");
        if (atoi(new_path[i]) > 255 || atoi(new_path[i]) < 0 || is_digit(new_path[i]) || comma != 2)
        {
            printf("color_not_valid\n");
            exit(1);
        }
        data_path = ft_strjoin(data_path, new_path[i]);
        if (i < 2)
            data_path = ft_strjoin(data_path, ",");
        i++;
    }
    return(data_path);
}

char    *ft_get_path(char *path)
{
    char *new_path = NULL;
    
    int i = 0;
    while(path[i])
    {
        if (path[i] == '.' && path[i + 1] == 'x' && path[i + 2] == 'p' && path[i + 3] == 'm')
        {
            new_path = strndup(path, i +4);
            break;
        }
        i++;
    }
    // printf("new_path = %s\n", new_path);
    return(new_path);
}

void    check_name(char *map)
{
    int len = ft_strlen(map);
    
    if (map[len - 1] != 'b' || map[len - 2] != 'u' || map[len - 3] != 'c' || map[len - 4] != '.')
    {
        printf("path_not_valid\n");
        exit(1);
    }
}

void check_map(t_data *data)
{
    int i = 0;
    int len = 0;
    
    while(data->map_path[len])
    {
        while(data->map_path[0][i])
        {
            if (data->map_path[0][i] != '1' && data->map_path[0][i] != '5')
            {
                printf("map_not_valid\n");
                exit(1);
            }
            i++;
        }
        len++;
    }
    
    // printf("len = %d\n", len);
    i = 0;
    while(data->map_path[len -1][i])
    {
        if (data->map_path[len -1][i] != '1' && data->map_path[len -1][i] != '5')
        {
            printf("map_not_valid\n");
            exit(1);
        }
        i++;
    }
    
}
