// Collin Li
// Data Structures
// 04/12/2021
// Song Queue Project

// Preprocessor directive
#include <iostream>
#include <string>
#include <fstream>
#include<bits/stdc++.h> 
using namespace std;

class SongQueue {
  private:
    string value; // stores song name
    SongQueue* previous; // sotres previous node
    SongQueue* next; // stores next node
    void removeSong(string song); // removes song with specific song name
    bool contains(string song); // checks if queue has song
  public:
    SongQueue(string a="", SongQueue* p=NULL, SongQueue* n=NULL); // constructor

    string dequeue(); // Dequeues and returns the first song of the queue
    void enqueue(string x); // Enqueue an song onto the back of this queue
    bool isEmpty(); // Returns true if this queue is empty, otherwise returns false.
    string peekFront(); // Returns the first song of the queue without dequeuing it.
    SongQueue* readPlayList();
    void processRequest(string str);
    void printSongList();
    SongQueue* getQueue();

    ~SongQueue() { delete previous; delete next; } // deconstructor that deletes pointer
};
void SongQueue::removeSong(string song) {
  if(isEmpty()) { return; }
  SongQueue* current = this->getQueue();
  while(current != NULL) {
    if(current->value == song) {
      current->value = "";
      if(current->previous == NULL) { // first element in queue
        current->dequeue();
        current = nullptr;
        delete current;
        return;
      } else if(current->next == NULL) { // last element in queue
        current->previous->next = NULL;
        current->previous = NULL;
        current = nullptr;
        delete current;
        return;
      } else { // middle element in queue
        current->next->previous = current->previous;
        current->previous->next = current->next;
        current->next = NULL;
        current->previous = NULL;
        current = nullptr;
        delete current;
        return;
      }
    }
    current = current->next; // go down the queue
  }
}
bool SongQueue::contains(string song) {
  if(isEmpty()) { return false; }
  SongQueue* current = this->getQueue();
  while(current != NULL) { // loop through queue
    if(current->value == song) { return true; } // if found song then return true
    current = current->next;
  }
  return false;
}
SongQueue::SongQueue(string a, SongQueue* p, SongQueue* n) { // a humble constructor...
  value = a;
  previous = p;
  next = n;
}
string SongQueue::dequeue() {
  SongQueue* first = this->getQueue(); // get first element and song
  string song = value; // store head song
  if(first->next != NULL) {
    SongQueue* newHead = first->next; // will be new head
    first->next = newHead->next;
    first->value = newHead->value;
    if(newHead->next != NULL) { newHead->next->previous = this; }
    newHead->value="";
    newHead->next=nullptr;
    newHead->previous=nullptr;
    newHead=nullptr;
    delete newHead;
  } else { first->value=""; } // just one node
  return song;
}
void SongQueue::enqueue(string x) {
  if(this->isEmpty()) { // if empty just set value to added song
    this->value = x;
  } else {
    SongQueue* current = this; // get a place in queue
    while(current->next != NULL) { current = current->next; } // go to end of queue
    SongQueue* newSong = new SongQueue(x, current, NULL); // new "tail"
    current->next = newSong;
  }
}
bool SongQueue::isEmpty() { return (this->value == "" && this->previous == NULL && this->next == NULL); }
string SongQueue::peekFront() { return this->getQueue()->value; }
// reads the file "songs.txt". Extracts the song's title and stores it in a queue.
SongQueue* SongQueue::readPlayList() {
  SongQueue* result = new SongQueue();
  string line;
  ifstream fileInput("songs.txt"); // Creates an input stream 
  int songIndex = 0; // count trial number
  if (fileInput.is_open()) { // open file
    while ( getline (fileInput, line) ) { // get lines
      for(int i = 0; i < line.length(); i++) {
        if (line.at(i) == '-') {
          line = line.substr(0, i - 1);
          break;
        }
      }
      result->enqueue(line);
    }
    fileInput.close();
  }
  return result;
}
/* processes the character codes A, P, D, Q, a, p, d, q.
"A" prompts the user to enter the name of the song, 
adds it to the queue, and displays the whole queue
after "Your music queue:  " . Do not add the same song twice.

"P" plays the song, if one exists, by displaying 
"Now playing: " and its title and then removing it from the queue.
If there is nothing play, the program displays "Empty queue!"

"D" displays the queue, prompts the user by showing 
"Delete which song (exact match)?" and will either delete the 
song and display the queue or show "Error:  Song not in list."   

"Q" displays "No more music for you today.  Goodbye!" 
and ends the program.
*/
void SongQueue::processRequest(string str) {
  string choice = str;
  if(choice == "a" || choice == "A") { // add song (enqueue)
    cout << "Song to add: ";
    string song;
    cin.ignore();
    getline(cin, song);
    if(this->contains(song)) {
      cout << "A duplicate exists so song was not added" << endl;
    } else {
      this->enqueue(song);
    }
  } else if(choice == "p" || choice == "P") { // play song (dequeue)
    if(this->isEmpty()) {
      cout << "Empty queue!" << endl;
    } else {
      cout << "Now Playing: " << this->dequeue() << endl;
    }
  } else if(choice == "d" || choice == "D") { // delete song
    cout << "Your music queue: ";
    this->printSongList();
    cout << "Delete which song (exact match)? ";
    string song;
    cin.ignore();
    getline(cin, song);
    if(this->contains(song)) {
      this->removeSong(song);
    } else {
      cout << "Error: Song not in list." << endl;
    }
  } else if(choice == "q" || choice == "Q") { // quit
    cout << "No more music for you today. Goodbye!" << endl;
    exit(0);
  } else {
    cout << "Invalid. Try again." << endl;
  }
}
// prints the songs in the queue, separated by commas.
void SongQueue::printSongList() {
  SongQueue* currentSong = this->getQueue(); // get first in queue
  string result = "";
  while(currentSong != NULL) { // loop till end of queue
    result += currentSong->value;
    result += ", ";
    currentSong = currentSong->next;
  }
  cout << result << endl; // print out
}
// standard accessor method.
SongQueue* SongQueue::getQueue() {
  SongQueue* current = this;
  while(current->previous != NULL) { current = current->previous; } // loop till head
  return current;
}
int main() {
  SongQueue* songs = new SongQueue();
  songs = songs->readPlayList(); // call readPlaylist
  string prompt = "Add song (A), Play song (P), Delete song (D), Quit (Q): ";
  do {
    cout << "Your music queue: ";
    songs->printSongList();
    cout << prompt; // prompt the user
    string choice; // get the choice
    cin >> choice;
    songs->processRequest(choice); // process it
  } while( true ); // repeat until quit   
}