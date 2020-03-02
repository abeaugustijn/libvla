/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vla_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:56:31 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/02 14:48:39 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvla.h"
#include <stdlib.h>

/*
**	Initializes a new VLA. Allocates the initial size for the array and sets up
**	the initial values for the struct.
**
**	@param {size_t} elem_sz - the size of one element of the array, in bytes
**	@param {size_t} init_cap - the amount of elements that can be stored
**		initially.
**	@param {t_vla *} result - pointer to store the vla
**
**	@return {bool} - true if allocation failed
*/

bool	vla_init(size_t elem_sz, size_t init_cap, t_vla *result)
{
	result->elem_sz = elem_sz;
	result->cap = init_cap;
	result->size = 0;
	result->vla = malloc(elem_sz * init_cap);
	if (!result->vla)
		return (true);
	return (false);
}
