/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:34:02 by rimagalh          #+#    #+#             */
/*   Updated: 2025/01/29 17:57:36 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <limits.h>

int** parse_nums(char **input, int total);
int** parse_str(char *input);
int valid_input(char *str);
int validate_stack(int *arr, int size);
int ft_sort(int *stack_a, int size_a);
void free_arr(int** arr);
void rotate(int *arr, int size, char c);
void push(int *src, int *src_size, int *dest, int *dest_size, char c);
void reverse_rotate(int *arr, int size, char c);
void swap(int *arr, char c);
void print_array(int *arr, int size);
int *copy_stack(int *arr, int size);
int find_max_bits(int num);
int find_ind(int *arr, int num, int size);

#endif
