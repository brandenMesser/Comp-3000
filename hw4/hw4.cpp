/*Branden Messer
 * FileName: hw4.cpp
 */


#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<ctime>

using namespace std;

bool at_least_two_alive(bool, bool, bool);
void pressAnyKey(void);
void Aaron_shoots1(bool&, bool&);
void Bob_shoots(bool&, bool&);
void Charlie_shoots(bool&, bool&);
void Aaron_shoots2(bool&, bool&);
void strategy1(void);
void strategy2(void);

	//testing methods
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);

// varibles

const double aAcc = 33.33;
const double bAcc = 50;
const double cAcc = 100;
const int duels = 10000;
int aWon = 0;
int aWon2 = 0;


int main(){
	
	
	cout.setf(ios::fixed); cout.setf(ios::showpoint); cout.precision(2);
	srand(clock());
	
	cout << "*** Welcome to Branden Messer's Duel Simulator ***" << endl;
	test_at_least_two_alive();
	cout << endl;

	test_Aaron_shoots1();
	cout << endl;

	test_Bob_shoots();
	cout << endl;
	
	test_Charlie_shoots();
	cout << endl;

	test_Aaron_shoots2();
	cout << endl;
	
	strategy1();
	
	strategy2();
	
	cout << endl;

	
	if (aWon2 > aWon) {
		 cout << "Strategy 2 is better than strategy 1.";
	}
	
	else {
		cout << "Strategy 1 is better than strategy 2.";
	}

	cout << endl;
	
	return 0;
}

void pressAnyKey(void) {

	cout << "Press any key to continue..." << endl;
	cin.ignore().get();

}

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
	if( A_alive && B_alive && C_alive || A_alive && B_alive || A_alive && C_alive || B_alive && C_alive) {
	
		return true;
	}

	else {
		return false;
	}
}

void test_at_least_two_alive(void) {
	cout << "Unit Testing 1: Function at_least_two_alive()" << endl;
	cout << "	Case 1: Aaron alive, Bob alive, Charlie alive" << endl;
	cout << "	Case passed ..." << endl;

	cout << "	Case 2: Aaron dead, Bob alive, Charlie alive" << endl;
	assert(at_least_two_alive(false, true, true));
	cout << "	Case passed ..." << endl;
	
	cout << "	Case 3: Aaron alive, Bob dead, Charlie alive" << endl;
	assert(at_least_two_alive(true, false, true));
	cout << "	Case passed ..." << endl;

	cout << "	Case 4: Aaron alive, Bob alive, Charlie dead" << endl;
	assert(at_least_two_alive(true, true, false));
	cout << "	Case passed ..." << endl;

	cout << "	Case 5: Aaron dead, Bob dead, Charlie alive" << endl;
	assert(at_least_two_alive(false, false, true) == false);
	cout << "	Case passed ..." << endl;

	cout << "	Case 6: Aaron dead, Bob alive, Charlie dead" << endl;
	assert(at_least_two_alive(false, true, false) == false);
	cout << "	Case passed ..." << endl;

	cout << "	Case 7: Aaron alive, Bob dead, Charlie dead" << endl;
	assert(at_least_two_alive(true, false, false) == false);
	cout << "	Case passed ..." << endl;

	cout << "	Case 8: Aaron dead, Bob dead, Charlie dead" << endl;
	assert(at_least_two_alive(false, false, false) == false);
	cout << "	Case passed ..." << endl;
	
	pressAnyKey();
}

void Aaron_shoots1(bool& B_alive, bool& C_alive){
	double hit = (rand() % 100) ;
	
	if(C_alive == true) {
		cout << "	Aaron is shooting at Charlie" << endl;
	
		if (aAcc >= hit) {
			C_alive = false;
			cout << "	Charlie is dead." << endl;
		}

		else {
			C_alive = true;
			cout << "	Aaron misses." << endl;

		}
	}
	else {
		cout << "	Aaron is shooting at Bob" << endl;
		
		if (aAcc >= hit) {
			B_alive = false;
			cout << "	Bob is dead." << endl;
		}

		else {
			B_alive = true;
			cout << "	Aaron misses." << endl;

		}		
	}
}

void test_Aaron_shoots1(void) {
	cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)" << endl;
	cout << "	Case 1: Bob alive, Charlie alive" << endl;
	bool B_alive = true;
	bool C_alive = true;
	Aaron_shoots1(B_alive, C_alive);
	
	cout << "	Case 2: Bob dead, Charlie alive" << endl;
	B_alive = false;
	C_alive = true;
	Aaron_shoots1(B_alive, C_alive);
	
	cout << "	Case 3: Bob alive, Charlie dead" << endl;
	B_alive = true;
	C_alive = false;
	Aaron_shoots1(B_alive, C_alive);
	
	pressAnyKey();
}


void Bob_shoots(bool& A_alive, bool& C_alive) {
	double hit = (rand() % 100);

	if (C_alive == true) {
		cout << "	Bob is shooting at Charlie" << endl;
		if (bAcc >= hit) {
			C_alive = false;
			cout << "	Charlie is dead." << endl;

		}
		
		else {
			C_alive = true;
			cout << "	Bob misses." << endl;

		}

	}	

	else {
		cout << "	Bob is shooting at Aaron" << endl;
		if (bAcc >= hit) {
			A_alive = false;
			cout << "	Aaron is dead." << endl;
		}
		
		else {
			A_alive = true;
			cout << "	Bob misses." << endl;
		}
	}	
}

void test_Bob_shoots(void) {

	cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)" << endl;
	cout << "	Case 1: Aaron alive, Charlie alive" << endl;
	bool A_alive = true;
	bool C_alive = true;
	Bob_shoots(A_alive, C_alive);

	cout << "	Case 2: Aaron dead, Charlie alive" << endl;
	A_alive = false;
	C_alive = true;
	Bob_shoots(A_alive, C_alive);
	
	cout << "	Case 3: Aaron alive, Charlie dead" << endl;
	A_alive = true;
	C_alive = false;
	Bob_shoots(A_alive, C_alive);
	
	pressAnyKey();
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
	if (B_alive == true) {
	
	cout << "	Charlie is shooting at Bob" << endl;
	B_alive = false;
	cout << "	Bob is dead." << endl;
	
	}
	
	else {
	cout << "	Charlie is shooting at Aaron" << endl;
	A_alive = false;
	cout << "	Aaron is dead." << endl;
	}
}



void test_Charlie_shoots(void) {

	cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)" << endl;

	cout << "	Case 1: Aaron alive, Bob alive" << endl;
	bool A_alive = true;
	bool B_alive = true;
	Charlie_shoots(A_alive, B_alive);

	cout << "	Case 2: Aaron dead, Bob alive" << endl;
	A_alive = false;
	B_alive = true;
	Charlie_shoots(A_alive, B_alive);

	cout << "	Case 3: Aaron alive, Bob dead" << endl;
	A_alive = true;
	B_alive = false;
	Charlie_shoots(A_alive, B_alive);
		
	pressAnyKey();
}

void Aaron_shoots2(bool& B_alive, bool& C_alive){
        double hit = (rand() % 100) ;
	
	if(C_alive == true && B_alive == true) {
		cout << "	Aaron intentionally misses his first shot" << endl;
		C_alive = true;
		B_alive = true;
		cout << "	Both Bob and Charlie are alive." << endl;	
	}
	
        else if(C_alive == true && B_alive == false) {
                cout << "	Aaron is shooting at Charlie" << endl;

                if (aAcc >= hit) {
                        C_alive = false;
                        cout << "       Charlie is dead." << endl;
                }

                else {
                        C_alive = true;
                        cout << "	Aaron misses." << endl;
                }
        }
        else {
                cout << "       Aaron is shooting at Bob" << endl;

                if (aAcc >= hit) {
                        B_alive = false;
                        cout << "	Bob is dead." << endl;
                }

                else {
                        B_alive = true;
                        cout << "	Aaron misses." << endl;

                }
        }
}

void test_Aaron_shoots2(void) {
	
        cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)" << endl;
        cout << "       Case 1: Bob alive, Charlie alive" << endl;
        bool B_alive = true;
        bool C_alive = true;
        Aaron_shoots2(B_alive, C_alive);

        cout << "       Case 2: Bob dead, Charlie alive" << endl;
        B_alive = false;
        C_alive = true;
        Aaron_shoots2(B_alive, C_alive);

        cout << "       Case 3: Bob alive, Charlie dead" << endl;
        B_alive = true;
        C_alive = false;
        Aaron_shoots2(B_alive, C_alive);

        pressAnyKey();
}

void strategy1() {
	cout << endl;	
	cout << "Ready to test strategy 1 (run 10000 times) :" << endl;
	pressAnyKey();

	int round = 0;	
	bool  A_alive = true;
	bool  B_alive = true;
	bool  C_alive = true;
	
	int  bWon = 0;
	int  cWon = 0;

	while (round < duels){
	
		while (at_least_two_alive(A_alive, B_alive, C_alive)) {
		
			if (A_alive == true) { 
				Aaron_shoots1(B_alive, C_alive);
			}
		
			if (B_alive == true) {
				Bob_shoots(A_alive, C_alive);

			}
		
			if (C_alive == true) {
				Charlie_shoots(A_alive, B_alive);
	 		}
	
		}
	
		if (A_alive == true && B_alive == false && C_alive == false) {
			aWon++;
		}
		
		else if (A_alive == false && B_alive == true && C_alive == false) {
			bWon++;
		}
		
		else {
			cWon++;
		}
	
		A_alive = true;
		B_alive = true;
		C_alive = true;
		
		round++;
	}
	double perA = aWon / 100;
        double perB = bWon / 100;
        double perC = cWon / 100;
	
	cout << endl;
        cout << "Aaron won " << aWon << "/" << duels << " duels or " << perA << "%" << endl;
        cout << "Bob won " << bWon << "/" << duels << " duels or " << perB<< "%" << endl;
        cout << "Charlie won " << cWon << "/" << duels << " duels or " << perC << "%" << endl;
}

void strategy2() {
	cout << "Ready to test strategy 2 (run 10000 times) :" << endl;
        pressAnyKey();

        int round2 = 0;
        bool  A_alive = true;
        bool  B_alive = true;
        bool  C_alive = true;
        
        int  bWon2 = 0;
        int  cWon2 = 0;
        
	 while (round2 < duels){
        
                while (at_least_two_alive(A_alive, B_alive, C_alive)) {
                 	
			if(A_alive == true)  {	
				Aaron_shoots2(B_alive, C_alive);
                        } 
                
                        if (B_alive == true) {
                                Bob_shoots(A_alive, C_alive);
    
                        }
                
                        if (C_alive == true) {
                                Charlie_shoots(A_alive, B_alive);
                        }

                }

                if (A_alive == true && B_alive == false && C_alive == false) {
                        aWon2++;
                }

                else if (A_alive == false && B_alive == true && C_alive == false) {
                        bWon2++;
                }

                else {
                        cWon2++;
                }

                A_alive = true;
                B_alive = true;
                C_alive = true;

                round2++;
        }

	
        double perA2 = aWon2 / 100;
        double perB2 = bWon2 / 100;
        double perC2 = cWon2 / 100;

        cout << endl;

        cout << "Aaron won " << aWon2 << "/" << duels << " duels or " << perA2 << "%" << endl;
        cout << "Bob won " << bWon2 << "/" << duels << " duels or " << perB2 << "%" << endl;
        cout << "Charlie won " << cWon2 << "/" << duels << " duels or " << perC2 << "%" << endl;
} 


