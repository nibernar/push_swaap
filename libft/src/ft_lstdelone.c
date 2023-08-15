#include "libft.h"

/**
 * @brief Deletes and frees the node, using the function ’free’:  void free (void *).
 * 
 * @param lst The liste.
 * @param del The function used on each node in the list, or NULL if no function is used.
 */
void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (lst == NULL)
		return ;
	if (del)
		(*del)(lst->content);
	free(lst);
}