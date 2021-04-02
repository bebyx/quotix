#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "quotix.h"

void check_file(const char* filename) {
  FILE *fptr;
  if ((fptr = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Error %d: %s\n", errno, strerror(errno));
    exit(EXIT_FAILURE);
  } else {
    fclose(fptr);
  }

}
