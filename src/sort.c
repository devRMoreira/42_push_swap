/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:13:28 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/29 18:48:52 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"


static int check_sorted(int *arr, int size)
{
    int i;
	i = 0;
    while (i < size - 1)
    {
        if (arr[i] > arr[i + 1])
            return 0;
        i++;
    }
    return 1;
}

int find_ind(int *arr, int num, int size)
{
	int i;

	i = 0;
	while(i <= size)
	{
		if(arr[i] == num)
			return (i);
		i++;
	}

	return (-1);
}

static void sort_copy(int *arr, int size)
{
	int i;
	int temp;

	i = 0;
	while(i < size - 1)
	{
		if(arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int *copy_stack(int *arr, int size)
{
	int *temp;
	temp = ft_calloc(size, sizeof(int));
	if(!temp)
		return (NULL);
	ft_memcpy(temp, arr, size * sizeof(int));

	sort_copy(temp, size);
	return(temp);
}

int *create_empty_stack(int size)
{
	int *new;

	new = ft_calloc(size, sizeof(int));
	if(!new)
		return NULL;
	return (new);
}

int find_max_bits(int num)
{
	int bits;

	bits = 0;
	while((num >> bits) != 0)
		bits++;
	return(bits);
}

void print_stack(int *stack, int size, char *name) {
    printf("%s: ", name);
    for (int i = 0; i < size; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void radix(int *stack_a, int *size_a, int *stack_b, int *copy)
{
	int max_num;
	int max_bits;
	int i;
	int j;
	int num;
	int size_b;

	size_b = 0;
	max_num = copy[*size_a - 1];
	max_bits = find_max_bits(max_num);
	i = 0;
	while(i < max_bits)
	{
		j = 0;
		while(j < *size_a)
		{
			num = find_ind(copy, stack_a[0], *size_a);
			if(num == -1)
			{
				j++;
				continue ;
			}
			if(((num >> i) & 1) == 1)
				rotate(stack_a, *size_a, 97);
			else
				push(stack_a, size_a, stack_b, &size_b, 98);
			j++;
		}
		while(size_b > 0)
			push(stack_b, &size_b, stack_a, size_a, 97);
		i++;
	}
}

int ft_sort(int *stack_a, int size_a)
{
	int *copy;
	int *stack_b;
	copy = copy_stack(stack_a, size_a);
	if(!copy)
		return (0);

	stack_b = create_empty_stack(size_a);
	if(!stack_b)
	{
		free(copy);
		return (0);
	}

	if(!check_sorted(stack_a, size_a))
		radix(stack_a, &size_a, stack_b, copy);

    free(stack_b);
    free(copy);
	return (1);
}


// ! old might be useful
// static int check_sorted(int *arr, int size)
// {
//     int i;

// 	i = 0;
//     while (i < size - 1)
//     {
//         if (arr[i] > arr[i + 1])
//             return 0;
//         i++;
//     }
//     return 1;
// }

// static void sort_three(int *arr)
// {
// 	int first;
// 	int second;
// 	int third;

// 	first = arr[0];
// 	second = arr[1];
// 	third = arr[2];
// 	if(first > second && second < third && first < third)
// 		swap(arr, 97);
// 	else if (first > second && first > third)
// 	{
// 		swap(arr, 97);
// 		reverse_rotate(arr, 3, 97);
// 	}
// 	else if (first > second && second < third)
// 		rotate(arr, 3, 97);
// 	else if (first < second && second > third && first < third)
// 	{
// 		swap(arr, 97);
// 		rotate(arr, 3, 97);
// 	}
// 	else if (first < second && second > third)
// 		reverse_rotate(arr, 3, 97);
// }
