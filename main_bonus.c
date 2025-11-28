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

int		ft_atoi_base(char *str, char *base);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));


void	ft_print_list(t_list *lst)
{
	printf("Print list:\n");
	while (lst)
	{
		printf("    \"%s\"\n", (char *)lst->data);
		lst = lst->next;
	}
}

void	ft_free_list(t_list *lst, void (*f)(void *))
{
	t_list	*tmp = NULL;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		if (f){
			f(tmp->data);
		}
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	//ft_atoi_base
	if (argc == 1 || !strcmp(argv[1],"ft_atoi_base") || !strcmp(argv[1],"atoi_base"))
	{
		printf("%s=== ft_atoi_base ===%s\n\n", COLOR, RESET);

		char	*str1 = "-42sdf123123123";
		char	*base1 = "0123456789";
		char	*str2 = "    	00101010";
		char	*base2 = "01";
		char	*str3 = "    ++++-----+2Ajsldj";
		char	*base3 = "0123456789ABCDEF";
		char	*base4 = "1";
		char	*base5 = "000123";
		char	*base6 = "+0123";

		printf("Test on %s\"%s\"%s with %s\"%s\"%s:\n", COLOR3, str1, RESET, COLOR3, base1, RESET);
		printf("%sft_atoi_base:%s %d\n\n", COLOR2, RESET, ft_atoi_base(str1, base1));
		printf("Test on %s\"%s\"%s with %s\"%s\"%s:\n", COLOR3, str2, RESET, COLOR3, base2, RESET);
		printf("%sft_atoi_base:%s %d\n\n", COLOR2, RESET, ft_atoi_base(str2, base2));
		printf("Test on %s\"%s\"%s with %s\"%s\"%s:\n", COLOR3, str3, RESET, COLOR3, base3, RESET);
		printf("%sft_atoi_base:%s %d\n\n", COLOR2, RESET, ft_atoi_base(str3, base3));
		printf("Test with incorrect base %s\"%s\"%s:\n", COLOR3, base4, RESET);
		printf("%sft_atoi_base:%s %d\n\n", COLOR2, RESET, ft_atoi_base("42", base4));
		printf("Test with incorrect base %s\"%s\"%s:\n", COLOR3, base5, RESET);
		printf("%sft_atoi_base:%s %d\n\n", COLOR2, RESET, ft_atoi_base("42", base5));
		printf("Test with incorrect base %s\"%s\"%s:\n", COLOR3, base6, RESET);
		printf("%sft_atoi_base:%s %d\n\n", COLOR2, RESET, ft_atoi_base("42", base6));
		printf("Test with %sNULL%s parameters:\n", COLOR2, RESET);
		printf("%sft_atoi_base:%s %d\n", COLOR2, RESET, ft_atoi_base(NULL, NULL));
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
		printf("\nPush front with %s\"First\"%s as data\n\n", COLOR3, RESET);
		ft_list_push_front(&lst, s1);
		ft_print_list(lst);

		printf("\nPush front with %s\"Second\"%s as data\n\n", COLOR3, RESET);
		ft_list_push_front(&lst, s2);
		ft_print_list(lst);

		printf("\nPush front with %s\"Third\"%s as data\n\n", COLOR3, RESET);
		ft_list_push_front(&lst, s3);
		ft_print_list(lst);

		ft_free_list(lst, NULL);
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
		ft_free_list(lst, NULL);
	
		ft_list_push_front(&lst, "3");
		ft_list_push_front(&lst, "2");
		ft_list_push_front(&lst, "1");
		ft_list_push_front(&lst, "0");
		ft_print_list(lst);
		printf("\n%sft_list_size:%s %d\n\n\n", COLOR2, RESET, ft_list_size(lst));
		ft_free_list(lst, NULL);
		lst = NULL;

		ft_list_push_front(&lst, "9");
		ft_list_push_front(&lst, "8");
		ft_list_push_front(&lst, "7");
		ft_list_push_front(&lst, "6");
		ft_list_push_front(&lst, "5");
		ft_list_push_front(&lst, "4");
		ft_list_push_front(&lst, "3");
		ft_list_push_front(&lst, "2");
		ft_list_push_front(&lst, "1");
		ft_list_push_front(&lst, "0");
		ft_print_list(lst);
		printf("\n%sft_list_size:%s %d\n", COLOR2, RESET, ft_list_size(lst));
		ft_free_list(lst, NULL);
		lst = NULL;
	}

	//ft_list_sort
	if (argc == 1 || !strcmp(argv[1],"ft_list_sort") || !strcmp(argv[1],"list_sort"))
	{
		if (argc == 1) {
			printf("\n\n");
		}
		printf("%s=== ft_list_sort ===%s\n\n", COLOR, RESET);

		t_list	*lst = NULL;
		ft_list_push_front(&lst, "9");
		ft_list_push_front(&lst, "6");
		ft_list_push_front(&lst, "1");
		ft_list_push_front(&lst, "4");
		ft_list_push_front(&lst, "7");
		ft_list_push_front(&lst, "3");
		ft_list_push_front(&lst, "0");
		ft_list_push_front(&lst, "8");
		ft_list_push_front(&lst, "2");
		ft_list_push_front(&lst, "5");
		ft_print_list(lst);
		printf("\n%sft_list_sort:%s\n\n", COLOR2, RESET);
		ft_list_sort(&lst, &strcmp);
		ft_print_list(lst);
		ft_free_list(lst, NULL);
		lst = NULL;
	}

	//ft_list_remove_if
	if (argc == 1 || !strcmp(argv[1],"ft_list_remove_if") || !strcmp(argv[1],"list_remove_if"))
	{
		if (argc == 1) {
			printf("\n\n");
		}
		printf("%s=== ft_list_remove_if ===%s\n\n", COLOR, RESET);

		t_list	*lst = NULL;
		ft_list_push_front(&lst, strdup("truth"));
		ft_list_push_front(&lst, strdup("false"));
		ft_list_push_front(&lst, strdup("truth"));
		ft_list_push_front(&lst, strdup("truth"));
		ft_list_push_front(&lst, strdup("truth"));
		ft_list_push_front(&lst, strdup("false"));
		ft_list_push_front(&lst, strdup("truth"));
		ft_list_push_front(&lst, strdup("false"));
		ft_list_push_front(&lst, strdup("truth"));
		ft_print_list(lst);
		printf("\n%sft_list_remove_if strcmp \"truth\":%s\n\n", COLOR2, RESET);
		ft_list_remove_if(&lst, "truth", strcmp, free);

		ft_print_list(lst);
		ft_free_list(lst, free);
	}
	printf("\n");
	return (0);
}
