#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *restrict dst, const char *restrict src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);

int	main(int argc, char **argv)
{
	//ft_strlen
	if (argc == 1 || !strcmp(argv[1],"ft_strlen") || !strcmp(argv[1],"strlen"))
	{
		printf("=== ft_strlen ===\n\n");

		printf("\"test\"       : %ld\n", ft_strlen("test"));
		printf("\"0123456789\" : %ld\n", ft_strlen("0123456789"));
		printf("\"\"           : %ld\n", ft_strlen(""));
	}

	//strcpy
	if (argc == 1 || !strcmp(argv[1],"ft_strcpy") || !strcmp(argv[1],"strcpy"))
	{
		if (argc == 1) {
			printf("\n\n");
		}
		printf("=== ft_strcpy ===\n\n");

		char	*dst = malloc(5 * sizeof(char));
		printf("ft_strcpy: %s\n", ft_strcpy(dst, "test"));
		printf("dst: %s\n", dst);
	}

	//strcmp
	if (argc == 1 || !strcmp(argv[1],"ft_strcmp") || !strcmp(argv[1],"strcmp"))
	{
		if (argc == 1) {
			printf("\n\n");
		}
		printf("=== ft_strcmp ===\n\n");
	
		char	*s1 = "testA";
		char	*s2 = "test";
		printf("ft_strcmp: %i\n", ft_strcmp(s1,s2));
		printf("strcmp   : %i\n", strcmp(s1,s2));
	}

	//write
	if (argc == 1 || !strcmp(argv[1],"ft_write") || !strcmp(argv[1],"write"))
	{
		if (argc == 1) {
			printf("\n\n");
		}
		printf("=== ft_write ===\n\n");
	
		char	*s1 = "This is a string";
		int		len1 = ft_strlen(s1);
		int		fd = 1;

		printf("test with string \"This is a string\" (16 characters): \n\n");

		printf("ft_write:\n    output: ");
		fflush(stdout);
		int	ret = ft_write(fd, s1, len1);
		printf("\n");
		printf("    return: %d\n", ret);
		printf("    errno: %d\n\n", errno);
	
		printf("write:\n    output: ");
		fflush(stdout);
		ret = write(fd, s1, len1);
		printf("\n");
		printf("    return: %d\n", ret);
		printf("    errno: %d\n\n", errno);

		fd = -1;
		printf("\nTest with invalid fd -1:\n\n");

		printf("ft_write:\n    output: ");
		fflush(stdout);
		ret = ft_write(fd, s1, len1);
		printf("\n");
		printf("    return: %d\n", ret);
		printf("    errno: %d\n\n", errno);
	
		printf("write:\n    output: ");
		fflush(stdout);
		ret = write(fd, s1, len1);
		printf("\n");
		printf("    return: %d\n", ret);
		printf("    errno: %d\n", errno);
	}

	return (0);
}
