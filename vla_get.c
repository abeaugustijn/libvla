/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vla_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:39:08 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/02 14:48:26 by aaugusti         ###   ########.fr       */
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
**	Get a value from a vla.
**
**	@param {t_vla} vla
**	@param {size_t} index
**	@param {void *} result
**
**	@return {bool} - true if the get failed
*/

bool	vla_get(t_vla vla, size_t index, void *result)
{
	if (check_index(vla, index))
		return (true);
	vla_memcpy(result, vla.vla + vla.elem_sz * index, vla.elem_sz);
	return (false);
}
