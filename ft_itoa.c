/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:59:04 by obensarj          #+#    #+#             */
/*   Updated: 2024/11/21 16:55:55 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;
	int 	negative;

	nbr = n;
	len = int_len(nbr);
	negative = 0;
	result = malloc((len + 1));
	if (!result)
		return (NULL);
	if (nbr < 0)
	{
		negative = 1;
		nbr = -nbr;
	}
	i = len - 1;
	while (i >= 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (negative)
		result[0] = '-';
	result[len] = 0;
	return (result);
}
