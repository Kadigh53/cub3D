/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:11:06 by sbzizal           #+#    #+#             */
/*   Updated: 2023/08/30 14:03:11 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char *ft_strdup_newline(char *line)
{
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (ft_strlen(line) + 1));
    while(line[i] && line[i] != '\n')
    {
        str[i] = line[i];
        i++;
    }
    str[i] = '\0';
    return(str);
}

int is_digit(char *str)
{
    int i = 0;
    
    while(str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return(1);
        i++;
    }
    return(0);
}
