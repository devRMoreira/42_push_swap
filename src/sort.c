/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:13:28 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/06 14:08:06 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(int **arr)
{
	int	first;
	int	second;
	int	third;

	first = arr[0][0];
	second = arr[0][1];
	third = arr[0][2];
	if (first > second && second < third && first < third)
		swap(arr, 'a');
	else if (first > second && second > third)
	{
		swap(arr, 'a');
		reverse_rotate(arr, 3, 'a');
	}
	else if (first > second && second < third)
		rotate(arr, 'a');
	else if (first < second && second > third && first < third)
	{
		swap(arr, 'a');
		rotate(arr, 'a');
	}
	else if (first < second && second > third)
		reverse_rotate(arr, 3, 'a');
}

void	ft_get_pos(int **stack)
{
	int	min;
	int	i;
	int	j;

	i = 0;
	while (i < *stack[1])
	{
		min = 2147483647;
		j = 0;
		while (j < *stack[1])
		{
			if (stack[0][j] < min && stack[2][j] == -1)
				min = stack[0][j];
			j++;
		}
		j = 0;
		while (j < *stack[1])
		{
			if (stack[0][j] == min)
				stack[2][j] = i;
			j++;
		}
		i++;
	}
}

static int	check_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static void	radix(int **stack_a, int **stack_b)
{
	int	bit;
	int	i;
	int	size;

	bit = 0;
	while (check_sorted(stack_a[2], *stack_a[1]) && bit < 32)
	{
		i = 0;
		size = *stack_a[1];
		while (size)
		{
			if (*stack_a[2] >> bit & 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			size--;
		}
		while (*stack_b[1] > 0)
			push(stack_b, stack_a, 'a');
		bit++;
	}
}

int	ft_sort(int **stack_a)
{
	int	**stack_b;

	if (*stack_a[1] == 3)
		sort_three(stack_a);
	else
	{
		stack_b = malloc(sizeof(int *) * 3);
		stack_b[0] = malloc(sizeof(int) * *stack_a[1]);
		stack_b[1] = malloc(sizeof(int));
		stack_b[2] = malloc(sizeof(int) * *stack_a[1]);
		if (!stack_b || !stack_b[0] || !stack_b[1] || !stack_b[2])
			return (free_stack(stack_b), 0);
		*stack_b[1] = 0;
		ft_get_pos(stack_a);
		radix(stack_a, stack_b);
		free_stack(stack_b);
	}
	return (1);
}
