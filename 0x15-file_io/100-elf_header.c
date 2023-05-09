#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *elf_id);
void elf_magic(unsigned char *elf_id);
void elf_class(unsigned char *elf_id);
void elf_data(unsigned char *elf_id);
void elf_version(unsigned char *elf_id);
void elf_abi(unsigned char *elf_id);
void elf_osabi(unsigned char *elf_id);
void elf_type(unsigned int el_typ, unsigned char *elf_id);
void elf_entry(unsigned long int el_ent, unsigned char *e_id);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file.
 * @elf_id: A pointer to an array containing the ELF magic numbers.
 * If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *elf_id)
{
	int jiwoong;

	for (jiwoong = 0; jiwoong < 4; jiwoong++)
	{
		if (elf_id[jiwoong] != 127 &&
		elf_id[jiwoong] != 'E' &&
		elf_id[jiwoong] != 'L' &&
		elf_id[jiwoong] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * elf_magic - Prints the magic numbers of an ELF header.
 * @elf_id: A pointer to an array containing the ELF magic numbers.
 * Magic numbers are separated by spaces.
 */
void elf_magic(unsigned char *elf_id)
{
	int jiwoong;

	printf("  Magic:   ");

	for (jiwoong = 0; jiwoong < EI_NIDENT; jiwoong++)
	{
		printf("%02x", elf_id[jiwoong]);

		if (jiwoong == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * elf_class - Prints the class of an ELF header.
 * @elf_id: A pointer to an array containing the ELF magic numbers.
 */
void elf_class(unsigned char *elf_id)
{
	printf("  Class:                             ");

	switch (elf_id[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_id[EI_CLASS]);
	}
}
/**
 * elf_data - Prints the data of an ELF header.
 * @elf_id: A pointer to an array containing the ELF magic numbers.
 */
void elf_data(unsigned char *elf_id)
{
	printf("  Data:                              ");

	switch (elf_id[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_id[EI_CLASS]);
	}
}
/**
 * elf_version - Prints the version of an ELF header.
 * @elf_id: A pointer to an array containing the ELF magic numbers.
 */
void elf_version(unsigned char *elf_id)
{
	printf("  Version:                           %d",
			elf_id[EI_VERSION]);

	switch (elf_id[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}
/**
 * elf_abi - Prints the ABI version of an ELF header.
 * @elf_id: A pointer to an array containing the ELF magic numbers.
 */
void elf_abi(unsigned char *elf_id)
{
	printf("  ABI Version:                       %d\n",
			elf_id[EI_ABIVERSION]);
}
/**
 * elf_osabi - Prints the OS/ABI of an ELF header.
 * @elf_id: A pointer to an array containing the ELF magic numbers.
 */
void elf_osabi(unsigned char *elf_id)
{
	printf("  OS/ABI:                            ");

	switch (elf_id[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_id[EI_OSABI]);
	}
}
/**
 * elf_type - Prints the type of an ELF header.
 * @el_typ: The ELF type.
 * @elf_id: A pointer to an array containing the ELF magic numbers.
 */
void elf_type(unsigned int el_typ, unsigned char *elf_id)
{
	if (elf_id[EI_DATA] == ELFDATA2MSB)
		el_typ >>= 8;

	printf("  Type:                              ");
	switch (el_typ)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", el_typ);
	}
}
/**
 * elf_entry - Prints the entry point of an ELF header.
 * @elf_id: A pointer to an array containing the ELF magic numbers.
 * @el_ent: The address of the ELF entry point.
 */
void elf_entry(unsigned long int el_ent, unsigned char *elf_id)
{
	printf("  Entry point address:               ");

	if (elf_id[EI_DATA] == ELFDATA2MSB)
	{
		el_ent = ((el_ent << 8) & 0xFF00FF00) |
			((el_ent >> 8) & 0xFF00FF);
		el_ent = (el_ent << 16) | (el_ent >> 16);
	}

	if (elf_id[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)el_ent);

	else
		printf("%#lx\n", el_ent);
}
/**
 * close_elf - Closes an ELF file.
 * If the file cannot be closed - exit code 98.
 * @elf: The file descriptor of the ELF file.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * If the file is not an ELF File or
 * the function fails - exit code 98.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int hao, bin;

	hao = open(argv[1], O_RDONLY);
	if (hao == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(hao);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	bin = read(hao, header, sizeof(Elf64_Ehdr));
	if (bin == -1)
	{
		free(header);
		close_elf(hao);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	elf_magic(header->e_ident);
	elf_class(header->e_ident);
	elf_data(header->e_ident);
	elf_version(header->e_ident);
	elf_osabi(header->e_ident);
	elf_abi(header->e_ident);
	elf_type(header->e_type, header->e_ident);
	elf_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(hao);
	return (0);
}
