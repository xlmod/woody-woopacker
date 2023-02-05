
#include <string.h>
#include <elf.h>

#include <wwp.h>
#include <format/elf64.h>

int wwp_elf64_read_ehdr(struct wwp_elf64 *elf64, void *file, uint64_t size) {
	if (size < sizeof(Elf64_Ehdr))
		return -1;
	memcpy(&elf64->ehdr, file, sizeof(Elf64_Ehdr));
	if (wwp_opt.debug)
		wwp_elf64_print_ehdr(elf64);
	return 0;
}
