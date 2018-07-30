// Example program
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int* prime(int n,int* mass)
{
    memset(mass, 0, sizeof(mass));

    int  count = 0;
    bool flag = true;
    int number = 0;

    unsigned long max = 8446744073709551615;

    for (int i = 2; i < max; i++)
    {
        flag = true;

        for (number = 2; number < i; number++)
        {
          if (!(i%number))
          {
            flag = false;
            break;
          }
        }

        if (flag)
        {
            mass[count] = number; // простое
            count++;
        }

        if(count == n)
            return mass;

     }

     return mass;

}


int main()
{

  int n = 0;
  cout << "How many number get prime? ";
  cin >> n;

  int* mass = new int[n];

  mass = prime(n,mass);

  for(int i=0; i < n;i++)
  {
    cout << "Prime["<<i+1<<"] = " << mass[i] << endl;
  }

  delete mass;

  return 0;
}
