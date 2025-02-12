/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:34:02 by rimagalh          #+#    #+#             */
/*   Updated: 2025/02/12 20:14:06 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <limits.h>

int		**parse_nums(char **input, int total);
int		**parse_str(char *input);
int		**new_stack(int size);
int		valid_input(char *str);
int		validate_stack(int *arr, int size);
int		ft_sort(int **stack_a);
int		check_sorted(int *arr, int size);
void	get_pos(int **stack);
int		get_min(int **stack);
void	free_stack(int **arr);
void	rotate(int **arr, char c);
void	push(int **src, int **dest, char c);
void	swap(int **arr, char c);
void	reverse_rotate(int **arr, char c);
void	rotate_min_top(int **stack, int min, char c);

#endif
