/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:33:49 by nibernar          #+#    #+#             */
/*   Updated: 2023/08/15 19:34:14 by nicolasbern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_is_double(int num, char **argv, int i);
static int	ft_is_not_num(char *num, long nbr);

/**
 * @brief Build the string which contains all the arguments.
 * 
 * @param argv The array of pointers containing all the arguments, except argv[0].
 * @param argc The total number of arguments passed on the command line.
 * @return The string which contains all the arguments.
 */ 
char	*args_build(char **argv, int argc)
{
	int		i;
	char	*str;
	char	*tmp;

	if (argc == 2)
		str = ft_strcpy(argv[1]);
	else
	{
		i = 2;
		str = ft_strcpy(argv[1]);
		while (i < argc)
		{
			tmp = ft_strjoin(str, " ");
			if (!tmp)
				return (free (str), ft_putstr_fd("ERROR MALLOC", 2), NULL);
			free (str);
			str = ft_strjoin(tmp, argv[i]);
			if (!str)
				return (free (tmp), ft_putstr_fd("ERROR MALLOC", 2), NULL);
			free (tmp);
			i++;
		}
	}
	return (str);
}

/**
 * @brief Check if the string has random numbers of positive or negative numbers without any duplicates.
 * 
 * @param argv The array of pointers containing all the arguments.
 * @return EXIT_SUCCESS if the arguments are valid, or EXIT_FAILURE if is not.
 */ 
int	ft_check_error(char **argv)
{
	int	i;
	int	nbr;

	i = 0;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		if (ft_is_not_num(argv[i], nbr))
		{
			ft_free(argv);
			return (EXIT_FAILURE);
		}
		if (ft_is_double(nbr, argv, i))
		{
			ft_free(argv);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Checks if the string contains only positive or negative numbers and with only one sign '-'
 * 
 * @param str The string containing all the arguments.
 * @return EXIT_SUCCESS if the arguments are valid, or EXIT_FAILURE if is not.
 */ 
int	check_neg(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0')
		return (EXIT_FAILURE);
	while (str[i] && str[i] == ' ')
		i++;
	if (i == ft_strlen(str))
		return (EXIT_FAILURE);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
		{
			if (!ft_isdigit((int)str[i + 1]) && str[i] != ' ')
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	ft_is_double(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	ft_is_not_num(char *num, long nbr)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (EXIT_FAILURE);
		i++;
	}
	if (!(nbr >= INT_MIN && nbr <= INT_MAX))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
