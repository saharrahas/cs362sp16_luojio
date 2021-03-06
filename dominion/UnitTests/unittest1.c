#include "../dominion.c"
#include "../rngs.c"
#include "../myassert.h"

/*************************************
Test for "updateCoins()" function
*************************************/

int main(){
	printf("\n*********************************************************\n\n");
	printf("                      Unit Test 1\n\n");
	printf("*********************************************************\n");

//	Test Initialization
	int i, temp, coin_result=0;
	srand (time(NULL));
	struct gameState game;
	int cards[10] = {estate, duchy, adventurer, embargo, sea_hag, feast, gardens, mine, tribute, outpost}; 
	int playerNum = 4;
	int theplayer = 2;

// Random settings
	int ramdomSeed = rand() % 99999 + 1;	
	int bonus = rand() % 10;
	int handNum = rand() % MAX_HAND;
	//initializeGame(playerNum, cards, ramdomSeed, &game);

	check_functions(initializeGame(playerNum, cards, ramdomSeed, &game));

	game.handCount[theplayer] = handNum;	// set a random hand number to selected player

	for(i = 0; i < handNum; i++){ 
		temp = rand() % 4;
		if(temp == 0){
			game.hand[theplayer][i] = copper;
			coin_result += 1;
		}else if(temp == 1){
			game.hand[theplayer][i] = silver;
			coin_result += 2;
		}else if(temp == 2){
			game.hand[theplayer][i] = gold;
			coin_result += 3;
		}else
			game.hand[theplayer][i] = 0;
	}
//  Test functions

	check_functions(updateCoins(theplayer, &game, bonus));

	check_equal(game.coins, bonus + coin_result);

	printf("Function 'updateCoins()': TEST SUCCESSFULLY COMPLETED\n\n");
	return 0;
}
