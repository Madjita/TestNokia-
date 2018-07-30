// Example program
#include <iostream>
#include <bitset>

using namespace std;

void getUnsignedInt32(unsigned long int x)
{
  cout <<"input:\t" << x << " \t\t= ";   
  cout << bitset<32>(x) <<endl; 
 
  bitset<32> max = 0, min = 0;
  int count=0;
  
  for ( int i = 0; i < 30; ++i )
  {
    if(bitset<32>(x)[i] == 1)
    {
      max[31-count]=1;
      min[count]=1;
      count++;
    }
       
  }
  
  cout <<"max = "<< unsigned(long(max.to_ulong())) <<" \t= " << bitset<32>(max) << endl;
  cout <<"min = "<< unsigned(long(min.to_ulong())) <<" \t\t= " << bitset<32>(min) << endl;
  
}

int main()
{
  getUnsignedInt32(35);
  return 0;
}
