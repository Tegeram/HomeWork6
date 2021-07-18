//=====Home Work 6, Exercise 3======================================================================

class Player : public GenericPlayer {
public:
	Player(string name) : GenericPlayer(name){}
	~Player(){}
	bool IsHitting() const {
		cout << " " << Name << ", do you want a hit? (Yes/No): ";
		char response;
		cin >> response;
		return (response == 'Y' || response == 'y' || response == 'yes' || response == 'Yes');
	}

	void Win() const {
		cout << " " << Name << " - win!" << endl;
	}

	void Lose() const {
		cout << " " << Name << " - lose!" << endl;
	}

	void Push() const {
		cout << " " << Name << " - played in draw!" << endl;
	}
};

//=====Home Work 6, Exercise 4======================================================================

class House : public GenericPlayer {
public:
	House(string name = "House") : GenericPlayer(name){}
    ~House(){}
	bool IsHitting() const {
		return (GetValue() <= 16);
	}

	void FlipFirstCard() {
		if (!(HandCards.empty())) HandCards[0]->Flip();
		else cout << "No card to flip!" << endl;
	}
};

//=====Home Work 6, Exercise 5======================================================================

ostream& operator<< (ostream & os, const Card & c) {
	const string Rank[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
	const string Suit[] = { "c", "d", "h", "s" };
	if (c.m_IsFaceUp) os << Rank[c.m_Rank] << Suit[c.m_Suit];
	else os << "XX";

	return os;
}


ostream& operator<<(ostream& os, const GenericPlayer& gp) {
	os << gp.Name << ":\t";

	vector<Card*>::const_iterator c;
	if (!gp.HandCards.empty()) {
		for (c = gp.HandCards.begin(); c != gp.HandCards.end(); ++c) {
			os << *(*c);
		}
		if (gp.GetValue() != 0) cout << gp.GetValue() << " points";
	}
	else os << "empty";

	return os;
}