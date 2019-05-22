/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_freearray.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 10:44:29 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/09 10:44:59 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freearray(char **array)
{
	size_t i;

	i = 0;
	if (array != NULL)
	{
		while (array[i] != NULL)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}
