/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:09:20 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/15 19:58:04 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_list **lst_a);

/**
 * @brief Shift up all elements of stack a by 1. The first element becomes
the last one.
 * 
 * @param lst_a The list has rotate.
 */
void	do_ra(t_list **lst_a)
{
	rotate(lst_a);
	ft_putstr_fd("ra\n", 1);
}

/**
 * @brief Shift up all elements of stack a by 1. The first element becomes
the last one.
 * 
 * @param lst_b The list has rotate.
 */
void	do_rb(t_list **lst_b)
{
	rotate(lst_b);
	ft_putstr_fd("rb\n", 1);
}

/**
 * @brief rotate ra and rb at the same time.
 * 
 * @param lst_a The list has rotate.
 * @param lst_b The list has rotate.
 */
void	do_rr(t_list **lst_a, t_list **lst_b)
{
	rotate(lst_a);
	rotate(lst_b);
	ft_putstr_fd("rr\n", 1);
}

static void	rotate(t_list **lst_a)
{
	t_list	*tmp;
	int		first;
	long	d;

	tmp = *lst_a;
	first = tmp->content;
	d = tmp->index;
	if (!tmp || !tmp->next)
		return ;
	while (tmp->next != NULL)
	{
		tmp->content = tmp->next->content;
		tmp->index = tmp->next->index;
		tmp = tmp->next;
	}
	tmp->content = first;
	tmp->index = d;
}
