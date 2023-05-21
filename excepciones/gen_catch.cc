#include <iostream>

using namespace std;

int main() {
  int data[3] = {11};
  for (int i = 0; i < 1; i++) {
    int value = data[i];
    try {
      if (value > 0)
        throw value;  // throwing numeric value as exception
      else
        throw 'exception';  // throwing a character as exception
    } catch ( char exception) {         // generalised catch block
      cerr << "Exception occurred: " << exception << endl;
    } catch (int exception) {           // specialized catch block
      cerr << "Exception occurred: " << exception << endl;
    }
  }
  return 0;
}