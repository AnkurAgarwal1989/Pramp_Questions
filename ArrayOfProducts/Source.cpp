#include<iostream>
#include<vector>

using namespace std;

void printArray(vector<int> arr) {
  for (auto n : arr)
    cout << n << "\t";
  cout << endl;
}

void AoP(vector<int> v) {
  vector<int> p(v.size(), 1);
  printArray(p);
  int temp_p = 1;
  //Forward Pass
  for (int i = 1; i < v.size(); ++i) {
    p[i] = p[i-1] * v[i - 1];
  }
  printArray(p);
  //Backward Pass
  for (int i = v.size()-1; i >= 0 ; --i) {
    p[i] = p[i] * temp_p;
    temp_p *= v[i];
  }
  printArray(p);

}

int main() {
  vector<int> v = { 1,2,3,4,5 };
  AoP(v);
  return 1;
}