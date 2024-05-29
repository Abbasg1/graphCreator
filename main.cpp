#include <iostream>
#include <cstring>
#include <vector>

/*
ghazi a
spring sem cpp/ds dc
graph creator, similar to my graph creator from java

Sources are canvas page

 */

using namespace std;

void addAdj(int t[][10], vector<char*> vs, char* first, char* second, int w)
{//table, vertices, first and second, weight
  int count, row, column = 0;
  vector<char*>::iterator it;
  for(it = vs.begin(); it < vs.end(); it++)
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
  return vs;
}

void removeAdjEdge(int t[][10], vector<char*> vs, char* first, char* second)
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
  t[row][column] = -1;
} 

void printAdj(int t[][10], vector<char*> vs)
{
  for(int x=0; x< vs.size(); x++)
  {
    cout << "\t" << vs.at(x);
  }
  cout << endl;


  //x is rows y is columns but im lazy as shit
  for(int x=0; x< vs.size(); x++)
  {
    cout << vs.at(x);
    for(int y =0; y < vs.size(); y++)
    {
      cout << "\t" << t[x][y];
    }
    cout << endl;
  }
}



int main()
{
  vector<char*> Vertices;
  int adjTable[10][10];


  //adjacency table
  for(int x =0; x < 10; x++)
  {
    for(int y =0; y < 10; y++)
    {
      adjTable[x][y] = -1;
    }
  }
  char* CHAR = new char[1];
  int weight = 0;
  int cmd;
  while(true)
  {
    cout << "1 to add Vertex, 2 to add Edge, 3 to remove Vertex, 4 to remove Edge, 5 to Print, 6 to Quit." << endl;
    cin >> cmd;
    cin.get();

    if(cmd == 1)
    {//add vertex
      cout << endl <<  "Create vertex. Enter label: ";
      cin>> CHAR;
      cin.get();
      Vertices.push_back(CHAR);
      CHAR = new char[1];
    }
    else if(cmd==2)
    {//add edge
      char* firstVertex = new char[1];
      char* secondVertex = new char[1];
      cout << endl << "Creaye edge. " << endl;
      cout << "enter first vertex";
      cin>> firstVertex;
      cin.get();
      cout << endl << "enter second vertex";
      cin>> secondVertex;
      cin.get();

      cout << "enter edge weight";
      cin >> weight;
      cin.get();

      addAdj(adjTable, Vertices, firstVertex, secondVertex, weight);
      
    }
    else if(cmd == 3)
    {///remove vertex
      cout << "\n Remove Vertex. Enter vertex label to remove";
      cin>> CHAR;
      cin.get();
      Vertices = removeAdjVertex(Vertices, CHAR);
      CHAR = new char[1];
    }
    else if(cmd==4)
    {//remove edge
      char* firstVertex = new char[1];
      char* secondVertex = new char[1];

      cout << "\n Remove edge.";
      cout << "\n Enter first vertex ";
      cin>> firstVertex;
      cin.get();
      cout << "\n Enter second vertex ";
      cin>> secondVertex;
      cin.get();
      removeAdjEdge(adjTable, Vertices, firstVertex, secondVertex);
    }
    else if(cmd==5)
    {//print
      printAdj(adjTable, Vertices);
    }
    else if(cmd==6)
    {//quit
      break;
    }
    else
    {
      cout << "invalid command" << endl;
    }
  }
}
