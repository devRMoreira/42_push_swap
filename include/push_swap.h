/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:34:02 by rimagalh          #+#    #+#             */
/*   Updated: 2024/12/19 16:05:28 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

int** parse_nums(char **input, int total);
int** parse_str(char *input);
int valid_input(char *str);
int validate_stack(int *arr, int size);
void ft_sort(int **arr, int size);
void free_arr(int** arr);

#endif
