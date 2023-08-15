/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:00:30 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/15 19:37:41 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_swap(t_list **lst_a, t_list **lst_b, char **argv);

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	*str;
	char	**args;

	if (argc < 2)
		ft_exit("ERROR\n");
	str = args_build(argv, argc);
	if (check_neg(str))
		ft_exit("ERROR\n");
	args = ft_split(str, ' ');
	lst_a = NULL;
	lst_b = NULL;
	if (ft_check_error(args))
		ft_exit("ERROR\n");
	else
		push_swap(&lst_a, &lst_b, args);
	free(args);
	clear_list(&lst_a, &lst_b);
	free(str);
	return (0);
}

/**
 * @brief Sorting data on a stack, with a limited set of instructions, and the smallest number of moves.
 * 
 * @param lst_a The list has sorting.
 * @param lst_b The list has sorting.
 * @param argv A random number of either positive or negative numbers without any duplicates.
 */ 
static void	push_swap(t_list **lst_a, t_list **lst_b, char **argv)
{
	int		i;

	create_lst(argv, lst_a);
	create_lst(argv, lst_b);
	swap_lst(lst_b);
	i = ft_index(lst_a, lst_b);
	ft_lstclear(lst_b, NULL);
	if (i == 2 && if_not_shorted(*lst_a))
		do_sa(lst_a);
	else if (i == 3 && if_not_shorted(*lst_a))
		sort_min(lst_a);
	else if ((i == 4 || i == 5) && if_not_shorted(*lst_a))
		sort_medium(lst_a, lst_b, i);
	else if (i > 5 && if_not_shorted(*lst_a))
		sort_max(lst_a, lst_b, i);
	ft_free(argv);
}
