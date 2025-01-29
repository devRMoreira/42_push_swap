/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:02:42 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/29 17:35:54 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int	main(int argc, char **argv)
{
	int	**arr;
	int res;

	if (argc == 2)
	{
		arr = parse_str(argv[1]);
		if (arr == NULL)
		{
			ft_printf("Error\n");
			return (1);
		}
	}
	else
	{
		arr = parse_nums(argv, argc - 1);
		if (arr == NULL)
		{
			ft_printf("Error\n");
			return (1);
		}
	}
	if(*arr[1] > 1)
		res = ft_sort(arr[0], *arr[1]);
	if(!res)
		ft_printf("Error\n");
	print_array(arr[0], *arr[1]);
	free_arr(arr);
	return (0);
}
