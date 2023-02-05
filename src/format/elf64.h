
#ifndef FORMAT_ELF64_H
#define FORMAT_ELF64_H

#include <stdint.h>
#include <elf.h>

struct wwp_elf64 {
	Elf64_Ehdr ehdr;
};

int wwp_elf64_parse(struct wwp_elf64 *elf64, void *file, uint64_t size);
int wwp_elf64_read_ehdr(struct wwp_elf64 *elf64, void *file, uint64_t size);
int wwp_elf64_print_ehdr(struct wwp_elf64 *elf64);

#endif // FORMAT_ELF64_H
