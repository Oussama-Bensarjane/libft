/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:55:21 by obensarj          #+#    #+#             */
/*   Updated: 2024/11/21 15:05:55 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handle_lmax(unsigned long nbr, int sign, int count)
{
	if (nbr > 9223372036854775807 || count >= 20)
	{
		if (sign == 1)
			return (-1);
		else if (sign == -1)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long	nbr;
	int				sign;
	int				count;

	nbr = 0;
	sign = 1;
	count = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str++ - '0');
		if (nbr != 0 && !count)
			count = 1;
		if (count && ft_handle_lmax(nbr, sign, count++) != 1)
			return (ft_handle_lmax(nbr, sign, --count));
	}
	return (nbr * sign);
}
