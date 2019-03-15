/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:47:00 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/08 18:00:34 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*launch_sorting(t_stack *a)
{
	if (a->len < 7)
		a = sort_quick(a, &sort_rest_numbers_less_7);
	else
		a = sort_quick(a, &sort_rest_numbers_general);
	return (a);
}

int				main(int argc, char **argv)
{
	t_stack		*a;

	split_argv(&argc, &argv, 0);
	errors_handling(argc, argv, e_push_swap);
	stack_filling(&a, argc, argv);
	a = launch_sorting(a);
	free_stack(a, argc);
	free_argv(argc, argv);
	return (0);
}
