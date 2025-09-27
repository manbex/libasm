#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COLOR "\e[0;93m"
#define COLOR2 "\e[0;96m"
#define COLOR3 "\e[0;95m"
#define RESET "\e[0m"

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);


void	ft_print_list(t_list *lst)
{
	printf("Print list:\n");
	while (lst)
	{
		printf("    \"%s\"\n", (char *)lst->data);
		lst = lst->next;
	}
}

void	ft_free_list(t_list *lst)
{
	t_list	*tmp = NULL;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	//ft_atoi_base
	if (argc == 1 || !strcmp(argv[1],"ft_atoi_base") || !strcmp(argv[1],"atoi_base"))
	{
		printf("%s=== ft_atoi_base ===%s\n\n", COLOR, RESET);
	}

	//ft_list_push_front
	if (argc == 1 || !strcmp(argv[1],"ft_list_push_front") || !strcmp(argv[1],"list_push_front"))
	{
		if (argc == 1) {
			printf("\n\n");
		}
		printf("%s=== ft_list_push_front ===%s\n\n", COLOR, RESET);

		t_list	*lst = NULL;

		char	*s1 = "First";
		char	*s2 = "Second";
		char	*s3 = "Third";
		ft_print_list(lst);
		printf("\nPush front with \"First\" as data\n\n");
		ft_list_push_front(&lst, (void *)s1);
		ft_print_list(lst);

		printf("\nPush front with \"Second\" as data\n\n");
		ft_list_push_front(&lst, (void *)s2);
		ft_print_list(lst);

		printf("\nPush front with \"Third\" as data\n\n");
		ft_list_push_front(&lst, (void *)s3);
		ft_print_list(lst);

		ft_free_list(lst);
	}

	//ft_list_size
	if (argc == 1 || !strcmp(argv[1],"ft_list_size") || !strcmp(argv[1],"list_size"))
	{
		if (argc == 1) {
			printf("\n\n");
		}
		printf("%s=== ft_list_size ===%s\n\n", COLOR, RESET);

		t_list	*lst = NULL;

		ft_print_list(lst);
		printf("\n%sft_list_size:%s %d\n\n\n", COLOR2, RESET, ft_list_size(lst));
		ft_free_list(lst);
	
		ft_list_push_front(&lst, (void *)"3");
		ft_list_push_front(&lst, (void *)"2");
		ft_list_push_front(&lst, (void *)"1");
		ft_list_push_front(&lst, (void *)"0");
		ft_print_list(lst);
		printf("\n%sft_list_size:%s %d\n\n\n", COLOR2, RESET, ft_list_size(lst));
		ft_free_list(lst);
		lst = NULL;

		ft_list_push_front(&lst, (void *)"9");
		ft_list_push_front(&lst, (void *)"8");
		ft_list_push_front(&lst, (void *)"7");
		ft_list_push_front(&lst, (void *)"6");
		ft_list_push_front(&lst, (void *)"5");
		ft_list_push_front(&lst, (void *)"4");
		ft_list_push_front(&lst, (void *)"3");
		ft_list_push_front(&lst, (void *)"2");
		ft_list_push_front(&lst, (void *)"1");
		ft_list_push_front(&lst, (void *)"0");
		ft_print_list(lst);
		printf("\n%sft_list_size:%s %d\n", COLOR2, RESET, ft_list_size(lst));
		ft_free_list(lst);
		lst = NULL;
	}

	//ft_list_sort
	if (argc == 1 || !strcmp(argv[1],"ft_list_sort") || !strcmp(argv[1],"list_sort"))
	{
		if (argc == 1) {
			printf("\n\n");
		}
		printf("%s=== ft_list_sort ===%s\n\n", COLOR, RESET);
	}
	printf("\n");
	return (0);
}
