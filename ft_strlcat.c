/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:47:59 by obensarj          #+#    #+#             */
/*   Updated: 2024/11/21 21:47:08 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	if (dstsize == 0 || dst == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (dstsize + src_len);
	if (dstsize > dst_len + 1)
	{
		while (src[i] && dst_len + 1 + i < dstsize)
		{
			dst[i + dst_len] = src[i];
			i++;
		}
	}
	dst[i + dst_len] = '\0';
	return (dst_len + src_len);
}
