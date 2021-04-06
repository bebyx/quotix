#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include "quotix.h"

void check_file(const char* filename)
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

int count_lines(const char* filename)
{
  FILE *fptr;
  fptr = fopen(filename, "r");
  char c; int count = 0;
  while ((fgetc(fptr)) != EOF)
  while ((c = fgetc(fptr)) != EOF)
  {
   if (c == '\n')
      count++;
  }
  fclose(fptr);

  return count;
}

void seed_random(const char* iteration)
{
  if (strcmp(iteration, "second") == 0)
    srand(time(0));
  else if (strcmp(iteration, "minute") == 0)
    srand(time(0)/60);
  else if (strcmp(iteration, "hour") == 0)
    srand(time(0)/60/60);
  else if (strcmp(iteration, "hour") == 0)
    srand(time(0)/60/60/24);
}

void print_random_quote(const char* filename, int lines_count)
{
  FILE *fptr;
  fptr = fopen(filename, "r");
  int count = 0, line_number;
  char buffer[1025];

  line_number = rand() % lines_count;
  while (fgets(buffer, sizeof buffer, fptr) != NULL)
  {
    if (count == line_number)
    {
      fprintf(stdout, "%s", buffer);
      fclose(fptr);
      exit(0);
    }
    else
    {
      count++;
    }
  }

  fclose(fptr);
}
