/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vla_memcpy.c                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 19:45:39 by abe            #+#    #+#                */
/*   Updated: 2020/03/02 14:46:56 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvla.h"
#include <stddef.h>

#ifndef FAST

static bool	check_null(void *dst, const void *src)
{
	return (dst == NULL && src == NULL);
}

#else

static bool	check_null(void *dst, const void *src)
{
	(void)dst;
	(void)src;
	return (false);
}

#endif

/*
**	Copy n bytes from stc to dst. The behaviour is undefined if src and
**	dst overlap or if one of both is NULL. Use memmove for safe copying of
**	overlapping sections of memory. Returns dst. If dst or src are NULL,
**	NULL is returned.
*/

void	*vla_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_cpy;

	if (check_null(dst, src))
		return (NULL);
	dst_cpy = dst;
	while (n > 0)
	{
		*dst_cpy = *((unsigned char *)src);
		dst_cpy++;
		src++;
		n--;
	}
	return (dst);
}
