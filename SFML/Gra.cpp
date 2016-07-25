#include "gra.h"

void sprawdŸ_ewentualnie_zapisz_w_top(int mapa, Gracz &gracz, bool wygrana = 0)
{
	//odczytujemy stan
	Osoba wynik;
	wynik.gracz = config["nick"];
	wynik.punkty = gracz.punkty;

	if (wygrana == true)
	{
		//dodatkowa premia za zachowane ¿ycia
		wynik.punkty += gracz.¿ycia * 1000;
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
		bufor_messagebox = "Nie mo¿na odczytaæ rekordów z pliku ";
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
				swap(top[i].gracz, bufor_gracz);
			}
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
		bufor_messagebox = "Nie mo¿na zapisaæ obecnego rekordu do pliku ";
		bufor_messagebox += lokalizacja;
		MessageBox(NULL, bufor_messagebox.c_str(), "ERROR", NULL);
	}

	plik2.close();
}

void Klocek::StwórzKlocek(int x, int y, int wytrzyma³oœæ, sf::RenderWindow &oknoGRA)
{
	this->x = x;
	this->y = y;
	this->wytrzyma³oœæ = wytrzyma³oœæ;
	width = 30;
	heigth = 15;
	switch (this->wytrzyma³oœæ)
	{
	case 0:
		//nic
		break;
	case 1:
		if (!Model.loadFromFile("resources/klocek_zielony.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy klocek_zielony.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoGRA.close();
		}
		ModelSprajt.setTexture(Model);
		ModelSprajt.setPosition((float)this->x, (float)this->y);
		oknoGRA.draw(ModelSprajt);

		break;
	case 2:
		if (!Model.loadFromFile("resources/klocek_zolty.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy klocek_zolty.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoGRA.close();
		}
		ModelSprajt.setTexture(Model);
		ModelSprajt.setPosition((float)this->x, (float)this->y);
		oknoGRA.draw(ModelSprajt);
		break;
	case 3:
		if (!Model.loadFromFile("resources/klocek_czerwony.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy klocek_czerwony.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoGRA.close();
		}
		ModelSprajt.setTexture(Model);
		ModelSprajt.setPosition((float)this->x, (float)this->y);
		oknoGRA.draw(ModelSprajt);
		break;
	}
}
void Klocek::Wytrzyma³oœæMinus(sf::RenderWindow &oknoGRA)
{
	wytrzyma³oœæ--;

	if (wytrzyma³oœæ == 2)
	{
		if (!Model.loadFromFile("resources/klocek_zolty.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy klocek_zolty.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoGRA.close();
		}
		ModelSprajt.setTexture(Model);
		ModelSprajt.setPosition((float)this->x, (float)this->y);
	}
	else if (wytrzyma³oœæ == 1)
	{
		if (!Model.loadFromFile("resources/klocek_zielony.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy klocek_zielony.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoGRA.close();
		}
		ModelSprajt.setTexture(Model);
		ModelSprajt.setPosition((float)this->x, (float)this->y);
	}
	else if (wytrzyma³oœæ == 0)
	{
		ModelSprajt.setColor(sf::Color::Transparent);
	}
}

int Plansza::wybierz_level(sf::RenderWindow &oknoGRA)
{
	sf::Texture T³o;
	sf::Sprite T³oSprajt;

	/* https://tgui.eu/tutorials/v06/intro3/ */

	sf::RenderWindow oknoWYBÓR(sf::VideoMode(480, 260, 32), "Arkanoid by PABLO", 1); //fullscreen to 8, 1 to brak paska  u góry i nierozszerzalnoœæ
	oknoGRA.setActive(false);
	oknoGRA.setVisible(false);
	oknoWYBÓR.setFramerateLimit(120);

	tgui::Gui gui(oknoWYBÓR);
	gui.setGlobalFont("resources/DejaVuSans.ttf");
	if (!T³o.loadFromFile("resources/t³o_wybór_mapy.jpg"))
	{
		MessageBox(NULL, "B³¹d podczas ³adowania obrazu t³o.jpg. Upewnij siê, ¿e obraz znajduje siê w katalogu resources.", "ERROR", NULL);
		oknoGRA.close();
	}
	T³oSprajt.setTexture(T³o);
	
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

	
	while (oknoWYBÓR.isOpen())
	{
		sf::Event event;
		while (oknoWYBÓR.pollEvent(event))
		{
			//Wciœniêcie ESC lub przycisk X
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed &&
				event.key.code == sf::Keyboard::Escape)  )
			{
				oknoGRA.close();
				oknoWYBÓR.close();
			}
			
			gui.handleEvent(event);
		}

		tgui::Callback callback;
		while (gui.pollCallback(callback))
		{
			if (callback.id == 0)
			{
				oknoGRA.close();
				oknoWYBÓR.close();
			}
			else if (callback.id == 1)
			{
				oknoGRA.setActive(true);
				oknoGRA.setVisible(true);
				oknoWYBÓR.close();

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

		oknoWYBÓR.clear();

		oknoWYBÓR.draw(T³oSprajt);

		gui.draw();
		
		oknoWYBÓR.display();
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
					klocek[i][j].StwórzKlocek(j * 64 + 15, i * 32 + 15, bufor, oknoGRA);
				}
			}
		}
		plik.close();
	}
	else
	{
		MessageBox(NULL, "B³¹d podczas ³adowania mapy. Upewnij siê, ¿e mapa znajduje siê w katalogu z gr¹.", "ERROR", NULL);
		oknoGRA.close();
	}
}
Plansza::Plansza(sf::RenderWindow &oknoGRA)
{
	wybór = wybierz_level(oknoGRA);

	switch (wybór)
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
void Plansza::WyœwietlPlanszê(sf::RenderWindow &oknoGRA, Gracz &gracz)
{
	bool BrakKlocków = true;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (klocek[i][j].GetWytrzyma³oœæ() != 0)
			{
				klocek[i][j].WyœwietlKlocek(oknoGRA);
				BrakKlocków = false;
			}
		}
	}
	if (BrakKlocków == true)
	{
		oknoGRA.close();
		audio.PlayWygrana();
		string bufor = "Wygra³eœ! Uzyska³eœ ";
		bufor += to_string(gracz.punkty);
		bufor += " punktów\nDodatkowo uzyska³eœ ";
		bufor += to_string(gracz.¿ycia * 1000);
		bufor += " punktów za zachowane ¿ycia";
		MessageBox(NULL, bufor.c_str(), "Koniec gry", NULL);
		sprawdŸ_ewentualnie_zapisz_w_top(wybór, gracz, true);
	}
}
int Plansza::CzyKolizja(float x, float y, sf::RenderWindow &oknoGRA)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (klocek[i][j].GetWytrzyma³oœæ() > 0)
			{
				sf::FloatRect sprajt = klocek[i][j].GetSprajt().getGlobalBounds();

				sf::Vector2f GóraPi³ki = { x + 11, y };
				sf::Vector2f PrawoPi³ki = { x + 22, y + 11 };
				sf::Vector2f Dó³Pi³ki = { x + 11, y + 22 };
				sf::Vector2f LewoPi³ki = { x, y + 11 };

				if (sprajt.contains(GóraPi³ki))
				{
					klocek[i][j].Wytrzyma³oœæMinus(oknoGRA);
					return 3;
				}
				else if (sprajt.contains(PrawoPi³ki))
				{
					klocek[i][j].Wytrzyma³oœæMinus(oknoGRA);
					return 4;
				}
				else if (sprajt.contains(Dó³Pi³ki))
				{
					klocek[i][j].Wytrzyma³oœæMinus(oknoGRA);
					return 1;
				}
				else if (sprajt.contains(LewoPi³ki))
				{
					klocek[i][j].Wytrzyma³oœæMinus(oknoGRA);
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
		MessageBox(NULL, "B³¹d podczas ³adowania bitmapy paletka.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu z gr¹.", "ERROR", NULL);
		oknoGRA.close();
	}
	PaletkaObiektSprajt.setTexture(PaletkaObiekt);
	PaletkaObiektSprajt.setPosition(x, y);
}
void Paletka::prawo(sf::RenderWindow &oknoGRA)
{
	if (x < 800 - 16 - d³ugoœæ - gruboœæ_ramki)
	{
		x += prêdkoœæ;
	}
	else
	{
		x = 800 - prêdkoœæ - d³ugoœæ - gruboœæ_ramki;
	}
}
void Paletka::lewo(sf::RenderWindow &oknoGRA)
{
	if (x > 16 + gruboœæ_ramki)
	{
		x -= prêdkoœæ;
	}
	else
	{
		x = 16;
	}
}


Pi³ka::Pi³ka(sf::RenderWindow &oknoGRA)
{
	if (!Pi³kaObiekt.loadFromFile("resources/pi³ka.bmp"))
	{
		MessageBox(NULL, "B³¹d podczas ³adowania bitmapy pi³ka.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
		oknoGRA.close();
	}
	Pi³kaObiektSprajt.setTexture(Pi³kaObiekt);
	Pi³kaObiektSprajt.setPosition(x, y);
}
void Pi³ka::ruch(Paletka &paletka, Plansza &plansza, Gracz &gracz, sf::RenderWindow &oknoGRA)
{
	if (czy_w_ruchu == false)
	{
		this->y = paletka.getY() - 24;
		this->x = paletka.getX() + 90 - 11;
	}
	else
	{
		pi³ka_ruch();

		//kolizja z klockami
		/*
                         bok 3
				  IIIIIIIIIIIIIIIIIII
				  IIIIIIIIIIIIIIIIIII
          bok 4   IIIIIIIIIIIIIIIIIII   bok 2
				  IIIIIIIIIIIIIIIIIII
				  IIIIIIIIIIIIIIIIIII
                         bok 3

				  0 = brak kolizji

				  */

		int bok = plansza.CzyKolizja(x, y, oknoGRA);

		//dzwiêk na uderzenie paletki w ifie poni¿ej
		if (bok >= 1 && bok <= 4)
		{
			audio.PlayKlocek();
		}

		switch (bok)
		{
		case 1:
			//prêdkoœæ_x = -prêdkoœæ_x;
			prêdkoœæ_y = -prêdkoœæ_y;
			gracz.punkty += 150;
			break;
		case 2:
			prêdkoœæ_x = -prêdkoœæ_x;
			gracz.punkty += 200;
			break;
		case 3:
			//prêdkoœæ_x = -prêdkoœæ_x;
			prêdkoœæ_y = -prêdkoœæ_y;
			gracz.punkty += 100;
			break;
		case 4:
			prêdkoœæ_x = -prêdkoœæ_x;
			gracz.punkty += 200;
			break;
		}

		//kolizja z œciankami
		if (x < 16)
		{
			audio.PlayŒciana();
			x = 16;
			prêdkoœæ_x = -prêdkoœæ_x;
		}
		else if (x > 784 - 16 - 11)
		{
			audio.PlayŒciana();
			x = 784 - 16 - 11;
			prêdkoœæ_x = -prêdkoœæ_x;
		}
		else if (y < 16)
		{
			audio.PlayŒciana();
			y = 16;
			prêdkoœæ_y = -prêdkoœæ_y;
		}


		//kolizja z paletk¹
		else if (y > 416 && x >= paletka.getX() && x <= paletka.getX() + paletka.GetD³ugoœæ())
		{
			audio.PlayPaletka();
			//sprawdzamy czy odbicie ma byæ w lewo czy w prawo
			float XNaPaletce = x - paletka.getX();

			if (XNaPaletce < paletka.GetD³ugoœæ() / 2)
			{
				//obicie w lewo
				prêdkoœæ_x = (float)-((paletka.GetD³ugoœæ() / 2) - XNaPaletce) * 0.05 * prêdkoœæ;
				prêdkoœæ_y = (float)-(5 - abs(prêdkoœæ_x / prêdkoœæ)) * prêdkoœæ;
			}
			else
			{
				//odbicie w prawo
				(float)prêdkoœæ_x = -((paletka.GetD³ugoœæ() / 2) - XNaPaletce) * 0.05  * prêdkoœæ;
				(float)prêdkoœæ_y = -(5 - abs(prêdkoœæ_x / prêdkoœæ)) * prêdkoœæ;
			}
		}


		//nieodbicie pi³eczki
		else if (y > 456 - 11 - 5)
		{
			audio.PlayStrata();
			gracz.¿ycia -= 1;
			if (gracz.¿ycia == 0)
			{
				oknoGRA.close();
				string bufor = "Przegra³eœ! Uzyska³eœ ";
				bufor += to_string(gracz.punkty);
				bufor += " punkty(ów)";
				MessageBox(NULL, bufor.c_str(), "Koniec gry", NULL);
				sprawdŸ_ewentualnie_zapisz_w_top(plansza.GetWybranaMapa(), gracz);
			}
			czy_w_ruchu = false;
			this->x = paletka.getX() + 90;
			this->y = paletka.getY() - 24;
			prêdkoœæ_x = 3 * prêdkoœæ;
			prêdkoœæ_y = -(5 - abs(prêdkoœæ_x / prêdkoœæ)) * prêdkoœæ;
		}
	}
}

class Engine //animacje i kolizje
{
private:
	//czcionka:
	sf::Font font;
	//t³o:
	sf::Texture T³o;
	sf::Sprite T³oSprajt;
	sf::RectangleShape ramka;
	//sta³y tekst:
	sf::Text nazwa_gracza;
	sf::Text ¿ycia_tekst;
	sf::Text punkty_tekst;
	sf::Text czas_tekst;
	sf::Text nazwa_gracza_tekst;

	//zegary:
	sf::Clock czas_pi³ka;
	sf::Clock czas_paletka;
	sf::Clock czas_gry;

	
	Gracz gracz;

	int która_mapa = 1;

	void ustaw_t³o(sf::RenderWindow &oknoGRA) //ustawia t³o i otoczkê t³a
	{
		ramka.setSize({ 768, 456 });
		ramka.setOutlineColor(sf::Color::Red);
		ramka.setOutlineThickness(5.0);
		ramka.setPosition({ 16, 16 });

		int random_t³o = rand() % 4;
		switch (random_t³o)
		{
		case 0:
			if (!T³o.loadFromFile("resources/t³o_0.bmp"))
			{
				MessageBox(NULL, "B³¹d podczas ³adowania bitmapy t³o_0.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
				oknoGRA.close();
			}
			break;
		case 1:
			if (!T³o.loadFromFile("resources/t³o_1.bmp"))
			{
				MessageBox(NULL, "B³¹d podczas ³adowania bitmapy t³o_1.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
				oknoGRA.close();
			}
			break;
		case 2:
			if (!T³o.loadFromFile("resources/t³o_2.bmp"))
			{
				MessageBox(NULL, "B³¹d podczas ³adowania bitmapy t³o_2.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
				oknoGRA.close();
			}
			break;
		case 3:
			if (!T³o.loadFromFile("resources/t³o_3.bmp"))
			{
				MessageBox(NULL, "B³¹d podczas ³adowania bitmapy t³o_3.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
				oknoGRA.close();
			}
			break;
		}

		T³oSprajt.setTexture(T³o);
		T³oSprajt.setPosition(16, 16);
	}

	void wyœwietl_t³o(sf::RenderWindow &oknoGRA)
	{
		oknoGRA.draw(ramka);
		oknoGRA.draw(T³oSprajt);
	}

	void ustaw_sta³y_tekst(sf::RenderWindow &oknoGRA)
	{
		nazwa_gracza.setFont(font);
		¿ycia_tekst.setFont(font);
		punkty_tekst.setFont(font);
		czas_tekst.setFont(font);
		nazwa_gracza_tekst.setFont(font);
		¿ycia_tekst.setString(gracz.¿ycia_tekst);
		punkty_tekst.setString(gracz.punkty_tekst);
		czas_tekst.setString(gracz.czas_tekst);
		nazwa_gracza_tekst.setString(gracz.nazwa_gracza_tekst);

		¿ycia_tekst.setPosition({ 45, 500 });
		punkty_tekst.setPosition({ 245, 500 });
		czas_tekst.setPosition({ 445, 500 });
		nazwa_gracza_tekst.setPosition({ 660, 500 });
		nazwa_gracza.setString(gracz.nazwa_gracza);
		nazwa_gracza.setPosition({ 660, 540 });
	}

	void wyœwietl_sta³y_tekst(sf::RenderWindow &oknoGRA)
	{
		oknoGRA.draw(¿ycia_tekst);
		oknoGRA.draw(punkty_tekst);
		oknoGRA.draw(czas_tekst);
		oknoGRA.draw(nazwa_gracza);
		oknoGRA.draw(nazwa_gracza_tekst);
	}

	void ustaw_wyœwietl_dynamiczny_tekst(sf::RenderWindow &oknoGRA)
	{
		sf::Text ¿ycia;
		sf::Text punkty;
		sf::Text czas;

		¿ycia.setFont(font);
		punkty.setFont(font);
		czas.setFont(font);

		char bufor[10];
		_itoa_s(gracz.¿ycia, bufor, 10);
		¿ycia.setString(bufor);
		¿ycia.setPosition({ 65, 540 });

		_itoa_s(gracz.punkty, bufor, 10);
		punkty.setString(bufor);
		punkty.setPosition({ 285, 540 });

		_itoa_s(gracz.minuty, bufor, 10);
		string po³¹czone = bufor;
		po³¹czone += ":";
		_itoa_s(gracz.sekundy, bufor, 10);
		if (gracz.sekundy < 10)
		{
			po³¹czone += '0';
		}
		po³¹czone += bufor;
		czas.setString(po³¹czone);
		czas.setPosition({ 445, 540 });
		
		oknoGRA.draw(¿ycia);
		oknoGRA.draw(punkty);
		oknoGRA.draw(czas);
	}

public:
	~Engine(){}

	Engine(sf::RenderWindow &oknoGRA)
	{
		if (!font.loadFromFile("resources/antibiotech.ttf"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania czcionki antibiotech.ttf. Upewnij siê, ¿e czcionka znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoGRA.close();
		}
	}

	void runEngine(sf::RenderWindow &oknoGRA)
	{
		Paletka paletka(oknoGRA);
		Pi³ka pi³ka(oknoGRA);
		Plansza plansza(oknoGRA);

		ustaw_t³o(oknoGRA);
		ustaw_sta³y_tekst(oknoGRA);

		oknoGRA.display();

		while (oknoGRA.isOpen())
		{
			sf::Event event;
			sf::Vector2i mysz(sf::Mouse::getPosition(oknoGRA));

			while (oknoGRA.pollEvent(event))
			{	
				switch (event.type)
				{	
/* [X] */		case sf::Event::Closed: // klikniêcie przycisku [X]
					oknoGRA.close();
					break;

/*MYSZ LEWY*/	case(sf::Event::MouseButtonPressed) :
					pi³ka.pi³ka_start();
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
						pi³ka.pi³ka_start();
					}

					break;
				}
			}


			if (czas_pi³ka.getElapsedTime() > sf::milliseconds(16))
			{
				pi³ka.ruch(paletka, plansza, gracz, oknoGRA);

				czas_pi³ka.restart();
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

			wyœwietl_t³o(oknoGRA);
			wyœwietl_sta³y_tekst(oknoGRA);
			ustaw_wyœwietl_dynamiczny_tekst(oknoGRA);
			
			
			plansza.WyœwietlPlanszê(oknoGRA, gracz);
			paletka.rysowanie(oknoGRA);
			pi³ka.rysowanie(oknoGRA);

			oknoGRA.display();
		}
	}
};

string ustaw_nick()
{

	string nick = config["nick"];
	return nick;
}

int sprawdŸ_tryb_ekranu()
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
	sf::RenderWindow OKNOgra(sf::VideoMode(800, 600, 32), "Arkanoid by PABLO", sprawdŸ_tryb_ekranu());
	ustaw_parametry(OKNOgra);

	Engine engine(OKNOgra);
	engine.runEngine(OKNOgra);
}