#include <iostream>
#include <fstream>
#include "HillClimbing.h"

using namespace std;


int main(int argc, char *argv[]) {
  fstream newfile;
   newfile.open("data.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){
     string tp;
     while(getline(newfile, tp)){
       int init[9];
       int go[9];
       int ini_z;
       int go_z;

       int i =0;
       for(; i < 9; i++){
         init[i] = tp[i] - '0';
         if(init[i] == 0){
           ini_z=i;
         }
       }

       i++;
       for(int j = 0; j < 9; j++){
         go[j] = tp[i+j] - '0';
         if(go[j] == 0){
           go_z=j;
         }
       }

       Node* goalState = new Node(go, go_z, 0, NULL);
       Node* startState = new Node(init, ini_z, 0, goalState);

       HillClimbing* bfs = new HillClimbing(startState, goalState);

       cout<<"It took "<<bfs->hillClimbing()<<" Number of iterations, with "<<goalState->getOptimum()<<" Optimum"<<endl;
     }
  }
  return 0;
}
