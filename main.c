/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:19:07 by ncolomer          #+#    #+#             */
/*   Updated: 2019/11/17 20:37:05 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*
** Useful macros
*/
# define STRLEN(x)			ft_strlen(x), (int)strlen(x)
# define STRCMP(a, b)		ft_strcmp(a, b), strcmp(a, b)
# define WRITE(s, x)		printf("^%ld\n", ft_write(STDOUT_FILENO, s, x));
# define READ(b, x)			r = ft_read(STDIN_FILENO, buffer, x); WRITE(buffer, r);
# define DUP(s)				tmp = ft_strdup(s); printf("`%s`\n", tmp); free(tmp); tmp = NULL;

/*
** Function prototypes
*/
int		ft_strlen(char const *str);

int		ft_strcmp(char const *s1, char const *s2);

char	*ft_strcpy(char *dst, char const *src);

ssize_t	ft_write(int fd, void const *buf, size_t nbyte);

ssize_t	ft_read(int fd, void *buf, size_t nbyte);

char	*ft_strdup(char const *s1);

/*
** Start !
*/
int		main(void)
{
	int		i;
	long	r;
	char	buffer[100];
	char	*tmp;
	char	*tmp2;

	r = 0;
	i = 0;
	while (i < 100)
		buffer[i++] = 0;

	printf("--strlen\n");
	printf("%d (%d)\n", STRLEN(""));
	printf("%d (%d)\n", STRLEN("toto"));
	printf("%d (%d)\n", STRLEN("totototo"));
	printf("%d (%d)\n", STRLEN("0123456789abcdef"));
	printf("-done\n");

	printf("\n--strcmp\n");
	printf("%d (%d)\n", STRCMP("", ""));
	printf("%d (%d)\n", STRCMP("toto", "toto"));
	printf("%d (%d)\n", STRCMP("", "toto"));
	printf("%d (%d)\n", STRCMP("toto", ""));
	printf("%d (%d)\n", STRCMP("toto", "totobar"));
	printf("-done\n");

	printf("\n--strcpy\n");
	printf("`%s` (`toto`)\n", ft_strcpy(buffer, "toto"));
	printf("`%s` (empty)\n", ft_strcpy(buffer, ""));
	printf("`%s` (`long message`)\n", ft_strcpy(buffer, "long message"));
	printf("-done\n");
	printf("\n--write\n");
	WRITE("toto", 4)
	WRITE("totototo", 4)
	WRITE("totototo", 8)
	WRITE("toto", 2)
	printf("-done\n");

	printf("\n--read (Makefile)\n");
	READ(buffer, 50)
	READ(buffer, 25)
	READ(buffer, 4)
	READ(buffer, 26)
	READ(buffer, 14)
	READ(buffer, 0)
	printf("-done\n");

	printf("--ft_strdup\n");
	tmp2 = ft_strdup("toto");
	DUP(tmp2)
	free(tmp2);
	DUP("totobar")
	DUP("long message")
	DUP("")
	DUP(NULL)
	printf("-done\n");

	return (0);
}
