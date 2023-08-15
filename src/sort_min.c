/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:21:59 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/15 18:07:15 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Sorting data on a stack, with 3 numbers.
 * 
 * @param lst_a The list has sorting.
 */ 
void	sort_min(t_list **lst_a)
{
	t_list	*tmp;

	tmp = *lst_a;
	if (tmp->content < tmp->next->content \
		&& tmp->content < tmp->next->next->content)
	{
		do_sa(lst_a);
		do_ra(lst_a);
	}
	else if (tmp->content < tmp->next->content \
		&& tmp->content > tmp->next->next->content)
		do_rra(lst_a);
	else if (tmp->content > tmp->next->content \
		&& tmp->content > tmp->next->next->content)
	{
		if (tmp->next->content > tmp->next->next->content)
		{
			do_ra(lst_a);
			do_sa(lst_a);
		}
		else if (tmp->next->content < tmp->next->next->content)
			do_ra(lst_a);
	}
	else
		do_sa(lst_a);
}
