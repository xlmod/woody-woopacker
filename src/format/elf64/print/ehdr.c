
#include <stdio.h>
#include <elf.h>

#include <format/elf64.h>

static void wwp_elf64_print_ehdr_magic(Elf64_Ehdr *ehdr) {
	printf("\tMagic:  ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf(" %2x", ehdr->e_ident[i]);
	printf("\n");
}

static void wwp_elf64_print_ehdr_class(Elf64_Ehdr *ehdr) {
	char *title = "Class:";
	char *content;
	switch (ehdr->e_ident[EI_CLASS]) {
		case ELFCLASSNONE:
			content = "None";
			break;
		case ELFCLASS32:
			content = "ELF32";
			break;
		case ELFCLASS64:
			content = "ELF64";
			break;
		default:
			content = "Error";
	}
	printf("\t%-20s %s\n", title, content);
}

static void wwp_elf64_print_ehdr_data(Elf64_Ehdr *ehdr) {
	char *title = "Data:";
	char *content;
	switch (ehdr->e_ident[EI_DATA]) {
		case ELFDATA2LSB:
			content = "2's complement, little endian";
			break;
		case ELFDATA2MSB:
			content = "2's complement, big endian";
			break;
		default:
			content = "Invalid data encoding";
	}
	printf("\t%-20s %s\n", title, content);
}

static void wwp_elf64_print_ehdr_iversion(Elf64_Ehdr *ehdr) {
	uint8_t v = ehdr->e_ident[EI_VERSION];
	printf("\t%-20s %d (%scurrent)\n", "Version:", v, v == EV_CURRENT ? "" : "not ");
}

static void wwp_elf64_print_ehdr_osabi(Elf64_Ehdr *ehdr) {
	char *title = "OS/ABI:";
	char *content;
	switch (ehdr->e_ident[EI_OSABI]) {
		case ELFOSABI_SYSV:
			content = "UNIX System V ABI"; break;
		case ELFOSABI_HPUX:
			content = "HP-UX"; break;
		case ELFOSABI_NETBSD:
			content = "NetBSD."; break;
		case ELFOSABI_GNU:
			content = "Object uses GNU ELF extensions."; break;
		case ELFOSABI_SOLARIS:
			content = "Sun Solaris."; break;
		case ELFOSABI_AIX:
			content = "IBM AIX."; break;
		case ELFOSABI_IRIX:
			content = "SGI Irix."; break;
		case ELFOSABI_FREEBSD:
			content = "FreeBSD."; break;
		case ELFOSABI_TRU64:
			content = "Compaq TRU64 UNIX."; break;
		case ELFOSABI_MODESTO:
			content = "Novell Modesto."; break;
		case ELFOSABI_OPENBSD:
			content = "OpenBSD."; break;
		case ELFOSABI_ARM_AEABI:
			content = "ARM EABI"; break;
		case ELFOSABI_ARM:
			content = "ARM"; break;
		case ELFOSABI_STANDALONE:
			content = "Standalone (embedded) application"; break;
		default:
			content = "Unknonw";
	}
	printf("\t%-20s %s\n", title, content);

}

static void wwp_elf64_print_ehdr_type(Elf64_Ehdr *ehdr) {
	char *title = "Type:";
	char *content;
	switch (ehdr->e_type) {
		case ET_NONE:
			content = "No file type"; break;
		case ET_REL:
			content = "REL"; break;
		case ET_EXEC:
			content = "EXEC"; break;
		case ET_DYN:
			content = "DYN"; break;
		case ET_CORE:
			content = "CORE"; break;
		default:
			content = "Unknonw";
	}
	printf("\t%-20s %s\n", title, content);
}

int wwp_elf64_print_ehdr(struct wwp_elf64 *elf64) {
	printf("ELF Header:\n");
	wwp_elf64_print_ehdr_magic(&elf64->ehdr);
	wwp_elf64_print_ehdr_class(&elf64->ehdr);
	wwp_elf64_print_ehdr_data(&elf64->ehdr);
	wwp_elf64_print_ehdr_iversion(&elf64->ehdr);
	wwp_elf64_print_ehdr_osabi(&elf64->ehdr);
	printf("\t%-20s %d\n", "OS/ABI Version:", elf64->ehdr.e_ident[EI_ABIVERSION]);
	wwp_elf64_print_ehdr_type(&elf64->ehdr);
	return 0;
}
