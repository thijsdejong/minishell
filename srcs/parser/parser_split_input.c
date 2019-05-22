/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_split_input.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 10:41:40 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/20 14:28:22 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	word_count(char *input)
{
	size_t	i;
	size_t	q;
	size_t	words;

	i = 0;
	q = 0;
	words = 0;
	while (input[i] != '\0')
	{
		while (input[i] != '\0' && (input[i] == ' ' || input[i] == '\t'))
			i++;
		if (input[i] != '\0')
			words++;
		while (input[i] != '\0' && ((q % 2 == 1) ||
				(input[i] != ' ' && input[i] != '\t')))
		{
			if (input[i] == '"')
				q++;
			i++;
		}
	}
	if (words == 0)
		return (1);
	return (words);
}

static size_t	argument_size(const char *argument, size_t n)
{
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	while (argument[i] != '\0' && i < n)
	{
		if (argument[i] != '"')
			size++;
		i++;
	}
	return (size);
}

static char		*copy_argument(const char *input, size_t n)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = ft_strnew(argument_size(input, n));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (input[i] != '\0' && i < n)
	{
		if (input[i] != '"')
		{
			str[j] = input[i];
			j++;
		}
		i++;
	}
	return (str);
}

static void		loop_over_word(char *input, size_t *i, size_t *j, size_t *q)
{
	*j = *i;
	while (input[*j] != '\0' && ((*q % 2 == 1) ||
				(input[*j] != ' ' && input[*j] != '\t')))
	{
		if (input[*j] == '"')
			(*q)++;
		(*j)++;
	}
}

char			**parser_split_input(char *input)
{
	char	**cmd;
	size_t	i;
	size_t	j;
	size_t	q;
	size_t	k;

	q = 0;
	i = 0;
	k = 0;
	cmd = (char**)ft_memalloc(sizeof(char*) * (word_count(input) + 1));
	while (input[i] != '\0' && cmd != NULL)
	{
		while (input[i] != '\0' && (input[i] == ' ' || input[i] == '\t'))
			i++;
		if (input[i] == '\0')
			break ;
		loop_over_word(input, &i, &j, &q);
		cmd[k] = copy_argument(input + i, j - i);
		if (cmd[k] == NULL)
			return (NULL);
		k++;
		i = j;
	}
	return (cmd);
}
