/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:42:26 by nicolasbern       #+#    #+#             */
/*   Updated: 2023/08/12 02:10:04 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include "limits.h"
# include "stdio.h"

typedef struct s_list
{
	int				content;
	long			index;
	struct s_list	*next;
}t_list;

/************
*	Checks	*
*************/

int		ft_isdigit(int c);
int		ft_isspace(int c);

/************
*	Memory	*
*************/

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t n);

/************
*	 Str	*
*************/

int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *src);

/****************
*	 Write_fd	*
****************/

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

/************
*	 Lst	*
*************/

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	    ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstdelone(t_list *lst, void (*del)(int));
#endif