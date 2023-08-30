/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:07:16 by sbzizal           #+#    #+#             */
/*   Updated: 2023/08/30 14:03:11 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    ft_fill_array(t_data *data, char *map)
{
    char *line;
    int fd;
    int i = 0;
    
    data->map_array = malloc(sizeof(char *) * (data->map_height + 1));
    fd = open(map, O_RDWR, 0777);
    line = get_next_line(fd);
    while(line)
    {
        data->map_array[i] = ft_strdup_newline(line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    data->map_array[i] = NULL;
}

void    ft_fill_space(char *str, int width)
{
    int i = 0;
    
    while(str[i])
        i++;
    while(i < width)
    {
        str[i] = '5';
        i++;
    }
    str[i] = '\0';
}

void    allocate_map(t_data *data)
{
    size_t i = 0;
    int j = 0;
    
    data->map_path = malloc(sizeof(char *) * (data->map_height + 1));
    while(data->map_array[i])
    {
        if (strncmp(data->map_array[i], "1", 1) == 0)
        {
            while(i < data->map_height)
            {
                data->map_path[j] = malloc(sizeof(char) * (data->map_width + 1));
                strcpy(data->map_path[j], data->map_array[i]);
                if (ft_strlen(data->map_path[j]) < data->map_width)
                    ft_fill_space(data->map_path[j], data->map_width);
                if (data->map_array[i][0] == '\0')
                    break;
                i++;
                j++;
            }
            data->map_path[j] = NULL;
            break;
        }
        i++;
    }
    
    i = 0;
    j = 0;
    while(data->map_path[i])
    {
        j = 0;
        while(data->map_path[i][j])
        {
            if (data->map_path[i][j] == ' ')
                data->map_path[i][j] = '5';
            j++;
        }
        i++;
    }
}

void    ft_get_width(t_data *data)
{
    int i;
    int j;
    size_t max = 0;
    i = 0;

    while (data->map_array[i])
    {
        j = 0;
        if (strncmp(data->map_array[i], "1", 1) == 0)
        {
            while(data->map_array[i][j])
            {
                max = ft_strlen(data->map_array[i]);
                if (max > data->map_width)
                    data->map_width = max;
                j++;
            }
        }
        i++;
    }
}

void    get_path(t_data *data)
{
    int i = 0;
    
    while(data->map_array[i])
    {
        if (strncmp(data->map_array[i], "NO", 2) == 0)
            data->n_path = ft_strtrim(ft_strdup(&data->map_array[i][3]), " ");
        if (strncmp(data->map_array[i], "SO", 2) == 0)
            data->s_path = ft_strtrim(ft_strdup(&data->map_array[i][3]), " ");
        if (strncmp(data->map_array[i], "WE", 2) == 0)
            data->w_path = ft_strtrim(ft_strdup(&data->map_array[i][3]), " ");
        if (strncmp(data->map_array[i], "EA", 2) == 0)
            data->e_path = ft_strtrim(ft_strdup(&data->map_array[i][3]), " ");
        if (strncmp(data->map_array[i], "F", 1) == 0)
            data->f_path = ft_get_color(ft_strdup(&data->map_array[i][2]));
        if (strncmp(data->map_array[i], "C", 1) == 0)
            data->c_path = ft_get_color(ft_strdup(&data->map_array[i][2]));
        if (strncmp(data->map_array[i], "1", 1) == 0)
            allocate_map(data);
        if (strncmp(data->map_array[i], "1", 1) != 0 && strncmp(data->map_array[i], "NO", 2) != 0 
        && strncmp(data->map_array[i], "SO", 2) != 0 && strncmp(data->map_array[i], "WE", 2) != 0 
        && strncmp(data->map_array[i], "EA", 2) != 0 && strncmp(data->map_array[i], "F", 1) != 0 
        && strncmp(data->map_array[i], "C", 1) != 0 && strncmp(data->map_array[i], "", 1) != 0 )
        {
            printf("config_not_valid\n");
            exit(1);
        }
        i++;
    }
    if (!data->n_path || !data->s_path || !data->w_path || !data->e_path 
        || !data->f_path || !data->c_path || !data->map_path)
    {
        printf("config_not_valid\n");
        exit(1);
    }

}

int check_path(t_data *data)
{
    if (open(data->n_path, O_RDONLY) < 0)
        return(printf("north_path_not_valid\n"), 1);
    if (open(data->s_path, O_RDONLY) < 0)
        return(printf("south_path_not_valid\n"), 1);
    if (open(data->w_path, O_RDONLY) < 0)
        return(printf("west_path_not_valid\n"), 1);
    if (open(data->e_path, O_RDONLY) < 0)
        return(printf("east_path_not_valid\n"), 1);
    return(0);
}
