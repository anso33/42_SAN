#include "minishell.h"

void	set_signal(struct termios *term)
{
	tcgetattr(STDIN, term);
	term->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN, TCSANOW, term);
	signal(SIGINT, ft_signal_handler);	// ctrl c
	signal(SIGQUIT, ft_signal_handler);	// ctrl "\"
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	extern int rl_catch_signals;
	rl_catch_signals = 0;
	t_minishell *sh;
//	struct termios term;
	char		*line;
	pid_t		pid;
	int			status;

//	set_signal(&term);
	g_e_status = 0;
	signal(SIGINT, ft_signal_handler);	// ctrl c
	signal(SIGQUIT, ft_signal_handler);	// ctrl "\"
	//sh->envp = envp;	minishell만의 환경변수리스트를 만들어야한다고 생각해서 위의 코드 살림
	sh = malloc(sizeof(t_minishell));
	sh->envp = copy_envp(envp);
	line = NULL;
	sh->in = dup(0);
	sh->out = dup(1);
	while (1)
	{
		read_line(&line);
		if (parse(sh, line) == 1)
			continue ;
		handle_cmd(sh);

		while ((pid = waitpid(0, &status, 0)) > 0)
		{
			// fprintf(stderr, "%d child completed\n", pid);
			if (WIFEXITED(status))

				if (pid == sh->pid && sh->pid != -1)
					g_e_status = WEXITSTATUS(status);

			// if (sh->pid == -1)
			// 	fprintf(stderr, "hihi\n"); 
		}
		ft_free_cmd_lst(sh);
	}
	free(sh);

	return (0);

}
