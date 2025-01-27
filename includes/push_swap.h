/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:34:02 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/27 16:58:52 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"

int** parse_nums(char **input, int total);
int** parse_str(char *input);
int valid_input(char *str);
int validate_stack(int *arr, int size);
void ft_sort(int *stack_a, int size_a);
void free_arr(int** arr);
void rotate(int *arr, int size);
void push(int *src, int *src_size, int *dest, int *dest_size);
int get_min(int *arr, int size);
void reverse_rotate(int *arr, int size);
void swap(int *arr);

#endif
