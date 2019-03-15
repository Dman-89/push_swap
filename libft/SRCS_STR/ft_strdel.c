/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:21:23 by bsprigga          #+#    #+#             */
/*   Updated: 2018/12/14 15:30:32 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strdel(char **as)
{
	char *tmp;

	tmp = *as;
	if (!as || !*as)
		return ;
	while (**as)
	{
		**as = '\0';
		*as += 1;
	}
	free(tmp);
	*as = NULL;
}
