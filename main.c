/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:19:07 by ncolomer          #+#    #+#             */
/*   Updated: 2019/11/16 17:36:22 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

# define STRLEN(x)		ft_strlen(x), (int)strlen(x)
# define STRCMP(a, b)	ft_strcmp(a, b), strcmp(a, b)
# define WRITE(s, x)	printf("^%ld\n", ft_write(0, s, x));

int
	ft_strlen(char const *str);

int
	ft_strcmp(char const *s1, char const *s2);

char
	*ft_strcpy(char *dst, char const *src);

ssize_t
	ft_write(int fd, void const *buf, size_t nbyte);

int
	main(int argc, char **argv)
{
	int		i;
	char	buffer[100];

	i = 0;
	while (i < 100)
		buffer[i++] = 0;

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
	printf("--strcpy\n");
	printf("dst: `%s` (`toto`)\n", ft_strcpy(buffer, "toto"));
	printf("dst: `%s` (empty)\n", ft_strcpy(buffer, ""));
	printf("dst: `%s` (`long message`)\n", ft_strcpy(buffer, "long message"));
	printf("-done\n");
	printf("--write\n");
	WRITE("toto", 4)
	WRITE("totototo", 4)
	WRITE("toto", 2)
	printf("-done\n");
	return (0);
}
