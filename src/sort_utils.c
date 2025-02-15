/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:32:23 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/13 11:10:59 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_min(int **stack)
{
	int	min;
	int	i;

	min = stack[0][0];
	i = 0;
	while (i < *stack[1])
	{
		if (stack[0][i] < min)
			min = stack[0][i];
		i++;
	}
	return (min);
}

void	rotate_min_top(int **stack, int min, char c)
{
	int	i;
	int	size;

	size = *stack[1];
	i = -1;
	while (++i < size)
		if (stack[0][i] == min)
			break ;
	if (i < size / 2)
		while (stack[0][0] != min)
			rotate(stack, c);
	else
		while (stack[0][0] != min)
			reverse_rotate(stack, c);
}

void	get_pos(int **stack)
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
