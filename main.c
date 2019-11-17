/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:19:07 by ncolomer          #+#    #+#             */
/*   Updated: 2019/11/17 18:51:58 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

# define STRLEN(x)		ft_strlen(x), (int)strlen(x)
# define STRCMP(a, b)	ft_strcmp(a, b), strcmp(a, b)
# define WRITE(s, x)	printf("^%ld\n", ft_write(STDOUT_FILENO, s, x));
# define READ(b, x)		r = ft_read(STDIN_FILENO, buffer, x); WRITE(buffer, r);
# define DUP(s)			tmp = ft_strdup(s); printf("`%s`\n", tmp); free(tmp); tmp = NULL;

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

void
	printf_list(t_list *list)
{
	while (list)
	{
		printf("; %s\n", list->data);
		list = list->next;
	}
}

void
	ft_lstclear(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

/**
 * Mandatory
 **/

int
	ft_strlen(char const *str);

int
	ft_strcmp(char const *s1, char const *s2);

char
	*ft_strcpy(char *dst, char const *src);

ssize_t
	ft_write(int fd, void const *buf, size_t nbyte);

ssize_t
	ft_read(int fd, void *buf, size_t nbyte);

char
	*ft_strdup(char const *s1);

/**
 * Bonus
 **/

int
	ft_atoi_base(char const *str, char const *base);

void
	ft_list_push_front(t_list **begin_list, void *data);

int
	ft_list_size(t_list *begin_list);

void
	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void*));

void
	ft_list_sort(t_list **begin_list,int (*cmp)());

int
	main(int argc, char **argv)
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

	(void) argc;
	(void) argv;
	(void) tmp;
	printf("--strlen\n");
	printf("%d (%d)\n", STRLEN(""));
	printf("%d (%d)\n", STRLEN("toto"));
	printf("%d (%d)\n", STRLEN("totototo"));
	printf("%d (%d)\n", STRLEN("0123456789abcdef"));
	printf("-done\n");
	printf("--strcmp\n");
	printf("%d (%d)\n", STRCMP("", ""));
	printf("%d (%d)\n", STRCMP("toto", "toto"));
	printf("%d (%d)\n", STRCMP("", "toto"));
	printf("%d (%d)\n", STRCMP("toto", ""));
	printf("%d (%d)\n", STRCMP("toto", "totobar"));
	printf("-done\n");
	printf("--strcpy\n");
	printf("`%s` (`toto`)\n", ft_strcpy(buffer, "toto"));
	printf("`%s` (empty)\n", ft_strcpy(buffer, ""));
	printf("`%s` (`long message`)\n", ft_strcpy(buffer, "long message"));
	printf("-done\n");
	printf("--write\n");
	WRITE("toto", 4)
	WRITE("totototo", 4)
	WRITE("totototo", 8)
	WRITE("toto", 2)
	printf("-done\n");
	printf("--read (Makefile)\n");
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

	t_list	list;
	t_list	list_next;
	t_list	list_last;
	list.data = ft_strdup("toto");
	list.next = &list_next;
	list_next.data = ft_strdup("bar");
	list_next.next = &list_last;
	list_last.data = ft_strdup("monkaS");
	list_last.next = NULL;
	printf("--ft_list_size\n");
	printf("%d (%d)\n", ft_list_size(&list), 3);
	printf("%d (%d)\n", ft_list_size(&list_next), 2);
	printf("%d (%d)\n", ft_list_size(NULL), 0);
	printf("%d (%d)\n", ft_list_size(&list_last), 1);
	printf("-done\n");
	free(list_next.data);
	free(list_last.data);

	printf("--ft_list_push_front\n");
	t_list	*push_test = &list;
	ft_list_push_front(&push_test, ft_strdup("toto"));
	printf("added: `%s` (next: %p)\n", push_test->data, push_test->next);
	printf("new list size: %d (%d)\n", ft_list_size(push_test), 4);
	free(list.data);
	free(push_test->data);
	free(push_test);
	push_test = NULL;
	ft_list_push_front(&push_test, ft_strdup("barbar"));
	printf("added: `%s` (%p : %p)\n", push_test->data, push_test, push_test->next);
	ft_list_push_front(&push_test, NULL);
	printf("added: `%s` (%p : %p)\n", push_test->data, push_test, push_test->next);
	free(push_test->next);
	push_test->next = NULL;
	ft_list_push_front(&push_test, ft_strdup("toto_r"));
	printf("added: `%s` (%p : %p)\n", push_test->data, push_test, push_test->next);
	ft_lstclear(&push_test);
	printf("-done\n");

	printf("--ft_list_remove_if\n");
	ft_list_push_front(&push_test, ft_strdup("toto"));
	ft_list_push_front(&push_test, ft_strdup("barbar"));
	ft_list_push_front(&push_test, ft_strdup("tortor"));
	ft_list_push_front(&push_test, ft_strdup(NULL));
	printf("before: %p%d (%d)\n", push_test, ft_list_size(push_test), 3);
	ft_list_remove_if(&push_test, "", &ft_strcmp, &free);
	printf("nothing: %p%d (%d)\n", push_test, ft_list_size(push_test), 3);
	ft_list_remove_if(&push_test, "toto", &ft_strcmp, &free);
	ft_list_remove_if(&push_test, "tortor", &ft_strcmp, &free);
	ft_list_remove_if(&push_test, "barbar", &ft_strcmp, &free);
	ft_list_remove_if(&push_test, "", &ft_strcmp, &free);
	ft_list_remove_if(&push_test, NULL, &ft_strcmp, &free);
	printf("after: %p:%d (%d)\n", push_test, ft_list_size(push_test), 0);
	ft_lstclear(&push_test);
	printf("-done\n");

	printf("--ft_list_sort\n");
	ft_list_push_front(&push_test, ft_strdup("zwxy"));
	ft_list_push_front(&push_test, ft_strdup("toto"));
	ft_list_push_front(&push_test, ft_strdup("0123456"));
	ft_list_push_front(&push_test, ft_strdup("barbar"));
	ft_list_push_front(&push_test, ft_strdup("lol"));
	ft_list_push_front(&push_test, ft_strdup("tortor"));
	ft_list_push_front(&push_test, ft_strdup("mdr"));
	ft_list_push_front(&push_test, ft_strdup("0547"));
	ft_list_push_front(&push_test, ft_strdup("000"));
	ft_list_push_front(&push_test, ft_strdup("zzz"));
	printf("before:\n");
	printf_list(push_test);
	ft_list_sort(&push_test, &ft_strcmp);
	printf("after:\n");
	printf_list(push_test);
	ft_lstclear(&push_test);
	printf("-done\n");
	return (0);
}
