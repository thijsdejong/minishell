/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell_display_prompt.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 14:53:19 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/08 13:52:51 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_display_prompt(void)
{
	ft_putstr(SHELLPREFIX "> ");
}
