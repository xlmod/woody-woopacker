
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include <error.h>

int wwp_error(char *str, int iserrno) {
	if (iserrno)
		str = strerror(errno);
	if (str)
		fprintf(stderr, "wwp: %s\n", str);
	return -1;
}
