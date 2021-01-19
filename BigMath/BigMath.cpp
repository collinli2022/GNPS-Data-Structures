// Collin Li
// Data Structures
// 01/04/2021
// BigMath

// Preprocessor directive
#include <iostream>
#include <string>
#include <sstream> // new include for ostringstream
using namespace std;

class BigMath {
	private: // contain private attributes for digit and pointer to next
		int digit;
		BigMath* next; // the head will be the smallest digit
		BigMath* add(int carry, BigMath* A, BigMath* B);
	public:
		BigMath(int d=0, BigMath* n=NULL) { // constructor takes integer (digit) and reference (to next node)
			digit = d;
			next = n;
		}
		BigMath operator + (BigMath head); // adding operator
		BigMath operator - (BigMath head); // subtracting operator
		// accesser methods
		int getDigit() {
			return digit;
		}
		BigMath* getNext() {
		    return next;
		}
		// mutator methods
		void setDigit(int d) {
			digit = d;
		}
		void setNext(BigMath* n) {
			next = n;
		}
        // converts BigMath into string containing all digits linked to this BigMath object
		string toString();
};

BigMath BigMath::operator + (BigMath head) { // addition
			int sum = head.digit + digit;
			BigMath copy; // will be head of number
			copy.digit = (sum%10); // first digit
			copy.next = add((sum/10), this->next, head.next); // recursion
			
			return copy;
}
		
BigMath* BigMath::add(int carry, BigMath* A, BigMath* B) {
			BigMath* copy = new BigMath();
			int sum = carry; // add the numbers and possible "remainder"
			if(A != NULL) { sum += A->getDigit(); }
			if(B != NULL) { sum += B->getDigit(); }
			copy->digit = sum%10; // to get the (last) digit
		    if(A != NULL && B != NULL) {
				copy->next = add((sum/10), A->next, B->next); // A and B still have remaining digits
		    } else if(A != NULL) {
				copy->next = add((sum/10), NULL, A->next); // B does not have any more digits to add
		    } else if(B != NULL) {
				copy->next = add((sum/10), NULL, B->next); // A does not have any more digits to add
		    } else { // both are null
		        if(sum != 0) { // A remainder left
		            return new BigMath(sum);
		        }
		        return NULL;
		    }
			return copy;
}

BigMath BigMath::operator - (BigMath head) { // subtraction
    BigMath* A = this;
    BigMath* B = &head;
    int aLen = A->toString().length();
    int bLen = B->toString().length();
    // A will always be larger in length or the same length as B
    int neg = 1; // indicate if result is negative or not
    if(aLen < bLen) { // if true then swap A and B to make sure it is larger - smaller
        A = &head;
        B = this;
        neg = -1;
    }
    if(aLen == bLen) { // account for if A and B are same length but A may be smaller than B
        string strA = A->toString();
        string strB = B->toString();
        for(int i = 0; i < aLen; i++) { // compare digits
            int aa = stoi( string(1, strA[i]) );
            int bb = stoi( string(1, strB[i]) );
            if(aa < bb) { // B is larger so swap, making sure A is now the larger Digit
                A = &head;
                B = this;
                neg = -1;
                break;
            } else if(aa > bb) {
                break;
            }
            if(i == aLen-1) { // means A and B are equal so return 0
                return BigMath(0);
            }
        }
    }
    BigMath copy = BigMath(); // will be the head of the BigMath object
    BigMath* C = &copy;
    while(A != NULL || B != NULL) {
        int digA = 0, digB = 0; // represent the current digit
        if(A != NULL) {
            digA = A->getDigit(); // get the current A digit
            if(digA < 0) { // if digit is < 0 then regroup
                if(A->next != NULL) { // make sure there is a next to call
                    A->next->digit = A->next->getDigit()-1;
                    digA += 10;
                }
            }
        }
        if(B == NULL) { // means I can just place down digA since nothing to subtract (B has no more digits)
            C->digit = digA;
            A = A->next;
            C->next = new BigMath();
            C = C->next;
        } else { // Both are not NULL
            digB = B->getDigit();
            int diff = digA - digB; // find difference
            if(diff >=0) { // no need to regroup
                C->digit = diff; // set digit
                A = A->next; // go to next
                B = B->next; // go to next
                C->next = new BigMath(); // new digit
                C = C->next;
            } else { // need to regroup
                if(A->next != NULL) { // make sure there is a next (technically there should always be a next because A > B)
                    A->next->digit = A->next->getDigit()-1;
                    C->digit = diff + 10; // set digit (+ 10 because regrouped)
                    A = A->next;
                    B = B->next;
                    C->next = new BigMath();
                    C = C->next;
                }
            }
        }
    }
    // need to add the negative sign if result is negative and make sure there are no extra zeros
    BigMath* temp = &copy;
    if(temp != NULL) {
        bool stillZero = true;
        while(stillZero) { // to make sure there are no extra zeros
            temp = &copy;
            while(temp->next != NULL) { // get to second to last object
                if(temp->next->next != NULL) {
                    temp = temp->next;
                } else { break; }
            }
            if(temp->next != NULL) {
                if(temp->next->getDigit() == 0) { // if the first object's digit is 0, remove it from this linked list
                    temp->next = NULL;
                } else {
                    stillZero = false;
                }
            } else { // keep going and deleting zeros in the front until there are no more 
                stillZero = false;
            }
        }
        while(temp->next != NULL) { // make sure temp is the last object
          temp = temp->next;
        }
        temp->digit = temp->getDigit() * neg; // add negative sign if negative to digit in the front (largest place)
    }
    A = nullptr; // set to null
	delete(A); // delete pointer
	B = nullptr;
	delete(B);
	C = nullptr;
	delete C;
	temp = nullptr;
	delete temp;
    
    return copy;
}

string BigMath::toString() {
	ostringstream formattedNum; // assists easy string construction
	BigMath* temp = this;
	while(temp->next != NULL) { // add all digits except first one (last node)
	    formattedNum << temp->getDigit();
        temp = temp->next;
	}
    if(temp->getDigit() >= 0) { // if last node's digit is positive add it normally
        formattedNum << temp->getDigit();
    } else { // if last node's digit is negative add digit first then sign
        formattedNum << temp->getDigit() * -1 << "-";
    }
	string str = formattedNum.str();
	string rev = string(str.rbegin(),str.rend()); // need to reverse because first node is smallest digit
	temp = nullptr; // set to nullptr
	delete(temp);
	return rev;
}

BigMath construct(string A) { // helper function "341"
	int firstIndex = A.length()-1; 
	BigMath head = BigMath( stoi( string(1, A[firstIndex]) ) ); // the last digit/head
	BigMath* prev = &head; // will represent the prev BigMath object
	for(int i = firstIndex-1; i >= 0; i--) { // iterate from last digit to first (right to left)
        BigMath* next = new BigMath();
		next->setDigit(stoi(string(1, A[i]))); // set digit
		prev->setNext(next); // set next
		prev = next;
		next = nullptr; // set to null
		delete next; // delete pointer
	}
	prev->setNext(NULL); // end of BigMath
	prev = nullptr;
	delete prev;
	return head;
}

int main() {
	int again = 0;
	do {
		// first choose operation
		int choice = 0;
		cout << "Please select a choice: " << endl;
		cout << "\t1. Add" << endl;
		cout << "\t2. Subtract" << endl;
		cin >> choice;
		// enter values required
		string num1 = "", num2 = "";
		cout << "Enter first positive integer: ";
		cin >> num1;
		cout << "Enter second positive integer: ";
		cin >> num2;
		// construct the BigMath objects from string
		BigMath one = construct(num1);
		BigMath two = construct(num2);
		if(choice == 1) { // addition
		    cout << one.toString() << " + " << two.toString() << " = ";
    		BigMath sum = one+two;
    		cout << sum.toString() << endl;
		} else if (choice == 2) { // subtraction
		    cout << one.toString() << " - " << two.toString() << " = ";
    		BigMath diff = one-two;
    		cout << diff.toString() << endl;
		}

		cout << "Do again? (0-no, 1-yes):"; // ask user to do again or not
		cin >> again;
	} while (again == 1);
	return 0;	
}
