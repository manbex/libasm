#include <stdio.h>
#include <string.h>

#define COLOR "\e[0;93m"
#define COLOR2 "\e[0;96m"
#define COLOR3 "\e[0;95m"
#define RESET "\e[0m"

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
	}

	//ft_list_size
	if (argc == 1 || !strcmp(argv[1],"ft_list_size") || !strcmp(argv[1],"list_size"))
	{
		if (argc == 1) {
			printf("\n\n");
		}
		printf("%s=== ft_list_size ===%s\n\n", COLOR, RESET);
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
