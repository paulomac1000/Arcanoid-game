#include "gra.h"

void sprawd�_ewentualnie_zapisz_w_top(int mapa, Gracz &gracz, bool wygrana = 0)
{
	//odczytujemy stan
	Osoba wynik;
	wynik.gracz = config["nick"];
	wynik.punkty = gracz.punkty;

	if (wygrana == true)
	{
		//dodatkowa premia za zachowane �ycia
		wynik.punkty += gracz.�ycia * 1000;
	}

	string lokalizacja;

	switch (mapa)
	{
	case 1:
		lokalizacja = "top/mapa_1.top";
		break;
	case 2:
		lokalizacja = "top/mapa_2.top";
		break;
	case 3:
		lokalizacja = "top/mapa_3.top";
		break;
	case 4:
		lokalizacja = "top/mapa_4.top";
		break;
	case 5:
		lokalizacja = "top/mapa_5.top";
		break;
	}

	//odczytujemy obecny top
	Osoba top[10];
	string bufor;
	ifstream plik;
	plik.open(lokalizacja, std::ifstream::in);

	if (plik.is_open())
	{

		for (int i = 0; i < 10; i++)
		{
			plik >> top[i].gracz;
			plik >> bufor;
			top[i].punkty = atoi(bufor.c_str());
		}
	}
	else
	{
		string bufor_messagebox;
		bufor_messagebox = "Nie mo�na odczyta� rekord�w z pliku ";
		bufor_messagebox += lokalizacja;
		MessageBox(NULL, bufor_messagebox.c_str(), "ERROR", NULL);
	}
	plik.close();

	//sprawdzamy, czy nowy wynik wskoczy do topu
	if (wynik.punkty > top[9].punkty)
	{
		int bufor = wynik.punkty;
		string bufor_gracz = wynik.gracz;
		for (int i = 0; i < 10; i++)
		{

			cout << "Bufor " << wynik.punkty << " gracz " << bufor_gracz << endl;
			if (top[i].punkty < bufor)
			{
				swap(top[i].punkty, bufor);
				swap(top[i].gracz, bufor_gracz);			}
		}
	}

	//teraz zapisujemy nowy top
	ofstream plik2;
	plik2.open(lokalizacja, std::ofstream::out);

	if (plik2.is_open())
	{

		for (int i = 0; i < 10; i++)
		{
			plik2 << top[i].gracz;
			plik2 << " ";
			plik2 << to_string(top[i].punkty);
			plik2 << endl;
		}


	}
	else
	{
		string bufor_messagebox;
		bufor_messagebox = "Nie mo�na zapisa� obecnego rekordu do pliku ";
		bufor_messagebox += lokalizacja;
		MessageBox(NULL, bufor_messagebox.c_str(), "ERROR", NULL);
	}

	plik2.close();
}

void Klocek::Stw�rzKlocek(int x, int y, int wytrzyma�o��, sf::RenderWindow &oknoGRA)
{
	this->x = x;
	this->y = y;
	this->wytrzyma�o�� = wytrzyma�o��;
	width = 30;
	heigth = 15;
	switch (this->wytrzyma�o��)
	{
	case 0:
		//nic
		break;
	case 1:
		if (!Model.loadFromFile("resources/klocek_zielony.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy klocek_zielony.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoGRA.close();
		}
		ModelSprajt.setTexture(Model);
		ModelSprajt.setPosition((float)this->x, (float)this->y);
		oknoGRA.draw(ModelSprajt);

		break;
	case 2:
		if (!Model.loadFromFile("resources/klocek_zolty.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy klocek_zolty.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoGRA.close();
		}
		ModelSprajt.setTexture(Model);
		ModelSprajt.setPosition((float)this->x, (float)this->y);
		oknoGRA.draw(ModelSprajt);
		break;
	case 3:
		if (!Model.loadFromFile("resources/klocek_czerwony.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy klocek_czerwony.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoGRA.close();
		}
		ModelSprajt.setTexture(Model);
		ModelSprajt.setPosition((float)this->x, (float)this->y);
		oknoGRA.draw(ModelSprajt);
		break;
	}
}
void Klocek::Wytrzyma�o��Minus(sf::RenderWindow &oknoGRA)
{
	wytrzyma�o��--;

	if (wytrzyma�o�� == 2)
	{
		if (!Model.loadFromFile("resources/klocek_zolty.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy klocek_zolty.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoGRA.close();
		}
		ModelSprajt.setTexture(Model);
		ModelSprajt.setPosition((float)this->x, (float)this->y);
	}
	else if (wytrzyma�o�� == 1)
	{
		if (!Model.loadFromFile("resources/klocek_zielony.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy klocek_zielony.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoGRA.close();
		}
		ModelSprajt.setTexture(Model);
		ModelSprajt.setPosition((float)this->x, (float)this->y);
	}
	else if (wytrzyma�o�� == 0)
	{
		ModelSprajt.setColor(sf::Color::Transparent);
	}
}

int Plansza::wybierz_level(sf::RenderWindow &oknoGRA)
{
	sf::Texture T�o;
	sf::Sprite T�oSprajt;

	/* https://tgui.eu/tutorials/v06/intro3/ */

	sf::RenderWindow oknoWYB�R(sf::VideoMode(480, 260, 32), "Arcanoid", 1); //fullscreen to 8, 1 to brak paska  u g�ry i nierozszerzalno��
	oknoGRA.setActive(false);
	oknoGRA.setVisible(false);
	oknoWYB�R.setFramerateLimit(120);

	tgui::Gui gui(oknoWYB�R);
	gui.setGlobalFont("resources/DejaVuSans.ttf");
	if (!T�o.loadFromFile("resources/t�o_wyb�r_mapy.jpg"))
	{
		MessageBox(NULL, "B��d podczas �adowania obrazu t�o.jpg. Upewnij si�, �e obraz znajduje si� w katalogu resources.", "ERROR", NULL);
		oknoGRA.close();
	}
	T�oSprajt.setTexture(T�o);
	
	tgui::ComboBox::Ptr Mapy(gui);
	Mapy->load("resources/Black.conf");
	Mapy->setBorders(4, 4, 4, 4);
	Mapy->addItem("   mapa 1");
	Mapy->addItem("   mapa 2");
	Mapy->addItem("   mapa 3");
	Mapy->addItem("   mapa 4");
	Mapy->addItem("   mapa 5");
	Mapy->setSelectedItem("   mapa 1");
	Mapy->setPosition(40, 60);
	Mapy->setSize(400, 30);

	tgui::Button::Ptr BACK(gui);
	BACK->load("resources/Black.conf");
	BACK->setPosition(40, 150);
	BACK->setText("COFNIJ");
	BACK->setSize(170, 40);
	BACK->bindCallback(tgui::Button::LeftMouseClicked);
	BACK->setCallbackId(0);

	tgui::Button::Ptr OK(gui);
	OK->load("resources/Black.conf");
	OK->setPosition(270, 150);
	OK->setText("OK");
	OK->setSize(170, 40);
	OK->bindCallback(tgui::Button::LeftMouseClicked);
	OK->setCallbackId(1);

	
	while (oknoWYB�R.isOpen())
	{
		sf::Event event;
		while (oknoWYB�R.pollEvent(event))
		{
			//Wci�ni�cie ESC lub przycisk X
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed &&
				event.key.code == sf::Keyboard::Escape)  )
			{
				oknoGRA.close();
				oknoWYB�R.close();
			}
			
			gui.handleEvent(event);
		}

		tgui::Callback callback;
		while (gui.pollCallback(callback))
		{
			if (callback.id == 0)
			{
				oknoGRA.close();
				oknoWYB�R.close();
			}
			else if (callback.id == 1)
			{
				oknoGRA.setActive(true);
				oknoGRA.setVisible(true);
				oknoWYB�R.close();

				switch (Mapy->getSelectedItemIndex()+1)
				{
				case 1:
					return 1;
					break;
				case 2:
					return 2;
					break;
				case 3:
					return 3;
					break;
				case 4:
					return 4;
					break;
				case 5:
					return 5;
					break;
				}
			}
		}

		oknoWYB�R.clear();

		oknoWYB�R.draw(T�oSprajt);

		gui.draw();
		
		oknoWYB�R.display();
	}

	return 0;
}
void Plansza::wczytaj_level(char *nazwa_pliku, sf::RenderWindow &oknoGRA)
{
	fstream plik;
	plik.open(nazwa_pliku, std::ios::in);

	if (plik.is_open())
	{
		int bufor;

		while (!plik.eof())
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 12; j++)
				{
					plik >> bufor;
					klocek[i][j].Stw�rzKlocek(j * 64 + 15, i * 32 + 15, bufor, oknoGRA);
				}
			}
		}
		plik.close();
	}
	else
	{
		MessageBox(NULL, "B��d podczas �adowania mapy. Upewnij si�, �e mapa znajduje si� w katalogu z gr�.", "ERROR", NULL);
		oknoGRA.close();
	}
}
Plansza::Plansza(sf::RenderWindow &oknoGRA)
{
	wyb�r = wybierz_level(oknoGRA);

	switch (wyb�r)
	{
	case 1:
		wczytaj_level("maps/map_1.map", oknoGRA);
		break;
	case 2:
		wczytaj_level("maps/map_2.map", oknoGRA);
		break;
	case 3:
		wczytaj_level("maps/map_3.map", oknoGRA);
		break;
	case 4:
		wczytaj_level("maps/map_4.map", oknoGRA);
		break;
	case 5:
		wczytaj_level("maps/map_5.map", oknoGRA);
		break;

	default:
		oknoGRA.close();
	}

}
void Plansza::Wy�wietlPlansz�(sf::RenderWindow &oknoGRA, Gracz &gracz)
{
	bool BrakKlock�w = true;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (klocek[i][j].GetWytrzyma�o��() != 0)
			{
				klocek[i][j].Wy�wietlKlocek(oknoGRA);
				BrakKlock�w = false;
			}
		}
	}
	if (BrakKlock�w == true)
	{
		oknoGRA.close();
		audio.PlayWygrana();
		string bufor = "Wygra�e�! Uzyska�e� ";
		bufor += to_string(gracz.punkty);
		bufor += " punkt�w\nDodatkowo uzyska�e� ";
		bufor += to_string(gracz.�ycia * 1000);
		bufor += " punkt�w za zachowane �ycia";
		MessageBox(NULL, bufor.c_str(), "Koniec gry", NULL);
		sprawd�_ewentualnie_zapisz_w_top(wyb�r, gracz, true);
	}
}
int Plansza::CzyKolizja(float x, float y, sf::RenderWindow &oknoGRA)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (klocek[i][j].GetWytrzyma�o��() > 0)
			{
				sf::FloatRect sprajt = klocek[i][j].GetSprajt().getGlobalBounds();

				sf::Vector2f G�raPi�ki = { x + 11, y };
				sf::Vector2f PrawoPi�ki = { x + 22, y + 11 };
				sf::Vector2f D�Pi�ki = { x + 11, y + 22 };
				sf::Vector2f LewoPi�ki = { x, y + 11 };

				if (sprajt.contains(G�raPi�ki))
				{
					klocek[i][j].Wytrzyma�o��Minus(oknoGRA);
					return 3;
				}
				else if (sprajt.contains(PrawoPi�ki))
				{
					klocek[i][j].Wytrzyma�o��Minus(oknoGRA);
					return 4;
				}
				else if (sprajt.contains(D�Pi�ki))
				{
					klocek[i][j].Wytrzyma�o��Minus(oknoGRA);
					return 1;
				}
				else if (sprajt.contains(LewoPi�ki))
				{
					klocek[i][j].Wytrzyma�o��Minus(oknoGRA);
					return 2;
				}
			}
		}
	}
	return 0; //brak kolizji
}

Paletka::Paletka(sf::RenderWindow &oknoGRA)
{
	if (!PaletkaObiekt.loadFromFile("resources/paletka.bmp"))
	{
		MessageBox(NULL, "B��d podczas �adowania bitmapy paletka.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu z gr�.", "ERROR", NULL);
		oknoGRA.close();
	}
	PaletkaObiektSprajt.setTexture(PaletkaObiekt);
	PaletkaObiektSprajt.setPosition(x, y);
}
void Paletka::prawo(sf::RenderWindow &oknoGRA)
{
	if (x < 800 - 16 - d�ugo�� - grubo��_ramki)
	{
		x += pr�dko��;
	}
	else
	{
		x = 800 - pr�dko�� - d�ugo�� - grubo��_ramki;
	}
}
void Paletka::lewo(sf::RenderWindow &oknoGRA)
{
	if (x > 16 + grubo��_ramki)
	{
		x -= pr�dko��;
	}
	else
	{
		x = 16;
	}
}


Pi�ka::Pi�ka(sf::RenderWindow &oknoGRA)
{
	if (!Pi�kaObiekt.loadFromFile("resources/pi�ka.bmp"))
	{
		MessageBox(NULL, "B��d podczas �adowania bitmapy pi�ka.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
		oknoGRA.close();
	}
	Pi�kaObiektSprajt.setTexture(Pi�kaObiekt);
	Pi�kaObiektSprajt.setPosition(x, y);
}
void Pi�ka::ruch(Paletka &paletka, Plansza &plansza, Gracz &gracz, sf::RenderWindow &oknoGRA)
{
	if (czy_w_ruchu == false)
	{
		this->y = paletka.getY() - 24;
		this->x = paletka.getX() + 90 - 11;
	}
	else
	{
		pi�ka_ruch();

		//kolizja z klockami
		/*
                         bok 1
				  IIIIIIIIIIIIIIIIIII
				  IIIIIIIIIIIIIIIIIII
          bok 4   IIIIIIIIIIIIIIIIIII   bok 2
				  IIIIIIIIIIIIIIIIIII
				  IIIIIIIIIIIIIIIIIII
                         bok 3

				  0 = brak kolizji

				  */

		int bok = plansza.CzyKolizja(x, y, oknoGRA);

		//dzwi�k na uderzenie paletki w ifie poni�ej
		if (bok >= 1 && bok <= 4)
		{
			audio.PlayKlocek();
		}

		switch (bok)
		{
		case 1:
			pr�dko��_y = -pr�dko��_y;
			gracz.punkty += 150;
			break;
		case 2:
			pr�dko��_x = -pr�dko��_x;
			gracz.punkty += 200;
			break;
		case 3:
			pr�dko��_y = -pr�dko��_y;
			gracz.punkty += 100;
			break;
		case 4:
			pr�dko��_x = -pr�dko��_x;
			gracz.punkty += 200;
			break;
		}

		//kolizja z �ciankami
		if (x < 16)
		{
			audio.Play�ciana();
			x = 16;
			pr�dko��_x = -pr�dko��_x;
		}
		else if (x > 784 - 16 - 11)
		{
			audio.Play�ciana();
			x = 784 - 16 - 11;
			pr�dko��_x = -pr�dko��_x;
		}
		else if (y < 16)
		{
			audio.Play�ciana();
			y = 16;
			pr�dko��_y = -pr�dko��_y;
		}


		//kolizja z paletk�
		else if (y > 416 && x >= paletka.getX() && x <= paletka.getX() + paletka.GetD�ugo��())
		{
			audio.PlayPaletka();
			//sprawdzamy czy odbicie ma by� w lewo czy w prawo
			float XNaPaletce = x - paletka.getX();

			if (XNaPaletce < paletka.GetD�ugo��() / 2)
			{
				//obicie w lewo
				pr�dko��_x = (float)-((paletka.GetD�ugo��() / 2) - XNaPaletce) * 0.05 * pr�dko��;
				pr�dko��_y = (float)-(5 - abs(pr�dko��_x / pr�dko��)) * pr�dko��;
			}
			else
			{
				//odbicie w prawo
				(float)pr�dko��_x = -((paletka.GetD�ugo��() / 2) - XNaPaletce) * 0.05  * pr�dko��;
				(float)pr�dko��_y = -(5 - abs(pr�dko��_x / pr�dko��)) * pr�dko��;
			}
		}


		//nieodbicie pi�eczki
		else if (y > 456 - 11 - 5)
		{
			audio.PlayStrata();
			gracz.�ycia -= 1;
			if (gracz.�ycia == 0)
			{
				oknoGRA.close();
				string bufor = "Przegra�e�! Uzyska�e� ";
				bufor += to_string(gracz.punkty);
				bufor += " punkty(�w)";
				MessageBox(NULL, bufor.c_str(), "Koniec gry", NULL);
				sprawd�_ewentualnie_zapisz_w_top(plansza.GetWybranaMapa(), gracz);
			}
			czy_w_ruchu = false;
			this->x = paletka.getX() + 90;
			this->y = paletka.getY() - 24;
			pr�dko��_x = 3 * pr�dko��;
			pr�dko��_y = -(5 - abs(pr�dko��_x / pr�dko��)) * pr�dko��;
		}
	}
}

class Engine //animacje i kolizje
{
private:
	//czcionka:
	sf::Font font;
	//t�o:
	sf::Texture T�o;
	sf::Sprite T�oSprajt;
	sf::RectangleShape ramka;
	//sta�y tekst:
	sf::Text nazwa_gracza;
	sf::Text �ycia_tekst;
	sf::Text punkty_tekst;
	sf::Text czas_tekst;
	sf::Text nazwa_gracza_tekst;

	//zegary:
	sf::Clock czas_pi�ka;
	sf::Clock czas_paletka;
	sf::Clock czas_gry;

	
	Gracz gracz;

	int kt�ra_mapa = 1;

	void ustaw_t�o(sf::RenderWindow &oknoGRA) //ustawia t�o i otoczk� t�a
	{
		ramka.setSize({ 768, 456 });
		ramka.setOutlineColor(sf::Color::Red);
		ramka.setOutlineThickness(5.0);
		ramka.setPosition({ 16, 16 });

		int random_t�o = rand() % 4;
		switch (random_t�o)
		{
		case 0:
			if (!T�o.loadFromFile("resources/t�o_0.bmp"))
			{
				MessageBox(NULL, "B��d podczas �adowania bitmapy t�o_0.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
				oknoGRA.close();
			}
			break;
		case 1:
			if (!T�o.loadFromFile("resources/t�o_1.bmp"))
			{
				MessageBox(NULL, "B��d podczas �adowania bitmapy t�o_1.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
				oknoGRA.close();
			}
			break;
		case 2:
			if (!T�o.loadFromFile("resources/t�o_2.bmp"))
			{
				MessageBox(NULL, "B��d podczas �adowania bitmapy t�o_2.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
				oknoGRA.close();
			}
			break;
		case 3:
			if (!T�o.loadFromFile("resources/t�o_3.bmp"))
			{
				MessageBox(NULL, "B��d podczas �adowania bitmapy t�o_3.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
				oknoGRA.close();
			}
			break;
		}

		T�oSprajt.setTexture(T�o);
		T�oSprajt.setPosition(16, 16);
	}

	void wy�wietl_t�o(sf::RenderWindow &oknoGRA)
	{
		oknoGRA.draw(ramka);
		oknoGRA.draw(T�oSprajt);
	}

	void ustaw_sta�y_tekst(sf::RenderWindow &oknoGRA)
	{
		nazwa_gracza.setFont(font);
		�ycia_tekst.setFont(font);
		punkty_tekst.setFont(font);
		czas_tekst.setFont(font);
		nazwa_gracza_tekst.setFont(font);
		�ycia_tekst.setString(gracz.�ycia_tekst);
		punkty_tekst.setString(gracz.punkty_tekst);
		czas_tekst.setString(gracz.czas_tekst);
		nazwa_gracza_tekst.setString(gracz.nazwa_gracza_tekst);

		�ycia_tekst.setPosition({ 45, 500 });
		punkty_tekst.setPosition({ 245, 500 });
		czas_tekst.setPosition({ 445, 500 });
		nazwa_gracza_tekst.setPosition({ 660, 500 });
		nazwa_gracza.setString(gracz.nazwa_gracza);
		nazwa_gracza.setPosition({ 660, 540 });
	}

	void wy�wietl_sta�y_tekst(sf::RenderWindow &oknoGRA)
	{
		oknoGRA.draw(�ycia_tekst);
		oknoGRA.draw(punkty_tekst);
		oknoGRA.draw(czas_tekst);
		oknoGRA.draw(nazwa_gracza);
		oknoGRA.draw(nazwa_gracza_tekst);
	}

	void ustaw_wy�wietl_dynamiczny_tekst(sf::RenderWindow &oknoGRA)
	{
		sf::Text �ycia;
		sf::Text punkty;
		sf::Text czas;

		�ycia.setFont(font);
		punkty.setFont(font);
		czas.setFont(font);

		char bufor[10];
		_itoa_s(gracz.�ycia, bufor, 10);
		�ycia.setString(bufor);
		�ycia.setPosition({ 65, 540 });

		_itoa_s(gracz.punkty, bufor, 10);
		punkty.setString(bufor);
		punkty.setPosition({ 285, 540 });

		_itoa_s(gracz.minuty, bufor, 10);
		string po��czone = bufor;
		po��czone += ":";
		_itoa_s(gracz.sekundy, bufor, 10);
		if (gracz.sekundy < 10)
		{
			po��czone += '0';
		}
		po��czone += bufor;
		czas.setString(po��czone);
		czas.setPosition({ 445, 540 });
		
		oknoGRA.draw(�ycia);
		oknoGRA.draw(punkty);
		oknoGRA.draw(czas);
	}

public:
	~Engine(){}

	Engine(sf::RenderWindow &oknoGRA)
	{
		if (!font.loadFromFile("resources/antibiotech.ttf"))
		{
			MessageBox(NULL, "B��d podczas �adowania czcionki antibiotech.ttf. Upewnij si�, �e czcionka znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoGRA.close();
		}
	}

	void runEngine(sf::RenderWindow &oknoGRA)
	{
		Paletka paletka(oknoGRA);
		Pi�ka pi�ka(oknoGRA);
		Plansza plansza(oknoGRA);

		ustaw_t�o(oknoGRA);
		ustaw_sta�y_tekst(oknoGRA);

		oknoGRA.display();

		while (oknoGRA.isOpen())
		{
			sf::Event event;
			sf::Vector2i mysz(sf::Mouse::getPosition(oknoGRA));

			while (oknoGRA.pollEvent(event))
			{	
				switch (event.type)
				{	
/* [X] */		case sf::Event::Closed: // klikni�cie przycisku [X]
					oknoGRA.close();
					break;

/*MYSZ LEWY*/	case(sf::Event::MouseButtonPressed) :
					pi�ka.pi�ka_start();
					break;

				case (sf::Event::KeyPressed):
/*P*/				if (event.key.code == sf::Keyboard::P)
					{
						MessageBox(NULL, "PAUZA", "", NULL);						
					}
/*ESCAPE*/			else if (event.key.code == sf::Keyboard::Escape)
					{
						oknoGRA.close();
					}
/*ENTER*/			else if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space)
					{
						pi�ka.pi�ka_start();
					}

					break;
				}
			}


			if (czas_pi�ka.getElapsedTime() > sf::milliseconds(16))
			{
				pi�ka.ruch(paletka, plansza, gracz, oknoGRA);

				czas_pi�ka.restart();
			}
			
			if (czas_paletka.getElapsedTime() > sf::milliseconds(8))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					paletka.lewo(oknoGRA);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					paletka.prawo(oknoGRA);
				}
				czas_paletka.restart();
			}

			if (czas_gry.getElapsedTime() > sf::seconds(1))
			{
				gracz.sekundy++;

				if (gracz.sekundy > 59)
				{
					gracz.sekundy = gracz.sekundy - 60;
					gracz.minuty++;
				}

				czas_gry.restart();
			}

			oknoGRA.clear();

			wy�wietl_t�o(oknoGRA);
			wy�wietl_sta�y_tekst(oknoGRA);
			ustaw_wy�wietl_dynamiczny_tekst(oknoGRA);
			
			
			plansza.Wy�wietlPlansz�(oknoGRA, gracz);
			paletka.rysowanie(oknoGRA);
			pi�ka.rysowanie(oknoGRA);

			oknoGRA.display();
		}
	}
};

string ustaw_nick()
{

	string nick = config["nick"];
	return nick;
}

int sprawd�_tryb_ekranu()
{
	int TRYBekranu;
	if (config["obraz"] == "fullscreen")
	{
		TRYBekranu = 8;
	}
	else
	{
		TRYBekranu = 1;
	}
	return TRYBekranu;
}

void ustaw_parametry(sf::RenderWindow &OKNO)
{
	int FPSlimit = atoi(config["fps"].c_str());
	if (FPSlimit > 0)
	{
		OKNO.setFramerateLimit(FPSlimit);
	}
	else
	{
		OKNO.setVerticalSyncEnabled(1);
	}
}

void gra()
{
	odczyt_z_configu(config);
	sf::RenderWindow OKNOgra(sf::VideoMode(800, 600, 32), "Arcanoid", sprawd�_tryb_ekranu());
	ustaw_parametry(OKNOgra);

	Engine engine(OKNOgra);
	engine.runEngine(OKNOgra);
}