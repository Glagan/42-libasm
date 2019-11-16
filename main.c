/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:19:07 by ncolomer          #+#    #+#             */
/*   Updated: 2019/11/16 16:26:28 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

# define STRLEN(x)		ft_strlen(x) == (int)strlen(x)
# define STRCMP(a, b)	ft_strcmp(a, b) == strcmp(a, b)

int
	ft_strlen(char const *str);

int
	ft_strcmp(char const *s1, char const *s2);

int
	main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	printf("--strlen\n");
	printf("%d (%d)\n", STRLEN(""));
	printf("%d (%d)\n", STRLEN("toto"));
	printf("%d (%d)\n", STRLEN("totototo"));
	printf("%d (%d)\n", STRLEN("0123456789abcdef"));
	printf("-done\n");
	printf("--strcmp\n");
	printf("equals %d (%d)\n", STRCMP("", ""));
	printf("equals %d (%d)\n", STRCMP("toto", "toto"));
	printf("equals %d (%d)\n", STRCMP("", "toto"));
	printf("equals %d (%d)\n", STRCMP("toto", ""));
	printf("equals %d (%d)\n", STRCMP("toto", "totobar"));
	printf("-done\n");
}
