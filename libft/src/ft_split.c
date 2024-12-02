/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:58:12 by jopereir          #+#    #+#             */
/*   Updated: 2024/10/15 10:46:59 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Takes a string and a char and split in a string of strings

	ex: ()"Hello world", ' ')
	str[0] = "Hello"
	str[1] = "World"
*/
static char	*add_word(char const *str, int size)
{
	int		i;
	char	*_str;

	_str = malloc(sizeof(char) * size + 1);
	if (!_str)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		_str[i] = str[i];
		i++;
	}
	_str[i] = '\0';
	return (_str);
}

static int	is_char(char const chr, char c)
{
	return (chr == c);
}

static int	wordlen(char const*str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !is_char(str[i], c))
		i++;
	return (i);
}

static int	word_count(char const *str, char c)
{
	int	i;
	int	cnt;
	int	word_len;

	i = 0;
	cnt = 0;
	word_len = 0;
	while (str[i])
	{
		while (str[i] && is_char(str[i], c))
			i++;
		word_len = wordlen(str + i, c);
		if (word_len)
			cnt++;
		i += word_len;
		word_len = 0;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word_cnt;
	int		word_len;
	int		i;
	int		j;

	word_cnt = word_count(s, c);
	str = malloc(sizeof(char *) * (word_cnt + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	word_len = 0;
	while (s[i])
	{
		while (s[i] && is_char(s[i], c))
			i++;
		word_len = wordlen(s + i, c);
		if (word_len)
			str[j++] = add_word(s + i, word_len);
		i += word_len;
		word_len = 0;
	}
	str[j] = 0;
	return (str);
}
