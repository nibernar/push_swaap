/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:38:36 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/15 19:59:33 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate(t_list **lst);

/**
 * @brief Shift down all elements of stack a by 1. The last element
 * becomes the first one.
 * 
 * @param lst_a The list has rotate.
 */
void	do_rra(t_list **lst_a)
{
	reverse_rotate(lst_a);
	ft_putstr_fd("rra\n", 1);
}

/**
 * @brief Shift down all elements of stack a by 1. The last element
 * becomes the first one.
 * 
 * @param lst_a The list has rotate.
 */
void	do_rrb(t_list **lst_b)
{
	reverse_rotate(lst_b);
	ft_putstr_fd("rrb\n", 1);
}

/**
 * @brief Shift down rra and rrb at the same time.
 * 
 * @param lst_a The list has rotate.
 * @param lst_b The list has rotate.
 */
void	do_rrr(t_list **lst_a, t_list **lst_b)
{
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
	ft_putstr_fd("rrr\n", 1);
}

static void	reverse_rotate(t_list **lst)
{
	t_list	*front;
	t_list	*back;
	t_list	*head;

	head = *lst;
	back = *lst;
	front = *lst;
	if (*lst == NULL)
		return ;
	while (front->next != NULL)
	{
		front = front->next;
		if (front->next != NULL)
			back = back->next;
	}
	if (front->next == NULL)
	{
		front->next = head;
		back->next = NULL;
	}
	*lst = front;
}