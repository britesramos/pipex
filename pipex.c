/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 13:29:50 by sramos        #+#    #+#                 */
/*   Updated: 2024/05/28 18:03:14 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	fdin;

	fdin = open(argv[1], O_RDONLY);
	if (!fdin)
		perror("Error on open function (fdin).\n"); //needs also exit(EXIT_FAILURE).
	close (fd[0]); //Close read end of the pipe.
	if (dup2(fdin, STDIN_FILENO) == -1) //Redirect std input to the argv[1].
		perror("Error on dup2 (STD_IN) child_process.\n"); //needs also exit(EXIT_FAILURE).
	if (dup2(fd[1], STDOUT_FILENO) == -1) //Redirect std output to the write side of the pipe.
		perror("Error on dup2 (STD_OUT) child_process.\n"); //needs also exit(EXIT_FAILURE).
	execute(envp, argv[2]);
	close(fdin); //????
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	fdout;

	fdout = open(argv[4], O_WRONLY);
	if (!fdout)
		perror("Error on open function (fdout).\n"); //needs also exit(EXIT_FAILURE).
	close (fd[1]);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		perror("Error on dup2 (STD_OUT) parent_process.\n"); //needs also exit(EXIT_FAILURE).
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("Error on dup2 (STD_OUT) child_process.\n"); //needs also exit(EXIT_FAILURE).
	execute(envp, argv[3]);
	close(fdout); //????
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2]; //pipe ends, fd[1] and fd[0].
	int		status; //children status.
	pid_t	pid1; //Process ID.

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			perror("Error creating the pipe.\n"); //needs also exit(EXIT_FAILURE).
		pid1 = fork(); //It returns the PID of the child process.
		if (pid1 == -1)
			perror("Error on forking.\n"); //needs also exit(EXIT_FAILURE).
		if (pid1 == 0)
			child_process(argv, envp, fd);
		if (waitpid(pid1, &status, 0) == -1)
			perror("Error on waiting for child process ID!\n"); //needs also exit(EXIT_FAILURE).
		parent_process(argv, envp, fd);
	}
	else
		perror("Invalid input!\nCorrect input: './pipex file1 cmd1 cmd2 file2'"); //needs also exit(EXIT_FAILURE).
	// close(fd); //?????
	return (0);
}
