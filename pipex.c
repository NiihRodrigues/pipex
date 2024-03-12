#include "pipex.h"

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char 	*final_path;
	char	*temp;

	if (!access(cmd, F_OK & X_OK))
		return (cmd);
	while(ft_strncmp(*envp, "PATH=", 5))
		envp++;
	paths = ft_split(*envp + 5, ':');
	i = -1;
	while(paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		final_path = ft_strjoin(temp, cmd);
		if (access(final_path, F_OK & X_OK) == 0)
			return (final_path);
		free(temp);
		free(final_path);
	}
	return (NULL);
}

void	open_files(int *fd, char *infile, char *outfile)
{
	fd[0] = open(infile, O_RDONLY);
	fd[1] =	open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
}
