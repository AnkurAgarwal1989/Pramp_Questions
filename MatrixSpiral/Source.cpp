#include<iostream>
#include<vector>
using namespace std;

void printMatrix(const vector<vector<int>> &vec) {
  for (int i = 0; i < vec.size(); ++i) {
    for (int j = 0; j < vec[0].size(); ++j) {
      cout << vec[i][j] << "\t";
    }
    cout << "\n";
  }
}

void spiralMatrix(const vector<vector<int>> &vec) {
  int r_top = 0;
  int r_bottom = vec.size();
  int c_left = 0;
  int c_right = vec[0].size();
  while (r_top < r_bottom && c_left < c_right) {
    //print top
    for (int j = c_left; j<c_right; ++j){
      cout << vec[r_top][j] << "\t";
    }
    ++r_top;

    //print right
    for (int i = r_top; i<r_bottom; ++i) {
      cout << vec[i][c_right-1] << "\t";
    }
    --c_right;

    //print bottom
    for (int j = c_right-1; j>=c_left; --j) {
      cout << vec[r_bottom-1][j] << "\t";
    }
    --r_bottom;

    //print right
    for (int i = r_bottom-1; i>=r_top; --i) {
      cout << vec[i][c_left] << "\t";
    }
    ++c_left;
  }
}

int main() {
  vector<vector<int>> vec;// (4, vector<int>(3));
  vec.push_back({0,1,2});
  vec.push_back({ 3,4,5 });
  vec.push_back({ 6,7,8 });
  vec.push_back({ 9, 10,11});
  printMatrix(vec);
  spiralMatrix(vec);

  cin.get();
  return 1;
}
