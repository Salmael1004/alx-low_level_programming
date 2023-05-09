#include "main.h"

/**
 * append_text_to_file - that appends text at the end of a file
 * @filename: variable pointer
 * @text_content: content file
 * Description: function that appends text at the end of a file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file, idk, len;

	file = idk = len = 0;
	if (!filename)
		return (-1);

	else if (!text_content || !text_content[0])
		return (1);

	file = open(filename, O_WRONLY | O_APPEND);

	if (file < 0)
		return (-1);

	while (text_content[len])
		len++;

	idk = write(file, text_content, len);
	if (idk < 0)
		return (-1);

	close(file);
	return (1);
}
