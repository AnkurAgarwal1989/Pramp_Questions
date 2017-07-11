#include <iostream>
#include<iostream>
#include<vector>
using namespace std;

int step = 0;




int play(int n, int me, int them) {

  if (n == 1 || n == 2 || n == 4) {
    cout << "n inside: " << n << endl;
    cout << "Winner: here: " << me << endl;
    return me;
  }

  int balance = n - 1;
  if (balance > 0)
    cout << "Winner: " << play(balance, them, me) << endl;

  balance = n - 2;
  if (balance > 0)
    cout << "Winner: " << play(balance, them, me) << endl;

  balance = n - 4;
  if (balance > 0)
    cout << "Winner: " << play(balance, them, me) << endl;

  /*if (n > 1 && n != 4 && n != 2)
    play(n - 1, them, me);
  if (n > 2 && n != 4)
    play(n - 2, them, me);
  if (n > 4)
    play(n - 4, them, me);
 */
}
int main(int argc, char * argv[]) {
  int result;
  argv[1] = "4";
  argv[2] = "AA";
  argv[3] = "BB";
 
  int n = atoi(argv[1]);
  way = 0;
  result = play(n, 0, 1);
  if (result == 0)
    cout << argv[2] << " ";
  else if (result == 1)
    cout << argv[3] << " ";
  cout << way;
  cin.get();
  return 0;
}