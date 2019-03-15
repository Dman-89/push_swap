/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_checker.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:02:31 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/08 15:55:24 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_elems_checker(t_stack *stack, int visualize)
{
	int tmp;

	if (stack->head && stack->head->next)
	{
		tmp = stack->head->data;
		stack->head->data = stack->head->next->data;
		stack->head->next->data = tmp;
		if (visualize)
		{
			if (stack->name == 'a')
				ft_printf("              {yellow}sa{def} \n");
			else
				ft_printf("              {yellow}sb{def} \n");
		}
	}
}

void		rotate_stack_checker(t_stack *stack, int visualize)
{
	if (stack->head && stack->head->next)
	{
		stack->head = stack->head->next;
		if (visualize)
		{
			if (stack->name == 'a')
				ft_printf("              {yellow}ra{def} \n");
			else
				ft_printf("              {yellow}rb{def} \n");
		}
	}
}

void		rev_rotate_stack_checker(t_stack *stack, int visualize)
{
	if (stack->head && stack->head->previous)
	{
		stack->head = stack->head->previous;
		if (visualize)
		{
			if (stack->name == 'a')
				ft_printf("              {yellow}rra{def}\n");
			else
				ft_printf("              {yellow}rrb{def}\n");
		}
	}
}

static void	push_checker_print(t_stack *to)
{
	if (to->name == 'a')
		ft_printf("              {yellow}pa{def} \n");
	else
		ft_printf("              {yellow}pb{def} \n");
}

void		push_checker(t_elem *data, t_stack *to, int visualize)
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
	if (visualize)
		push_checker_print(to);
}
