/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 12:48:58 by sramos        #+#    #+#                 */
/*   Updated: 2024/05/22 18:49:48 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	check_envp(char **envp, char *cmd)
{
	char	**paths;
	int		i;
	int		j = 0; //temp

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	while (j <= i)
	{
		printf("This is path[%i]: %s.\n", j, paths[j]);
		j++;
	}
	return(1); //temp.
	//Have to split the envp.
	//if it finds the cmd return 0.
	//if it doenst find it return 1.
}

// void	execute(char **envp, char argv)
// {
// 	char	**cmd;
// 	char	*path;

// 	cmd = ft_split(argv, ' ');
// 	path = check_envp(envp, cmd[0]);
// 	if (!path)
// 	{

// 	}
// 	//Use check_envp function here.
// 	//And then execute if the path exists.
// }

int	main(int argc, char **argv, char **envp)
{
	check_envp(envp, argv[1]);
	return (0);
}