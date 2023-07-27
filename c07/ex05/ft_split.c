/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:54:42 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/22 15:18:02 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_exist(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *s1, char *s2)
{
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	if (s1[0])
		counter++;
	while (s1[i])
	{
		if (!ft_exist(s1[i], s2) && ft_exist(s1[i - 1], s2))
			counter++;
		i++;
	}
	return (counter);
}

char	**ft_split(char *str, char *charset)
{
	char	**substrs;
	**substrs = malloc(ft_strlen(str, charset));
}
