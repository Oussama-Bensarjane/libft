/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:29:57 by obensarj          #+#    #+#             */
/*   Updated: 2024/11/21 15:37:54 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*tmp;

	total_size = count * size;
	if (count != 0 && (total_size / count) != size)
		return (NULL);
	tmp = malloc(total_size);
	if (!tmp)
		return (NULL);
	ft_memset (tmp, 0, total_size);
	return (tmp);
}
