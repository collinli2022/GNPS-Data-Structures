// Collin Li
// Data Structures
// 04/19/2021
// AssemblyLine Project 

// Preprocessor directive
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include<bits/stdc++.h> 
using namespace std;
/* --------------------------------------------------templates-------------------------------------------------- */
template <typename T> class Stack { // add to the head and take from head
  private:
    T* value;
    Stack* next;
  public:
    Stack(T* v=NULL, Stack* n=NULL) { value = v; n = next; }

    T* pop() {
      if(next != NULL) {
        T* returnT = value;
        value = next->value;
        next = next->next;
        return returnT;
      } else { value = NULL; return value; }
      return NULL;
    }

    void push(T* v) {
      if(next != NULL) {
        Stack<T>* oldHead = new Stack<T>(value, next);
        value = v;
        next = oldHead;        
      } else { value=v; }
    }
    
    void setValue(T v) { value = v; }
    T getValue() { return value; }
    void setNext(Stack* n) { next = n; }
    Stack* getNext() { return next; }
    string toString() {
      string returnS = "[";
      Stack* node = this;
      while(node != NULL) {
        returnS += node->value->getValue();
        returnS += ", ";
        node = node->next;
      }
      if(returnS.length()>2) {
        returnS=returnS.substr(returnS.length()-2);
      }
      returnS+= "]";
      return returnS;
    }
    ~Stack() { delete next; }
};

template <class T> class Queue { // add to tail and take from head
  private:
    T* value;
    Queue* next;
  public:
    Queue(T* v=NULL, Queue* n=NULL) {value = v; next = n; } // Constructor

    T pop() { // take from head
      if(next != NULL) {
        T* returnT = value;
        value = next->value;
        next = next->next;
        return returnT;
      } else { value = NULL; return value; }
    }

    void push(T* v) { // add to tail
      Queue* last = this;
      while(last->next != NULL) {
        last=last->next;
      }
      if(last != NULL) {
        last->next=v;        
      } else { value = v; }
    }

    void setValue(T v) { value = v; }
    T getValue() { return value; }
    void setNext(Queue* n) { next = n; }
    Queue* getNext() { return next; }
    ~Queue() { delete next; }
};
/* --------------------------------------------------templates-------------------------------------------------- */
class Disk {
  private:
    int radius;
  public:
    Disk(int r) { radius = r;}
    int getValue() { return radius;}
    void setRadius(int r) { radius = r; }
    ~Disk() { }
};

class Pyramid {
  private:
    Stack<Disk>* disks;
  public:
    Pyramid(Stack<Disk>* d=new Stack<Disk>()) { disks = d; }
    
    Disk* pop() { return disks->pop(); }
    void push(Disk* value) { disks->push(value); }

    string toString() {
      return disks->toString();
    }

    ~Pyramid() { delete disks; }
};

class AssemblyLine {
  private:
    Queue<Disk>* assemblyLineIn;
    Queue<Pyramid>* assemblyLineOut;
  public:
    // initializes this object so the assemblyLineIn contains nDisks with random radii; assemblyLineOut is initialized to an empty Queue; robotArm is initialized to an empty Pyramid.
    AssemblyLine() {
    }
    
    // "flips over" the pyramid in the robotArm and adds it to the assemblyLineOut queue. Precondition: robotArm is not empty and holds an inverted  pyramid of disks
    void unloadRobot() {

    }

    /* processes all disks from assemblyLineIn; a disk is processed as follows:
    if robotArm is not empty and the next disk does
    not fit on top of robotArm (which must be an inverted
    pyramid) then robotArm is unloaded first; the disk from
    assemblyLineIn is added to robotArm; when all the disks
    have been retrieved from assemblyLineIn, robotArm is unloaded.
    Precondition: robotArm is empty;
                  assemblyLineOut is empty
    */
    void process() {

    }

    ~AssemblyLine() { }
};


int main() {


  Pyramid temp;
  temp.push(new Disk(5));
  cout << "A: " << temp.toString() << endl;
  temp.push(new Disk(7));
  temp.push(new Disk(6));
  temp.push(new Disk(34));
  cout << "B: " << temp.toString() << endl;
  cout << temp.pop() << endl;
  cout << temp.toString() << endl;

  // prompts the user for the name of a file
  cout << "Enter the name of the file: ";
  string inputName;
  cin >> inputName;

  string line;
  ifstream fileInput(inputName); // Creates an input stream
  ofstream fileOutput;  
  int trialIndex = 0; // count trial number
  if (fileInput.is_open()) { // open file
    fileOutput.open("result.txt");
    // fileOutput << "Infix    -->    Postfix    -->    Evaluate\n";
    while ( getline (fileInput, line) ) { // get lines
      fileOutput << line << endl; // outputs to txt
      trialIndex += 1;
    }
    fileInput.close();
    fileOutput.close();
  } else { cout << "Unable to open file"; }

  return 0;
}