/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:46:22 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/19 23:39:24 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	pow;
	int	i;

	pow = 1;
	i = 1;
	if (power < 0)
		return (0);
	while (i <= power)
	{
		pow *= nb;
		i++;
	}
	return (pow);
}
