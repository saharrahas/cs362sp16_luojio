#include "../dominion.c"
#include "../rngs.c"
#include "../myassert.h"

/*************************************
Test for "drawCard()" function
*************************************/

int main(){
	printf("\n*********************************************************\n\n");
	printf("                      Unit Test 3\n\n");
	printf("*********************************************************\n");
//	Test Initialization
	int i, temp1,temp2;
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
	check_functions(drawCard(theplayer, &game));

	// true when temp1 = temp2 + 1
	temp1 = game.deckCount[theplayer];
	for(i = 0; i < 5; i++){
		drawCard(theplayer, &game);
	}
	temp2 = game.deckCount[theplayer];
	check_equal(temp1,temp2+5);


	// true when temp1 = temp2 - 1
	temp1 = game.handCount[theplayer];
	for(i = 0; i < 3; i++){
		drawCard(theplayer, &game);
	}
	temp2 = game.handCount[theplayer];
	check_equal(temp1,temp2-3);


	printf("Function 'drawCard()': TEST SUCCESSFULLY COMPLETED\n\n");
	return 0;
}
