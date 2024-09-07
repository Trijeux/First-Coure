#pragma once

#include <SFML/Graphics.hpp>

#include "ui_button.h"

class Graphics
{
private:
	sf::Sprite dice_sprite_;
	sf::Texture dice_one_texture_;
	sf::Texture dice_tow_texture_;
	sf::Texture dice_three_texture_;
	sf::Texture dice_four_texture_;
	sf::Texture dice_five_texture_;
	sf::Texture dice_six_texture_;

	UiButton btn_one_;
	UiButton btn_tow_;
	UiButton btn_three_;
	UiButton btn_four_;
	UiButton btn_five_;
	UiButton btn_six_;

	UiButton btn_bet_one_;
	UiButton btn_bet_tow_;
	UiButton btn_bet_three_;
	UiButton btn_bet_four_;
	UiButton btn_bet_five_;
	UiButton btn_bet_six_;

	UiButton btn_yes_;
	UiButton btn_no_;

	sf::Text text_choice_;
	sf::Text text_bankroll_;
	sf::Font font_;

	sf::Text text_win_or_lose_;
	sf::Text text_result_bet_;

	bool is_choice_ = true;
	bool is_bet_ = false;

protected:
public:
	Graphics();

	int number_choice_ = 0;
	int bet_choice_ = 0;

	void CreateButton(sf::RenderWindow&);

	void update_bankroll(sf::RenderWindow&, int);

	int HandleEventChoiceNumber(const sf::Event& event);

	int HandleEventChoiceBet(const sf::Event& event);

	void ChangeTextChoice(sf::RenderWindow&);

	void ChoiceNumber();

	void LoadImageDice(int, sf::RenderWindow&);

	void Draw(sf::RenderWindow&);
};

