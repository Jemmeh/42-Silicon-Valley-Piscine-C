/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 14:08:02 by akali             #+#    #+#             */
/*   Updated: 2018/08/12 21:57:36 by jcope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush_2.h"

char	*create_char_string(t_list *list)
{
	int		i;
	char	*str;
	int		list_length;

	if (!list)
		return (NULL);
	str = NULL;
	i = 0;
	list_length = list_size(list);
	str = (char *)malloc(sizeof(char) * (list_length + 1));
	while (i < list_length)
	{
		str[i] = list->data;
		list = list->next;
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_list	*list_create_elem(char c)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	node->data = c;
	node->next = NULL;
	return (node);
}

void	list_insert_element(t_list **list, char c)
{
	t_list *node;

	if (list && *list)
	{
		node = *list;
		while (node->next)
			node = node->next;
		node->next = list_create_elem(c);
	}
	else
	{
		*list = list_create_elem(c);
	}
}

t_list	*get_input(void)
{
	t_list	*list;
	char	buffer;

	list = NULL;
	while (read(0, &buffer, 1) > 0)
		list_insert_element(&list, buffer);
	return (list);
}

int		main(void)
{
	t_list	*in;
	char	*compare;

	in = get_input();
	compare = create_char_string(in);
	find_rush_combos(compare);
	write(1, "\n", 1);
	return (0);
}
