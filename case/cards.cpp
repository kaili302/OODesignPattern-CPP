#include <ctime>
#include <cstdlib>

enum class Suit{
	Spade = 1,
	Heart,
	Club, 
	Diamond
};

class Card{
public:
	int m_faceValue; // 1 2 3 .. 10 11 12 13
	Suit m_suit;
	Card(int faceValue, Suit suit) : m_faceValue{faceValue}, m_suit{suit}{}
	virtual int value() = 0;
};

class Hand{
protected:
	vector<Card*> cards;
public:
	virtual void addCard(Card* pCard) = 0;
	virtual int score() = 0;
};


class BlackJackCard: public Card{
public:
	BlackJackCard(int faceValue, Suit suit) : Card{faceValue, suit}{}

	virtual int value(){
		/*
		if (m_faceValue >= 10)
			return 10;*/
		return m_faceValue;
	}
	bool isAce(){
		return m_faceValue == 1;
	}
};

class BlackJackHand: public Hand{
public:
	virtual void addCard(Card* pCard) {
		cards.push_back(pCard);
	}
	virtual int score(){
		int score = 0;
		for (auto& pCard : cards){
			if (dynamic_cast<BlackJackCard*>(pCard)->isAce()){
				score += 11;
			}else{
				score += pCard->value();
			}
		}
		return score;
	}
};



class Deck{
private:
	vector<Card*> cards;
	int idx = 0;
public:
	void init(string cardType){
		if (cardType == "blackjack"){
			for (int i = 1; i <= 13; i++){
				for (int suit = 1; suit <= 4; suit++){
					cards.push_back(new BlackJackCard{i, static_cast<Suit>(suit)});
				}
			}
		}
	}
	void shuffle(){
		srand(time(0));
		for (int i = 0; i < cards.size(); i++){
			int j = rand() % (i + 1);
			swap(cards[i], cards[j]);
		}
	}
	Card* dealCard(){
		if (idx == cards.size())
			return nullptr;
		return cards[idx++];
	}
};