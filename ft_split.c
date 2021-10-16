/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 05:38:59 by fabet             #+#    #+#             */
/*   Updated: 2021/10/16 07:17:18 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordscount(char *str, char c)
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

static void	ft_addword(char **array, size_t wnum, char **str, size_t wordlen)
{
	size_t	chnum;

	chnum = 0;
	while (wordlen > 0)
	{
		array[wnum][chnum] = **str;
		(*str)++;
		chnum++;
		wordlen--;
	}
	array[wnum][chnum] = '\0';
}

static char	**ft_freearray(char **array)
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

static char	**ft_fillarray(char **array, char c, char *str, char *strend)
{
	size_t	wnum;
	char	*temp;
	size_t	wordlen;
	size_t	wordscount;

	wnum = 0;
	wordscount = ft_wordscount(str, c);
	while (wordscount > wnum)
	{
		while (*str == c)
			str++;
		temp = str;
		while (*temp != c && temp < strend)
			temp++;
		wordlen = temp - str;
		array[wnum] = (char *)malloc(sizeof(char) * (wordlen + 1));
		if (array[wnum] == NULL)
			return (ft_freearray(array));
		ft_addword(array, wnum, &str, wordlen);
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
	array = (char **)malloc(sizeof(char *) * (ft_wordscount(str, c) + 1));
	if (array == NULL)
	{
		free(str);
		return (NULL);
	}
	array = ft_fillarray(array, c, str, str + ft_strlen(str));
	free(str);
	return (array);
}
