/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_part_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:54:09 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/01 14:41:17 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		count_iterations(t_stack *from, int selected)
{
	int		i;
	int		nr_iterations;
	t_elem	*tmp;

	i = from->len;
	nr_iterations = from->len;
	tmp = from->head->previous;
	while (i-- > 0)
	{
		if (from->name == 'a' && tmp->data < selected)
			break ;
		else if (from->name == 'b' && tmp->data > selected)
			break ;
		tmp = tmp->previous;
		nr_iterations--;
	}
	return (nr_iterations);
}

static t_stack	*sort_quick_less_4(t_stack *from,
void (*sort_rest_numbers)(t_stack *))
{
	if (from->name == 'a')
		sort_rest_numbers(from);
	else
		from = sort_rest_numbers_b_to_a(from);
	return (from);
}

static int		push_rotate_loop(t_stack *from, t_stack *to,
int nr_iterations, int selected)
{
	int	i;
	int	rev_rotation;

	rev_rotation = 0;
	i = -1;
	while (++i < nr_iterations)
	{
		if (from->name == 'a' && from->head->data < selected)
			push(pop(from), to);
		else if (from->name == 'b' && from->head->data > selected)
			push(pop(from), to);
		else
		{
			rotate_stack(from);
			rev_rotation++;
		}
	}
	return (rev_rotation);
}

static void		rev_rotation_assigning(t_stack *from)
{
	if (from->name == 'b')
		from->switched_to_b = 1;
	if (from->name == 'a' && !(from->switched_to_b))
		from->rev_rotate = 0;
	else if (from->name == 'b' && from->len > from->len_ini / 3)
		from->rev_rotate = 0;
	else
		from->rev_rotate = 1;
}

t_stack			*sort_quick(t_stack *from,
void (*sort_rest_numbers)(t_stack *))
{
	t_stack	*to;
	int		selected;
	int		rev_rotation;
	int		len_ini_iter;
	int		nr_iterations;

	len_ini_iter = from->len;
	rev_rotation_assigning(from);
	if (from->len < 4)
		return (sort_quick_less_4(from, sort_rest_numbers));
	to = stack_setup(NULL, 0, from->len_ini, from->name == 'a' ? 'b' : 'a');
	to->switched_to_b = (from->switched_to_b == 1) ? 1 : 0;
	selected = get_average_bubble(from);
	nr_iterations = count_iterations(from, selected);
	rev_rotation = push_rotate_loop(from, to, nr_iterations, selected);
	if (from->name == 'b' && len_ini_iter > from->len_ini / 3)
		from->len_ini = len_ini_iter;
	while (from->rev_rotate && rev_rotation--)
		rev_rotate_stack(from);
	if (from->name == 'a')
		return (merge_stacks(sort_quick(from, sort_rest_numbers),
		sort_quick(to, sort_rest_numbers)));
	else
		return (merge_stacks(sort_quick(to, sort_rest_numbers),
		sort_quick(from, sort_rest_numbers)));
}
