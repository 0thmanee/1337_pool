/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:55:45 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/17 09:19:01 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*(str + i) += 32;
		i++;
	}
	return (str);
}
