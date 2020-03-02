/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vla_get_addr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:39:08 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/02 18:42:22 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvla.h"

#ifndef FAST

static bool	check_index(t_vla vla, size_t index)
{
	return (index >= vla.size);
}

#else

static bool	check_index(t_vla vla, size_t index)
{
	return (false);
}

#endif

/*
**	Get the address of an element in the VLA.
**
**	@param {t_vla} vla
**	@param {size_t} index
**	@param {void **} result
**
**	@return {bool} - true if the get failed
*/

bool	vla_get_addr(t_vla vla, size_t index, void **result)
{
	if (check_index(vla, index))
		return (true);
	*result = vla.vla + vla.elem_sz * index;
	return (false);
}
