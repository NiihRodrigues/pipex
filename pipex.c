/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicrodri <nicrodri@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:49:18 by nicrodri          #+#    #+#             */
/*   Updated: 2024/03/12 11:54:42 by nicrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*final_path;
	char	*temp;

	if (!access(cmd, F_OK & X_OK))
		return (cmd);
	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	paths = ft_split(*envp + 5, ':');
	i = -1;
	while (paths[++i])
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
	fd[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
}

void	close_files(int *fd, int *ch)
{
	close(fd[0]);
	close(fd[1]);
	close(ch[0]);
	close(ch[1]);
}

void	free_cmds(char **cmds[2])
{
	int	i;

	i = 0;
	while (cmds[0][i])
	{
		free(cmds[0][i]);
		i++;
	}
	i = 0;
	while (cmds[1][i])
	{
		free(cmds[1][i]);
		i++;
	}
}
