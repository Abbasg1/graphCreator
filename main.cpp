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
  t[row][column]= w;
}

vector<char*> removeAdjVertex (vector<char*> vs, char* v)
{//vertices and vertex to be removed from adj table
  vector <char*>::iterator it;
  for(it = vs.begin(); it < vs.end(); it++)
  {
    if(strcmp(*it, v)==0)
    {
      vs.erase(it);
      cout << "removed vertex"<< endl;
      break;
    }
  }
  return v;
}

void removeAdjEdge(int t[][20], vector<char*> vs, char* first, char* second)
{
  int count, row, column = 0;
  for(vector<char*>::iterator it = vs.begin(); it < vs.end(); it++)
  {
    if(strcmp(*it, first)==0)
    {
      column = count;
    }
    else if(strcmp(*it, second)==0)
    {
      row = count;
    }
    count++;
  }
  t[r][c] = -1;
}





int main()
{


}
