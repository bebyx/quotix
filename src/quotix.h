#ifndef QUOTIX_H_INCLUDED
#define QUOTIX_H_INCLUDED

#define LINE_LIMIT 1024

#include <stdio.h>

void check_file(const char* filename);
void check_line(const int line_count, const int char_count);
void check_content(int lines_quantity);
int count_lines(const char* filename);
void seed_random(const char* iteration);
void print_random_quote(const char* filename);
FILE *filter_material(const char* filename);

#endif
