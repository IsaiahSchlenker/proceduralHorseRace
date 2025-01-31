#include <iostream>
#include <random>
#include <cstdlib>
std::random_device rd;
std::uniform_int_distribution<int> dist(0, 1);

const int NUM_HORSES = 5;
const int TRACK_LENGTH = 15;

void advance(int horseNum, int* horses);
void printLane(int horseNum, int* horses);
bool isWinner(int horseNum, int* horses);
int updateBal(int bal, int bet, int winner, int betHorseNum);
void printBal(int bal);

int main(){
	std::cout << "bet more than your balance when you would like to quit" << std::endl;
	int bet;
	int bal = 100;
	bool keepGoing = true;
	int betHorseNum;
	int winner;
	while (keepGoing){
		int horses[] = {0,0,0,0,0};
		bool keepGoing2 = true;
		printBal(bal);
		std::cout << "How much would you like to bet: ";
		std::cin >> bet;
		if (bet > bal){
			keepGoing = false;
			keepGoing2 = false;
		}//end if
		std::cout << "Which horse would you like to bet on? (0,1,2,3,4): ";
		std::cin >> betHorseNum;
		std::cin.get();
		while (keepGoing2){
			for (int i = 0; i < NUM_HORSES; i++){
				advance(i, horses);
				printLane(i, horses);
				if (isWinner(i, horses)){
					std::cout << "Horse " << i << " wins!!!" << std::endl;
					keepGoing2 = false;
					winner = i;
					bal = updateBal(bal, bet, winner, betHorseNum);
				}//end if	
			}//end for
			std::cout << "Press enter for another turn";
			std::cin.get();
		}//end while2
	}//end while
}//end main

void advance(int horseNum, int* horses){
	int coin = dist(rd);
	if (coin == 1){
		*(horses+horseNum) += 1;
	}//end if
}//end advance

void printLane(int horseNum, int* horses){
	for(int i = 0; i < TRACK_LENGTH; i++){
		if(*(horses+horseNum) == i){
			std::cout << horseNum;
		}else{
			std::cout << ".";	
		}//end else
	}//end for
	std::cout << std::endl;
}//end printLane

bool isWinner(int horseNum, int* horses){
	if(*(horses+horseNum) == 15){
		return true;
	}else{
		return false;
	}//end else
}//end isWinner

int updateBal(int bal, int bet, int winner, int betHorseNum){
	if (winner == betHorseNum){
		bal += (5*bet);
	}else{
		bal -= bet;
	}//end else
	return bal;
}//end updateBal

void printBal(int bal){
	std::cout << "Current Balance: " << bal << std::endl;
}//end printBal
