/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vla_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:06:33 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/02 15:05:15 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvla.h"

/*
**	Pushes a value onto the end of the VLA.
**
**	@param {t_vla *} vla
**	@param {void *} elem - this element should have the size of elem_sz in the
**		t_vla struct.
**
**	@return {bool} - true if an allocation failed
*/

bool	vla_push(t_vla *vla, void *elem)
{
	if (vla->size >= vla->cap)
		if (vla_resize(vla))
			return (true);
	vla_memcpy(vla->vla + vla->elem_sz * vla->size, elem, vla->elem_sz);
	vla->size++;
	return (false);
}
