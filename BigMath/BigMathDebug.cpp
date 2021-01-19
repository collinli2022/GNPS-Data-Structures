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
	private:
		int digit;
		BigMath* next; // the head will be the smallest digit
		BigMath* add(int carry, BigMath* A, BigMath* B);
		BigMath* sub(int carry, BigMath* A, BigMath* B);
	public:
		BigMath(int d=0, BigMath* n=NULL) {
			digit = d;
			next = n;
		}
		BigMath operator + (BigMath head);
		BigMath operator - (BigMath head);
		
		int getDigit() {
			return digit;
		}
		
		BigMath* getNext() {
		    return next;
		}
		
		void setDigit(int d) {
			digit = d;
		}
		
		void setNext(BigMath* n) {
			next = n;
		}
		//TODO: write a to string operator
		string toString();
		
		operator const char*();
};

BigMath BigMath::operator + (BigMath head) { // addition
			int sum = head.digit + digit;
			BigMath copy; // will be head of number
			copy.digit = (sum%10); // first digit
			copy.next = add((sum/10), this->next, head.next);
			
			return copy;
}
		
BigMath* BigMath::add(int carry, BigMath* A, BigMath* B) {
			BigMath* copy = new BigMath();
			
			int sum = carry;
			if(A != NULL) {
			    sum += A->getDigit();
			}
			if(B != NULL) {
			    sum += B->getDigit();
			}
			
			copy->digit = sum%10;
		
		    if(A != NULL && B != NULL) {
				copy->next = add((sum/10), A->next, B->next); // set next as next digit
		    } else if(A != NULL) {
				copy->next = add((sum/10), NULL, A->next);
		    } else if(B != NULL) {
				copy->next = add((sum/10), NULL, B->next);
		    } else { // both are null
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
    int neg = 1;
    if(aLen < bLen) {
        A = &head;
        B = this;
        neg = -1;
    }
    
    if(aLen == bLen) {
        cout << "SAME" << endl;
        
        string strA = A->toString();
        string strB = B->toString();
        for(int i = 0; i < aLen; i++) {
            int aa = stoi( string(1, strA[i]) );
            int bb = stoi( string(1, strB[i]) );
            cout << aa << " vs " << bb << endl;
            if(aa < bb) {
                A = &head;
                B = this;
                neg = -1;
                break;
            } else if(aa > bb) {
                break;
            }
        }
    }

    BigMath copy = BigMath();
    BigMath* C = &copy;
    
    while(A != NULL || B != NULL) {
        cout << "START" << endl;
        
        int digA = 0, digB = 0;
        
        if(A != NULL) {
            digA = A->getDigit();
            if(digA < 0) {
                if(A->next != NULL) {
                    A->next->digit = A->next->getDigit()-1;
                    digA += 10;
                }
            }
        }
        if(B != NULL) {
            digB = B->getDigit();
        } else { // means only A left over
            cout << "A" << endl;
            cout << "placed: " << digA << endl;
            C->digit = digA;
            A = A->next;
            C->next = new BigMath();
            C = C->next;
            continue;
        }
        
        cout << digA << " --- " << digB << endl;
        
        if(A == NULL) { // A will always be larger in length or the same length as B
            cout << "AAA" << endl;
            break;
        } else { // Both are not NULL
            int diff = digA - digB;
            cout << "Diff = " << diff << endl;
            if(diff >=0) {
                cout << "Ba" << endl;
                cout << "placed: " << diff << endl;
                C->digit = diff;
                A = A->next;
                B = B->next;
                C->next = new BigMath();
                C = C->next;
            } else {
                if(A->next != NULL) {
                    cout << "Bb" << endl;
                    A->next->digit = A->next->getDigit()-1;
                    diff += 10;
                    cout << "placed: " << diff << endl;
                    C->digit = diff;
                    A = A->next;
                    B = B->next;
                    C->next = new BigMath();
                    C = C->next;
                } else {
                    cout << "Bc" << endl;
                    cout << "placed: " << diff << endl;
                    C->digit = diff;
                    A = A->next;
                    B = B->next;
                    C->next = new BigMath();
                    C = C->next;
                }
            }
        }
    }
    
    BigMath* temp = &copy;
    
    if(temp != NULL) {
        
        cout << "Endgame" << endl;
        
        bool stillZero = true;
        while(stillZero) {
            cout << "Here" << endl;
            temp = &copy;
            while(temp->next != NULL) {
                if(temp->next->next != NULL) {
                    cout << "he" << endl;
                    temp = temp->next;
                } else {
                    cout << "hbe" << endl;
                    break;
                }
            }
            cout << temp->getDigit() << endl;
            if(temp->next->getDigit() == 0) {
                temp->next = NULL;
            } else {
                stillZero = false;
            }
        }
        
        temp = &copy;
        
        while(temp->next != NULL) {
          temp = temp->next;
        }
        temp->digit = temp->getDigit() * neg;
    }
    
    return copy;

}

string BigMath::toString() {
	ostringstream formattedNum; // assists easy string construction
	BigMath* temp = this;
	while(temp->next != NULL) {
	    formattedNum << temp->getDigit();
        temp = temp->next;
	}
    if(temp->getDigit() >= 0) {
        formattedNum << temp->getDigit();
    } else {
        formattedNum << temp->getDigit() * -1 << "-";
    }
	
	
	string str = formattedNum.str();
	string rev = string(str.rbegin(),str.rend()); 
	return rev;
}

BigMath::operator const char*() {
			ostringstream formattedNum; // assists easy string construction
			formattedNum << digit;
			string temp = formattedNum.str();
			return temp.c_str();
}

BigMath construct(string A) {
	int firstIndex = A.size()-1; 
	BigMath head = BigMath( stoi( string(1, A[firstIndex]) ) ); // the last digit/head
	BigMath* prev = &head; // will represent the prev BigMath object
	for(int i = firstIndex-1; i >= 0; i--) { // iterate from last digit to first
        BigMath* next = new BigMath();
		next->setDigit( stoi(string(1, A[i]))); // set digit
		prev->setNext(next); // set next
		prev = next;
	}
	prev->setNext(NULL);
	return head;
}

int main() {

	int again = 0;
	
	do {
		
		string num1 = "", num2 = "";
		cout << "Enter first positive integer: ";
		cin >> num1;
		cout << "Enter second positive integer: ";
		cin >> num2;
		
		BigMath one = construct(num1);
		BigMath two = construct(num2);
		
		int choice = 0;
		cout << "Please select a choice: " << endl;
		cout << "\t1. Add" << endl;
		cout << "\t2. Subtract" << endl;
		cin >> choice;
		
		if(choice == 1) {
		    cout << one.toString() << " + " << two.toString() << " = ";
    		BigMath sum = one+two;
    		cout << sum.toString() << endl;
		} else if (choice == 2) {
		    cout << one.toString() << " - " << two.toString() << " = ";
    		BigMath diff = one-two;
    		cout << diff.toString() << endl;
		}

		cout << "Do again? (0-no, 1-yes):";
		cin >> again;
	} while (again == 1);


	return 0;	
}

