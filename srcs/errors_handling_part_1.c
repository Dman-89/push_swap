/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_part_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:01:55 by bsprigga          #+#    #+#             */
/*   Updated: 2019/03/08 17:59:03 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_non_numbers(int argc, char **argv)
{
	int i;

	while (--argc > -1)
	{
		i = -1;
		while (argv[argc][++i])
			if ((argv[argc][i] < '0' || argv[argc][i] > '9') &&
			argv[argc][i] != '-' && argv[argc][i] != '+')
				return (1);
	}
	return (0);
}

static int	check_non_integers(int argc, char **argv)
{
	long long nbr;

	while (--argc > -1)
	{
		if (ft_strlen(argv[argc]) > 11)
			return (1);
		nbr = ft_atoi_long(argv[argc]);
		if (nbr < -2147483648 || nbr > 2147483647)
			return (1);
	}
	return (0);
}

static int	check_duplicates(int argc, char **argv)
{
	int		i;

	while (--argc > -1)
	{
		i = argc;
		while (--i > -1)
			if (ft_strcmp(argv[argc], argv[i]) == 0)
				return (1);
	}
	return (0);
}

static int	check_errors(int argc, char **argv)
{
	if (check_non_numbers(argc, argv))
		return (1);
	if (check_correct_signs_and_numbers(argc, argv))
		return (1);
	if (check_non_integers(argc, argv))
		return (1);
	if (check_duplicates(argc, argv))
		return (1);
	return (0);
}

/*
**	92 line - reallocing argv to make data consistently malloc`ed
*/

void		errors_handling(int argc, char **argv, int push_swap_or_checker)
{
	if (check_errors(argc, argv))
	{
		ft_printf("Error\n");
		exit(0);
	}
	if (push_swap_or_checker == e_push_swap && check_sorted_argv(argc, argv))
		exit(0);
}
