/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:55:42 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/15 19:57:43 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_list *lst);

/**
 * @brief Swap the first 2 elements at the top of stack a. Do nothing if there
 * is only one or no elements.
 * 
 * @param lst_a The list has swap.
 */
void	do_sa(t_list **lst_a)
{
	swap(*lst_a);
	ft_putstr_fd("sa\n", 1);
}

/**
 * @brief Swap the first 2 elements at the top of stack b. Do nothing if there
 *is only one or no elements.
 * 
 * @param lst_b The list has swap.
 */
void	do_sb(t_list **lst_b)
{
	swap(*lst_b);
	ft_putstr_fd("sb\n", 1);
}

/**
 * @brief Swap sa and sb at the same time.
 * 
 * @param lst_a The list has swap.
 * @param lst_b The list has swap.
 */
void	do_ss(t_list **lst_a, t_list **lst_b)
{
	swap(*lst_a);
	swap(*lst_b);
	ft_putstr_fd("ss\n", 1);
}

static void	swap(t_list *lst)
{
	int		tmp;
	long	tmp2;

	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
	tmp2 = lst->index;
	lst->index = lst->next->index;
	lst->next->index = tmp2;
}
