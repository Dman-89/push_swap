/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operations_checker_part_2.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:02:31 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/08 18:33:42 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_elems_ss_checker(t_stack *a, t_stack *b, int visualize)
{
	swap_elems_checker(a, 0);
	swap_elems_checker(b, 0);
	if (visualize)
		ft_printf("              {yellow}ss{def} \n");
}

void	rotate_stack_rr_checker(t_stack *a, t_stack *b, int visualize)
{
	rotate_stack_checker(a, 0);
	rotate_stack_checker(b, 0);
	if (visualize)
		ft_printf("              {yellow}rr{def} \n");
}

void	rev_rotate_stack_rrr_checker(t_stack *a, t_stack *b, int visualize)
{
	rev_rotate_stack_checker(a, 0);
	rev_rotate_stack_checker(b, 0);
	if (visualize)
		ft_printf("              {yellow}rrr{def} \n");
}
