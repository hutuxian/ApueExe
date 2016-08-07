#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	DIR *dp;
	struct dirent *dirp;
	if (argc != 2) {
		printf("argument error...\n");
	}
	if ((dp = opendir(argv[1])) == NULL) {
		printf("cannot open...\n");
	}
	while ((dirp = readdir(dp)) != NULL) {
		printf("%s\n", dirp->d_name);
	}
	closedir(dp);
	exit(0);
}
