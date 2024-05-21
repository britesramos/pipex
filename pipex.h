/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/09 12:49:10 by sramos        #+#    #+#                 */
/*   Updated: 2024/05/21 15:49:01 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h> //pipe() fork() library
#include <sys/wait.h> //waitpid() library
#include <fcntl.h> //O_RDONLY library

#ifndef PIPEX_H
# define PIPEX_H

void	child_process(char **argv, char **envp, int *fd);
void	parent_process(char **argv, char **envp, int *fd);

int		check_envp(char **envp, char *argv);

#endif