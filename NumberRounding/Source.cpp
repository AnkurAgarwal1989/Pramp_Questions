#include<iostream>
#include<bitset>
using namespace std;

int main() {
  unsigned int a = 17;
  bitset<8> b(a);

  unsigned int r = a & (~15);
  bitset<8> br(r);
  bitset<8> mask(~15);
  cout << a << endl;
  cout << mask << endl;
  cout << b << endl;
  cout << br << endl;
  cout << r << endl;
  return 1;
}