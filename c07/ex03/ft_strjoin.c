/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:44:30 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/22 12:58:01 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	strrlen(char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
		i++;
	return (i);
}

int	ft_strslen(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			counter++;
			j++;
		}
		if (i != size - 1)
			counter += strrlen(sep);
		i++;
	}
	return (counter);
}

void	ft_fillstr(char **strs, char *str, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = -1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
		{
			str[++k] = strs[i][j];
		}
		j = -1;
		if (i != size - 1)
		{
			while (sep[++j])
			{
				str[++k] = sep[j];
			}
		}
	}
	str[++k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;

	str = malloc(ft_strslen(size, strs, sep) + 1);
	ft_fillstr(strs, str, sep, size);
	return (str);
}
