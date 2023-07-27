/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:52:41 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/14 23:27:50 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *b;
	*b = *a;
	*a = c;
}

int	ft_check_order(int a, int b)
{
	if (a > b)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_check_order(*(tab + i), *(tab + j)))
			{
				ft_swap(tab + i, tab + j);
			}
			j++;
		}
		i++;
	}
}
