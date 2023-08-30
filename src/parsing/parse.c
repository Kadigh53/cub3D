/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:54:28 by sbzizal           #+#    #+#             */
/*   Updated: 2023/08/30 12:13:38 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void    parse_player(t_data *data)
{
    int x = 0;
    int y = 0;
    int count = 0;
    
    while(data->map_path[x])
    {
        y = 0;
        while(data->map_path[x][y])
        {
            if (data->map_path[x][y] == 'N' || data->map_path[x][y] == 'S' || data->map_path[x][y] == 'W' || data->map_path[x][y] == 'E')
            {
                count++;
                data->x_pos = x;
                data->y_pos = y;
                data->player = data->map_path[x][y];
                printf("player: %c\n", data->player);
            }
            y++;
        }
        x++;
    }
    if (count != 1)
    {
        printf("player_not_valid\n");
        exit(1);
    }
}

void    final_pars_map(char **map)
{
    int x = 0;
    int y = 0;

    while(map[x])
    {
        y = 0;
        while(map[x][y])
        {
            if (map[x][y] != '1' && map[x][y] != '0'&& map[x][y] != 'N' && map[x][y] != 'S' 
                && map[x][y] != 'W' && map[x][y] != 'E' && map[x][y] != '5')
            {
                printf("Error\n");
                exit(1);
            }
            if (map[x][y] == '0')
            {
                if (map[x][y + 1] == '5' || map[x][y - 1] == '5' || map[x + 1][y] == '5' || map[x - 1][y] == '5')
                {
                    printf("Error\n");
                    exit(1);
                }
            }
            y++;
        }
        x++;
    }
}

void    ft_inisialize(t_data *data)
{
    data->map_array = NULL;
    data->map_path = NULL;
    data->n_path = NULL;
    data->s_path = NULL;
    data->w_path = NULL;
    data->e_path = NULL;
    data->f_path = NULL;
    data->c_path = NULL;
    data->map_height = 0;
    data->map_width = 0;
    data->x_pos = 0;
    data->y_pos = 0;
    data->player = 0;
}

int    ft_parsing(int ac, char *map, t_data *data)
{
    char    *line;
    int     fd;

    if (ac != 2)
    {
        printf("Error\n");
        exit(1);
    }
    
    ft_inisialize(data);
    check_name(map);
    fd =  open(map, O_RDWR, 0777);
    if (fd < 0)
        printf("file_not_found\n");
    line = get_next_line(fd);
    while(line)
    {
        data->map_height++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    
    ft_fill_array(data, map);
    ft_get_width(data);
    // print_array(data);
    get_path(data);
    if (check_path(data))
        exit(1);
    allocate_map(data);
    check_map(data);
    print_map(data);
    parse_player(data);
    final_pars_map(data->map_path);
    return (0);
}
