/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_part_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:19:01 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/08 19:10:26 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sorted_argv(int argc, char **argv)
{
	int i;

	if (argc < 2)
		return (1);
	i = 1;
	while (i < argc && ft_atoi(argv[i]) > ft_atoi(argv[i - 1]))
		i++;
	if (i == argc)
		return (1);
	return (0);
}

void	free_stack(t_stack *stack, int len)
{
	int		i;
	t_elem	*tmp;

	i = -1;
	while (stack->head && ++i < len)
	{
		tmp = stack->head->next;
		free(stack->head);
		stack->head = NULL;
		stack->head = tmp;
	}
	free(stack);
}

void	free_argv(int argc, char **argv)
{
	int		i;

	i = -1;
	while (++i < argc)
		free(argv[i]);
	free(argv);
}
