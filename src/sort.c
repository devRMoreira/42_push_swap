/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:13:28 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/13 11:11:01 by rimagalh         ###   ########.fr       */
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
		reverse_rotate(arr, 'a');
	}
	else if (first > second && second < third)
		rotate(arr, 'a');
	else if (first < second && second > third && first < third)
	{
		swap(arr, 'a');
		rotate(arr, 'a');
	}
	else if (first < second && second > third)
		reverse_rotate(arr, 'a');
}

static void	sort_four_five(int **stack_a, int **stack_b)
{
	int	min;

	min = get_min(stack_a);
	rotate_min_top(stack_a, min, 'a');
	push(stack_a, stack_b, 'b');
	if (*stack_a[1] == 4)
	{
		min = get_min(stack_a);
		rotate_min_top(stack_a, min, 'a');
		push(stack_a, stack_b, 'b');
	}
	sort_three(stack_a);
	while (*stack_b[1] > 0)
		push(stack_b, stack_a, 'a');
}

static void	radix(int **stack_a, int **stack_b)
{
	int	bit;
	int	size;

	bit = 0;
	while (!check_sorted(stack_a[2], *stack_a[1]) && bit < 32)
	{
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

	stack_b = new_stack(*stack_a[1]);
	if (!stack_b || !stack_b[0] || !stack_b[1] || !stack_b[2])
		return (free_stack(stack_b), 0);
	*stack_b[1] = 0;
	if (!check_sorted(stack_a[0], *stack_a[1]))
	{
		if (*stack_a[1] == 2)
			swap(stack_a, 'a');
		else if (*stack_a[1] == 3)
			sort_three(stack_a);
		else if (*stack_a[1] == 4 || *stack_a[1] == 5)
			sort_four_five(stack_a, stack_b);
		else
		{
			get_pos(stack_a);
			radix(stack_a, stack_b);
		}
	}
	free_stack(stack_b);
	return (1);
}
