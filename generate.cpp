// Preprocessor directive
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include<bits/stdc++.h> 
using namespace std;

int main() {
  ofstream fileOutput;  
  fileOutput.open("result.txt");
  int trialIndex = 500;
  int range = 10;
  int length = 10;
  string operators[7] = {"+", "-", "*", "/", "%", "!", "^"};
  while ( trialIndex >= 0 ) { // get lines
    string output = "";
    output += to_string(rand() % range) + " ";
    output += to_string(rand() % range) + " ";
    
    int num = 1;
    int oper = 0;
    for(int i = 0; i < (rand()%length); i++) {
      if(rand()%2 == 0) {
        output += to_string(rand() % range) + " ";
        num++;
      } else {
        for(int j = oper; j < num; j++) {
          output += operators[ (int)(rand() % 7) ] + " ";
          oper++;
        }
      }
    }
    if(oper > num) {
      continue;
    } else {
      cout << "DIE: " << num << " - " << oper << " _ "<< output << endl;
      for(int j = oper; j < num; j++) {
        output += operators[ (int)(rand() % 7) ] + " ";
        oper++;
      }
      cout << output << endl;
      fileOutput << output<< endl;
    }

    trialIndex -= 1;
  }
  fileOutput.close();

  return 0;
}