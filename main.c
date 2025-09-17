#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);

int	main()
{
	printf("out: %ld\n", ft_strlen("ceci est un test"));
	return (0);
}
