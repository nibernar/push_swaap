# push_swap
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, we will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

## Rules
* The game is composed of 2 stacks.<br/>
* The goal is to sort in ascending order numbers into stack a.<br/>
* To do this, we have the operations listed below<br/>

### How to compile library:
* `make` - to compile C files - create object files and library libft.a<br/>
* `make clean` - to remove object files<br/>
* `make fclean` - clean and remove libft.a file<br/>
* `make re` - recompile the library<br/>

### libft functions:

| Function      | Description                                                                           |
| ------------- | --------------------------------------------------------------------------------------| 
| ft_isdigit | Checks if the character is a digital character. |
| ft_isspace | Checks if the character is a space character. |
| ft_bzero | Writes 'n' zeroed bytes to the string 's'. |
| ft_calloc | Allocates dynamic memory for an array of elements of specified size. |
| ft_free | Free an array of elements. |
| ft_strlen | Find length of string. |
| ft_strlcpy | Size bounded string copy. |
| ft_atoi | Convert ASCII string to integer. |
| ft_substr     | Allocates and returns a "new" substring from the given argument string. The substring starts at index 'start'. If the allocation fails, the function returns NULL. |
| ft_strjoin    | Allocates and returns a 'new' string ending with ’\0’, result of the concatenation of 's1' and 's2'. If the allocation fails the function returns NULL. |
| ft_split      | Allocates and returns an array of 'new' strings, the character 'c' as a delimiter. If the allocation fails the function returns NULL. |
| ft_putchar_fd | Outputs the char 'c' to the file descriptor 'fd'. |
| ft_putstr_fd  | Outputs the string 's' to the file descriptor 'fd'. |
| ft_lstadd_back | Adds the node ’new’ at the end of the list. |
| ft_lstclear | Deletes and frees the given node and every successor of that node, using the function ’free’:  void free (void *). |
| ft_lstdelone  | Deletes and frees the node, using the function ’free’:  void free (void *). |
| ft_lstlast | Returns the last node of the list. |
| ft_lstnew     | Allocates with malloc and returns a 'new' node. |
| ft_lstsize | Counts the number of nodes in a list. |

### list of operations:

| Function      | Description                                                                           |
| ------------- | --------------------------------------------------------------------------------------| 
| pa | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| pb | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| sa | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| sb | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| ss | Swap sa and sb at the same time. |
| ra | Shift up all elements of stack a by 1. The first element becomes the last one. |
| rb | Shift up all elements of stack a by 1. The first element becomes the last one. |
| rr | rotate ra and rb at the same time. |
| rra | Shift down all elements of stack a by 1. The last element becomes the first one. |
| rrb | Shift down all elements of stack a by 1. The last element becomes the first one. |
| rrr | Shift down rra and rrb at the same time. |