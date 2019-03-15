/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:47:04 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/08 19:38:36 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_stack_a_b(t_stack *a, t_stack *b, char *line, int visualize)
{
	if (ft_strequ(line, "pa"))
		push_checker(pop(b), a, visualize);
	else if (ft_strequ(line, "ra"))
		rotate_stack_checker(a, visualize);
	else if (ft_strequ(line, "rra"))
		rev_rotate_stack_checker(a, visualize);
	else if (ft_strequ(line, "sa"))
		swap_elems_checker(a, visualize);
	else if (ft_strequ(line, "pb"))
		push_checker(pop(a), b, visualize);
	else if (ft_strequ(line, "rb"))
		rotate_stack_checker(b, visualize);
	else if (ft_strequ(line, "rrb"))
		rev_rotate_stack_checker(b, visualize);
	else if (ft_strequ(line, "sb"))
		swap_elems_checker(b, visualize);
	else if (ft_strequ(line, "ss"))
		swap_elems_ss_checker(a, b, visualize);
	else if (ft_strequ(line, "rr"))
		rotate_stack_rr_checker(a, b, visualize);
	else if (ft_strequ(line, "rrr"))
		rev_rotate_stack_rrr_checker(a, b, visualize);
	else
		return (-1);
	return (0);
}

static void	sort_stack(t_stack *a, int argc, int visualize)
{
	t_stack	*b;
	char	*line;

	if (!(b = stack_setup(NULL, 0, argc, 'b')))
		exit(0);
	line = NULL;
	if (visualize)
		print_stacks(a, b);
	while (get_next_line(0, &line))
	{
		if (sort_stack_a_b(a, b, line, visualize) == -1)
		{
			ft_putstr("Error\n");
			exit(0);
		}
		if (visualize)
			print_stacks(a, b);
		free(line);
	}
	free(line);
	free_stack(b, b->len);
}

static int	check_sorted_list(t_stack *a, int argc)
{
	int		i;
	t_elem	*tmp;

	i = -1;
	tmp = a->head;
	if (!(a->head) || a->len < argc)
		return (0);
	while (++i < argc - 1)
	{
		if (a->head->data > a->head->next->data)
			return (0);
		a->head = a->head->next;
	}
	a->head = tmp;
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack		*a;
	int			res;
	int			visualize;

	if (argc == 1)
		return (0);
	visualize = 0;
	check_flag_v(argc, argv, &visualize);
	split_argv(&argc, &argv, visualize);
	errors_handling(argc, argv, e_checker);
	stack_filling(&a, argc, argv);
	sort_stack(a, argc, visualize);
	res = check_sorted_list(a, argc);
	if (res == 1)
		ft_putstr("OK\n");
	else if (res == 0)
		ft_putstr("KO\n");
	free_stack(a, a->len);
	free_argv(argc, argv);
	return (0);
}
