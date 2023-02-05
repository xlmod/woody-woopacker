
#include <stdio.h>
#include <stdint.h>

#include <getoption/getoption.h>

#include <error.h>
#include <wwp.h>

struct wwp_opt wwp_opt;

static int wwp_checkformat(char *format) {
	wwp_opt.ftype = WWP_ELF64;	
	return 0;
}

int main(int argc, char **argv) {
	int ret;
	for (;;) {
		int c = getoption(argc, argv, "def:");
		if (c < 0)
			break;
		switch (c) {
			case 'd':
				wwp_opt.debug = 1;
				break;
			case 'e':
				wwp_opt.exec = 1;
				break;
			case 'f':
				if (wwp_checkformat(optionarg))
					return wwp_error("Format not supported!", 0);
				break;
			default:
				return wwp_error(NULL, 0);
		}
	}
	if (optionind == argc)
		return wwp_error("Not enough arguments!", 0);

	if (!wwp_opt.ftype)
		wwp_opt.ftype = WWP_ELF64;	

	struct wwp_exec exe;
	
	ret = wwp_map(&exe, argv[optionind]);
	if (ret)
		goto out;
	ret = wwp_parse(&exe);
	if (ret)
		goto out_unmap;
	ret = wwp_exec(&exe);
	if (ret)
		goto out_unmap_free;

	return 0;

out_unmap_free:
	wwp_free(&exe);
out_unmap:
	wwp_unmap(&exe);
out:
	return wwp_error(NULL, 0);
}
