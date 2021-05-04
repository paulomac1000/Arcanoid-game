#include "menu.h"

void wybór_opcji(char wybór, int &opcja, sf::RenderWindow &oknoAplikacji, Tekstury &obrazki)
{
	
	if (wybór == 'g')
	{
		opcja++;
	}
	else if (wybór == 'd')
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
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy NowaGraON.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.NowaGraSprajt.setTexture(obrazki.NowaGra);
		obrazki.NowaGraSprajt.setPosition(150, 25);


		if (!obrazki.Top10.loadFromFile("resources/Top10OFF.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy Top10OFF.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.Top10Sprajt.setTexture(obrazki.Top10);
		obrazki.Top10Sprajt.setPosition(150, 170);

		
		if (!obrazki.Ustawienia.loadFromFile("resources/UstawieniaOFF.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy UstawieniaOFF.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.UstawieniaSprajt.setTexture(obrazki.Ustawienia);
		obrazki.UstawieniaSprajt.setPosition(150, 315);

		if (!obrazki.Wyjœcie.loadFromFile("resources/WyjscieOFF.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy WyjscieOFF.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.WyjœcieSprajt.setTexture(obrazki.Wyjœcie);
		obrazki.WyjœcieSprajt.setPosition(150, 460);
		
		break;
	case 2:
		if (!obrazki.NowaGra.loadFromFile("resources/NowaGraOFF.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy NowaGraOFF.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.NowaGraSprajt.setTexture(obrazki.NowaGra);
		obrazki.NowaGraSprajt.setPosition(150, 25);

		if (!obrazki.Top10.loadFromFile("resources/Top10ON.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy Top10ON.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.Top10Sprajt.setTexture(obrazki.Top10);
		obrazki.Top10Sprajt.setPosition(150, 170);


		if (!obrazki.Ustawienia.loadFromFile("resources/UstawieniaOFF.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy UstawieniaOFF.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.UstawieniaSprajt.setTexture(obrazki.Ustawienia);
		obrazki.UstawieniaSprajt.setPosition(150, 315);

		if (!obrazki.Wyjœcie.loadFromFile("resources/WyjscieOFF.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy WyjscieOFF.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources/.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.WyjœcieSprajt.setTexture(obrazki.Wyjœcie);
		obrazki.WyjœcieSprajt.setPosition(150, 460);

		break;

	case 3:
		if (!obrazki.NowaGra.loadFromFile("resources/NowaGraOFF.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy NowaGraOFF.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.NowaGraSprajt.setTexture(obrazki.NowaGra);
		obrazki.NowaGraSprajt.setPosition(150, 25);


		if (!obrazki.Top10.loadFromFile("resources/Top10OFF.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy Top10OFF.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.Top10Sprajt.setTexture(obrazki.Top10);
		obrazki.Top10Sprajt.setPosition(150, 170);

		if (!obrazki.Ustawienia.loadFromFile("resources/UstawieniaON.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy UstawieniaON.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.UstawieniaSprajt.setTexture(obrazki.Ustawienia);
		obrazki.UstawieniaSprajt.setPosition(150, 315);


		if (!obrazki.Wyjœcie.loadFromFile("resources/WyjscieOFF.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy WyjscieOFF.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.WyjœcieSprajt.setTexture(obrazki.Wyjœcie);
		obrazki.WyjœcieSprajt.setPosition(150, 460);

		break;

	case 4:
		if (!obrazki.NowaGra.loadFromFile("resources/NowaGraOFF.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy NowaGraOFF.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.NowaGraSprajt.setTexture(obrazki.NowaGra);
		obrazki.NowaGraSprajt.setPosition(150, 25);


		if (!obrazki.Top10.loadFromFile("resources/Top10OFF.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy Top10OFF.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.Top10Sprajt.setTexture(obrazki.Top10);
		obrazki.Top10Sprajt.setPosition(150, 170);


		if (!obrazki.Ustawienia.loadFromFile("resources/UstawieniaOFF.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy UstawieniaOFF.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.UstawieniaSprajt.setTexture(obrazki.Ustawienia);
		obrazki.UstawieniaSprajt.setPosition(150, 315);

		if (!obrazki.Wyjœcie.loadFromFile("resources/WyjscieON.bmp"))
		{
			MessageBox(NULL, "B³¹d podczas ³adowania bitmapy WyjscieON.bmp. Upewnij siê, ¿e bitmapa znajduje siê w katalogu resources.", "ERROR", NULL);
			oknoAplikacji.close();
		}
		obrazki.WyjœcieSprajt.setTexture(obrazki.Wyjœcie);
		obrazki.WyjœcieSprajt.setPosition(150, 460);

		break;
	}
}

void wybór_podprogramu(int wybór_opcji_w_menu, sf::RenderWindow &oknoAplikacj)
{
	if (wybór_opcji_w_menu == 1)
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
	else if (wybór_opcji_w_menu == 2)
	{
		oknoAplikacj.setVisible(false);
		top10();
		oknoAplikacj.setVisible(true);
	}
	else if (wybór_opcji_w_menu == 3)
	{
		oknoAplikacj.setVisible(false);
		ustawienia();
		oknoAplikacj.setVisible(true);
	}
	else if (wybór_opcji_w_menu == 4)
	{
		int odpowiedŸ = MessageBox(NULL, "Czy na pewno chcesz wyjœæ z gry?", "Koñczymy?", MB_YESNO);
		if (odpowiedŸ == IDYES)
		{
			oknoAplikacj.close();
		}
	}
}

void menu()
{
	sf::RenderWindow oknoMENU(sf::VideoMode(800, 600, 32), "Arcanoid", 1); //fullscreen to 8, 1 to brak paska  u góry i nierozszerzalnoœæ

	sf::Image im;
	if (!im.loadFromFile("resources/icon.png"))
	{
		MessageBox(NULL, "B³¹d podczas ³adowania obrazu icon.png. Upewnij siê, ¿e obraz znajduje siê w katalogu resources.", "ERROR", NULL);
		oknoMENU.close();
	}
	oknoMENU.setIcon(32, 32, im.getPixelsPtr());

	sf::Texture T³o;
	sf::Sprite T³oSprajt;
	if (!T³o.loadFromFile("resources/t³o_menu.jpg"))
	{
		MessageBox(NULL, "B³¹d podczas ³adowania obrazu t³o.jpg. Upewnij siê, ¿e obraz znajduje siê w katalogu resources.", "ERROR", NULL);
		oknoMENU.close();
	}
	T³oSprajt.setTexture(T³o);
	
	

	int wybór_opcji_w_menu = 1;
	Tekstury obrazki;

	wybór_opcji('0', wybór_opcji_w_menu, oknoMENU, obrazki);

	sf::Vector2i pozycja_kursora;
	sf::FloatRect bufor;

	if (audio.CzyAktywny() == true)
	{
		audio.PlayMuzykaMenu();
	}

	int wybór_opcji_pamiêæ = 10;

	// program bêdzie w³¹czony dopóki okno jest otwarte
	while (oknoMENU.isOpen())
	{
		sf::Event event;
		while (oknoMENU.pollEvent(event))
		{
			oknoMENU.clear();

			switch (event.type)
			{
/* [X] */	case sf::Event::Closed: // klikniêcie przycisku [X]
				oknoMENU.close();
				break;

/*MYSZ LEWY*/	case(sf::Event::MouseButtonPressed) :
				audio.PlayConfirm();
				wybór_podprogramu(wybór_opcji_w_menu, oknoMENU);
				break;

			case sf::Event::KeyPressed:
/*UP*/			if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
				{
					audio.PlaySwitch();
					wybór_opcji('d', wybór_opcji_w_menu, oknoMENU, obrazki);
				}
/*DOWN*/		else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
				{
					audio.PlaySwitch();
					wybór_opcji('g', wybór_opcji_w_menu, oknoMENU, obrazki);
				}
/*ESCAPE*/		else if (event.key.code == sf::Keyboard::Escape)
				{
					audio.PlaySwitch();
					wybór_podprogramu(4, oknoMENU);
				}
/*ENTER*/		else if (event.key.code == sf::Keyboard::Return)
				{
					audio.PlayConfirm();
					wybór_podprogramu(wybór_opcji_w_menu, oknoMENU);
				}

				break;

			}

			pozycja_kursora = sf::Mouse::getPosition(oknoMENU);
			bufor = obrazki.NowaGraSprajt.getLocalBounds();		

			

			if (pozycja_kursora.x > 150 && pozycja_kursora.x < bufor.width+150 &&
				pozycja_kursora.y > 25+bufor.top && pozycja_kursora.y < bufor.height+25)
			{
				wybór_opcji_w_menu = 1;
				if (wybór_opcji_pamiêæ != wybór_opcji_w_menu)
				{
					audio.PlaySwitch();
				}
				wybór_opcji('0', wybór_opcji_w_menu, oknoMENU, obrazki);
			}
			if (pozycja_kursora.x > 150 && pozycja_kursora.x < bufor.width + 150 &&
				pozycja_kursora.y > 50 + bufor.height && pozycja_kursora.y < 50 + 2*bufor.height)
			{
				wybór_opcji_w_menu = 2;
				if (wybór_opcji_pamiêæ != wybór_opcji_w_menu)
				{
					audio.PlaySwitch();
				}
				wybór_opcji('0', wybór_opcji_w_menu, oknoMENU, obrazki);
			}
			if (pozycja_kursora.x > 150 + bufor.left && pozycja_kursora.x < bufor.width + 150 &&
				pozycja_kursora.y > 75 + 2*bufor.height && pozycja_kursora.y < 3*bufor.height + 75)
			{
				wybór_opcji_w_menu = 3;
				if (wybór_opcji_pamiêæ != wybór_opcji_w_menu)
				{
					audio.PlaySwitch();
				}
				wybór_opcji('0', wybór_opcji_w_menu, oknoMENU, obrazki);
			}
			if (pozycja_kursora.x > 150 + bufor.left && pozycja_kursora.x < bufor.width + 150 &&
				pozycja_kursora.y > 100 + 3 * bufor.height && pozycja_kursora.y < 4 * bufor.height + 100)
			{
				wybór_opcji_w_menu = 4;
				if (wybór_opcji_pamiêæ != wybór_opcji_w_menu)
				{
					audio.PlaySwitch();
				}
				wybór_opcji('0', wybór_opcji_w_menu, oknoMENU, obrazki);
			}

			wybór_opcji_pamiêæ = wybór_opcji_w_menu;

			oknoMENU.draw(T³oSprajt);
			oknoMENU.draw(obrazki.NowaGraSprajt);
			oknoMENU.draw(obrazki.Top10Sprajt);
			oknoMENU.draw(obrazki.UstawieniaSprajt);
			oknoMENU.draw(obrazki.WyjœcieSprajt);
			oknoMENU.display();
		}
	}
}