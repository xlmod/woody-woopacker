
#ifndef WWP_H
#define WWP_H

#include <stdint.h>

#include <format/elf64.h>

struct wwp_opt {
	int debug;
	int exec;
	int ftype;
};

extern struct wwp_opt wwp_opt;

enum wwp_format_type {
	WWP_ELF64 = 1,
};

struct wwp_exec {
	union {
		struct wwp_elf64 elf64;
	} format;
	void *file;
	uint64_t size;
};

int wwp_map(struct wwp_exec *exe, char *filename);
int wwp_parse(struct wwp_exec *exe);
int wwp_exec(struct wwp_exec *exe);
int wwp_free(struct wwp_exec *exe);
int wwp_unmap(struct wwp_exec *exe);

#endif // WWP_H
