#include "game.h"

#include <iostream>
#include <random>
#include <thread>

Game::Game()
{
	std::cout << "Welcome to the dice game" << std::endl << std::endl;

	window_.create(sf::VideoMode(450, 700), "Dice Game");

	graphics_.CreateButton(window_);
}

void Game::gameloop()
{
	while (window_.isOpen())
	{
		do
		{
			sf::Event event;
			while (window_.pollEvent(event))
			{
				if (ChoiceNumber(event) && !choice_number_lock_)
				{
					choice_number_lock_ = true;
				}

				DieRoll();

				if (event.type == sf::Event::Closed)
				{
					window_.close();
					replay_ = false;
				}
			}

			window_.clear(sf::Color::Blue);

			graphics_.ChangeTextChoice(window_);

			graphics_.update_bankroll(window_, player_bankroll_);

			graphics_.Draw(window_);

			window_.display();

			//ChoiceNumber();

			//ChoiceBet();

			//DieRoll();

			//ComparePlayerChoice();

			//if (player_bankroll_ <= 0)
			//{
			//	ReplayOrNot();
			//}

		} while (replay_);
	}
}

void Game::ChoiceNumber()
{
	bool valid_player_choice_number = false;

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
			std::cout << "Between invalid" << std::endl << std::endl;
		}
		else
		{
			int checker_number = 1;
			bool valid_number = false;
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
					std::cout << "Between invalid" << std::endl << std::endl;
				}
				checker_number++;
			} while (!valid_number);
		}

	} while (!valid_player_choice_number);
}

bool Game::ChoiceNumber(sf::Event event)
{
	//Ask the player number
	int choice_test = 0;

	choice_test = graphics_.HandleEventChoiceNumber(event);

	int checker_number = 1;
	bool valid_number = false;
	if (choice_test > 0)
	{
		do
		{
			if (choice_test == checker_number)
			{
				valid_number = true;
				choice_number_ = choice_test;
				return true;
			}
			else if (checker_number >= 6)
			{
				valid_number = true;
			}
			checker_number++;
		} while (!valid_number);
	}
	return false;
}

void Game::ChoiceBet()
{
	bool valid_player_choice_bet = false;

	//Ask the player bet
	do
	{
		std::cout << "if you win you double the bet and if you lose you lose the bet" << std::endl << std::endl;

		std::cout << "Your bankroll : " << player_bankroll_ << "$" << std::endl;
		std::cout << "Choose a number between 10$(1), 50$(2), 100$(3), 250$(4), 500$(5) or 1000$(6) : ";
		std::cin >> player_choice_bet_;

		system("cls");

		//Check if player input is valid
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Between invalid" << std::endl << std::endl;
		}
		else
		{
			int checker_bet = 1;
			bool valid_bet = false;
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
					std::cout << "Between invalid" << std::endl << std::endl;
				}
				checker_bet++;
			} while (!valid_bet);
		}

	} while (!valid_player_choice_bet);

	SaveChoice();
}

void Game::SaveChoice()
{
	//Save Choice player
	choice_number_ = player_choice_number_;
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


	if (bet_ <= player_bankroll_)
	{
		std::cout << "You play " << choice_number_ << std::endl;
		std::cout << "You bet " << bet_ << "$" << std::endl;
	}
	else
	{
		std::cout << "you can't bet what you don't have!!!" << std::endl << std::endl;
		ChoiceBet();
	}


	//std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Game::DieRoll()
{
	bool good_rand;

	//Roll Die
	do
	{
		result_ = 0;

		std::random_device rand;
		std::uniform_int_distribution<int> nb_rand{ 1,  6 };

		result_ = nb_rand(rand);

		if (result_ <= 0 || result_ > 6)
		{
			good_rand = false;
		}
		else
		{
			good_rand = true;
		}

	} while (!good_rand);

	graphics_.LoadImageDice(result_, window_);
}

void Game::ComparePlayerChoice()
{
	std::cout << std::endl;

	//Compare with player choice
	if (result_ == choice_number_)
	{
		std::cout << "The result is " << result_ << std::endl;
		std::cout << "You win : " << bet_ * 2 << "$" << std::endl << std::endl;
		player_bankroll_ += bet_ * 2;
		std::cout << "You bankroll : " << player_bankroll_ << "$";
	}
	else
	{
		std::cout << "The result is " << result_ << std::endl;
		std::cout << "You lost : " << bet_ << "$" << std::endl << std::endl;
		player_bankroll_ -= bet_;
		std::cout << "You bankroll : " << player_bankroll_ << "$";
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
			std::cout << "Between invalid" << std::endl << std::endl;
		}
	} while (!valid_replay_choice);

	if (player_choice_replay_ == 'N' || player_choice_replay_ == 'n')
	{
		replay_ = false;
		window_.close();
	}

	player_bankroll_ = 1000;
}
