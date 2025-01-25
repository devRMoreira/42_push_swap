/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:31:03 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/25 16:09:19 by rimagalh         ###   ########.fr       */
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
	size_t	len = ft_strlen(str);

	if(len > 11)
		return (1);

	if(str[0] == '-')
	{
		if(len == 11 && ft_strncmp(str, min, 11) > 0)
			return (1);
	}
	else
	{
		if(str[0] == '+')
			str++;

		len = ft_strlen(str);
		if(len == 10 && ft_strncmp(str, max, 10) > 0)
			return (1);

	}

	return (0);
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
		if(arr[0])
			free(arr[0]);
		if(arr[1])
			free(arr[1]);
		free(arr);
	}
}

