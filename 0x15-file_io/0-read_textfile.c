#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX
 * @filename: points to the file that we will be receiving
 * @letters: size of letters to read in
 * file: file
 * read_f: read file
 * write_f: write file
 * close_f: close file
 *
 * Return: the read file
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file = 0, read_f = 0, write_f = 0, close_f;
	char *buffer;

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	read_f = read(file, buffer, letters);
	if (read_f == -1)
		return (0);

	write_f = write(STDOUT_FILENO, buffer, read_f);
	if (write_f == -1)
		return (0);

	close_f = close(file);
	if (close_f == -1)
		return (0);

	free(buffer);
	return (read_f);
}
