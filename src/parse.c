/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:17:28 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/27 14:20:23 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	**parse_str(char *input)
{
	char	**split_input;
	int		**arr;
	int		i;

	i = 0;
	split_input = ft_split(input, ' ');
	if (!split_input)
		return (NULL);
	while (split_input[i])
		i++;
	arr = malloc(sizeof(int *) * 2);
	arr[0] = malloc(sizeof(int) * i);
	arr[1] = malloc(sizeof(int));
	*arr[1] = i;
	if (!arr || !arr[0] || !arr[1])
		return (free_split(split_input), free_arr(arr), NULL);
	i--;
	while (i >= 0)
	{
		if (valid_input(split_input[i]))
			return (free_split(split_input), free_arr(arr), NULL);
		arr[0][i] = ft_atoi(split_input[i]);
		i--;
	}
	free_split(split_input);
	if (validate_stack(arr[0], *arr[1]))
		return (free_arr(arr), NULL);
	return (arr);
}

int	**parse_nums(char **input, int total)
{
	int	i;
	int	**arr;

	i = 0;
	arr = malloc(sizeof(int *) * 2);
	arr[0] = malloc(sizeof(int) * (total));
	arr[1] = malloc(sizeof(int));
	*arr[1] = total;
	if (!arr || !arr[0] || !arr[1])
		return (free_arr(arr), NULL);
	while (i < *arr[1])
	{
		if (valid_input(input[i + 1]))
			return (free_arr(arr), NULL);
		arr[0][i] = ft_atoi(input[i + 1]);
		i++;
	}
	if (validate_stack(arr[0], *arr[1]))
		return (free_arr(arr), NULL);
	return (arr);
}
