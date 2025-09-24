#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *restrict dst, const char *restrict src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);

int	main()
{
	//ft_strlen
	printf("ft_strlen:\n");
	printf("    \"test\"       : %ld\n", ft_strlen("test"));
	printf("    \"0123456789\" : %ld\n", ft_strlen("0123456789"));
	printf("    \"\"           : %ld\n", ft_strlen(""));


	//strcpy
	printf("\n");
	char	*dst = malloc(5 * sizeof(char));
	printf("ft_strcpy: %s\n", ft_strcpy(dst, "test"));
	printf("dst: %s\n", dst);


	//strcmp
	printf("\n");
	char	*s1 = "testA";
	char	*s2 = "test";
	printf("ft_strcmp: %i\n", ft_strcmp(s1,s2));
	printf("strcmp   : %i\n", strcmp(s1,s2));


	//write
	printf("\n");
	printf("write: %ld\n", ft_write(1, "Ceci est un test\n", 17));

	return (0);
}
