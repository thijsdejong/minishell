/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell_run.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 15:00:36 by tde-jong       #+#    #+#                */
/*   Updated: 2019/05/09 11:00:35 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_run(void)
{
	bool	run;
	char	*input;
	char	status;

	run = true;
	status = 0;
	input = NULL;
	while (run)
	{
		shell_display_prompt();
		if (get_next_line(STDIN_FILENO, &input) != -1)
		{
			evaluator(parser(input), &status);
			ft_strdel(&input);
		}
		else
			run = false;
	}
	exit(status);
}
