/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:58:18 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/07 21:13:31 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **str, int j)
{
	while (j--)
		free(str[j]);
	free(str);
}

static int	count_words(const char *s)
{
	int	i = 0;
	int	count = 0;

	while (s[i])
	{
		if ((s[i] != ' ' && s[i] != '\t') &&
			(i == 0 || s[i - 1] == ' ' || s[i - 1] == '\t'))
			count++;
		i++;
	}
	return (count);
}

static int	get_next_word(const char *s, int *i, char **word)
{
	int	len = 0;
	int	start = *i;
	int	j = 0;

	while (s[*i] && s[*i] != ' ' && s[*i] != '\t')
	{
		len++;
		(*i)++;
	}
	*i = start;

	*word = malloc(sizeof(char) * (len + 1));
	if (!(*word))
		return (-1);

	while (j < len)
	{
		(*word)[j] = s[*i + j];
		j++;
	}
	(*word)[j] = '\0';
	*i += len;
	return (0);
}

static char	**process_split(const char *s, char **str)
{
	int	i = 0;
	int	j = 0;

	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if (s[i])
		{
			if (get_next_word(s, &i, &str[j]) == -1)
			{
				free_split(str, j);
				return (NULL);
			}
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(const char *s)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc((count_words(s) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	return (process_split(s, str));
}
