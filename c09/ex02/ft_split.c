/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:49:34 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/26 10:34:17 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	ft_strslen(char *str, char *charset)
{
	int	is_new;
	int	counter;

	is_new = 1;
	counter = 0;
	while (*str)
	{
		if (!ft_exist(*str, charset) && is_new)
		{
			counter++;
			is_new = 0;
		}
		else if (ft_exist(*str, charset))
			is_new = 1;
		str++;
	}
	return (counter);
}

char	*ft_strcpy(char *src, char *charset)
{
	char	*dest;
	char	*temp;
	int		len;

	len = 0;
	temp = src;
	while (*temp && !ft_exist(*temp, charset))
	{
		len++;
		temp++;
	}
	dest = (char *)malloc(sizeof(*src) * len);
	temp = dest;
	while (*src && len > 0)
	{
		*temp = *src;
		temp++;
		src++;
		len--;
	}
	*temp = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	char	**strs2;
	int		is_new;

	strs = (char **)malloc(ft_strslen(str, charset) * sizeof(*strs) + 1);
	strs2 = strs;
	is_new = 1;
	while (*str)
	{
		if (!ft_exist(*str, charset) && is_new)
		{
			is_new = 0;
			*strs2 = ft_strcpy(str, charset);
			strs2++;
		}
		else if (ft_exist(*str, charset))
			is_new = 1;
		str++;
	}
	*strs2 = 0;
	return (strs);
}
