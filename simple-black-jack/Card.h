#pragma once

class Card
{
public:
	// Wasn't able to encapsulate enums (oops)
	enum CardSuit
	{
		SUIT_CLUB,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_SPADE,
		MAX_SUITS
	};

	enum CardRank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANKS
	};

	Card(CardRank rank = MAX_RANKS, CardSuit suit = MAX_SUITS);

	void printCard() const;

	int getCardValue() const;

private:
	CardRank m_rank;
	CardSuit m_suit;

};