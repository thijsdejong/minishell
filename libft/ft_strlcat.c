/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:36:32 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/10 14:44:11 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	dlen = ft_min(size, ft_strlen(dst));
	slen = ft_strlen(src);
	if (dlen == size)
	{
		return (size + slen);
	}
	if (slen < size - dlen)
	{
		ft_strncat(dst, src, slen);
	}
	else
	{
		ft_strncat(dst, src, size - dlen - 1);
		dst[size - 1] = '\0';
	}
	return (dlen + slen);
}
