#include <iostream>
#include <cstring>
#include <vector>

/*
ghazi a
spring sem cpp/ds dc
graph creator, similar to my graph creator from java
 */

using namespace std;

void addAdj(int t[][20], vector<char*> v, char* first, char* second, int w)
{//table, vertices, first and second, weight
  int count, row, column = 0;
  vector<char*>::iterator it;
  for(it = v.begin(); it < v.end(); it++)
  {
    if(strcmp(*it, first)==0)
    {
      column=count;
    }
    else if(strcmp(*it, second)==0)
    {
      row=count;
    }
    count++;
  }
  
}





int main()
{


}
