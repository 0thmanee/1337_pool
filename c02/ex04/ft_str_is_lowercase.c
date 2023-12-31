/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:51:32 by obouchta          #+#    #+#             */
/*   Updated: 2023/07/16 11:51:38 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
	{
		return (1);
	}
	while (*str)
	{
		if (!(*str >= 97 && *str <= 122))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
