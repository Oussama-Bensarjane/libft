/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:43:23 by obensarj          #+#    #+#             */
/*   Updated: 2024/11/11 17:04:12 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tm_src;
	unsigned char	*tm_dst;
	size_t			i;

	tm_src = (unsigned char *)src;
	tm_dst = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	if (tm_dst >= tm_src)
		while (len-- > 0)
			tm_dst[len] = tm_src[len];
	else
	{
		while (i < len)
		{
			tm_dst[i] = tm_src[i];
			i++;
		}
	}
	return (dst);
}
