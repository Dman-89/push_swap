/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_part_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:01:55 by bsprigga          #+#    #+#             */
/*   Updated: 2019/02/27 10:40:14 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_correct_signs_and_numbers(int argc, char **argv)
{
	int i;
	int	sign;

	while (--argc > -1)
	{
		sign = 0;
		i = 0;
		if ((argv[argc][0] == '-' || argv[argc][0] == '+'))
			sign = 1;
		while (argv[argc][++i])
			if ((argv[argc][i] == '-' || argv[argc][i] == '+'))
				return (1);
		if (ft_strlen(argv[argc]) == 1 && sign == 1)
			return (1);
	}
	return (0);
}
