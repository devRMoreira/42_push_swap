/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:25:05 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/01 18:51:49 by rimagalh         ###   ########.fr       */
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

void rotate(int **arr, char c)
{
	int i;
	int size;
	int temp;
	int temp_id;

	size = *arr[1];
	if(size < 2)
		return ;
	i = 0;
	temp = arr[0][0];
	temp_id = arr[2][0];
	while(i < size - 1)
	{
		arr[0][i] = arr[0][i + 1];
		arr[2][i] = arr[2][i + 1];
		i++;
	}
	arr[0][size - 1] = temp;
	arr[2][size - 1] = temp_id;
	ft_printf("r%c\n", c);
}

void push(int **src, int **dest, char c)
{
	if(*src[1] <= 0)
		return ;
	int i = *dest[1];

	while(i > 0)
	{
		dest[0][i] = dest[0][i - 1];
		dest[2][i] = dest[2][i - 1];
		i--;
	}

	dest[0][0] = src[0][0];
	dest[2][0] = src[2][0];
	i = 0;
	while(i < *src[1] - 1)
	{
		src[0][i] = src[0][i + 1];
		src[2][i] = src[2][i + 1];
		i++;
	}
	(*src[1])--;
	(*dest[1])++;
	ft_printf("p%c\n", c);
}
