/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:23:03 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/12 13:57:12 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push(t_list **source, t_list **target);

/**
 * @brief Take the first element at the top of b and put it at the top of a. Do
 *nothing if b is empty.
 * 
 * @param lst_a The list has push.
 * @param lst_b The list has push.
 */
void	do_pb(t_list **lst_a, t_list **lst_b)
{
	push(lst_a, lst_b);
	ft_putstr_fd("pb\n", 1);
}

/**
 * @brief Take the first element at the top of a and put it at the top of b. Do
 *nothing if a is empty.
 * 
 * @param lst_a The list has push.
 * @param lst_b The list has push.
 */
void	do_pa(t_list **lst_a, t_list **lst_b)
{
	push(lst_b, lst_a);
	ft_putstr_fd("pa\n", 1);
}

static void	push(t_list **source, t_list **target)
{
	t_list	*tmp;
	t_list	*element;

	if (!*source)
		return ;
	element = (*source)->next;
	tmp = *source;
	tmp->next = *target;
	*target = tmp;
	*source = element;
}
