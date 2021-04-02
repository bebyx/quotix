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

int count_lines(const char* filename) {
  FILE *fptr;
  fptr = fopen(filename, "r");
  char c; int count = 0;
  while ((c = fgetc(fptr)) != EOF) {
   if (c == '\n')
      count++;
  }
  fclose(fptr);

  return count;
}
