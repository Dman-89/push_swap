/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_v_and_printing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:59:08 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/08 18:04:31 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			check_flag_v(int argc, char **argv, int *visualize)
{
	if (argc > 1 && ft_strequ(argv[1], "-v"))
		*visualize = 1;
}

static void		print_stacks_a_b(t_stack *a, t_stack *b, int *i)
{
	int		sp_lt;
	int		sp_rt;
	char	*data_str;

	*i = a->len;
	while ((*i)-- > b->len)
	{
		data_str = ft_itoa(a->head->data);
		sp_rt = (13 - ft_strlen(data_str)) / 2;
		sp_lt = sp_rt;
		if (a->name == 'a')
			ft_printf("%*c{green}%i{def}%*c\n", sp_lt, ' ',
			a->head->data, sp_rt, ' ');
		else
			ft_printf("%*c{blue}%i{def}%*c\n", 13 + 5 + sp_lt, ' ',
			a->head->data, sp_rt, ' ');
		a->head = a->head->next;
		free(data_str);
	}
}

static t_print *make_print_struct(t_stack *a, t_stack *b, char *data_a_str,
			char *data_b_str)
{
	t_print *tmp;
	int		spaces_a;
	int		spaces_b;
	int a_data;
	int b_data;

	a_data = a->head->data;
	b_data = b->head->data;

	spaces_a = (13 - ft_strlen(data_a_str)) / 2;
	spaces_b = (13 - ft_strlen(data_b_str)) / 2;
	if (!(tmp = (t_print *)malloc(sizeof(t_print))))
		exit(0);
	tmp->sp_a_lt = spaces_a;
	tmp->sp_a_rt = spaces_a;
	tmp->sp_b_lt = spaces_b;
	tmp->sp_b_rt = spaces_b;
	return (tmp);
}

static void		print_stacks_main_loop(t_stack *a, t_stack *b, int *i)
{
	char	*data_a_str;
	char	*data_b_str;
	t_print *pr_struct;

	while ((*i)-- >= 0)
	{
		data_a_str = ft_itoa(a->head->data);
		data_b_str = ft_itoa(b->head->data);
		pr_struct = make_print_struct(a, b, data_a_str, data_b_str);
		ft_printf("%*c{green}%i{def}%*c", pr_struct->sp_a_lt,
		' ', a->head->data, 13 - pr_struct->sp_a_rt - ft_strlen(data_a_str), ' ');
		ft_printf("%*c{blue}%i{def}%*c\n", 5 + pr_struct->sp_b_lt,
		' ', b->head->data, pr_struct->sp_b_rt, ' ');
		a->head = a->head->next;
		b->head = b->head->next;
		free(data_a_str);
		free(data_b_str);
	}
}

void		print_stacks(t_stack *a, t_stack *b)
{
	t_elem	*tmp_a;
	t_elem	*tmp_b;
	int		i;

	tmp_a = a->head;
	tmp_b = b->head;
	i = 0;
	if (a->len >= b->len)
		print_stacks_a_b(a, b, &i);
	else if (b->len > a->len)
		print_stacks_a_b(b, a, &i);
	print_stacks_main_loop(a, b, &i);
	a->head = tmp_a;
	b->head = tmp_b;
	ft_printf("=============     =============\n");
	ft_printf("      {cyan}a                 b{def}     \n");
	ft_printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
}
