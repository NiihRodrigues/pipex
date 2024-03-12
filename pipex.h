#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_path(char *cmd, char **envp);
void	open_files(int *fd, char *infile, char *outfile);
#endif
