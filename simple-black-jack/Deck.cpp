#include "Deck.h"
#include <cassert>

int Deck::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // Using static since we have to calculate only once
	// Uniformly distributing calculation value from our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Deck::swapCard(Card& a, Card& b)
{
	Card temp = a;
	a = b;
	b = temp;
}

Deck::Deck() // Constructor
{
	int card = 0;
	for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
	for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
	{
		m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
		++card;
	}
}

void Deck::printDeck() const
{
	for (const auto& card : m_deck)
	{
		card.printCard();
		std::cout << ' ';
	}

	std::cout << '\n';
}

void Deck::shuffleDeck()
{
	// Sorting out every card in the deck
	for (int index = 0; index < 52; ++index)
	{
		// Choosing random card from the deck
		int swapIndex = getRandomNumber(0, 51);
		// Swapping places with current card
		swapCard(m_deck[index], m_deck[swapIndex]);
	}

	m_cardIndex = 0; // Starting new deal 
}

const Card& Deck::dealCard()
{
	assert(m_cardIndex < 52);
	return m_deck[m_cardIndex++];
}