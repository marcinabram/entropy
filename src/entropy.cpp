#include <math.h>
#include <string.h>
#include "entropy.h"

float entropy(bool *signal, int n, int window) {
    // Calculate sygnal entropy
    unsigned chunks = n/window;
    unsigned parts = pow(2, window);

    // count how many time each pattern apprared
    int counter[parts];
    memset(counter, 0, sizeof(counter));
    for (unsigned i=0; i<chunks; i++) {
      int k = bools_to_int(signal, i*window, (i+1)*window);
      counter[k] += 1;
    }

    // calculate entropy
    double s = 0;
    double fchunks = double(chunks);
    for (unsigned i=0; i<parts; i++) {
      double p = double(counter[i])/fchunks;
      if (p > 0) {
        s += p*log(p);
      }
    }

    return -s/(window*log(2));
}


int bools_to_int(bool *tab, int start, int end){
  // change bools to int.
  int result = 0;
  for (int i=start; i<end; i++) {
    if (tab[i] == true) {
      result ^= 1 << (end - i - 1);
    }
  }
  return result;
}
