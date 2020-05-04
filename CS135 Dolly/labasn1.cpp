#include <iostream>

using namespace std;

int main ()

{

  double farenheit = 74.00;
  double romer = 0.00;
  double celsius = 0.00;
  double kelvin = 0.00;

  romer = (farenheit - 32.0) * 7.0 / 24.0 + 7.5;
  celsius = (farenheit - 32.0) * 5/9;
  kelvin = celsius + 273.15;

  cout << "When Farenheit is equal to " << farenheit << ", Romer is equal to " << romer << endl;
  cout << "When Farenheit is equal to " << farenheit << ", Celsius is equal to " << celsius << endl;
  cout << "when Celsius is equal to " << celsius << ", Kelvin is equal to " << kelvin << endl;


  return 0;



}
