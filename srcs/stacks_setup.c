/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:35:33 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/01 14:42:16 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*stack_setup(t_elem *head, int len, int len_ini, char name)
{
	t_stack *tmp;

	if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
		exit(0);
	tmp->len = len;
	tmp->len_ini = len_ini;
	tmp->head = head;
	tmp->name = name;
	tmp->rev_rotate = 1;
	tmp->switched_to_b = 0;
	return (tmp);
}

static t_elem	*new_elem(int data)
{
	t_elem *tmp;

	if (!(tmp = (t_elem *)malloc(sizeof(t_elem))))
		exit(0);
	tmp->data = data;
	tmp->next = NULL;
	tmp->previous = NULL;
	return (tmp);
}

void			stack_filling(t_stack **a, int argc, char **argv)
{
	int		i;
	t_elem	*head_cp;

	*a = stack_setup(new_elem(ft_atoi(argv[0])), argc, argc, 'a');
	head_cp = (*a)->head;
	i = 0;
	while (++i < argc)
	{
		if (!((*a)->head->next = new_elem(ft_atoi(argv[i]))))
			exit(0);
		(*a)->head = (*a)->head->next;
	}
	(*a)->head->next = head_cp;
	(*a)->head = (*a)->head->next;
	while (i-- > 0)
	{
		(*a)->head->next->previous = (*a)->head;
		(*a)->head = (*a)->head->next;
	}
}
