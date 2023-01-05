#include "get_next_line.h"
#include "so_long.h"
#include <string.h>

int	item_chr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && c != s[i])
		i++;
	if (c == s[i])
		return (i);
	return (0);
}
