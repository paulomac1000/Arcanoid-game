#pragma once

#include "main.h"

extern Audio audio;

struct Tekstury
{
	sf::Texture NowaGra;
	sf::Sprite NowaGraSprajt;

	sf::Texture Top10;
	sf::Sprite Top10Sprajt;

	sf::Texture Ustawienia;
	sf::Sprite UstawieniaSprajt;

	sf::Texture Wyjœcie;
	sf::Sprite WyjœcieSprajt;
};

void wybór_opcji(char wybór, int &opcja, sf::RenderWindow &oknoAplikacji, Tekstury &obrazki);
void wybór_podprogramu(int wybór_opcji_w_menu, sf::RenderWindow &oknoAplikacj, Audio &audio);