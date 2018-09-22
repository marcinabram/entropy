// Demo
#include <iostream>
#include <fstream>
#include <vector>
#include "src/entropy.h"

using namespace std;


int main(int argc,  char** argv) {
  // Run demo.
  string file_name = "signal.dat";
  int window = 2;

  // Read the arguments
  if (argc > 1) {
    file_name = argv[1];
  }
  if (argc > 2) {
    window = atoi(argv[2]);
  }

  // Open file
  ifstream fin;
  fin.open(file_name, ios::in);
  char c;
  vector<bool> buffer;
  while (fin.eof() == false) {
    fin.get(c);
    buffer.push_back(c != '0');
	}


  // vector -> bool[]
  int n = buffer.size();
  bool *my_signal = new bool[n];
  for (int i=0; i<n; i++) {
    my_signal[i] = bool(buffer[i]);
  }

  // Calculate the entropy
  double exact_result = 0.999999220151945879971556546101657914889769688960930;
  double s = entropy(my_signal, n, window);

  cout.precision(20);
  cout << "Entropy: " << s << endl;
  cout << "Error: " << abs(s-exact_result) << endl;

  return 0;
}
