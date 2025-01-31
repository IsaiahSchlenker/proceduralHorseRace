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

int main(){
	bool keepGoing = true;
	int horses[] = {0,0,0,0,0};
	while (keepGoing){
		for (int i = 0; i < NUM_HORSES; i++){
			advance(i, horses);
			printLane(i, horses);
			if (isWinner(i, horses)){
				std::cout << "Horse " << i << " wins!!!" << std::endl;
				keepGoing = false;
			}//end if	
		}//end for
		std::cout << "Press enter for another turn";
		std::cin.get();
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
