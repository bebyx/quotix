#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#include "quotix.h"

int main(int argc, char const *argv[]) {
  /*
  open file with a quote per line
  check number of lines
  choose one of the lines randomly
  display a quote from a chosen line
  clean, close file, etc.
  */

  FILE *fptr;
  char buffer[200];
  const char filename[] = "quotes.txt";
  int lines_count;

  check_file(filename);

  lines_count = count_lines(filename);

  fptr = fopen(filename, "r");
  printf("Total number of lines are: %d\n", lines_count);

  int count = 0;
  srand(time(0));
  int line_number = rand() % lines_count;
  printf("%d\n", line_number);
  while (fgets(buffer, sizeof buffer, fptr) != NULL) {
    if (count == line_number) {
      printf("%s", buffer);
      fclose(fptr);
      return 0;
    }
    else {
      count++;
    }
  }

  fclose(fptr);
  return 0;
}
