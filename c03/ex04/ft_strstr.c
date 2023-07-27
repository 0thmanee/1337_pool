/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:38:15 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/17 20:08:50 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (*(str + i))
	{	
		j = 0;
		while (*(to_find + j) && *(to_find + j) == *(str + i + j))
		{
			j++;
		}
		if (j == ft_strlen(to_find))
			return (str + i);
		i++;
	}
	return (0);
}
