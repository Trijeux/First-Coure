#include "game.h"

#include <iostream>
#include <random>
#include <thread>


Game::Game()
{
	std::cout << "Welcome to the dice game" << std::endl;

	std::cout << std::endl;
}

void Game::gameloop()
{
	do
	{
		ChoiceNumber();

		ChoiceBet();

		SaveChoice();

		DieRoll();

		ComparePlayerChoice();

		if (player_bankroll_ <= 0)
		{
			ReplayOrNot();
		}

	} while (replay_);
}

void Game::ChoiceNumber()
{
	bool valid_player_choice_number = false;
	bool valid_number = false;

	//Ask the player number
	do
	{
		std::cout << "Choose a number between 1 and 6 : ";
		std::cin >> player_choice_number_;

		system("cls");

		//Check if player input is valid
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Between invalid" << std::endl;
			std::cout << std::endl;
		}
		else
		{
			int checker_number = 1;
			valid_number = false;
			do
			{
				if (player_choice_number_ == checker_number)
				{
					valid_number = true;
					valid_player_choice_number = true;
				}
				else if (checker_number >= 6)
				{
					valid_number = true;
					std::cout << "Between invalid" << std::endl;
					std::cout << std::endl;
				}
				checker_number++;
			} while (!valid_number);
		}

	} while (!valid_player_choice_number);
}

void Game::ChoiceBet()
{
	bool valid_player_choice_bet = false;
	bool valid_bet = false;

	//Ask the player bet
	do
	{
		std::cout << "if you win you double the bet and if you lose you lose the bet" << std::endl;
		std::cout << std::endl;

		std::cout << "Your bankroll : " << player_bankroll_ << std::endl;
		std::cout << "Choose a number between 10(1), 50(2), 100(3), 250(4), 500(5) or 1000(6) : ";
		std::cin >> player_choice_bet_;

		system("cls");

		//Check if player input is valid
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Between invalid" << std::endl;
			std::cout << std::endl;
		}
		else
		{
			int checker_bet = 1;
			valid_bet = false;
			do
			{
				if (player_choice_bet_ == checker_bet)
				{
					valid_bet = true;
					valid_player_choice_bet = true;
				}
				else if (checker_bet >= 6)
				{
					valid_bet = true;
					std::cout << "Between invalid" << std::endl;
					std::cout << std::endl;
				}
				checker_bet++;
			} while (!valid_bet);
		}

	} while (!valid_player_choice_bet);
}

void Game::SaveChoice()
{
	//Save Choice player
	choice_player_ = player_choice_number_;
	choice_bet_ = player_choice_bet_;
	bet_ = 0;

	switch (choice_bet_)
	{
	case 1:
	{
		bet_ = 10;
	}
		break;
	case 2:
	{
		bet_ = 50;
	}
	break;
	case 3:
	{
		bet_ = 100;
	}
	break;
	case 4:
	{
		bet_ = 250;
	}
	break;
	case 5:
	{
		bet_ = 500;
	}
	break;
	case 6:
	{
		bet_ = 1000;
	}
	break;
	default:
	{
		std::cout << "Error choice bet" << std::endl;
		EXIT_FAILURE;
	}
	}

	std::cout << "You play " << choice_player_ << std::endl;
	std::cout << "You bet " << bet_ << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Game::DieRoll()
{
	bool good_rand = false;

	//Roll Die
	do
	{
		result_ = 0;

		std::random_device rand;
		std::uniform_int_distribution<int> nb_rand{ 1,  6 };

		result_ = nb_rand(rand);

		if (result_ <= 0 || result_ >= 6)
		{
			good_rand = false;
		}
		else
		{
			good_rand = true;
		}

	} while (!good_rand);
}

void Game::ComparePlayerChoice()
{
	std::cout << std::endl;

	//Compare with player choice
	if (result_ == choice_player_)
	{
		std::cout << "The result is " << result_ << std::endl;
		std::cout << "You win !" << std::endl;
		player_bankroll_ += bet_ * 2;
		std::cout << "You bankroll : " << player_bankroll_;
	}
	else
	{
		std::cout << "The result is " << result_ << std::endl;
		std::cout << "You lost !" << std::endl;
		player_bankroll_ -= bet_;
		std::cout << "You bankroll : " << player_bankroll_;
	}

	std::cout << std::endl << std::endl;
	
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

	player_bankroll_ = 1000;
}
