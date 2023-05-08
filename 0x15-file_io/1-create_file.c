#include "main.h"

/**
 * create_file - create a function that creates a file
 * @filename: points to file that we will be receiving
 * @text_content: the text that is being written
 *
 * Return: 1 if success
 */
int create_file(const char *filename, char *text_content)
{
	int close_file, write_file, len;

	len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	close_file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	write_file = write(close_file, text_content, len);

	if (close_file == -1 || write_file == -1)
		return (-1);

	close(close_file);

	return (1);
}
