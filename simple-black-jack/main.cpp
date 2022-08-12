#include "Card.h"
#include "Deck.h"
#include "gamefunctions.h"
#include <iostream>
#include <array> // For std::array<>
#include <ctime> // For time()
#include <cstdlib> // For rand() and srand()
#include <cassert> // For assert()

int main()
{
	srand(static_cast<unsigned int>(time(0))); // Using system clock as starting value
	rand(); // Resetting first random number (for Visual Studio specifically)

	Deck deck;
	deck.shuffleDeck();

	if (playBlackjack(deck)) { std::cout << "You win!\n"; } 
	else { std::cout << "You lose!\n"; }
		
	return 0;
}