#pragma once

#include "main.h"

extern Audio audio;

struct Osoba
{
	string gracz;
	int punkty;
};

Osoba* odczytaj_top_z_pliku(string lokalizacja);

class Okno
{
	tgui::RadioButton::Ptr Mapa1;
	tgui::RadioButton::Ptr Mapa2;
	tgui::RadioButton::Ptr Mapa3;
	tgui::RadioButton::Ptr Mapa4;
	tgui::RadioButton::Ptr Mapa5;
	sf::Font napisy;
	tgui::Button::Ptr BACK;
	sf::Text ZawartoœæTop;

public:
	Okno(sf::RenderWindow &oknoTOP10, tgui::Gui &gui);

	void wybierz_mapê(int numer);
	void wybrana_mapa();

	void WyœwietlTop(sf::RenderWindow &oknoTOP10)
	{
		oknoTOP10.draw(ZawartoœæTop);
	}

	~Okno(){}
};