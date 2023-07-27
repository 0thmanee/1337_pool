/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 23:11:37 by yboutsli          #+#    #+#             */
/*   Updated: 2023/07/23 15:32:29 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	g_index;
int	g_baselen;

int	basecheck(char *base)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}	
		if (base[i] == ' ' || base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	char_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
		i++;
	if (!base[i])
		return (-1);
	return (i);
}

int	ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == ' '
		|| c == '\t' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int	sign(char *str, int *i)
{
	int	signe;

	signe = 1;
	while (str[*i] && (str[*i] == '-' || str[*i] == '+'))
	{
		if (str[*i] == '-')
			signe *= -1;
		(*i)++;
	}
	return (signe);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	signe;
	int	res;

	res = 0;
	g_baselen = basecheck(base);
	if (g_baselen == 0)
		return (0);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	signe = (sign(str, &i));
	while (str[i])
	{
		g_index = char_in_base(str[i], base);
		if (g_index == -1 || g_index >= g_baselen)
			return (0);
		res = (res * g_baselen) + g_index;
		i++;
	}
	return (res * signe);
}
