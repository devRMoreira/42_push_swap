/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:25:05 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/29 14:23:52 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(int *arr, char c)
{
	int temp;

	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	ft_printf("s%c\n", c);
}

void rotate(int *arr, int size, char c)
{
	int temp;
	int i;

	if(size < 2)
		return ;
	temp = arr[0];
	i = 0;
	while(i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[size - 1] = temp;
	ft_printf("r%c\n", c);
}

void reverse_rotate(int *arr, int size, char c)
{
	int temp;
	int i;

	if(size < 2)
		return ;
	temp = arr[size - 1];
	i = size - 1;
	while(i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = temp;
	ft_printf("rr%c\n", c);
}

void push(int *src, int *src_size, int *dest, int *dest_size, char c)
{
	if(*src_size <= 0)
		return ;
	int i = *dest_size;

	while(i > 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}

	dest[0] = src[0];
	i = 0;
	while(i < *src_size - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	(*src_size)--;
	(*dest_size)++;
	ft_printf("p%c\n", c);
}
