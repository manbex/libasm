#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define COLOR "\e[0;93m"
#define COLOR2 "\e[0;96m"
#define COLOR3 "\e[0;95m"
#define RESET "\e[0m"

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *restrict dst, const char *restrict src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);

int	main(int argc, char **argv)
{
	//ft_strlen
	if (argc == 1 || !strcmp(argv[1],"ft_strlen") || !strcmp(argv[1],"strlen"))
	{
		printf("%s=== ft_strlen ===%s\n\n", COLOR, RESET);

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
		printf("%s=== ft_strcpy ===%s\n\n", COLOR, RESET);

		char	*dst = malloc(5 * sizeof(char));
		printf("ft_strcpy: %s\n", ft_strcpy(dst, "test"));
		printf("dst: %s\n", dst);
		free(dst);
	}

	//strcmp
	if (argc == 1 || !strcmp(argv[1],"ft_strcmp") || !strcmp(argv[1],"strcmp"))
	{
		if (argc == 1) {
			printf("\n\n");
		}
		printf("%s=== ft_strcmp ===%s\n\n", COLOR, RESET);
	
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
		printf("%s=== ft_write ===%s\n\n", COLOR, RESET);
	
		char	*s1 = "This is a string";
		int		len1 = ft_strlen(s1);
		int		fd = 1;

		printf("test with string %s\"This is a string\"%s (16 characters): \n\n", COLOR3, RESET);

		printf("%sft_write:%s\n    output: ", COLOR2, RESET);
		fflush(stdout);
		int	ret = ft_write(fd, s1, len1);
		printf("\n");
		printf("    return: %d\n", ret);
		printf("    errno: %d\n\n", errno);
	
		printf("%swrite:%s\n    output: ", COLOR2, RESET);
		fflush(stdout);
		ret = write(fd, s1, len1);
		printf("\n");
		printf("    return: %d\n", ret);
		printf("    errno: %d\n\n", errno);

		fd = -1;
		printf("\nTest with invalid fd -1:\n\n");

		printf("%sft_write:%s\n    output: ", COLOR2, RESET);
		fflush(stdout);
		ret = ft_write(fd, s1, len1);
		printf("\n");
		printf("    return: %d\n", ret);
		printf("    errno: %d\n\n", errno);
	
		printf("%swrite:%s\n    output: ", COLOR2, RESET);
		fflush(stdout);
		ret = write(fd, s1, len1);
		printf("\n");
		printf("    return: %d\n", ret);
		printf("    errno: %d\n", errno);
	}

	//read
	if (argc == 1 || !strcmp(argv[1],"ft_read") || !strcmp(argv[1],"read"))
	{
		if (argc == 1) {
			printf("\n\n");
		}
		printf("%s=== ft_read ===%s\n\n", COLOR, RESET);


		char	buf[1024];
		int		fd = open("file.txt", 0);
		int		ret;
		errno = 0;

		printf("read file containing %s\"This is a test\\n\"%s (15 characters) in buffer of size 1024: \n\n", COLOR3, RESET);

		bzero(buf, 1024);
		ret = ft_read(fd, buf, 1024);
		printf("%sft_read:%s\n", COLOR2, RESET);
		printf("    return: %d\n", ret);
		printf("    buffer: %s", buf);
		printf("    errno : %d\n\n", errno);
		lseek(fd, 0, SEEK_SET);

		bzero(buf, 1024);
		ret = read(fd, buf, 1024);
		printf("%sread:%s\n", COLOR2, RESET);
		printf("    return: %d\n", ret);
		printf("    buffer: %s", buf);
		printf("    errno : %d\n\n", errno);
		lseek(fd, 0, SEEK_SET);

		printf("\ntest with invalid fd -1:\n\n");

		bzero(buf, 1024);
		ret = ft_read(-1, buf, 1024);
		printf("%sft_read:%s\n", COLOR2, RESET);
		printf("    return: %d\n", ret);
		printf("    buffer: %s\n", buf);
		printf("    errno : %d\n\n", errno);

		bzero(buf, 1024);
		ret = read(-1, buf, 1024);
		printf("%sread:%s\n", COLOR2, RESET);
		printf("    return: %d\n", ret);
		printf("    buffer: %s\n", buf);
		printf("    errno : %d\n\n", errno);

		printf("\ntest partial read of size 7:\n\n");

		errno = 0;
		bzero(buf, 1024);
		ret = ft_read(fd, buf, 7);
		printf("%sft_read:%s\n", COLOR2, RESET);
		printf("    return: %d\n", ret);
		printf("    buffer: %s\n", buf);
		printf("    errno : %d\n\n", errno);

		bzero(buf, 1024);
		ret = read(fd, buf, 7);
		printf("%sread:%s\n", COLOR2, RESET);
		printf("    return: %d\n", ret);
		printf("    buffer: %s\n", buf);
		printf("    errno : %d\n\n", errno);

		close(fd);
	}

	//strdup
	if (argc == 1 || !strcmp(argv[1],"ft_strdup") || !strcmp(argv[1],"strdup"))
	{
		if (argc == 1) {
			printf("\n\n");
		}
		printf("%s=== ft_strdup ===%s\n\n", COLOR, RESET);

		char	*s1 = ft_strdup("This is a test");
		(void)s1;
		printf("string: %s\n", s1);
		free(s1);
	}
	printf("\n");

	return (0);
}
