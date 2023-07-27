/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:20:28 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/19 16:08:38 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	is_alpha(char c)
{
	if (!(c >= 'A' && c <= 'Z') && (c >= 'a' && c <= 'z'))
		return (0);
	return (1);
}

int	ft_baselen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isvalid(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_baselen(str) < 2)
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

void	ft_display(long nbr, char *base)
{
	if (nbr < ft_baselen(base))
		write(1, &base[nbr % ft_baselen(base)], 1);
	else
	{
		ft_display(nbr / ft_baselen(base), base);
		write(1, &base[nbr % ft_baselen(base)], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nnbr;

	nnbr = nbr;
	if (!ft_isvalid(base))
		return ;
	if (nnbr < 0)
	{
		write(1, "-", 1);
		nnbr = -nnbr;
	}
	ft_display(nnbr, base);
}
