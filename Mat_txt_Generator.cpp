#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <time.h>
using namespace std;

void create(string name, int x, int y) {
  srand(time(NULL));
  ofstream new_mat;
  new_mat.open(name);
  string str;
  int temp;
  for (int i = 0; i < x - 1; i++) {
    str = "";
    for (int j = 0; j < y - 1; j++) {
      temp = rand() % 100;
      str += to_string(temp);
      str += " ";
    }
    temp = rand() % 100;
    str += to_string(temp);
    str += '\n';
    new_mat << str;
  }
  str = "";
    for (int j = 0; j < y - 1; j++) {
      temp = rand() % 100;
      str += to_string(temp);
      str += " ";
    }
    temp = rand() % 100;
    str += to_string(temp);
  new_mat << str;
  new_mat.close();
}

int main(int argc, char** argv) {
  switch(argc){
    case 2:{
      stringstream ss(argv[1]);
      int x;
      ss>>x;
      create("mat1.txt",x,x);
      create("mat2.txt",x,x);
      break;
    }
    case 3:{
      stringstream ss(argv[1]);
      stringstream ss1(argv[2]);
      int x,y;
      ss>>x;
      ss1>>y;
      create("mat1.txt",x,y);
      create("mat2.txt",y,x);
      break;
    }
    case 4:{
      stringstream ss(argv[1]);
      stringstream ss1(argv[2]);
      stringstream ss2(argv[3]);
      int x,y,z;
      ss>>x;
      ss1>>y;
      ss2>>z;
      create("mat1.txt",x,y);
      create("mat2.txt",y,z);
      break;
    }
    default:
    cout<<"error con el numero de argumentos"<<endl;
  }
  return 0;
}