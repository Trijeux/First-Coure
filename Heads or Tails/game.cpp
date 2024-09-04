#include "game.h"

#include <iostream>
#include <random>
#include <thread>


Game::Game()
{
	std::cout << "Welcome to the coin toss game" << std::endl;

	std::cout << std::endl;
}

void Game::gameloop()
{
	do
	{
		ChoiceNumber();

		SaveChoice();

		DieRoll();

		ComparePlayerChoice();

		ReplayOrNot();

	} while (replay_);
}

void Game::ChoiceNumber()
{
	bool valid_player_choice = false;

	//Ask the player heads or tails
	do
	{
		std::cout << "Choose heads [H/h] or tails [T/t] : ";
		std::cin >> player_choice_heads_or_tails_;

		system("cls");

		//Check if player input is valid
		if (player_choice_heads_or_tails_ == 'H' || player_choice_heads_or_tails_ == 'h' || player_choice_heads_or_tails_ == 'T' || player_choice_heads_or_tails_ == 't')
		{
			valid_player_choice = true;
		}
		else
		{
			std::cout << "Between invalid" << std::endl;
			std::cout << std::endl;
		}


	} while (!valid_player_choice);
}

void Game::SaveChoice()
{
	//Save Choice player
	if (player_choice_heads_or_tails_ == 'H' || player_choice_heads_or_tails_ == 'h')
	{
		choice_player_ = true;
	}

	if (choice_player_)
	{
		std::cout << "You play Heads" << std::endl;
	}
	else
	{
		std::cout << "You play Tails" << std::endl;
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Game::DieRoll()
{
	bool good_rand = false;

	//Flip the coin
	do
	{
		std::random_device rand;
		std::uniform_int_distribution<int> nb_rand{ 0,  1 };

		const int result = nb_rand(rand);

		if (result == 1)
		{
			result_ = true;
			good_rand = true;
		}
		else if(result == 0)
		{
			result_ = false;
			good_rand = true;
		}
		else
		{
			good_rand = false;
		}
	}
	while (!good_rand);
}

void Game::ComparePlayerChoice() const
{
	//Compare with player choice
	if (result_ == choice_player_)
	{
		std::cout << "You win !" << std::endl;
	}
	else
	{
		std::cout << "You lost !" << std::endl;
	}

	std::cout << std::endl;
}

void Game::ReplayOrNot()
{
	bool valid_replay_choice = false;

	//Ask the player if they should play again
	do
	{
		std::cout << "Do you want to play again Yes [Y/y] or No [N/n] : ";
		std::cin >> player_choice_replay_;
		system("cls");
		if (player_choice_replay_ == 'Y' || player_choice_replay_ == 'y' || player_choice_replay_ == 'N' || player_choice_replay_ == 'n')
		{
			valid_replay_choice = true;
		}
		else
		{
			std::cout << "Between invalid" << std::endl;
			std::cout << std::endl;
		}
	} while (!valid_replay_choice);

	if (player_choice_replay_ == 'N' || player_choice_replay_ == 'n')
	{
		replay_ = false;
	}
}
