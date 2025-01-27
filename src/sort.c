/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:13:28 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/27 17:39:52 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static int check_sorted(int *arr, int size)
{
	int i;

	i = 0;
	while(i < size - 1)
	{
		if(arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void sort_three(int *stack_a) {
    if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2] && stack_a[0] < stack_a[2])
	{
        swap(stack_a);
		ft_printf("sa\n");
	}
    else if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2])
    {
        swap(stack_a);
		ft_printf("sa\n");
        reverse_rotate(stack_a, 3);
		ft_printf("rra\n");
    }
    else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2])
	{
        rotate(stack_a, 3);
		ft_printf("ra\n");
	}
    else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2] && stack_a[0] < stack_a[2])
    {
        swap(stack_a);
		ft_printf("sa\n");
        rotate(stack_a, 3);
		ft_printf("ra\n");
    }
    else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2])
	{
        reverse_rotate(stack_a, 3);
		ft_printf("rra\n");
	}
}

static void	sort(int *stack_a, int size_a, int *stack_b, int size_b)
{
	int min;
	if(check_sorted(stack_a, size_a))
		return ;
	if (stack_a[0] > stack_a[1] && size_a == 2)
	{
		swap(stack_a);
		ft_printf("sa\n");
		return ;
	}
	while (size_a > 3) {
		min = get_min(stack_a, size_a);
		while(stack_a[0] != min)
		{
			rotate(stack_a, size_a);
        	ft_printf("ra\n");
		}
		push(stack_a, &size_a, stack_b, &size_b);
		ft_printf("pb\n");

	}
	sort_three(stack_a);
	while (size_b > 0) {
		push(stack_b, &size_b, stack_a, &size_a);
		ft_printf("pa\n");

	}
}



void ft_sort(int *stack_a, int size_a)
{
	int *stack_b;
	int size_b;

	stack_b = ft_calloc(size_a, sizeof(int));
	if(!stack_b)
		return ;
	size_b = 0;

	sort(stack_a, size_a, stack_b, size_b);
	free(stack_b);
}

