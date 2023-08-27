#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "core.h"
#include "checks.h"

int count_lines(const char *filename)
{
  FILE *stream;
  char *filtered_material;
  int line_count = 0, char_count = 0;
  char c;

  filtered_material = filter_material(filename);
  stream = streamify(filtered_material);
  // Count all available lines
  while ((c = fgetc(stream)) != EOF)
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

  fclose(stream);
  free(filtered_material);

  return line_count;
}

void seed_random(const char *iteration)
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

void print_random_quote(const char *filename)
{
  int count = 0;
  char buffer[LINE_LIMIT+1] = "";

  int lines_quantity = count_lines(filename);
  check_content(lines_quantity);

  int line_number = rand() % lines_quantity;

  char *filtered_material = filter_material(filename);
  
  FILE *stream = streamify(filtered_material);
  // Print out random line
  while (fgets(buffer, sizeof(buffer), stream) != NULL)
  {
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
  free(filtered_material);
}

char *filter_material(const char *filename)
{
  FILE *fptr;
  char buffer[LINE_LIMIT+1] = "";

  // Initialize variable-sized string
  char *filtered_material = NULL;
  size_t filtered_size = 0;

  // Filter out commented lines
  fptr = fopen(filename, "r");
  while (fgets(buffer, sizeof(buffer), fptr) != NULL)
  {
    if (buffer[0] != '#') // Filter out commented lines
    {
      size_t line_len = strlen(buffer);

      // Allocate or reallocate memory for the filtered material
      char *temp = realloc(filtered_material, filtered_size + line_len + 1); // +1 for null terminator
      if (temp == NULL)
      {
        perror("Memory allocation failed");
        free(filtered_material);
        exit(EXIT_FAILURE);
      }

      filtered_material = temp;
      strcpy(filtered_material + filtered_size, buffer);
      filtered_size += line_len;
    }
  }
  fclose(fptr);

  if (filtered_material != NULL)
  {
    filtered_material[filtered_size] = '\0'; // Null-terminate the filtered material
  }

  return filtered_material;
}

// Open stream from a string
FILE *streamify(char *string)
{
  FILE *stream = fmemopen(string, strlen(string), "r");

  return stream;
}
