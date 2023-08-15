/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:23:22 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/15 19:13:33 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long	index_base(long nbr);
static void	index_binary(t_list **lst_a);
static int	assign_index(t_list **lst_b);
static void	assign_index_ab(t_list **lst_a, t_list **lst_b);

/**
 * @brief Calculates the number of integers and gives a binary index for each integers in the list.
 * 
 * @param lst_a The list to be indexed
 * @param lst_b The list to be indexed.
 * @return Number of integer to sort.
 */ 
int	ft_index(t_list **lst_a, t_list **lst_b)
{
	int	nb_int;

	nb_int = assign_index(lst_b);
	assign_index_ab(lst_a, lst_b);
	index_binary(lst_a);
	return (nb_int);
}

static long	index_base(long nbr)
{
	if (nbr >= 2)
		return (index_base(nbr / 2) * 10 + nbr % 2);
	if (nbr % 2)
		return (1);
	return (0);
}

static void	index_binary(t_list **lst_a)
{
	t_list	*tmp;

	tmp = *lst_a;
	while (tmp)
	{
		tmp->index = index_base(tmp->index);
		tmp = tmp->next;
	}
}

static int	assign_index(t_list **lst_b)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = *lst_b;
	while (tmp != NULL)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
	return (i - 1);
}

static void	assign_index_ab(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *lst_a;
	tmp_b = *lst_b;
	while (tmp_a)
	{
		while (tmp_b)
		{
			if (tmp_a->content == tmp_b->content)
				tmp_a->index = tmp_b->index;
			tmp_b = tmp_b->next;
		}
		tmp_b = *lst_b;
		tmp_a = tmp_a->next;
	}
}

