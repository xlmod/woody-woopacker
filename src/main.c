
#include <stdio.h>

#include <getoption/getoption.h>

int main(int argc, char **argv) {

	printf("addr: %p\n", &main);
	int c = 0;
	while ((c = getoption(argc, argv, "abc:d")) > 0) {
		printf("arg: '%c' (%s)\n", c, optionarg);
	}
	for (int i = optionind; i < argc; i++)
		printf(" argv[%d] = %s\n", i, argv[i]);
	return 0;
}
