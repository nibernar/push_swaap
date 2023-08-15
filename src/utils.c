/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:48:01 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/15 19:52:21 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Checks if the numbers are already sorted.
 * 
 * @param lst_a The list has indexed.
 * @return EXIT_SUCCESS if it's sorted, or EXIT_FAILURE if is not.
 */
int	if_not_shorted(t_list *lst_a)
{
	while (lst_a->next != NULL)
	{
		if (lst_a->content > lst_a->next->content)
			return (EXIT_FAILURE);
		lst_a = lst_a->next;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Get the smallest number from the list.
 * 
 * @param lst The list to check.
 * @param data The integer in the first position in the list.
 * @return The smallest integer in the list.
 */
int	data_min(t_list *lst, int data)
{
	while (lst->next)
	{
		if (data > lst->next->content)
			data = lst->next->content;
		lst = lst->next;
	}
	return (data);
}

/**
 * @brief Get the largest number from the list.
 * 
 * @param lst The list to check.
 * @param data The integer in the first position in the list.
 * @return The largest integer in the list.
 */
long	data_max(t_list *lst, long data)
{
	while (lst->next)
	{
		if (data < lst->next->index)
			data = lst->next->index;
		lst = lst->next;
	}
	return (data);
}

/**
 * @brief Get the index of the node that contains the smallest number in the list.
 * 
 * @param lst The list to check.
 * @param data The smallest integer in the list.
 * @param j List index.
 * @return The index of the node that contains the smallest number in the list.
 */
int	position_min(t_list *lst, int data, int j)
{
	while (lst->next)
	{
		if (data == lst->content)
			break ;
		lst = lst->next;
		j++;
	}
	return (j);
}

/**
 * @brief Free an array of string.
 * 
 * @param str The array of string.
 */
void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	ft_exit(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
