#pragma once

#include "main.h"

extern Audio audio;

void zapis_do_configu(map <string, string> &config);
void odczyt_z_configu(map <string, string> &config);

class T≥o
{
	sf::Texture T≥oTekstura;
	sf::Sprite T≥oSprajt;
public:
	T≥o(sf::RenderWindow &oknoUSTAWIENIA);

	void WyúwietlT≥o(sf::RenderWindow &oknoUSTAWIENIA)
	{
		oknoUSTAWIENIA.draw(T≥oSprajt);
	}


	~T≥o(){}
};

class Obraz
{
	sf::Font tytu≥;
	sf::Font napisy;
	sf::Text OBRAZ;

	tgui::Checkbox::Ptr RadioFULLSCREEN;
	tgui::Checkbox::Ptr RadioWINDOW;

public:
	Obraz(sf::RenderWindow &oknoUSTAWIENIA, tgui::Gui &gui, map <string, string> &config);

	void WyúwietlObraz(sf::RenderWindow &oknoUSTAWIENIA)
	{
		oknoUSTAWIENIA.draw(OBRAZ);
	}

	void WciúniÍtoFULLSCREEN(map <string, string> &config);

	void WciúniÍtoWINDOW(map <string, string> &config);

	~Obraz(){}
};

class Fps
{
	sf::Font tytu≥;
	sf::Font napisy;
	sf::Text FPS;

	tgui::Checkbox::Ptr RadioWPISYWANIE;
	tgui::Checkbox::Ptr RadioSYNCHRONIZACJA;
	tgui::EditBox::Ptr EditBoxWPISYWANIE;

public:

	Fps(sf::RenderWindow &oknoUSTAWIENIA, tgui::Gui &gui, map <string, string> &config);

	void WyúwietlFps(sf::RenderWindow &oknoUSTAWIENIA)
	{
		oknoUSTAWIENIA.draw(FPS);
	}

	void WciúniÍtoWPISYWANIE(map <string, string> &config);

	void WciúniÍtoFPS(map <string, string> &config);

	void ZatwierdzonoFPS(map <string, string> &config);

	void WciúniÍtoSYNCHRONIZACJA(map <string, string> &config);


	~Fps(){}
};

class G≥Íbia
{
	sf::Font tytu≥;
	sf::Font napisy;

	sf::Text G£ BIA;

	tgui::Checkbox::Ptr Radio16BIT;
	tgui::Checkbox::Ptr Radio32BIT;

public:
	G≥Íbia(sf::RenderWindow &oknoUSTAWIENIA, tgui::Gui &gui, map <string, string> &config);

	void WyúwietlG≥Íbia(sf::RenderWindow &oknoUSTAWIENIA)
	{
		oknoUSTAWIENIA.draw(G£ BIA);
	}

	void WciúniÍto32BIT(map <string, string> &config);

	void WciúniÍto16BIT(map <string, string> &config);

	~G≥Íbia(){}
};

class DüwiÍk
{
	sf::Font tytu≥;
	sf::Font napisy;
	sf::Text DèWI K;

	tgui::Checkbox::Ptr RadioDèWI KON;
	tgui::Checkbox::Ptr RadioDèWI KOFF;

public:
	DüwiÍk(sf::RenderWindow &oknoUSTAWIENIA, tgui::Gui &gui, map <string, string> &config);

	void WyúwietlDüwiÍk(sf::RenderWindow &oknoUSTAWIENIA)
	{
		oknoUSTAWIENIA.draw(DèWI K);
	}

	void WciúniÍtoDèWI KON(map <string, string> &config);

	void WciúniÍtoDèWI KOFF(map <string, string> &config);

	~DüwiÍk(){}
};

class Nick
{
	sf::Font tytu≥;
	sf::Font napisy;
	sf::Text NICK;
	tgui::EditBox::Ptr EditBoxNICK;


public:
	Nick(sf::RenderWindow &oknoUSTAWIENIA, tgui::Gui &gui, map <string, string> &config);

	void WyúwietlNick(sf::RenderWindow &oknoUSTAWIENIA)
	{
		oknoUSTAWIENIA.draw(NICK);
	}

	void WciúniÍtoNICK(map <string, string> &config)
	{
		EditBoxNICK->enable();
	}

	void ZatwierdzonoNICK(map <string, string> &config);

	~Nick(){}
};

class Back
{
	tgui::Button::Ptr BACK;
	sf::Font napisy;

public:
	Back(sf::RenderWindow &oknoUSTAWIENIA, tgui::Gui &gui);

	~Back(){}

};