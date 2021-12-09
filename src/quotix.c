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

void check_content(int lines_quantity) {
  if (lines_quantity == 0)
  {
    fprintf(stderr, "No available quotes in file\n");
    exit(EXIT_FAILURE);
  }
}

int count_lines(const char* filename)
{
  FILE *fptr;
  fptr = filter_material(filename);
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

void print_random_quote(const char* filename)
{
  int lines_quantity = count_lines(filename);
  check_content(lines_quantity);


  FILE *stream;
//  fptr = fopen(filename, "r");
  int count = 0, line_number;
  char buffer[LINE_LIMIT+1] = "";

  line_number = rand() % lines_quantity;

  stream = filter_material(filename);
  while (fgets(buffer, sizeof(buffer), stream) != NULL)
  {
    // Print out random line
    if (count == line_number)
    {
      fprintf(stdout, "%s", buffer);
      fclose(stream);
      exit(0);
    }
    else
    {
      count++;
    }
  }


  fclose(stream);
}

FILE *filter_material(const char* filename) {
  char buffer[LINE_LIMIT+1] = "";

  FILE *fptr;
  fptr = fopen(filename, "r");

  fseek(fptr, 0L, SEEK_END);
  // calculating the size of the file
  long int res = ftell(fptr);
  fprintf(stdout, "Bytes: %li\n", res);
  fclose(fptr);

  char filtered_material[res];
  memset(filtered_material, 0, res*sizeof(char));

  fptr = fopen(filename, "r");
  // Let's filter out commented lines
  while (fgets(buffer, sizeof(buffer), fptr) != NULL)
  {
    if (buffer[0] == '#')
    {
      continue;
    }
    fprintf(stdout, "%s", buffer);
    strcat(filtered_material, buffer);
  }
  //fprintf(stdout, "%s", filtered_material);
  fclose(fptr);

  FILE *stream_ptr;
  stream_ptr = fmemopen(filtered_material, sizeof(filtered_material), "r");

  return stream_ptr;
}
