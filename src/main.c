/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:02:42 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/25 16:12:33 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	int **arr;

	if(argc == 2)
	{
		arr = parse_str(argv[1]);
		if(arr == NULL)
		{
			write(1,"Error\n",6);
			return (1);
		}

	} else {
		arr = parse_nums(argv, argc);
		if(arr == NULL)
		{
			write(1,"Error\n",6);
			return (1);
		}
	}
	ft_sort(arr[0], *arr[1]);

	free_arr(arr);
	return (0);
}
