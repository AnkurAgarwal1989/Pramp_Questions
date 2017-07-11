/*
Given an array of integers arr where each element is at most k places away from its sorted position, code an efficient function sortKMessedArray that sorts arr.For instance, for an input array of size 10 and k = 2, an element belonging to index 6 in the sorted array will be located at either index 4, 5, 6, 7 or 8 in the input array.

Analyze the time and space complexities of your solution.

Example:

input:  arr = [1, 4, 5, 2, 3, 7, 8, 6, 10, 9], k = 2

  output : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define MIN(a,b) (a<b ? a : b)

void printVec(vector<int> v) {
  for (int i : v) {
    cout << i << "  ";
  }
  cout << endl;
}

void sortMessedArray(vector<int> v, int k) {
  for (int i = 0; i < v.size() - 1; ++i) {
    //Find min element in the window
    int min = v[i];
    int min_idx = i;
    for (int j = i + 1; j < MIN(i+k+1, v.size()); ++j) {
      if (v[j] < min) {
        min = v[j];
        min_idx = j;
      }
    }
    if (min_idx != i) {
      std::swap(v[i], v[min_idx]);
    }
    
    printVec(v);
  }
  printVec(v);
}

int main() {
  vector<int> v{ 1, 4, 5, 2, 3, 7, 8, 6, 10, 9 };
  printVec(v);
  sortMessedArray(v, 2);
  cin.get();
  return -1;

}