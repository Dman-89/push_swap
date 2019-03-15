/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_push_swap.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:02:31 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/01 14:40:46 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_elems(t_stack *stack)
{
	int tmp;

	if (stack->head && stack->head->next)
	{
		tmp = stack->head->data;
		stack->head->data = stack->head->next->data;
		stack->head->next->data = tmp;
		if (stack->name == 'a')
			ft_putstr("sa\n");
		else
			ft_putstr("sb\n");
	}
}

void	rotate_stack(t_stack *stack)
{
	if (stack->head && stack->head->next)
	{
		stack->head = stack->head->next;
		if (stack->name == 'a')
			ft_putstr("ra\n");
		else
			ft_putstr("rb\n");
	}
}

void	rev_rotate_stack(t_stack *stack)
{
	if (stack->head && stack->head->previous)
	{
		stack->head = stack->head->previous;
		if (stack->name == 'a')
			ft_putstr("rra\n");
		else
			ft_putstr("rrb\n");
	}
}

t_elem	*pop(t_stack *stack)
{
	t_elem *tmp;

	if (!(stack->head))
		return (NULL);
	tmp = stack->head;
	if ((stack->len -= 1) == 0)
		stack->head = NULL;
	else if (stack->len == 1)
	{
		stack->head->next->next = NULL;
		stack->head->next->previous = NULL;
		stack->head = stack->head->next;
	}
	else
	{
		stack->head->previous->next = stack->head->next;
		stack->head->next->previous = stack->head->previous;
		stack->head = stack->head->next;
	}
	tmp->next = NULL;
	tmp->previous = NULL;
	return (tmp);
}

void	push(t_elem *data, t_stack *to)
{
	if (!data)
		return ;
	if ((to->len += 1) == 1)
		to->head = data;
	else if (to->len == 2)
	{
		data->next = to->head;
		data->previous = to->head;
		to->head->next = data;
		to->head->previous = data;
		to->head = to->head->previous;
	}
	else
	{
		data->next = to->head;
		data->previous = to->head->previous;
		to->head->previous->next = data;
		to->head->previous = data;
		to->head = to->head->previous;
	}
	if (to->name == 'a')
		ft_putstr("pa\n");
	else
		ft_putstr("pb\n");
}
