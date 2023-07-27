/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:47:46 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/19 15:41:08 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == ' ')
		return (1);
	if (c == '\t' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int	ft_isnumeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_skip(char *str, int *i, int *sign)
{
	while (ft_isspace(str[*i]))
		(*i)++;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	numb;
	int	multi_done;

	i = 0;
	sign = 1;
	numb = 0;
	multi_done = 0;
	ft_skip(str, &i, &sign);
	while (ft_isnumeric(str[i]) && str[i])
	{
		numb = ((numb * 10) + (str[i] - 48));
		i++;
	}
	return (sign * numb);
}
