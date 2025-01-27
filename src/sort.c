/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:13:28 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/27 14:17:17 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_sort(int *stack_a, int size_a)
{
	int *stack_b;
	int size_b;
	ft_printf("size_A %d \n", size_a);
	stack_b = ft_calloc(size_a, sizeof(int));
	if(!stack_b)
		return ;
	size_b = 0;
	(void) size_b;
	(void) stack_a;


	free(stack_b);
}
