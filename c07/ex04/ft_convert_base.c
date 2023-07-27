/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:13:45 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/23 11:13:55 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"ft_convert_base2.c"

int	ft_result_size(int nbr, char *base)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strinfos('a', base, 1);
	while (nbr > 0)
	{
		nbr /= len;
		i++;
	}
	return (++i);
}

void	ft_convert_to_base(int nbr, char **str, char *base_to)
{
	int	len;

	len = ft_strinfos('a', base_to, 1);
	if (nbr >= len)
	{
		ft_convert_to_base(nbr / len, str, base_to);
	}
	**str = base_to[nbr % len];
	(*str)++;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decim;
	char	*str;
	char	*str2;
	int		result_size;
	int		sign;

	if (!ft_isvalid(base_from) || !ft_isvalid(base_to))
		return (NULL);
	decim = ft_base_to_deci(nbr, base_from);
	sign = 1;
	result_size = ft_result_size(decim, base_to);
	str = malloc(result_size + 2);
	str2 = str;
	if (!str)
		return (NULL);
	if (decim < 0)
	{
		*str = '-';
		str++;
		decim = -decim;
	}
	ft_convert_to_base(decim, &str, base_to);
	*str = '\0';
	return (str2);
}
