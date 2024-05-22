/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/09 12:49:10 by sramos        #+#    #+#                 */
/*   Updated: 2024/05/22 18:42:11 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h> //pipe() fork() library
#include <sys/wait.h> //waitpid() library
#include <fcntl.h> //O_RDONLY library

#ifndef PIPEX_H
# define PIPEX_H

void	child_process(char **argv, char **envp, int *fd);
void	parent_process(char **argv, char **envp, int *fd);

void	execute(char **envp, char argv);
char	check_envp(char **envp, char *argv);

#endif