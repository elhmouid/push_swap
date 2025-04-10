/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hmo <moel-hmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:44:33 by moel-hmo          #+#    #+#             */
/*   Updated: 2025/04/10 23:48:19 by moel-hmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(long value)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	add_back(t_list **stack, t_list *node)
{
	t_list	*tmp;

	if (!*stack)
	{
		*stack = node;
		return;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	parse_args(char *arg, t_list **stack)
{
	char	**split;
	int		i;
	long	value;
	t_list	*node;

	i = 0;
	split = ft_split(arg);
	if (!split || !stack)
		return;
	while (split[i])
	{
		value = ft_atoi(split[i]);
		node = new_node(value);
		if (!node)
		{
			while (split[i])
				free(split[i++]);
			free(split);
			return;
		}
		add_back(stack, node);
		free(split[i]);
		i++;
	}
	free(split);
}
