/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 13:29:50 by sramos        #+#    #+#                 */
/*   Updated: 2024/08/22 10:47:47 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(char **argv, char **envp, int *fd)
{
	int	fdin;

	fdin = open(argv[1], O_RDONLY, 0444);
	if (!fdin)
		ft_error_process_child1(1);
	close (fd[0]);
	if (dup2(fdin, STDIN_FILENO) == -1)
		ft_error_process_child1(2);
	close(fdin);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error_process_child1(3);
	close (fd[1]);
	execute(envp, argv[2]);
}

void	child2_process(char **argv, char **envp, int *fd)
{
	int	fdout;

	fdout = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0666);
	if (!fdout)
		ft_error(6);
	close (fd[1]);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		ft_error(7);
	close(fdout);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error(8);
	close (fd[0]);
	execute(envp, argv[3]);
}

void	end_program(int fd[], pid_t pid1, pid_t pid2, int status)
{
	close (fd[1]);
	close (fd[0]);
	if (waitpid(pid1, &status, 0) == -1)
		ft_error(3);
	if (waitpid(pid2, &status, 0) == -1)
		ft_error(3);
	exit(WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	status = 0;
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error(1);
		pid1 = fork();
		if (pid1 == -1)
			ft_error(2);
		if (pid1 == 0)
			child1_process(argv, envp, fd);
		pid2 = fork();
		if (pid2 == -1)
			ft_error(4);
		if (pid2 == 0)
			child2_process(argv, envp, fd);
		end_program(fd, pid1, pid2, status);
	}
	else
		ft_error(5);
	return (0);
}
