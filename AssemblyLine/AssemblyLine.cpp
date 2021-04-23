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
    T value;
    Stack* next;
    int length;
  public:
    Stack() {next = NULL; length = 0;}
    Stack(T v, Stack* n=NULL) {value = v; next = n; length = 1; }

    T pop() {
      if(length <= 1) {
        length = 0;
        return value;
      } else {
        T returnT = value;
        value = next->value;
        next = next->next;
        length -= 1;
        return returnT;
      }
    }
    T peek() { return value; }
    void push(T v) {
      if(length == 0) {
        value = v;
      } else if(next == NULL) {
        Stack<T>* oldHead = new Stack<T>(value, NULL);
        value = v;
        next = oldHead;
      } else {
        Stack<T>* oldHead = new Stack<T>(value, next);
        value = v;
        next = oldHead;  
      }
      length += 1;
    }
    bool isEmpty() {return (length<=0); }
    void setValue(T v) { value = v; }
    T getValue() { return value; }
    void setNext(Stack* n) { next = n; }
    Stack* getNext() { return next; }
    string toString() {
      string returnS = "[";
      Stack* node = this;
      while(node != NULL) {
        returnS += to_string(node->value.getValue());
        returnS += ", ";
        node = node->next;
      }
      if(returnS.length()>2) {
        returnS=returnS.substr(0, returnS.length()-2);
      }
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
    Queue() {next = NULL; length = 0;}
    Queue(T v, Queue* n=NULL) {value = v; next = n; length = 1;} // Constructor

    T pop() { // take from head
      if(length<=0) {
        length=0;
        return value;
      } else if(next == NULL) {
        T returnT = value;
        length-=1;
        return returnT;
      } else {
        T returnT = value;
        value = next->value;
        next = next->next;
        length-=1;
        return returnT;
      }
    }
    T peek() { return value; }

    void push(T v) { // add to tail
      if(length<=0) {
        length=1;
        value=v;
        return;
      } else if(next == NULL) {
        next = new Queue<T>(v);
        length+=1;
      } else {
        Queue<T>* last = this;
        while(last->next != NULL) { last=last->next; }
        Queue<T>* newTail = new Queue<T>(v);
        last->next=newTail;
        length+=1;
      }
    }

    bool isEmpty() {
      return (length<=0);
    }

    void setValue(T v) { value = v; }
    T getValue() { return value; }
    void setNext(Queue* n) { next = n; }
    Queue* getNext() { return next; }
    string toString() { // only work with disks
      string returnS = "[";
      Queue* node = this;
      while(node != NULL) {
        returnS += node->value.toString();
        returnS += ", ";
        node = node->next;
      }
      if(returnS.length()>2) {
        returnS=returnS.substr(0,returnS.length()-2);
      }
      returnS+= " - " + to_string(length);
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
    Disk(int r=-1) { radius = r;}
    int getValue() { return radius;}
    void setRadius(int r) { radius = r; }
    string toString() { return to_string(radius); }
    ~Disk() { }
};

class Pyramid {
  private:
    Stack<Disk> disks;
  public:
    Pyramid(Stack<Disk> d=Stack<Disk>()) {disks = d; }
    Disk pop() { return disks.pop(); }
    Disk peek() { return disks.peek(); }
    void push(Disk value) { disks.push(value); }
    bool isEmpty() { return disks.isEmpty(); }
    string toString() { return disks.toString(); }
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
      assemblyLineIn = Queue<Disk>();
      assemblyLineOut = Queue<Pyramid>();
      robotArm = Pyramid();

      stringstream iss(line);
      string number;
      vector<string> myNumbers;
      while (iss >> number) {
        myNumbers.push_back( number );
      }

      for(string i : myNumbers) {
        assemblyLineIn.push(Disk(stoi(i)));
      }

      assemblyLineOut = Queue<Pyramid>();
      robotArm = Pyramid();
    }
    
    // "flips over" the pyramid in the robotArm and adds it to the assemblyLineOut queue. Precondition: robotArm is not empty and holds an inverted  pyramid of disks
    void unloadRobot() {
      Pyramid temp = Pyramid();
      while(!robotArm.isEmpty()) { Disk tempValue = robotArm.pop(); temp.push(tempValue); }
      assemblyLineOut.push(temp);
      
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
        cout << "IN: " << assemblyLineIn.toString() << endl;
        cout << "OUT: " << assemblyLineOut.toString() << endl;
        cout << "Robot: " << robotArm.toString() << endl << endl;
        bool A = robotArm.isEmpty();
        bool B = assemblyLineIn.peek().getValue() > robotArm.peek().getValue();
        
        if(A || B) {
          Disk popped = assemblyLineIn.pop();
          robotArm.push(popped);
        } else {
          unloadRobot();
        }
      }
      if(!robotArm.isEmpty()) {
        unloadRobot();
      }
    }
    
    string getAssemblyLineOut() {
      return assemblyLineOut.toString();
    }
    ~AssemblyLine() { }
};


int main() {
  cout << "test" << endl;
  Pyramid robotArm = Pyramid();
  cout << "test2" << endl;
  robotArm.push(Disk(7));
  robotArm.push(Disk(6));
  robotArm.push(Disk(5));
  robotArm.push(Disk(4));
  cout << "test3" << endl;
  cout << robotArm.toString() << endl;
  cout << "test4" << endl;
  cout << robotArm.pop().toString() << endl;
  cout << robotArm.pop().toString() << endl;
  cout << robotArm.pop().toString() << endl;
  cout << robotArm.toString() << endl;
  cout << "test5" << endl;
  cout << robotArm.pop().toString() << endl;
  robotArm.push(Disk(7));
  robotArm.push(Disk(6));
  cout << robotArm.toString() << endl;

  // prompts the user for the name of a file
  cout << "Enter the name of the file: ";
  string inputName = "in.txt";
  //cin >> inputName;

  string line;
  ifstream fileInput(inputName); // Creates an input stream
  ofstream fileOutput;  
  int trialIndex = 0; // count trial number
  if (fileInput.is_open()) { // open filep
    fileOutput.open("result.txt");
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