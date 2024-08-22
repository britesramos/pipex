/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/09 12:49:10 by sramos        #+#    #+#                 */
/*   Updated: 2024/08/22 10:48:52 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

void	child1_process(char **argv, char **envp, int *fd);
void	child2_process(char **argv, char **envp, int *fd);

void	execute(char **envp, char *argv);
char	*check_envp(char **envp, char *argv);
void	ft_error(int num);
void	ft_error_process_child1(int num);

#endif