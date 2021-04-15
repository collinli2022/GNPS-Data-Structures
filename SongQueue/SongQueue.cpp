// Collin Li
// Data Structures
// 04/12/2021
// Song Queue Project

// Preprocessor directive
#include <iostream>
#include <string>
using namespace std;

class SongQueue {
  private:
    string value;
    SongQueue* previous;
    SongQueue* next;
    void removeSong(string song) {
      if(isEmpty()) {
        return;
      }
      SongQueue* current = this->getQueue();
      while(current != NULL) {
        if(current->value == song) {
          current->value = "";
          if(current->previous == NULL && current->next == NULL) {
            current->previous = NULL;
            current->next = NULL;
          } else if(current->previous == NULL) {
            current->next->previous = NULL;
            current->next = NULL;
          } else if(current->next == NULL) {
            current->previous->next = NULL;
            current->previous = NULL;
          } else {
            current->next->previous = current->previous;
            current->next = NULL;
            current->previous->next = current->next;
            current->previous = NULL;
          }
          return;
        }
        current = current->next;
      }
    }
    bool contains(string song) {
      if(isEmpty()) {
        return false;
      }
      SongQueue* current = this->getQueue();
      while(current != NULL) {
        if(current->value == song) {
          return true;
        }
        current = current->next;
      }
      return false;
    }
  public:
    SongQueue(string a="", SongQueue* p=NULL, SongQueue* n=NULL); // constructor

    string dequeue();
    void enqueue(string x);
    bool isEmpty();
    string peekFront();
    
    /* reads the file "songs.txt".  Extracts the song's title
  and stores it in a queue.
  */
    SongQueue* readPlayList() {
      
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
    
    void processRequest(string str) {
    
    }
       
    // prints the songs in the queue, separated by commas.
    void printSongList() {
      SongQueue* currentSong = this->getQueue();
      string result = "";
      while(currentSong != NULL) {
        result += currentSong->value;
        result += ", ";
        currentSong = currentSong->next;
      }
      cout << result << endl;
    }
       
    // standard accessor method.
    SongQueue* getQueue() {
      SongQueue* current = this;
      while(current->previous != NULL) {
        current = current->previous;
      }
      return current;
    }

    ~SongQueue() { delete previous; delete next; } // deconstructor that deletes pointer
};

SongQueue::SongQueue(string a, SongQueue* p, SongQueue* n) {
  value = a;
  previous = p;
  next = n;
}

string SongQueue::dequeue() {
  // get first element and song
  SongQueue* first = this->getQueue();
  string song = value;

  // delete first element
  if(first->next != NULL) {
    SongQueue* newHead = first->next;
    first->next = newHead->next;
    first->value = newHead->next->value;
    if(newHead->next != NULL) {
      newHead->next->previous = this;
    }
    newHead->value="";
    newHead->next=nullptr;
    newHead->previous=nullptr;
    newHead=nullptr;
    delete newHead;
  }
  return song;
}

void SongQueue::enqueue(string x) {
  if(this->isEmpty()) {
    this->value = x;
  } else {
    SongQueue* current = this;
    while(current->next != NULL) {
      current = current->next;
    }
    SongQueue* newSong = new SongQueue(x, current, NULL);
    current->next = newSong;
  }
}

bool SongQueue::isEmpty() {
  if(this->value == "" && this->previous == NULL && this->next == NULL) {
    return true;
  }
  return false;
}

string SongQueue::peekFront() {
  return this->getQueue()->value;
}

int main() {
  cout << "Start" << endl;
  SongQueue* test = new SongQueue("bob");
  cout << "1" << endl;
  test->enqueue("no");
  cout << "2" << endl;
  test->enqueue("sad");
  test->enqueue("ha");
  cout << "4" << endl;
  test->printSongList();
  cout << "Stop" << endl;
  
  //call readPlaylist
  //call printSongList
	  
  string prompt = "Add song (A), Play song (P), Delete song (D), Quit (Q):  ";
  string str = "";
  do{
  //prompt the user
  //get the choice
  //process it
  //repeat until quit     
  }while( true );
}

/*********************************************

      Sample output
 Your music queue: Really Love, Uptown Funk, Thinking Out Loud, Alright, Traveller, Shallow, 
 Add song (A), Play song (P), Delete song (D), Quit (Q):  p
 Now playing: Really Love
 Your music queue: Uptown Funk, Thinking Out Loud, Alright, Traveller, Shallow, 
 
 Add song (A), Play song (P), Delete song (D), Quit (Q):  x
 Invalid.  Try again.
 
 Add song (A), Play song (P), Delete song (D), Quit (Q):  d
 Your music queue: Uptown Funk, Thinking Out Loud, Alright, Traveller, Shallow, 
 Delete which song (exact match)?  xxx
 Error:  Song not in list.
 Your music queue: Uptown Funk, Thinking Out Loud, Alright, Traveller, Shallow, 
 
 Add song (A), Play song (P), Delete song (D), Quit (Q):  d
 Your music queue: Uptown Funk, Thinking Out Loud, Alright, Traveller, Shallow, 
 Delete which song (exact match)?  Alright
 Your music queue: Uptown Funk, Thinking Out Loud, Traveller, Shallow, 
 
 Add song (A), Play song (P), Delete song (D), Quit (Q):  q
 
 No more music for you today.  Goodbye!
 
**********************************************/
