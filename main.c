#include "pipex.h"

void	check_params(int argc, char **argv)
{
	if (!argc == 5)
	{
		perror("pipex: wrong number of arguments");
		exit(2);
	}
	if (access(argv[1], F_OK & R_OK) == -1)
	{
		perror("pipex: infile doesn't have permition or do not exist");
		exit(66);
	}

}

void	build_cmds(char **cmds[2], char *cmd1, char *cmd2)
{
	if (cmd1[0] == ' ')
		cmd1++;
	if (cmd2[0] == ' ')
		cmd2++;
	if (!*cmd1 || !*cmd2)
	{
		write(2, "pipex: no command passed to either cmd1 or cmd2 or both\n", 56);
		exit(64);
	}
	cmds[0] = ft_split(cmd1, ' ');
	cmds[1] = ft_split(cmd2, ' ');
}

void	exec_cmd_1(int infile, int outfile, char **cmds[2], char **envp)
{
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	execve(get_path(cmds[0][0], envp), cmds[0], envp);
	perror("pipex: command not found: ");
	exit(22);
}

void	exec_cmd_2(int infile, int outfile, char**cmds[2], char **envp)
{
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	execve(get_path(cmds[1][0], envp), cmds[1], envp);
	perror("pipex: command not found: ");
	exit(22);
}

int	main(int argc, char **argv, char **envp)
{
	int		pids[2];
	int		fds[2];
	int		ch[2];
	char 	**cmds[2];

	check_params(argc, argv);
	build_cmds(cmds, argv[2], argv[3]);
	open_files(fds, argv[1], argv[4]);
	pipe(ch);
	pids[0] = fork();
	if (pids[0] == 0)
	{
		close(ch[0]);
		exec_cmd_1(fds[0], ch[1], cmds, envp);
	}
	if (pids[0] != 0)
		pids[1] = fork();
	if (pids[1] == 0)
	{
		close(ch[1]);
		exec_cmd_2(ch[0], fds[1], cmds, envp);
	}
	close(ch[0]);
	close(ch[1]);
	close(fds[0]);
	close(fds[1]);
	return (0);
}
