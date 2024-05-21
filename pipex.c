/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 13:29:50 by sramos        #+#    #+#                 */
/*   Updated: 2024/05/21 15:54:58 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_envp(char **envp, char *argv)
{
	//Have to split the envp.
	//if it finds the cmd return 0.
	//if it doenst find it return 1.
}

void	child_process(char **argv, char **envp, int *fd)
{
	int	fdin;

	fdin = open(argv[1], O_RDONLY);
	if (!fdin)
		perror("fdin was not createn on child_process.\n"); //needs also exit(EXIT_FAILURE).
	close (fd[0]); //Close read end of the pipe.
	if (check_envp(envp, argv) == 0) //cmd1 has to exist in the envp
	{
		if (dup2(fdin, STDIN_FILENO) == -1) //Redirect std input to the argv[1].
			perror("Error on dup2 (STD_IN) child_process.\n"); //needs also exit(EXIT_FAILURE).
		if (dup2(fd[1], STDOUT_FILENO) == -1) //Redirect std output to the write side of the pipe.
			perror("Error on dup2 (STD_OUT) child_process.\n"); //needs also exit(EXIT_FAILURE).
		else
			execute() //Function to execute the cmd1 with the file1 input and fd[1] output.
	}
	else
		perror("Cmd1 does not exist.\n"); //needs also exit(EXIT_FAILURE).
	close(fdin);

}

void	parent_process(char **argv, char **envp, int *fd)
{
	//close fd[1] and then open it?;
	//cmd2 has to exist in the envp
	//How does the fd[1] becomes fd[0]?? How does the pipe work?
	//perform cmd2 in fd[0]
	//cmd2 outputs argv[4]
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2]; //pipe ends, fd[1] and fd[0].
	int		status; //children status.
	pid_t	pid1; //Process ID.

	if (argc == 5)
	{
		if (pipe(fd) == -1);
			perror("Error creating the pipe.\n"); //needs also exit(EXIT_FAILURE).
		//What if pipe() doenst return -1 or 0? errno it's a global variable.
		pid1 = fork(); //It returns the PID of the child process.
		if (pid1 == -1)
			perror("Error on forking.\n"); //needs also exit(EXIT_FAILURE).
		if (pid1 == 0)
			child_process(argv, envp, fd);
		if (waitpid(pid1, &status, 0) == -1);
			perror("Error on waiting for child process ID!\n"); //needs also exit(EXIT_FAILURE).
		parent_process(argv, envp, fd);
	}
	else
		perror("Invalid input!\nCorrect input: './pipex file1 cmd1 cmd2 file2'"); //needs also exit(EXIT_FAILURE).
	//Where should I check if there are valid cmds?
	close(fd); //?????
	return (0);
}

//USING DUP2 - DUPLICATES PROCESSES
// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>
 
// int main()
// {
// 	int fd;
 
// 	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
// 	dup2(fd, STDOUT_FILENO);
	
// 	printf("This is printed in example.txt!\n");
// 	close(fd);
// 	return (0);
// }