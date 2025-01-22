/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:31:03 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/22 15:39:30 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int check_dupe(int *arr, int size, int i)
{
	int j;

	j = i + 1;
	while(j < size)
	{
		if(arr[j] == arr[i])
			return 1;
		j++;
	}

	return (0);
}

static int check_size(char *str)
{
	char* max = "2147483647";
	char* min = "-2147483648";

	if(ft_strncmp(str, max, ft_strlen(str)) >= 0)
		return 1;
	if(ft_strncmp(str, min, ft_strlen(str)) >= 0)
		return 1;
	return 0;
}
int validate_stack(int *arr, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if(check_dupe(arr, size, i))
			return 1;
		i++;
	}
	return (0);
}

int valid_input(char *str)
{
	int i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;

	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	if(check_size(str))
		return (1);
	return (0);
}

void free_arr(int** arr)
{
	if(arr)
	{
		free(arr[0]);
		free(arr[1]);
		free(arr);
	}
}

