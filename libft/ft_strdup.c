/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 09:47:37 by tde-jong       #+#    #+#                */
/*   Updated: 2019/03/26 12:08:45 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;

	len = ft_strlen(s1);
	str = (char *)ft_memalloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	return (str);
}
