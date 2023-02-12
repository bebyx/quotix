#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "checks.h"

void check_file(const char *filename)
{
  FILE *fptr;

  if ((fptr = fopen(filename, "r")) == NULL)
  {
    fprintf(stderr, "File error %d: %s — '%s'\n", errno, strerror(errno), filename);
    exit(EXIT_FAILURE);
  }
  else
  {
    fclose(fptr);
  }
}

void check_line(const int line_count, const int char_count)
{
  if (char_count >= LINE_LIMIT)
  {
    fprintf(stderr, "Error: Line's too long: %d\nExiting...\n", line_count);
    exit(EXIT_FAILURE);
  }
}

void check_content(int lines_quantity)
{
  if (lines_quantity == 0)
  {
    fprintf(stderr, "No available quotes in file\n");
    exit(EXIT_FAILURE);
  }
}
