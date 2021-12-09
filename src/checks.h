#ifndef CHECKS_H_INCLUDED
#define CHECKS_H_INCLUDED

#define LINE_LIMIT 1024

void check_file(const char* filename);
void check_line(const int line_count, const int char_count);
void check_content(int lines_quantity);

#endif
