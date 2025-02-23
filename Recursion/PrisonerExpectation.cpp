#include <iostream>

using namespace std;

int main() {
  // Define expected times for each route (given)
  double e_t_r1 = 4;
  double e_t_r2 = 5;
  double e_t_r3 = 7;
  double e_t_r4 = 15;

  // Calculate expected travel time E(T)
  double e_t = (e_t_r1 + e_t_r2 + e_t_r3 + e_t_r4) / (1 - 3 * 0.25); 

  cout << "The expected travel time is: " << e_t << " minutes" << endl;

  return 0;
}