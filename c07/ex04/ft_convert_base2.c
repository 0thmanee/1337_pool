/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:14:23 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/23 11:14:32 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int		g_converted;

int	ft_strinfos(char c, char *str, int x)
{
	int	i;

	if (!x)
	{
		if (c == '\f' || c == '\n' || c == ' ')
			return (1);
		if (c == '\t' || c == '\v' || c == '\r')
			return (1);
		return (0);
	}
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
		return (i);
	}
}

int	ft_isvalid(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strinfos('a', str, 1) < 2)
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
	{
		return (nb * ft_power(nb, power - 1));
	}
}

int	ft_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_base_to_deci(char *nbr, char *base_from)
{
	int		i;
	int		j;
	int		sign;
	int		index;
	int		curr;

	i = 0;
	sign = 1;
	while (ft_strinfos(nbr[i], "", 0))
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	g_converted = 0;
	index = -1;
	j = ft_strinfos('a', nbr, 1);
	while (--j >= i)
	{
		curr = ft_in_base(base_from, nbr[j]);
		g_converted += curr * ft_power(ft_strinfos('a', base_from, 1), ++index);
	}
	return (g_converted * sign);
}
