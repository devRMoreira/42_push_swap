/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:59:31 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/27 16:58:39 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(int *arr)
{
	int temp;

	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;

}

void rotate(int *arr, int size)
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
}

void reverse_rotate(int *arr, int size)
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
}

void push(int *src, int *src_size, int *dest, int *dest_size)
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
}

int get_min(int *arr, int size)
{
	int i;
	int res;

	res = arr[0];
	i = 1;
	while(i < size)
	{
		if(arr[i] < res)
			res = arr[i];
		i++;
	}
	return (res);
}


