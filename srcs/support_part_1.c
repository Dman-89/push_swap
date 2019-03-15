/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_part_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:19:01 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/01 14:50:11 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			split_count_numbers(char **argv)
{
	int res;
	int i;

	res = 0;
	i = -1;
	while (argv[++i])
		res++;
	return (res);
}

static char	**realloc_argv(int argc, char **argv)
{
	int		i;
	char	**res;

	i = -1;
	if (!(res = (char **)malloc(sizeof(res) * argc + 1)))
		return (NULL);
	while (argv[++i])
	{
		if (!(res[i] = ft_strdup(argv[i])))
		{
			while (--i > -1)
				free(res[i]);
			free(res);
			return (NULL);
		}
	}
	return (res);
}

static void	get_average_bubble_main_loop(int **arr, int len)
{
	int		i;
	int		j;

	i = -1;
	while (++i < len - 1)
	{
		j = i;
		while (++j < len)
			if ((*arr)[i] > (*arr)[j])
				ft_swap(&((*arr)[i]), &((*arr)[j]));
	}
}

int			get_average_bubble(t_stack *stack)
{
	t_elem	*tmp_head;
	int		*arr;
	int		i;

	tmp_head = stack->head;
	if (!(arr = (int *)malloc(sizeof(int) * stack->len)))
		exit(0);
	i = -1;
	while (++i < stack->len)
	{
		arr[i] = stack->head->data;
		stack->head = stack->head->next;
	}
	get_average_bubble_main_loop(&arr, stack->len);
	stack->head = tmp_head;
	i = arr[(int)(stack->len * 0.5)];
	free(arr);
	return (i);
}

/*
**	here I get rid of first argv - name of program;
**	also getting rid of -v flag if it's presented in agrv
*/

void		split_argv(int *argc, char ***argv, int visualize)
{
	int start_index;

	start_index = (visualize == 1) ? 2 : 1;
	if ((start_index == 1 && *argc == 2) || (start_index == 2 && *argc == 3))
	{
		if (!(*argv = ft_strsplit((*argv)[start_index], ' ')))
			exit(0);
		*argc = split_count_numbers(*argv);
	}
	else
	{
		(*argv)++;
		(*argc)--;
		if (visualize)
		{
			(*argv)++;
			(*argc)--;
		}
		if (!(*argv = realloc_argv(*argc, *argv)))
			exit(0);
	}
}
