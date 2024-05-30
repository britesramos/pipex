/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 13:29:50 by sramos        #+#    #+#                 */
/*   Updated: 2024/05/30 13:44:09 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(char **argv, char **envp, int *fd)
{
	int	fdin;

	fdin = open(argv[1], O_RDONLY);
	if (!fdin)
		ft_error_process(1);
	close (fd[0]); //Close read end of the pipe.
	if (dup2(fdin, STDIN_FILENO) == -1) //Redirect std input to the argv[1].
		ft_error_process(2);
	if (dup2(fd[1], STDOUT_FILENO) == -1) //Redirect std output to the write side of the pipe.
		ft_error_process(3);
	execute(envp, argv[2]);
	close(fdin); //????
}

void	child2_process(char **argv, char **envp, int *fd)
{
	int	fdout;

	fdout = open(argv[4], O_WRONLY);
	if (!fdout)
		ft_error_process(4);
	close (fd[1]);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		ft_error_process(5);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error_process(6);
	execute(envp, argv[3]);
	close(fdout); //????
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2]; //pipe ends, fd[1] and fd[0].
	int		status; //children status.
	pid_t	pid1; //Process ID child 1.
	pid_t	pid2; //Process ID child 2.

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error(1);
		pid1 = fork(); //It returns the PID of the child process.
		if (pid1 == -1)
			ft_error(2);
		if (pid1 == 0)
			child1_process(argv, envp, fd);
		if (waitpid(pid1, &status, 0) == -1)
			ft_error(3);
		pid2 = fork();
		if (pid2 == -1)
			ft_error(4);
		if (pid2 == 0)
			child2_process(argv, envp, fd);
	}
	else
		ft_error(5);
	// close(fd); //?????
	return (0);
}
