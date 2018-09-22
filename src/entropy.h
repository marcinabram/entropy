#include <string>

#ifndef ENTROPY_H_INCLUDED
#define ENTROPY_H_INCLUDED

float entropy(bool *signal, int n, int window);

int bools_to_int(bool *tab, int start, int end);

#endif
