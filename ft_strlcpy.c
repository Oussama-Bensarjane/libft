/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:59:38 by obensarj          #+#    #+#             */
/*   Updated: 2024/11/21 21:53:57 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	k;

	k = 0;
	if (dstsize)
	{
		while (src[k] && k < dstsize - 1)
		{
			dst[k] = src[k];
			k++;
		}
		dst[k] = '\0';
	}
	return (ft_strlen(src));
}
