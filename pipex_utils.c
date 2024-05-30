/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 12:48:58 by sramos        #+#    #+#                 */
/*   Updated: 2024/05/30 13:43:37 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_envp(char **envp, char *cmd)
{
	char	**paths;
	char	*temp;
	int		i;
	int 	j;

	i = 0;
	j = 1;
	if(access(cmd, X_OK) == 0)
		return(cmd);
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		exit(1);
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = ft_strjoin(temp, cmd);
		free(temp);
		if(access(paths[i], X_OK) == 0)
		{
			while(paths[i + j] != NULL)
			{
				free(paths[i + j]);
				j++;
			}
			temp = paths[i];
			free(paths);
			return(temp);
		}
		free(paths[i]);
		i++;
	}
	free(paths);
	return(0);
}

void	execute(char **envp, char *argv)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' '); //dont forget to free.
	path = check_envp(envp, cmd[0]);
	if (!path)
		perror("Error on finding the comand.\n"); //Needs exit???
	else if (execve(path, cmd, envp) == -1)
		perror("Execve error!\n");
	free(path);
}

void	ft_error(int num)
{
	if (num == 1)
		perror("Error creating the pipe.\n");
	else if (num == 2)
		perror("Error on forking child 1.\n");
	else if (num == 3)
		perror("Error on waiting for child process ID!\n");
	else if (num == 4)
		perror("Error on forking child 2.\n");
	else if (num == 5)
		perror("Invalid input!\nCorrect input: './pipex file1 cmd1 cmd2 file2'");
	exit(EXIT_FAILURE);
}

void	ft_error_process(int num)
{
	if (num == 1)
		perror("Error on open function (fdin).\n");
	if (num == 2)
		perror("Error on dup2 (STD_IN) child1_process.\n");
	if (num == 3)
		perror("Error on dup2 (STD_OUT) child1_process.\n");
	if (num == 4)
		perror("Error on open function (fdout).\n");
	if (num == 5)
		perror("Error on dup2 (STD_OUT) child2_process.\n");
	if (num == 6)
		perror("Error on dup2 (STD_IN) child2_process.\n");
	exit(EXIT_FAILURE);
}
