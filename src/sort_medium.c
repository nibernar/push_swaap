/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:52:53 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/08/15 18:43:47 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	algo_4num(t_list **lst_a, t_list **lst_b, t_list *tmp_a, int data);
static void	resole_4num(t_list **lst_a, t_list **lst_b, int j);
static int 	algo_5num(t_list **lst_a, t_list **lst_b, t_list *tmp_a, int data);
static void	resolve_5num(t_list **lst_a, t_list **lst_b, int j);

/**
 * @brief Sorting data on a stack, with 4 or 5 numbers.
 * 
 * @param lst_a The list has rotate.
 * @param lst_b The list has rotate.
 * @param i Number of integer to sort.
 */ 
void	sort_medium(t_list **lst_a, t_list **lst_b, int i)
{
	t_list	*tmp_a;
	int		data;

	tmp_a = *lst_a;
	data = tmp_a->content;
	if (i == 4)
		algo_4num(lst_a, lst_b, tmp_a, data);
	else
	{
		data = algo_5num(lst_a, lst_b, tmp_a, data);
		if (if_not_shorted(*lst_a))
		{
			data = INT_MAX;
			algo_4num(lst_a, lst_b, tmp_a, data);
			do_pa(lst_a, lst_b);
		}
		else
			do_pa(lst_a, lst_b);
	}
}

static void	algo_4num(t_list **lst_a, t_list **lst_b, t_list *tmp_a, int data)
{
	int	j;

	j = 1;
	tmp_a = *lst_a;
	data = tmp_a->content;
	dprintf(2, "data : %d\n", data);
	data = data_min(tmp_a, data);
	j = position_min(tmp_a, data, j);
	if (j >= 1 && j <= 3)
		resole_4num(lst_a, lst_b, j);
	else
	{
		do_rra(lst_a);
		do_pb(lst_a, lst_b);
		if (if_not_shorted(*lst_a))
			sort_min(lst_a);
		do_pa(lst_a, lst_b);
	}
}

static int algo_5num(t_list **lst_a, t_list **lst_b, t_list *tmp_a, int data)
{
	int		j;

	j = 1;
	data = tmp_a->content;
	data = data_min(tmp_a, data);
	tmp_a = *lst_a;
	j = position_min(tmp_a, data, j);
	resolve_5num(lst_a, lst_b, j);
	return (data);
}

static void	resole_4num(t_list **lst_a, t_list **lst_b, int j)
{
	if (j == 1)
	{
		do_pb(lst_a, lst_b);
		if (if_not_shorted(*lst_a))
			sort_min(lst_a);
		do_pa(lst_a, lst_b);
	}
	else if (j == 2)
	{
		do_sa(lst_a);
		do_pb(lst_a, lst_b);
		if (if_not_shorted(*lst_a))
			sort_min(lst_a);
		do_pa(lst_a, lst_b);
	}
	else if (j == 3)
	{
		do_rra(lst_a);
		do_rra(lst_a);
		do_pb(lst_a, lst_b);
		if (if_not_shorted(*lst_a))
			sort_min(lst_a);
		do_pa(lst_a, lst_b);
	}
}

static void	resolve_5num(t_list **lst_a, t_list **lst_b, int j)
{
	if (j == 1)
		do_pb(lst_a, lst_b);
	else if (j == 2)
	{
		do_sa(lst_a);
		do_pb(lst_a, lst_b);
	}
	else if (j == 3)
	{
		do_ra(lst_a);
		do_ra(lst_a);
		do_pb(lst_a, lst_b);
	}
	else if (j == 4)
	{
		do_rra(lst_a);
		do_rra(lst_a);
		do_pb(lst_a, lst_b);
	}
	else
	{
		do_rra(lst_a);
		do_pb(lst_a, lst_b);
	}
}
