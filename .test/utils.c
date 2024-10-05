
#include <fcntl.h>
#include <stdlib.h>
#define BUFFER_SIZE 100

typedef struct s_data t_data;
struct s_data
{
	char	*buffer;
	t_data	*next;
};

static t_data	*data_read(int fd)
{
	t_data	*data = malloc(sizeof(*data));
	data->buffer = malloc(BUFFER_SIZE);
	if (read(fd, data->buffer, BUFFER_SIZE) == BUFFER_SIZE)
		data->next = data_read(fd);
	return (data);
}

static t_size	data_len(t_data *data)
{
	if (!data->next)
		return (strlen(data->buffer));
	return (BUFFER_SIZE + data_len(data->next));
}

static void	data_write(char *dst, t_data *data)
{
	int		limit = BUFFER_SIZE;
	char	*buffer = data->buffer;
	while (limit-- && *(buffer))
		*(dst++) = *(buffer++);
	free(data->buffer);
	if (data->next)
		data_write(dst, data->next);
	free(data);
}

char	*file_read(const char *path)
{
	int		fd = open(path, O_RDONLY);
	t_data	*data;
	t_size	len;
	char	*res;

	if (fd == -1) return (0);
	data = data_read(fd);
	close(fd);
	len = data_len(data);
	res = malloc(len);
	data_write(res, data);
	return (res);
}