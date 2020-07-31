#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "get_next_line.h"

int	main()
{
	char	*line;
	char	*line1;
	int		fd;
	int		fd1;
	int		des;
	int		des1;
	int		i;

	fd = open("text.txt", O_RDONLY);
	fd1 = open("text1.txt", O_RDONLY);
	des1 = 1;
	i = 0;
	while (des1 == 1)
	{
		if (i % 2 == 0)
		{
			des = get_next_line(fd, &line);
			printf("%s, %d\n", line, des);
			free(line);
		}
		else
		{
			des1 = (get_next_line(fd1, &line1));
			printf("%s, %d\n", line1, des1);
			free(line1);
		}
		i++;
	}
	printf("%s, %d\n", line1, des1);
}
