/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_part_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:54:09 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/01 14:41:35 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sorted_stack(t_stack *stack)
{
	int i;

	i = -1;
	while (++i < stack->len - 1)
		if (stack->head->data > stack->head->next->data)
			return (0);
	return (1);
}

void		sort_bubble(t_stack *from)
{
	t_stack	*to;
	int		i;
	int		j;
	int		len_from_ini;

	to = stack_setup(NULL, 0, from->len_ini, from->name == 'a' ? 'b' : 'a');
	i = -1;
	len_from_ini = from->len;
	while (++i < len_from_ini - 1)
	{
		j = i;
		while (++j < len_from_ini)
		{
			if (from->head->data > from->head->next->data)
				swap_elems(from);
			rotate_stack(from);
		}
		if (check_sorted_stack(from))
			break ;
	}
}

static void	merge_stacks_1_to_many(t_stack *bottom, t_stack *top)
{
	if (bottom->len == 1 && top->len > 1)
	{
		bottom->head->next = top->head;
		bottom->head->previous = top->head->previous;
		top->head->previous->next = bottom->head;
		top->head->previous = bottom->head;
	}
	else if (bottom->len > 1 && top->len == 1)
	{
		top->head->next = bottom->head;
		top->head->previous = bottom->head->previous;
		bottom->head->previous->next = top->head;
		bottom->head->previous = top->head;
	}
}

t_stack		*merge_stacks(t_stack *bottom, t_stack *top)
{
	t_elem	*tmp;

	top->len += bottom->len;
	if (bottom->len == 1 && top->len == 1)
	{
		top->head->next = bottom->head;
		top->head->previous = bottom->head;
		bottom->head->next = top->head;
		bottom->head->previous = top->head;
	}
	else if ((bottom->len == 1 && top->len > 1) ||
				(bottom->len > 1 && top->len == 1))
		merge_stacks_1_to_many(bottom, top);
	else
	{
		tmp = bottom->head->previous;
		bottom->head->previous->next = top->head;
		bottom->head->previous = top->head->previous;
		top->head->previous->next = bottom->head;
		top->head->previous = tmp;
	}
	free(bottom);
	return (top);
}
