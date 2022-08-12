#include "Deck.h"
#include <iostream>

char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;

	do
	{ 
	std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

bool playBlackjack(Deck& deck)
{
	//|*|*|*|Brief gameplay rules below|*|*|*\\

	int playerTotal = 0;
	int dealerTotal = 0;

	// Dealer gets one card
	dealerTotal += deck.dealCard().getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// Player gets two cards
	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();

	// Player starts
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's') { break; }

		playerTotal += deck.dealCard().getCardValue();

		// Checking if the player didn't lose
		if (playerTotal > 21) { return false; }
	}

	// If the player didn't lose (he has more than 21 points) then dealer gets cards until he has at least 17 points
	while (dealerTotal < 17)
	{
		dealerTotal += deck.dealCard().getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// If dealer lost player won
	if (dealerTotal > 21) { return true; }

	return (playerTotal > dealerTotal);
}