/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:59:53 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/09 12:35:46 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_elem
{
	int				data;
	struct s_elem	*previous;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_stack
{
	char			name;
	int				len;
	int				len_ini;
	int				rev_rotate;
	int				switched_to_b;
	t_elem			*head;
}					t_stack;

typedef struct		s_print
{
	int				sp_a_rt;
	int				sp_b_rt;
	int				sp_a_lt;
	int				sp_b_lt;
}					t_print;

enum	e_trigger	{e_push_swap, e_checker};

int					split_count_numbers(char **argv);
void				stack_filling(t_stack **a, int argc, char **argv);
int					get_data(t_stack *stack, int index);
int					check_sorted_argv(int argc, char **argv);
void				swap_elems(t_stack *stack);
void				rotate_stack(t_stack *stack);
void				rev_rotate_stack(t_stack *stack);
t_elem				*pop(t_stack *stack);
void				push(t_elem *data, t_stack *to);
void				free_stack(t_stack *stack, int len);
void				free_argv(int argc, char **argv);
t_stack				*stack_setup(t_elem *head, int len, int len_ini, char name);
int					get_average_bubble(t_stack *stack);
void				sort_bubble(t_stack *from);
t_stack				*merge_stacks(t_stack *bottom, t_stack *top);
void				sort_rest_numbers_less_7(t_stack *stack);
void				sort_rest_numbers_general(t_stack *stack);
t_stack				*sort_rest_numbers_b_to_a(t_stack *b);
t_stack				*sort_quick(t_stack *from,
					void (*sort_rest_numbers)(t_stack *));
int					check_correct_signs_and_numbers(int argc, char **argv);
void				swap_elems_checker(t_stack *stack, int visualize);
void				rotate_stack_checker(t_stack *stack, int visualize);
void				rev_rotate_stack_checker(t_stack *stack, int visualize);
void				push_checker(t_elem *data, t_stack *to, int visualize);
void				split_argv(int *argc, char ***argv, int visualize);
void				check_flag_v(int argc, char **argv, int *visualize);
void				print_stacks(t_stack *a, t_stack *b);
void				errors_handling(int argc, char **argv,
					int push_swap_or_checker);
void				swap_elems_ss_checker(t_stack *a, t_stack *b,
					int visualize);
void				rotate_stack_rr_checker(t_stack *a, t_stack *b,
					int visualize);
void				rev_rotate_stack_rrr_checker(t_stack *a, t_stack *b,
					int visualize);

#endif
