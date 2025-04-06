/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:58:18 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/06 13:39:26 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **str, int j)
{
	while (j--)
		free(str[j]);
	free(str);
}

static int	get_next_word(const char *s, char c, char a, int *i, char **word)
{
	int	len;
	int	start;

	start = *i;
	len = 0;
	while (s[*i] && s[*i] != c && s[*i] != a)
	{
		len++;
		(*i)++;
	}
	*i = start;
	*word = malloc(sizeof(char) * (len + 1));
	if (!(*word))
		return (-1);
	ft_strlcpy(*word, &s[*i], len + 1);
	*i += len;
	return (0);
}

static int	count_words(const char *s, char c, char a)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != a && s[i] != c && (i == 0 || s[i - 1] == c || s[i - 1] == a))
			count++;
		i++;
	}
	return (count);
}

static char	**process_split(const char *s, char c, char a, char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c || s[i] == a)
			i++;
		if (s[i])
		{
			if (get_next_word(s, c, a, &i, &str[j]) == -1)
				return (free_split(str, j), NULL);
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c, char a)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc((count_words(s, c, a) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	return (process_split(s, c, str));
}
