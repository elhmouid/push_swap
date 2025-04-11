/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:58:18 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/11 22:22:28 by moel-hmo         ###   ########.fr       */
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
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != ' ' && s[i] != '\t')
			&& (i == 0 || s[i - 1] == ' ' || s[i - 1] == '\t'))
			count++;
		i++;
	}
	return (count);
}

static int	get_next_word(const char *s, int *i, char **word)
{
	int	len;
	int	start;
	int	j;

	len = 0;
	j = 0;
	start = *i;
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
	int	i;
	int	j;

	i = 0;
	j = 0;
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
