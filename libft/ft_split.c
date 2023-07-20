/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:39:52 by mumontei          #+#    #+#             */
/*   Updated: 2023/07/19 18:40:05 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	i;
	size_t	num_words;

	num_words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			num_words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (num_words);
}

static size_t	len_word(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_arr;
	int		num_words;
	int		i;
	int		len;

	if (!s)
		return (0);
	num_words = word_count(s, c);
	arr_arr = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!arr_arr)
		return (0);
	i = 0;
	while (i < num_words)
	{
		while (*s == c)
			s++;
		len = len_word(s, c);
		arr_arr[i] = ft_substr(s, 0, len);
		s = s + len;
		i++;
	}
	arr_arr[i] = NULL;
	return (arr_arr);
}