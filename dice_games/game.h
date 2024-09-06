#pragma once
#include "graphics.h"


class Game
{
private:

	bool sfml_enable_ = false;

	sf::RenderWindow window_;
	Graphics graphics_;

	int player_choice_number_ = 0;
	int player_choice_bet_ = 0;
	char player_choice_replay_ = 'O';

	int choice_player_ = 0;
	int choice_bet_ = 0;
	int result_ = 0;

	int player_bankroll_ = 1000;
	int bet_ = 0;

	bool replay_ = true;


	void ChoiceNumber(); //Ask the player number
	void ChoiceBet(); //Ask the player bet
	void SaveChoice(); //Save choice player
	void DieRoll(); //Flip the coin
	void ComparePlayerChoice(); //Compare with player choice
	void ReplayOrNot();//Ask the player if they should play again

protected:
public:
	Game();

	void gameloop();
};

