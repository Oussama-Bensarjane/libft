/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 01:27:30 by obensarj          #+#    #+#             */
/*   Updated: 2024/11/21 20:41:28 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	safe_malloc(char **new_str, int position, size_t len)
{
	int	i;

	i = 0;
	new_str[position] = malloc(len + 1);
	if (!new_str[position])
	{
		while (i < position)
		{
			free (new_str[i++]);
		}
		free (new_str);
		return (1);
	}
	return (0);
}

static int	fill(char **new_str, char const *s, char c)
{
	size_t	len_word;
	int		i;

	i = 0;
	while (*s)
	{
		len_word = 0;
		while (*s == c && *s)
			++s;
		while (*s != c && *s)
		{
			len_word++;
			s++;
		}
		if (len_word)
		{
			if (safe_malloc (new_str, i, len_word))
				return (1);
			ft_strlcpy(new_str[i], s - len_word, len_word + 1);
			i++;
		}
	}
	return (0);
}

static size_t	count_words(char const *s, char c)
{
	size_t	con_word;
	int		inside_word;

	con_word = 0;
	inside_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!inside_word)
			{
				con_word++;
				inside_word = 1;
			}
		}
		else
			inside_word = 0;
		s++;
	}
	return (con_word);
}

char	**ft_split(char const *s, char c)
{
	size_t	con_word;
	char	**new_str;

	if (!s)
		return (NULL);
	con_word = 0;
	con_word = count_words(s, c);
	new_str = malloc((con_word + 1) * sizeof(char *));
	if (!new_str)
		return (NULL);
	new_str[con_word] = 0;
	if (fill(new_str, s, c))
		return (NULL);
	return (new_str);
}
