#pragma once

#include "Card.h"
#include <array>
#include <iostream>
#include <cassert>

class Deck
{
private:
	std::array<Card, 52> m_deck;
	int m_cardIndex = 0;
	// Generating random number between min and max(included).
	// srand() should have been called by the moment
	static int getRandomNumber(int min, int max);
	
	static void swapCard(Card& a, Card& b);

public:
	Deck();

	void printDeck() const;

	void shuffleDeck();

	const Card& dealCard();
};