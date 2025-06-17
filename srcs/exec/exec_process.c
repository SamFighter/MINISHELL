
#include "../../headers/minishell.h"

static void	exec_child(t_controller *cont, t_cmd *cmd, int *pip)
{
	char	*path;
	char	*path_env;

	redir_in_out(cont, cmd, pip);
	if (is_builtin(cmd))
		exit(prepare_builtin(cont, cmd));
	path_env = search_envp("PATH", cont->env);
	path = get_path(path_env, cmd);
	if (!path)
	{
		utl_putstr_fd(cmd->str_cmd, 2);
		utl_putstr_fd(": command not found\n", 2);
		free(path_env);
		exit(127);
	}
	execve(path, cmd->cmd_args, cont->env);
	perror(path);
	free(path);
	if (path_env)
		free(path_env);
	exit(126);
}

static void	exec_parent(t_cmd *cmd, int *pip)
{
	if (pip)
	{
		close(pip[1]);
		if (cmd->next)
			cmd->next->fd_inf = pip[0];
		else
			close(pip[0]);
	}
	if (cmd->fd_inf > 2)
		close(cmd->fd_inf);
}


void	exec_cmd(t_controller *cont, t_cmd *cmd, int *pip)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
		exec_child(cont, cmd, pip);
	else
	{
		g_sig = pid;
		exec_parent(cmd, pip);
	}
}


