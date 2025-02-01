/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:13:28 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/01 19:22:10 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

void ft_get_pos(int **stack)
{
	int max;
	int i;
	int j;

	i = 0;
	while(i < *stack[1])
	{
		max = 2147483647;
		j = 0;
		while(j < *stack[1])
		{
			if(stack[0][j] < max && stack[2][j] == -1)
				max = stack[0][j];
			j++;
		}
		j = 0;
		while(j < *stack[1])
		{
			if(stack[0][j] == max)
				stack[2][j] = i;
			j++;
		}
		i++;
	}
}

static int check_sorted(int *arr, int size)
{
    int i;

	if(arr[0])
	{
		i = 0;
		while (i < size - 1)
		{
			if(arr[i] > arr[i + 1])
				return (1);
			i++;
		}
	}
    return (0);
}

void radix(int **stack_a, int **stack_b)
{
	int bits;
	int i;

	bits = -1;
	while (check_sorted(stack_a[2], *stack_a[1]) && ++bits < 32)
	{
		i = 0;
		while(i < *stack_a[1])
		{
			if((stack_a[2][0] >> bits) & 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			i++;
		}
		i = 0;
		while(i < *stack_b[1])
		{
			push(stack_b, stack_a, 'a');
			i++;
		}
	}
}

int ft_sort(int **stack_a)
{
	int **stack_b;

	stack_b = malloc(sizeof(int *) * 3);
	stack_b[0] = malloc(sizeof(int) * *stack_a[1]);
	stack_b[1] = malloc(sizeof(int));
	stack_b[2] = malloc(sizeof(int) * *stack_a[1]);

	if (!stack_b || !stack_b[0] || !stack_b[1] || !stack_b[2])
		return(free_stack(stack_b), 0);
	*stack_b[1] = 0;


	ft_get_pos(stack_a);
	print_array(stack_a[0], *stack_a[1]);
	print_array(stack_a[2], *stack_a[1]);
	radix(stack_a, stack_b);
	print_array(stack_a[0], *stack_a[1]);
	print_array(stack_a[2], *stack_a[1]);

    free_stack(stack_b);
	return (1);
}
