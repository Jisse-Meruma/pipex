/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:05:51 by jmeruma           #+#    #+#             */
/*   Updated: 2022/12/08 14:15:43 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	word_count(char const *s, char c, int len_s1)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (i < len_s1)
	{
		while (s[i] == c && i < len_s1)
			i++;
		if (i == len_s1)
			return (word);
		word++;
		while (s[i] != c && i < len_s1)
			i++;
	}
	return (word);
}

static int	substring_len(char const *s, char c, int len_s1, int i)
{
	int	len;

	len = 0;
	while (s[i] == c && i < len_s1)
		i++;
	while (s[i] != c && i < len_s1)
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free(char **ptr, int words)
{
	while (words >= 0)
	{
		free(ptr[words]);
		words--;
	}
	free(ptr);
}

static int	split_creation(char const *s, char c, char **ptr, int w_count)
{
	int	len_s1;
	int	len;
	int	words;
	int	i;

	words = 0;
	i = 0;
	len_s1 = ft_strlen(s);
	while (words < w_count)
	{
		while (s[i] == c && i < len_s1)
			i++;
		len = substring_len(s, c, len_s1, i);
		ptr[words] = ft_substr(s, i, len);
		if (!ptr[words])
			return (ft_free(ptr, words), 1);
		words++;
		while (s[i] != c && i < len_s1)
			i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		len_s1;
	int		w_count;
	char	**ptr;

	len_s1 = ft_strlen(s);
	w_count = word_count(s, c, len_s1);
	ptr = (char **)ft_calloc(w_count + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	if (split_creation(s, c, ptr, w_count) == 1)
		return (NULL);
	return (ptr);
}
