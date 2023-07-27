/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:39:31 by yboutsli          #+#    #+#             */
/*   Updated: 2023/07/24 14:39:46 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	lendest;
	unsigned int	lensrc ;

	lendest = str_len(dest);
	lensrc = str_len(src);
	if (size <= lendest)
		return (lensrc + size);
	j = 0;
	i = lendest;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (lendest + lensrc);
}
