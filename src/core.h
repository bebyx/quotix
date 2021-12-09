#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include <stdio.h>

int count_lines(const char* filename);
void seed_random(const char* iteration);
void print_random_quote(const char* filename);
FILE *filter_material(const char* filename);

#endif
