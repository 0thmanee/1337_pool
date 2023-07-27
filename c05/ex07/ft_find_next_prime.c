/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:39:09 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/20 01:30:20 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(long nnb)
{
	int	i;

	i = 2;
	if (nnb <= 1)
		return (0);
	while (i < nnb)
	{
		if (!(nnb % i))
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	long nnb = nb;
	if (nnb <= 2)
		return (2);
	while (ft_is_prime(nnb) == 0)
		nnb++;
	return (nnb);
}
#include<stdio.h>
int main(void)
{
	printf("%d", ft_find_next_prime(65147483648));
}
