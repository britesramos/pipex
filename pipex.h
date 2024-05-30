/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/09 12:49:10 by sramos        #+#    #+#                 */
/*   Updated: 2024/05/30 13:41:45 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h> //pipe() fork() library
#include <sys/wait.h> //waitpid() library
#include <fcntl.h> //O_RDONLY library

#ifndef PIPEX_H
# define PIPEX_H

void	child1_process(char **argv, char **envp, int *fd);
void	child2_process(char **argv, char **envp, int *fd);

void	execute(char **envp, char *argv);
char	*check_envp(char **envp, char *argv);
void	ft_error(int num);
void	ft_error_process(int num);

#endif