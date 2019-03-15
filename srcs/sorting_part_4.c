/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_part_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:54:09 by bsprigga          #+#    #+#             */
/*   Updated: 2019/02/26 15:34:25 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2_values(t_stack *b, t_stack *a)
{
	if (b->head->data < b->head->next->data)
		swap_elems(b);
	push(pop(b), a);
	push(pop(b), a);
}

static void	sort_rest_numbers_b_to_a_lower_lower(t_stack *b, t_stack *a)
{
	if (b->head->data > b->head->previous->data)
	{
		push(pop(b), a);
		swap_elems(a);
		push(pop(b), a);
		swap_elems(a);
	}
	else
	{
		swap_elems(b);
		push(pop(b), a);
		swap_elems(a);
		push(pop(b), a);
		swap_elems(a);
	}
}

static void	sort_rest_numbers_b_to_a_higher_lower(t_stack *b, t_stack *a)
{
	swap_elems(b);
	push(pop(b), a);
	swap_elems(a);
	push(pop(b), a);
}

static void	sort_rest_numbers_b_to_a_lower_higher(t_stack *b, t_stack *a)
{
	push(pop(b), a);
	swap_elems(a);
	push(pop(b), a);
}

t_stack		*sort_rest_numbers_b_to_a(t_stack *b)
{
	t_stack *a;
	t_elem	*b_1;

	a = stack_setup(NULL, 0, b->len_ini, 'a');
	if (b->len == 2)
		sort_2_values(b, a);
	else if (b->len == 3)
	{
		b_1 = b->head;
		push(pop(b), a);
		if (b_1->data > b->head->data && b_1->data > b->head->previous->data)
			sort_2_values(b, a);
		else if (b_1->data > b->head->data &&
		b_1->data < b->head->previous->data)
			sort_rest_numbers_b_to_a_higher_lower(b, a);
		else if (b_1->data < b->head->data &&
		b_1->data > b->head->previous->data)
			sort_rest_numbers_b_to_a_lower_higher(b, a);
		else if (b_1->data < b->head->data &&
		b_1->data < b->head->previous->data)
			sort_rest_numbers_b_to_a_lower_lower(b, a);
	}
	free(b);
	b = a;
	return (b);
}
