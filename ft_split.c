/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 05:38:59 by fabet             #+#    #+#             */
/*   Updated: 2021/10/15 21:50:01 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordscount(char *str, char c)
{
	size_t	result;

	result = 1;
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
}

static char	**ft_fillarray(char **array, char c, char *str, char *strend)
{
	size_t	wnum;
	char	*temp;
	size_t	wordlen;
	size_t	wordscount;
	int		i;

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
		array[wnum] = (char *)malloc(sizeof(char) * wordlen);
		if (array[wnum] == NULL)
		{
			i = 0;
			while(array[i])
			{
				free(array[i]);
				i++;
			}
			free(array);
			return (NULL);
		}
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
	size_t	wordscount;
	char	*strend;

	if (s == NULL)
		return (NULL);
	set = (char *)malloc(sizeof(char));
	if (set == NULL)
		return (NULL);
	*set = c;
	str = ft_strtrim(s, set);
	free(set);
	if (ft_strlen(str) == 0)
	{
		free(str);
		array = (char **)malloc(sizeof(char *));
		array[0] = NULL;
		return (array);
	}
	strend = str + ft_strlen(str);
	wordscount = ft_wordscount(str, c);
	array = (char **)malloc(sizeof(char *) * (wordscount + 1));
	if (array == NULL)
	{
		free(str);
		return (NULL);
	}
	array = ft_fillarray(array, c, str, strend);
	free(str);
	return (array);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char	**tab;
// 	char	*splitme;
// 	splitme = ft_strdup("--1-2--3---4----5-----42");
// 	tab = ft_split(splitme, '-');
// 	printf("%s\n", tab[0]);
// 	printf("%d\n", strcmp(tab[0], "1"));
// 	printf("%s\n", tab[1]);
// 	printf("%d\n", strcmp(tab[1], "2"));
// 	printf("%s\n", tab[2]);
// 	printf("%s\n", tab[3]);
// 	printf("%s\n", tab[4]);
// 	printf("%s\n", tab[5]);
// 	return (0);
// }
