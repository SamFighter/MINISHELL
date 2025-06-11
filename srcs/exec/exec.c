/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:47:28 by samfighter        #+#    #+#             */
/*   Updated: 2025/06/02 16:49:12 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"


static void exec_child(t_controller *cont, t_cmd *cmd, int *pip)
{
	char *path;

	if (is_builtin(cmd))
	{
		redir_in_out(cont, cmd, pip);
		prepare_builtin(cont, cmd);
		exit(0);
	}
	path = get_path(search_envp("PATH", cont->env), &cont->cmdlist);
	if (!path || check_cmd(cont) == -1)
	{
		perror("command not found");
		exit(EXIT_FAILURE);
	}
	redir_in_out(cont, cmd, pip);
	execve(path, cmd->cmd_args, cont->env);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

static void		exec_parent(t_cmd *cmd, int *pip)
{
	close(pip[1]);
	if (cmd->fd_inf >= 0)
		close(cmd->fd_inf);
	if (cmd->fd_inf == -2)
		cmd->fd_inf = pip[0];
	if (cmd->next && cmd->next != cmd && cmd->next->fd_inf == -2)
		cmd->fd_inf = pip[0];
	else
		close(pip[0]);
}

static void		exec_cmd(t_controller *cont, t_cmd *cmd, int *pip)
{
	g_sig = fork();
	if (g_sig < 0)
		perror("fork failed");
	else if (!g_sig)
	{	
	  if (cmd && cmd->cmd_args && cmd->cmd_args[0])
			exec_child(cont, cmd, pip);
	  else
			perror("empty command");
	}
	else
		exec_parent(cmd, pip);
}

static void		wait_process(t_controller *cont, t_cmd *cmd)
{
	int status;
	int pid;
	int len;

	len = len_cmd(cmd);
	while (len--)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == g_sig && WIFEXITED(status))
			cont->excode = WEXITSTATUS(status);
		if (cmd->fd_out >= 0)
			close(cmd->fd_out);
		if (cmd->fd_inf >= 0)
			close(cmd->fd_inf);
		cmd = cmd->next;
	}
}

int exec(t_controller *cont)
{
	t_cmd *cmd;
	int *pip;

	cmd = cont->cmdlist.cmds;
	if (is_builtin(cmd) && !search_pipe(cont->cmdlist.tokens))
		return (prepare_builtin(cont, cmd));
	pip = cont->pip;
	if (pipe(pip) == -1)
		return (1);
	exec_cmd(cont, cmd, pip);
	cmd = cmd->next;
	if (!cmd)
		return (1);
	if (cmd->next == NULL)
		cmd->next = cmd;
	while (cmd != cont->cmdlist.cmds)
	{
		if (pipe(pip) == -1)
			return (-1);
		exec_cmd(cont, cmd, pip);
		cmd = cmd->next;
	}
	wait_process(cont, cmd);
	return (0);
}
