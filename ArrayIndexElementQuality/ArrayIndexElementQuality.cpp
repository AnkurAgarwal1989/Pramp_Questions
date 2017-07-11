/* ArrayIndexElementQuality.cpp : Defines the entry point for the console application.
Given a sorted array of ints. Return the index where arr[i]==i;
if not return -1;
*/

#include<iostream>
#include<vector>
using namespace std;

int arrayIdxElemQuality_recursive(vector<int> &v, int b, int e) {
  if (b > e)
    return -1;
  int mid = b + (e - b) / 2;

  if (v[mid] == mid)
    return mid;

  if (v[mid] > mid)
    return arrayIdxElemQuality_recursive(v, b, mid - 1);

  if (v[mid] < mid)
    return arrayIdxElemQuality_recursive(v, mid + 1, e);
}

int arrayIdxElemQuality_iterative(const vector<int> &v) {
  int start = 0;
  int end = v.size();
  int mid;
  while (start < end) {
    mid = start + (end - start) / 2;

    if (v[mid] == mid) {
      return mid;
    }

    if (v[mid] > mid) { //If value at i is greater than i, the element must be behind
      end = mid - 1;
    }
    else
      start = mid + 1;
  }
  return -1;
}

int main()
{
  vector<int> data{ -1, 0, 2, 8, 9 };
  cout << arrayIdxElemQuality_iterative(data) << endl;
  cout << arrayIdxElemQuality_recursive(data, 0, data.size()) << endl;

  data = vector<int>{ -5, -3, -2, 0, 4 };
  cout << arrayIdxElemQuality_iterative(data) << endl;
  cout << arrayIdxElemQuality_recursive(data, 0, data.size()) << endl;

  data = vector<int>{ 1,2,3,4,5 };
  cout << arrayIdxElemQuality_iterative(data) << endl;
  cout << arrayIdxElemQuality_recursive(data, 0, data.size()) << endl;
  cin.get();
  return 0;
}

