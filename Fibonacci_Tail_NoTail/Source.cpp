#include<iostream>

using namespace std;

int fib_noTail(int n) {
  if (n <= 1) {
    return 1;
  }
  return (fib_noTail(n - 1) + fib_noTail(n - 2));
}

int fib_tail(int n, int curr, int acc) {
  if (n == 0) {
    return acc;
  }
  return fib_tail(n - 1, acc, acc + curr);
}


int main() {
  cout << fib_noTail(5) <<endl;
  cout << fib_tail(5, 0, 1) << endl;
  return 1;
}