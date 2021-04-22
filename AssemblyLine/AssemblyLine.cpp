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
    Stack(T* v=NULL, Stack* n=NULL) { value = v; next = n; }

    T* pop() {
      if(next != NULL) {
        T* returnT = value;
        value = next->value;
        next = next->next;
        return returnT;
      } else { value = NULL; return value; }
      return NULL;
    }
    T* peek() { return value; }
    bool isEmpty() {return (value==NULL); }

    void push(T* v) {
      if(value != NULL) {
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
        returnS += to_string(node->value->getValue());
        returnS += ", ";
        node = node->next;
      }
      if(returnS.length()>2) {
        returnS=returnS.substr(0,returnS.length()-2);
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

    T* pop() { // take from head
      if(next != NULL) {
        T* returnT = value;
        value = next->value;
        next = next->next;
        return returnT;
      } else { value = NULL; return value; }
    }
    T* peek() { return value; }

    void push(T* v) { // add to tail
      if(value==NULL) {
        value=v;
        return;
      }
      Queue<T>* last = this;
      while(last->next != NULL) { last=last->next; }
      Queue<T>* newTail = new Queue<T>(v, NULL);
      last->setNext(newTail);
    }

    bool isEmpty() {
      return value == NULL;
    }

    void setValue(T v) { value = v; }
    T getValue() { return value; }
    void setNext(Queue* n) { next = n; }
    Queue* getNext() { return next; }
    string toString() { // only work with disks
      string returnS = "[";
      Queue* node = this;
      while(node != NULL) {
        returnS += node->value->toString();
        returnS += ", ";
        node = node->next;
      }
      if(returnS.length()>2) {
        returnS=returnS.substr(0,returnS.length()-2);
      }
      returnS+= "]";
      return returnS;
    }
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
    string toString() {return to_string(radius); }
    ~Disk() { }
};

class Pyramid {
  private:
    Stack<Disk>* disks;
  public:
    Pyramid(Stack<Disk>* d=new Stack<Disk>()) { disks = d; }
    
    Disk* pop() { return disks->pop(); }
    Disk* peek() { return disks->peek(); }
    void push(Disk* value) { disks->push(value); }

    bool isEmpty() {
      return disks->isEmpty();
    }

    string toString() {
      return disks->toString();
    }

    ~Pyramid() { delete disks; }
};

class AssemblyLine {
  private:
    Queue<Disk> assemblyLineIn;
    Queue<Pyramid> assemblyLineOut;
    Pyramid robotArm;
  public:
    // initializes this object so the assemblyLineIn contains nDisks with random radii; assemblyLineOut is initialized to an empty Queue; robotArm is initialized to an empty Pyramid.
    AssemblyLine(string line) {
      assemblyLineIn = Queue<Disk>();
      assemblyLineOut = Queue<Pyramid>();
      robotArm = Pyramid();

      stringstream iss(line);
      string number;
      vector<string> myNumbers;
      while ( iss >> number ) {
        myNumbers.push_back( number );
      }

      for(string i:myNumbers) {
        assemblyLineIn.push(new Disk(stoi(i)));
      }

      assemblyLineOut = Queue<Pyramid>();
      robotArm = Pyramid();
    }
    
    // "flips over" the pyramid in the robotArm and adds it to the assemblyLineOut queue. Precondition: robotArm is not empty and holds an inverted  pyramid of disks
    void unloadRobot() {
      Pyramid temp = Pyramid();
      while(!robotArm.isEmpty()) { temp.push(robotArm.pop()); }
      assemblyLineOut.push(&temp);
      robotArm = Pyramid();
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
      while(!assemblyLineIn.isEmpty()) {
        if (robotArm.isEmpty() || assemblyLineIn.peek()->getValue() > robotArm.peek()->getValue()) {
          robotArm.push(assemblyLineIn.pop());
        } else {
          unloadRobot();
        }
      }
    }
    
    string getAssemblyLineOut() {
      return assemblyLineOut.toString();
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
  cout << temp.toString() << endl << endl;

  Queue<Disk> aa;
  cout << "Start" << endl;
  aa.push(new Disk(5));
  cout << "A: " << aa.toString() << endl;
  aa.push(new Disk(7));
  aa.push(new Disk(6));
  aa.push(new Disk(34));
  cout << "B: " << aa.toString() << endl;
  cout << aa.pop() << endl;
  cout << aa.toString() << endl;

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
      AssemblyLine input = AssemblyLine(line);
      input.process();
      string output = input.getAssemblyLineOut();
      fileOutput << trialIndex << ": " << output << endl; // outputs to txt
      trialIndex += 1;
    }
    fileInput.close();
    fileOutput.close();
  } else { cout << "Unable to open file"; }

  return 0;
}