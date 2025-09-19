#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
ssize_t	ft_write(int fd, const void *buf, size_t count);

int	main()
{
	//printf("strlen: %ld\n", ft_strlen("ceci est un test"));
	printf("out: %ld\n", ft_write(1, "Ceci est un test\n", 17));
	return (0);
}
