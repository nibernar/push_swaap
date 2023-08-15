/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:03:43 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/15 19:35:00 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include/libft.h"

/****************
*	UTILS_TRI	*
****************/

int		if_not_shorted(t_list *lst_a);
long	data_max(t_list *lst, long data);
int     data_min(t_list *lst, int data);
int		position_min(t_list *lst, int data, int j);

/****************
*	MAKE_INDEX	*
****************/

int		ft_index(t_list **lst_a, t_list **lst_b);

/****************
*	CHECK_ERRO	*
****************/

int		ft_check_error(char **argv);
char	*args_build(char **argv, int argc);
int	    check_neg(char *str);
void	ft_free(char **str);
void	ft_exit(char *str);

/****************
*	UTILS_LST	*
****************/

void	create_lst(char **argv, t_list **lst);
void	swap_lst(t_list **lst);
void	clear_list(t_list **lst_a, t_list **lst_b);

/****************
*	TRI_SORT	*
****************/

void	sort_min(t_list **lst_a);
void	sort_medium(t_list **lst_a, t_list **lst_b, int i);
void	sort_max(t_list **lst_a, t_list **lst_b, int nb);

/****************
*	   SWAP    	*
****************/

void	do_sa(t_list **lst_a);
void	do_sb(t_list **lst_b);
void	do_ss(t_list **lst_a, t_list **lst_b);

/****************
*	 ROTATE 	*
****************/

void	do_ra(t_list **lst_a);
void	do_rb(t_list **lst_b);
void	do_rr(t_list **lst_a, t_list **lst_b);

/********************
*	REVERESE_ROTATE	*
********************/

void	do_rra(t_list **lst_a);
void	do_rrb(t_list **lst_b);
void	do_rrr(t_list **lst_a, t_list **lst_b);

/****************
*	  PUSH      *
****************/

void	do_pa(t_list **lst_a, t_list **lst_b);
void	do_pb(t_list **lst_a, t_list **lst_b);

#endif
