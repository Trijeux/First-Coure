#include <iostream>
#include <random>

int main()
{
	bool replay = true;
	do
	{
		std::cout << "Welcome to the coin toss game" << std::endl;

		std::cout << std::endl;

		//Ask the player heads or tails
		char player_choice_heads_or_tails = NULL;
		bool valid_player_choice = false;
		do
		{
			std::cout << "Choose heads [H/h] or tails [T/t] : ";
			std::cin >> player_choice_heads_or_tails;
			system("cls");
			if (player_choice_heads_or_tails == 'H' || player_choice_heads_or_tails == 'h' || player_choice_heads_or_tails == 'T' || player_choice_heads_or_tails == 't')
			{
				valid_player_choice = true;
			}
			else
			{
				std::cout << "Between invalid" << std::endl;
				std::cout << std::endl;
			}
		}
		while (!valid_player_choice);


		//Save Choice player
		bool choice_player = false;
		if(player_choice_heads_or_tails == 'H' || player_choice_heads_or_tails == 'h')
		{
			choice_player = true;
		}
	

		//Flip the coin
		bool result = false;
		std::random_device rand;
		std::default_random_engine e2(rand());
		std::poisson_distribution<> nb_rand(1);

		if (nb_rand(e2) <= 1)
		{
			result = true;
		}

		//Compare with player choice
		if (result == choice_player)
		{
			std::cout << "You win !" << std::endl;
		}
		else
		{
			std::cout << "You lost !" << std::endl;
		}

		std::cout << std::endl;

		//Ask the player if they should play again
		char player_choice_replay = NULL;
		bool valid_replay_choice = false;

		do
		{
			std::cout << "Do you want to play again Yes [Y/y] or No [N/n] : ";
			std::cin >> player_choice_replay;
			system("cls");
			if (player_choice_replay == 'Y' || player_choice_replay == 'y' || player_choice_replay == 'N' || player_choice_replay == 'n')
			{
				valid_replay_choice = true;
			}
			else
			{
				std::cout << "Between invalid" << std::endl;
				std::cout << std::endl;
			}
		}
		while (!valid_replay_choice);

		if (player_choice_replay == 'N' || player_choice_replay == 'n')
		{
			replay = false;
		}
	}
	while (replay);
}
