/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:58:37 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/16 15:11:14 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	is_lower(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	is_numeric(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_special(char c)
{
	if (!is_lower(c) && !is_numeric(c) && !(c >= 65 && c <= 90))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (is_lower(*str))
	{
		*str = *str - 32;
	}
	i = 1;
	while (*(str + i))
	{
		if (!is_special(*(str + i)) && !is_numeric(*(str + i)))
		{
			if (!is_lower(*(str + i)))
				*(str + i) = *(str + i) + 32;
			if (is_special(*(str + i - 1)))
				*(str + i) = *(str + i) - 32;
		}
		i++;
	}
	return (str);
}
