/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:09:11 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/15 18:06:59 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long	index_size_len(long nbr);
static void	tri_lst_a(t_list **lst_a, t_list **lst_b, int div, int nb);

/**
 * @brief Sorting data on a stack, with a random numbers of integer.
 * 
 * @param lst_a The list has rotate.
 * @param lst_b The list has rotate.
 * @param nb Number of integer to sort.
 */ 
void	sort_max(t_list **lst_a, t_list **lst_b, int nb)
{
	long	data;
	int		div;
	int		i;
	int		n;
	t_list	*tmp_b;

	data = 0;
	div = 0;
	i = 1;
	data = data_max(*lst_a, data);
	while (i <= index_size_len(data))
	{
		tri_lst_a(lst_a, lst_b, div, nb);
		tmp_b = *lst_b;
		n = ft_lstsize(tmp_b);
		while (n > 0)
		{
			do_pa(lst_a, lst_b);
			n--;
		}
		i *= 10;
	}
}

static long	index_size_len(long nbr)
{
	int		len;
	char	*result;
	int		res;
	int		i;

	len = 1;
	res = 0;
	i = 1;
	while (nbr >= 10)
	{
		len++;
		nbr /= 10;
	}
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	result[0] = '1';
	while (i < len)
		result[i++] = '0';
	result[len] = '\0';
	res = ft_atoi(result);
	free(result);
	return (res);
}

static void	tri_lst_a(t_list **lst_a, t_list **lst_b, int div, int nb)
{
	t_list	*tmp_a;
	int		a;

	tmp_a = *lst_a;
	a = 0;
	while (a < nb)
	{
		div = tmp_a->index % 10;
		if (div % 2 == 1)
		{
			tmp_a->index = tmp_a->index / 10;
			do_ra(lst_a);
			tmp_a = *lst_a;
		}
		else
		{
			tmp_a->index = tmp_a->index / 10;
			do_pb(lst_a, lst_b);
			tmp_a = *lst_a;
		}
		a++;
	}
}

