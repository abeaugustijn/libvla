/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vla_get_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:39:08 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/03 08:30:35 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvla.h"

/*
**	Get the index of an element in the vla from it's address.
**
**	@param {t_vla} vla
**	@param {void *} elem
**	@param {bool *} result - false if failed
**
**	@return {void *} - NULL if failed
*/

size_t	vla_get_index(t_vla vla, void *elem, bool *result)
{
	size_t	index;

	if (elem < vla.vla)
	{
		if (result)
			*result = false;
		return (0);
	}
	index = (elem - vla.vla) / vla.elem_sz;
	if (index >= vla.size)
	{
		if (result)
			*result = false;
		return (0);
	}
	if (result)
		*result = true;
	return (index);
}
