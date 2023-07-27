/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:07:47 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/22 18:46:12 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	arrlen;
	int	i;
	int	j;

	i = min;
	j = 0;
	arrlen = max - min;
	arr = malloc(arrlen * sizeof(int));
	if (!arr || min >= max)
		return (NULL);
	while (i < max)
	{
		arr[j] = i;
		i++;
		j++;
	}
	return (arr);
}
