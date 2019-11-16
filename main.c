/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:19:07 by ncolomer          #+#    #+#             */
/*   Updated: 2019/11/16 15:40:33 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int
	ft_strlen(char const *str);

int
	main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	printf("--strlen\n");
	printf("%d\n", ft_strlen(""));
	printf("%d\n", ft_strlen("toto"));
	printf("%d\n", ft_strlen("totototo"));
	printf("%d\n", ft_strlen("0123456789abcdef"));
	printf("-done\n");
}
