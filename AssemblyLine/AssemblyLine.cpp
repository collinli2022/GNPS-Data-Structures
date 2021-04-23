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
template <typename T> class Stack { // add to the tail and take from tail
  private:
    T value;
    Stack* next;
    int length;
  public:
    Stack() {next = NULL; length = 0;} // default constructor
    Stack(T v, Stack* n = NULL) {value = v; next = n; length = 1; } // constructor
    T pop() { // take from tail
      if(length <= 1) { // one or less node
        length = 0;
        return value;
      } else { // more than one node
        Stack<T>* newLast = this; // get second to last node
        while(newLast->next->next != NULL) { newLast = newLast->next; }
        T returnT = newLast->next->value; // last node's value
        newLast->next = NULL; // second to last node is now last node
        length -= 1;
        return returnT;
      }
    }
    T peek() { // get last value
      if(length <= 1) { return value; } // only one node
      else { // more than last node
        Stack<T>* newLast = this; // get last node
        while(newLast->next != NULL) { newLast = newLast->next; }
        return newLast->value;
      }
    }
    void push(T v) { // add to tail
      if(length <= 0) { length = 1; value = v; } // no nodes
      else if(next == NULL) { length += 1; next = new Stack<T>(v); } // one node
      else { // more than one node
        Stack<T>* last = this; // get last node
        while(last->next != NULL) { last = last->next; }
        Stack<T>* newTail = new Stack<T>(v); // new last node
        last->next = newTail;
        length += 1;
      }
    }
    bool isEmpty() { return (length<=0); }
    void setValue(T v) { value = v; }
    T getValue() { return value; }
    string toString() { // to string
      string returnS = "[";
      Stack* node = this; // current node
      while(node != NULL) { // loop till end of stack
        returnS += to_string(node->value.getValue()); 
        returnS += ", ";
        node = node->next;
      }
      if(returnS.length()>2) { returnS = returnS.substr(0, returnS.length()-2); } // remove the last ", "
      returnS+= "]";
      return returnS;
    }
    ~Stack() { next = nullptr; delete next; }
};
template <class T> class Queue { // add to tail and take from head
  private:
    T value;
    Queue* next;
    int length;
  public:
    Queue() {next = NULL; length = 0;} // default constructor
    Queue(T v, Queue* n=NULL) {value = v; next = n; length = 1;} // constructor
    T pop() { // take from head
      if(length <= 0) { length = 0; return value; } // no nodes so return is most likely NULL
      else if(next == NULL) { T returnT = value; length-=1; return returnT; } // one node
      else {
        T returnT = value; // original Head to return
        value = next->value; // replace with new head
        next = next->next;
        length-=1;
        return returnT;
      }
    }
    T peek() { return value; }
    void push(T v) { // add to tail
      if(length <= 0) { length = 1; value = v; } // no nodes
      else if(next == NULL) { next = new Queue<T>(v); length+=1; } // one node
      else { // more than one node
        Queue<T>* last = this; // get last node
        while(last->next != NULL) { last=last->next; }
        Queue<T>* newTail = new Queue<T>(v);
        last->next=newTail; // set new last node
        length+=1;
      }
    }
    bool isEmpty() { return (length<=0); }
    void setValue(T v) { value = v; }
    T getValue() { return value; }
    string toString() { // to string
      string returnS = "[";
      Queue* node = this; // current node
      while(node != NULL) { // loop till end of queue
        returnS += node->value.toString();
        returnS += ", ";
        node = node->next;
      }
      if(returnS.length()>2) { returnS=returnS.substr(0,returnS.length()-2); } // remove the last ", "
      returnS+= "]";
      return returnS;
    }
    ~Queue() { next = nullptr; delete next; }
};
/* --------------------------------------------------templates-------------------------------------------------- */
class Disk {
  private:
    int radius;
  public:
    Disk(int r=-1) { radius = r;} // constructor
    int getValue() { return radius;}
    string toString() { return to_string(radius); }
    ~Disk() { }
};
class Pyramid {
  private:
    Stack<Disk> disks;
  public:
    Pyramid(Stack<Disk> d=Stack<Disk>()) {disks = d; } // constructor
    Disk pop() { return disks.pop(); } // pop from stack
    Disk peek() { return disks.peek(); } // peek from stack
    void push(Disk value) { disks.push(value); } // push from stack
    bool isEmpty() { return disks.isEmpty(); } // checks if stack is empty
    string toString() { return disks.toString(); } // returns stack as a string
    ~Pyramid() { }
};

class AssemblyLine {
  private:
    Queue<Disk> assemblyLineIn;
    Queue<Pyramid> assemblyLineOut;
    Pyramid robotArm;
  public:
    // initializes this object so the assemblyLineIn contains nDisks with random radii; assemblyLineOut is initialized to an empty Queue; robotArm is initialized to an empty Pyramid.
    AssemblyLine(string line) {
      assemblyLineIn = Queue<Disk>(); // empty assemblyLineIn
      assemblyLineOut = Queue<Pyramid>(); // empty assemblyLineOut
      robotArm = Pyramid(); // empty pyramid
      stringstream iss(line);
      string number;
      vector<string> myNumbers;
      while (iss >> number) { myNumbers.push_back( number ); } // seperate numbers representing disk radius
      for(string i : myNumbers) { assemblyLineIn.push(Disk(stoi(i))); } // add disks with radius to assemblyLineIn
      assemblyLineOut = Queue<Pyramid>();
    }
    // "flips over" the pyramid in the robotArm and adds it to the assemblyLineOut queue. Precondition: robotArm is not empty and holds an inverted  pyramid of disks
    void unloadRobot() {
      Pyramid temp = Pyramid();
      while(!robotArm.isEmpty()) { temp.push(robotArm.pop()); } // flips to temp pyramid
      assemblyLineOut.push(temp); // add to assemblyLineOut
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
        /*
        cout << "IN: " << assemblyLineIn.toString() << endl;
        cout << "OUT: " << assemblyLineOut.toString() << endl;
        cout << "Robot: " << robotArm.toString() << endl << endl;
        */
        bool A = robotArm.isEmpty(); // robot arm is empty
        bool B = assemblyLineIn.peek().getValue() > robotArm.peek().getValue(); // the next disk can be added with the robotArm pyramid
        if(A || B) { // checks A first and then if false then checks B
          Disk popped = assemblyLineIn.pop();
          robotArm.push(popped);
        } else { unloadRobot(); }
      }
      if(!robotArm.isEmpty()) { unloadRobot(); } // if no more inputs, empty the robot arm
    }
    string toString() { return assemblyLineOut.toString(); } // to string
    ~AssemblyLine() { }
};


int main() {
  // prompts the user for the name of a file
  cout << "Enter the name of the file: ";
  string inputName;
  cin >> inputName; // get name
  string line;
  ifstream fileInput(inputName); // Creates an input stream
  ofstream fileOutput;  
  int trialIndex = 0; // count trial number
  if (fileInput.is_open()) { // open filep
    fileOutput.open("result.txt");
    while ( getline (fileInput, line) ) { // get lines
      AssemblyLine input = AssemblyLine(line);
      input.process();
      string output = input.toString();
      fileOutput << trialIndex << ": " << output << endl; // outputs to txt
      trialIndex += 1; // counts trials
    }
    fileInput.close();
    fileOutput.close();
  } else { cout << "Unable to open file"; }
  return 0;
}