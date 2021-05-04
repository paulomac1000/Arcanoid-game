#include "menu.h"

void wyb�r_opcji(char wyb�r, int &opcja, sf::RenderWindow &oknoAplikacji, Tekstury &obrazki)
{
	
	if (wyb�r == 'g')
	{
		opcja++;
	}
	else if (wyb�r == 'd')
	{
		opcja--;
	}


	if (opcja < 1)
	{
		opcja = 4;
	}
	else if (opcja > 4)
	{
		opcja = 1;
	}

	switch (opcja)
	{
	case 1:
		
		if (!obrazki.NowaGra.loadFromFile("resources/NowaGraON.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy NowaGraON.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.NowaGraSprajt.setTexture(obrazki.NowaGra);
		obrazki.NowaGraSprajt.setPosition(150, 25);


		if (!obrazki.Top10.loadFromFile("resources/Top10OFF.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy Top10OFF.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.Top10Sprajt.setTexture(obrazki.Top10);
		obrazki.Top10Sprajt.setPosition(150, 170);

		
		if (!obrazki.Ustawienia.loadFromFile("resources/UstawieniaOFF.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy UstawieniaOFF.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.UstawieniaSprajt.setTexture(obrazki.Ustawienia);
		obrazki.UstawieniaSprajt.setPosition(150, 315);

		if (!obrazki.Wyj�cie.loadFromFile("resources/WyjscieOFF.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy WyjscieOFF.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.Wyj�cieSprajt.setTexture(obrazki.Wyj�cie);
		obrazki.Wyj�cieSprajt.setPosition(150, 460);
		
		break;
	case 2:
		if (!obrazki.NowaGra.loadFromFile("resources/NowaGraOFF.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy NowaGraOFF.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.NowaGraSprajt.setTexture(obrazki.NowaGra);
		obrazki.NowaGraSprajt.setPosition(150, 25);

		if (!obrazki.Top10.loadFromFile("resources/Top10ON.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy Top10ON.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.Top10Sprajt.setTexture(obrazki.Top10);
		obrazki.Top10Sprajt.setPosition(150, 170);


		if (!obrazki.Ustawienia.loadFromFile("resources/UstawieniaOFF.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy UstawieniaOFF.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.UstawieniaSprajt.setTexture(obrazki.Ustawienia);
		obrazki.UstawieniaSprajt.setPosition(150, 315);

		if (!obrazki.Wyj�cie.loadFromFile("resources/WyjscieOFF.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy WyjscieOFF.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources/.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.Wyj�cieSprajt.setTexture(obrazki.Wyj�cie);
		obrazki.Wyj�cieSprajt.setPosition(150, 460);

		break;

	case 3:
		if (!obrazki.NowaGra.loadFromFile("resources/NowaGraOFF.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy NowaGraOFF.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.NowaGraSprajt.setTexture(obrazki.NowaGra);
		obrazki.NowaGraSprajt.setPosition(150, 25);


		if (!obrazki.Top10.loadFromFile("resources/Top10OFF.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy Top10OFF.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.Top10Sprajt.setTexture(obrazki.Top10);
		obrazki.Top10Sprajt.setPosition(150, 170);

		if (!obrazki.Ustawienia.loadFromFile("resources/UstawieniaON.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy UstawieniaON.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.UstawieniaSprajt.setTexture(obrazki.Ustawienia);
		obrazki.UstawieniaSprajt.setPosition(150, 315);


		if (!obrazki.Wyj�cie.loadFromFile("resources/WyjscieOFF.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy WyjscieOFF.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.Wyj�cieSprajt.setTexture(obrazki.Wyj�cie);
		obrazki.Wyj�cieSprajt.setPosition(150, 460);

		break;

	case 4:
		if (!obrazki.NowaGra.loadFromFile("resources/NowaGraOFF.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy NowaGraOFF.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.NowaGraSprajt.setTexture(obrazki.NowaGra);
		obrazki.NowaGraSprajt.setPosition(150, 25);


		if (!obrazki.Top10.loadFromFile("resources/Top10OFF.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy Top10OFF.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.Top10Sprajt.setTexture(obrazki.Top10);
		obrazki.Top10Sprajt.setPosition(150, 170);


		if (!obrazki.Ustawienia.loadFromFile("resources/UstawieniaOFF.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy UstawieniaOFF.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.UstawieniaSprajt.setTexture(obrazki.Ustawienia);
		obrazki.UstawieniaSprajt.setPosition(150, 315);

		if (!obrazki.Wyj�cie.loadFromFile("resources/WyjscieON.bmp"))
		{
			MessageBox(NULL, "B��d podczas �adowania bitmapy WyjscieON.bmp. Upewnij si�, �e bitmapa znajduje si� w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.Wyj�cieSprajt.setTexture(obrazki.Wyj�cie);
		obrazki.Wyj�cieSprajt.setPosition(150, 460);

		break;
	}
}

void wyb�r_podprogramu(int wyb�r_opcji_w_menu, sf::RenderWindow &oknoAplikacj)
{
	if (wyb�r_opcji_w_menu == 1)
	{
		oknoAplikacj.setVisible(false);
		audio.StopMuzykaMenu();
		if (audio.CzyAktywny() == true)
		{
			audio.PlayMuzykaGra();
		}
		gra();
		audio.StopMuzykaGra();
		oknoAplikacj.setVisible(true);
		if (audio.CzyAktywny() == true)
		{
			audio.PlayMuzykaMenu();
		}
	}
	else if (wyb�r_opcji_w_menu == 2)
	{
		oknoAplikacj.setVisible(false);
		top10();
		oknoAplikacj.setVisible(true);
	}
	else if (wyb�r_opcji_w_menu == 3)
	{
		oknoAplikacj.setVisible(false);
		ustawienia();
		oknoAplikacj.setVisible(true);
	}
	else if (wyb�r_opcji_w_menu == 4)
	{
		int odpowied� = MessageBox(NULL, "Czy na pewno chcesz wyj�� z gry?", "Ko�czymy?", MB_YESNO);
		if (odpowied� == IDYES)
		{
			oknoAplikacj.close();
		}
	}
}

void menu()
{
	sf::RenderWindow oknoMENU(sf::VideoMode(800, 600, 32), "Arcanoid", 1); //fullscreen to 8, 1 to brak paska  u g�ry i nierozszerzalno��

	sf::Image im;
	if (!im.loadFromFile("resources/icon.png"))
	{
		MessageBox(NULL, "B��d podczas �adowania obrazu icon.png. Upewnij si�, �e obraz znajduje si� w katalogu resources.", "ERROR", NULL);
		oknoMENU.close();
	}
	oknoMENU.setIcon(32, 32, im.getPixelsPtr());

	sf::Texture T�o;
	sf::Sprite T�oSprajt;
	if (!T�o.loadFromFile("resources/t�o_menu.jpg"))
	{
		MessageBox(NULL, "B��d podczas �adowania obrazu t�o.jpg. Upewnij si�, �e obraz znajduje si� w katalogu resources.", "ERROR", NULL);
		oknoMENU.close();
	}
	T�oSprajt.setTexture(T�o);
	
	

	int wyb�r_opcji_w_menu = 1;
	Tekstury obrazki;

	wyb�r_opcji('0', wyb�r_opcji_w_menu, oknoMENU, obrazki);

	sf::Vector2i pozycja_kursora;
	sf::FloatRect bufor;

	if (audio.CzyAktywny() == true)
	{
		audio.PlayMuzykaMenu();
	}

	int wyb�r_opcji_pami�� = 10;

	// program b�dzie w��czony dop�ki okno jest otwarte
	while (oknoMENU.isOpen())
	{
		sf::Event event;
		while (oknoMENU.pollEvent(event))
		{
			oknoMENU.clear();

			switch (event.type)
			{
/* [X] */	case sf::Event::Closed: // klikni�cie przycisku [X]
				oknoMENU.close();
				break;

/*MYSZ LEWY*/	case(sf::Event::MouseButtonPressed) :
				audio.PlayConfirm();
				wyb�r_podprogramu(wyb�r_opcji_w_menu, oknoMENU);
				break;

			case sf::Event::KeyPressed:
/*UP*/			if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
				{
					audio.PlaySwitch();
					wyb�r_opcji('d', wyb�r_opcji_w_menu, oknoMENU, obrazki);
				}
/*DOWN*/		else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
				{
					audio.PlaySwitch();
					wyb�r_opcji('g', wyb�r_opcji_w_menu, oknoMENU, obrazki);
				}
/*ESCAPE*/		else if (event.key.code == sf::Keyboard::Escape)
				{
					audio.PlaySwitch();
					wyb�r_podprogramu(4, oknoMENU);
				}
/*ENTER*/		else if (event.key.code == sf::Keyboard::Return)
				{
					audio.PlayConfirm();
					wyb�r_podprogramu(wyb�r_opcji_w_menu, oknoMENU);
				}

				break;

			}

			pozycja_kursora = sf::Mouse::getPosition(oknoMENU);
			bufor = obrazki.NowaGraSprajt.getLocalBounds();		

			

			if (pozycja_kursora.x > 150 && pozycja_kursora.x < bufor.width+150 &&
				pozycja_kursora.y > 25+bufor.top && pozycja_kursora.y < bufor.height+25)
			{
				wyb�r_opcji_w_menu = 1;
				if (wyb�r_opcji_pami�� != wyb�r_opcji_w_menu)
				{
					audio.PlaySwitch();
				}
				wyb�r_opcji('0', wyb�r_opcji_w_menu, oknoMENU, obrazki);
			}
			if (pozycja_kursora.x > 150 && pozycja_kursora.x < bufor.width + 150 &&
				pozycja_kursora.y > 50 + bufor.height && pozycja_kursora.y < 50 + 2*bufor.height)
			{
				wyb�r_opcji_w_menu = 2;
				if (wyb�r_opcji_pami�� != wyb�r_opcji_w_menu)
				{
					audio.PlaySwitch();
				}
				wyb�r_opcji('0', wyb�r_opcji_w_menu, oknoMENU, obrazki);
			}
			if (pozycja_kursora.x > 150 + bufor.left && pozycja_kursora.x < bufor.width + 150 &&
				pozycja_kursora.y > 75 + 2*bufor.height && pozycja_kursora.y < 3*bufor.height + 75)
			{
				wyb�r_opcji_w_menu = 3;
				if (wyb�r_opcji_pami�� != wyb�r_opcji_w_menu)
				{
					audio.PlaySwitch();
				}
				wyb�r_opcji('0', wyb�r_opcji_w_menu, oknoMENU, obrazki);
			}
			if (pozycja_kursora.x > 150 + bufor.left && pozycja_kursora.x < bufor.width + 150 &&
				pozycja_kursora.y > 100 + 3 * bufor.height && pozycja_kursora.y < 4 * bufor.height + 100)
			{
				wyb�r_opcji_w_menu = 4;
				if (wyb�r_opcji_pami�� != wyb�r_opcji_w_menu)
				{
					audio.PlaySwitch();
				}
				wyb�r_opcji('0', wyb�r_opcji_w_menu, oknoMENU, obrazki);
			}

			wyb�r_opcji_pami�� = wyb�r_opcji_w_menu;

			oknoMENU.draw(T�oSprajt);
			oknoMENU.draw(obrazki.NowaGraSprajt);
			oknoMENU.draw(obrazki.Top10Sprajt);
			oknoMENU.draw(obrazki.UstawieniaSprajt);
			oknoMENU.draw(obrazki.Wyj�cieSprajt);
			oknoMENU.display();
		}
	}
}