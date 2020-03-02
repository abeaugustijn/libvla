/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:32:47 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/02 15:04:04 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libvla.h"

static void	test_simple()
{
	t_vla	vla;
	int		a;
	int		x;

	assert(!vla_init(sizeof(int), 1, &vla));
	assert(vla.cap == 1);
	assert(vla.size == 0);
	x = 3;
	vla_push(&vla, &x);
	assert(vla.cap == 1);
	assert(vla.size == 1);
	assert(((int*)vla.vla)[0] == 3);
	vla_get(vla, 0, &a);
	assert(a == 3);
	x = 4;
	vla_push(&vla, &x);
	assert(vla.cap == 2);
	assert(vla.size == 2);
	x = 4;
	vla_push(&vla, &x);
	assert(vla.cap == 4);
	assert(vla.size == 3);
	vla_shrink(&vla);
	assert(vla.size == 3);
	assert(vla.cap == 3);
}

int	main(void)
{
	test_simple();
}
