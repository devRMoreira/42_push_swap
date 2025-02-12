/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:02:42 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/12 20:08:32 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(int **stack, char *name)
{
    int i;
    printf("%s: ", name);
    for (i = 0; i < *stack[1]; i++)
    {
        printf("%d ", stack[0][i]);
    }
    printf("\n");
}

int	main(int argc, char **argv)
{
	int	**stack;
	int res;

	if (argc == 2)
	{
		stack = parse_str(argv[1]);
		if (stack == NULL)
			return (ft_printf("Error \n"), 1);
	}
	else
	{
		stack = parse_nums(argv, argc - 1);
		if (stack == NULL)
			return (ft_printf("Error \n"), 1);
	}
	res = ft_sort(stack);
	if(!res)
		return(ft_printf("Error \n"), free_stack(stack), 1);
	free_stack(stack);
	return (0);
}
