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

void check_line(const int line_count, const int char_count)
{
  if(char_count >= LINE_LIMIT)
  {
    fprintf(stderr, "Error: Line's too long: %d\nExiting...\n", line_count);
    exit(EXIT_FAILURE);
  }
}

int count_lines(const char* filename)
{
  FILE *fptr;
  fptr = fopen(filename, "r");
  char c; int line_count = 0, char_count = 0;
  while ((c = fgetc(fptr)) != EOF)
  {
   if (c == '\n')
   {
      line_count++;
      check_line(line_count, char_count);
      char_count = 0;
   }
   else
   {
     char_count++;
   }
  }

  fclose(fptr);

  return line_count;
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

void print_random_quote(const char* filename, int lines_quantity)
{
  FILE *fptr;
  fptr = fopen(filename, "r");
  int count = 0, line_number;
  char buffer[LINE_LIMIT+1] = "";

  line_number = rand() % lines_quantity;
  while (fgets(buffer, sizeof(buffer), fptr) != NULL)
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
