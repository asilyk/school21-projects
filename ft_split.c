/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 05:38:59 by fabet             #+#    #+#             */
/*   Updated: 2021/10/16 11:33:12 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_words_count(char *str, char c)
{
	size_t	result;

	result = 1;
	if (ft_strlen(str) == 0)
		return (0);
	while (*str)
	{
		if ((*str == c) && (*(str + 1) != c))
			result++;
		str++;
	}
	return (result);
}

static void	ft_add_word(char **array, size_t wnum, char **str, size_t word_len)
{
	size_t	chnum;

	chnum = 0;
	while (word_len > 0)
	{
		array[wnum][chnum] = **str;
		(*str)++;
		chnum++;
		word_len--;
	}
	array[wnum][chnum] = '\0';
}

static char	**ft_free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (array);
}

static char	**ft_fill_array(char **array, char c, char *str, char *str_end)
{
	size_t	wnum;
	char	*temp;
	size_t	word_len;
	size_t	words_count;

	wnum = 0;
	words_count = ft_words_count(str, c);
	while (words_count > wnum)
	{
		while (*str == c)
			str++;
		temp = str;
		while (*temp != c && temp < str_end)
			temp++;
		word_len = temp - str;
		array[wnum] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (array[wnum] == NULL)
			return (ft_free_array(array));
		ft_add_word(array, wnum, &str, word_len);
		wnum++;
	}
	array[wnum] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*str;
	char	*set;

	if (s == NULL)
		return (NULL);
	set = (char *)malloc(sizeof(char));
	if (set == NULL)
		return (NULL);
	*set = c;
	str = ft_strtrim(s, set);
	free(set);
	array = (char **)malloc(sizeof(char *) * (ft_words_count(str, c) + 1));
	if (array == NULL)
	{
		free(str);
		return (NULL);
	}
	array = ft_fill_array(array, c, str, str + ft_strlen(str));
	free(str);
	return (array);
}
