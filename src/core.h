#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include <stdio.h>

int count_lines(const char *filename);
void seed_random(const char *iteration);
void print_random_quote(const char *filename);
char *filter_material(const char *filename);
FILE *streamify(char *string);

#endif
