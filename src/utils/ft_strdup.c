/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:58:47 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/08/30 14:08:16 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!p)
		return (NULL );
	else
	{
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = '\0';
		return (p);
	}
}
