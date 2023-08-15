/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:14:37 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/12 02:10:42 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_lst(char **argv, t_list **lst)
{
	unsigned int	i;
	int				nbr;

	i = 0;
	nbr = 0;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		ft_lstadd_back(lst, ft_lstnew(nbr));
		i++;
	}
}

void	swap_lst(t_list **lst)
{
	t_list	*tmp;
	int swap;

	swap = 0;
	tmp = *lst;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->content > tmp->next->content)
		{
			swap = tmp->content;
			tmp->content = tmp->next->content;
			tmp->next->content = swap;
			tmp = *lst;
		}
		else
			tmp = tmp->next;
	}
}

void	clear_list(t_list **lst_a, t_list **lst_b)
{
	ft_lstclear(lst_a, NULL);
	ft_lstclear(lst_b, NULL);
}