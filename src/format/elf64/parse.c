
#include <elf.h>
#include <string.h>

#include <error.h>
#include <format/elf64.h>

int wwp_elf64_parse(struct wwp_elf64 *elf64, void *file, uint64_t size) {
	if (wwp_elf64_read_ehdr(elf64, file, size))
		return -1;
	if (memcmp(elf64->ehdr.e_ident, ELFMAG, SELFMAG))
		return wwp_error("Not a valid elf file!", 0);
	return 0;
}
