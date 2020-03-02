/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vla_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:39:08 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/02 14:49:06 by aaugusti         ###   ########.fr       */
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
**	Set a value in a vla.
**
**	@param {t_vla} vla
**	@param {size_t} index
**	@param {void *} new_value - a pointer to the value to store in the vla
**
**	@return {bool} - true if the set failed
*/

bool	vla_set(t_vla vla, size_t index, void *new_value)
{
	if (check_index(vla, index))
		return (true);
	vla_memcpy(vla.vla + vla.elem_sz * index, new_value, vla.elem_sz);
	return (false);
}
