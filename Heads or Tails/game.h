#pragma once

class Game
{
private:
	bool replay_ = true;
	bool choice_player_ = false;
	bool result_ = false;

	char player_choice_heads_or_tails_ = 'N';
	char player_choice_replay_ = 'N';
	
protected:
public:
	Game();

	void gameloop();

	void ChoiceNumber(); //Ask the player heads or tails
	void SaveChoice(); //Save Choice player
	void DieRoll(); //Flip the coin
	void ComparePlayerChoice() const; //Compare with player choice
	void ReplayOrNot();//Ask the player if they should play again

	
};

