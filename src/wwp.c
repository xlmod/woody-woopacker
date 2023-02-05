
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#include <wwp.h>

int wwp_map(struct wwp_exec *exe, char *filename) {
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
		return -1;
	exe->size = lseek(fd, 0, SEEK_END);
	if (exe->size <= 0)
		goto out_close;
	if (lseek(fd, 0, SEEK_SET) != 0)
		goto out_close;
	exe->file = mmap(NULL, exe->size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (exe->file == NULL)
		goto out_close;
	return 0;
out_close:
	close(fd);
	return -1;
}

int wwp_parse(struct wwp_exec *exe) {
	switch (wwp_opt.ftype) {
		case WWP_ELF64:
			return wwp_elf64_parse(&exe->format.elf64, exe->file, exe->size);
		default:
			return -1;
	}
}

int wwp_exec(struct wwp_exec *exe) {
	return 0;
}

int wwp_free(struct wwp_exec *exe) {
	return 0;
}

int wwp_unmap(struct wwp_exec *exe) {
	return 0;
}
