/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:02:42 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/03 16:45:25 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		res = ft_sort(arr);
	if(!res)
		ft_printf("Error\n");
	free_stack(arr);
	return (0);
}
