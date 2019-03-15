/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_part_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:54:09 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/01 14:41:50 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_rest_numbers_less_7_b_more_3(t_stack *s)
{
	if (s->head->data > s->head->next->data && s->head->data >
	s->head->previous->data && s->head->next->data < s->head->previous->data)
		rotate_stack(s);
	else if (s->head->data > s->head->next->data &&
	s->head->data < s->head->previous->data)
		rev_rotate_stack(s);
	else if (s->head->data < s->head->next->data &&
	s->head->data > s->head->previous->data)
		swap_elems(s);
	else if (s->head->data < s->head->next->data &&
	s->head->data < s->head->previous->data)
	{
		if (s->head->next->data > s->head->previous->data)
			rotate_stack(s);
		else
		{
			rotate_stack(s);
			swap_elems(s);
		}
	}
}

static void	sort_rest_numbers_less_7_a_more_3(t_stack *s)
{
	if (s->head->data > s->head->next->data &&
	s->head->data > s->head->previous->data)
	{
		if (s->head->next->data > s->head->previous->data)
		{
			swap_elems(s);
			rev_rotate_stack(s);
		}
		else
			rotate_stack(s);
	}
	else if (s->head->data > s->head->next->data &&
	s->head->data < s->head->previous->data)
		swap_elems(s);
	else if (s->head->data < s->head->next->data &&
	s->head->data > s->head->previous->data)
		rev_rotate_stack(s);
	else if (s->head->data < s->head->next->data &&
	s->head->data < s->head->previous->data &&
	s->head->next->data > s->head->previous->data)
	{
		rev_rotate_stack(s);
		swap_elems(s);
	}
}

void		sort_rest_numbers_less_7(t_stack *s)
{
	if (s->name == 'a' && s->len == 2 && s->head->data > s->head->next->data)
		swap_elems(s);
	else if (s->name == 'b' && s->len == 2 &&
				s->head->data < s->head->next->data)
		swap_elems(s);
	else if (s->name == 'b' && s->len == 3)
		sort_rest_numbers_less_7_b_more_3(s);
	else if (s->name == 'a' && s->len == 3)
		sort_rest_numbers_less_7_a_more_3(s);
}

static void	sort_rest_numbers_general_b_more_3(t_stack *s)
{
	if (s->head->data < s->head->next->data)
		swap_elems(s);
	if (s->head->next->data < s->head->next->next->data)
	{
		rotate_stack(s);
		swap_elems(s);
		rev_rotate_stack(s);
	}
	if (s->head->data < s->head->next->data)
		swap_elems(s);
}

void		sort_rest_numbers_general(t_stack *s)
{
	if (s->name == 'a' && s->len == 2 &&
	s->head->data > s->head->next->data)
		swap_elems(s);
	else if (s->name == 'b' && s->len == 2 &&
	s->head->data < s->head->next->data)
		swap_elems(s);
	else if (s->name == 'a' && s->len == 3)
	{
		if (s->head->data > s->head->next->data)
			swap_elems(s);
		if (s->head->next->data > s->head->next->next->data)
		{
			rotate_stack(s);
			swap_elems(s);
			rev_rotate_stack(s);
		}
		if (s->head->data > s->head->next->data)
			swap_elems(s);
	}
	else if (s->name == 'b' && s->len == 3)
		sort_rest_numbers_general_b_more_3(s);
}
