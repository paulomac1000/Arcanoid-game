#include "Top 10.h"

Osoba* odczytaj_top_z_pliku(string lokalizacja)
{
	Osoba *top = new Osoba[10];
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

		plik.close();
	}
	else
	{
		MessageBox(NULL, "Nie mo�na odczyta� pliku z zapisem rekord�w graczy.", "ERROR", NULL);
	}

	return top;
}

Okno::Okno(sf::RenderWindow &oknoTOP10, tgui::Gui &gui)
{
	tgui::RadioButton::Ptr bufor1(gui);
	tgui::RadioButton::Ptr bufor2(gui);
	tgui::RadioButton::Ptr bufor3(gui);
	tgui::RadioButton::Ptr bufor4(gui);
	tgui::RadioButton::Ptr bufor5(gui);
	tgui::Button::Ptr bufor6(gui);
	Mapa1 = bufor1;
	Mapa2 = bufor2;
	Mapa3 = bufor3;
	Mapa4 = bufor4;
	Mapa5 = bufor5;
	BACK = bufor6;

	if (!napisy.loadFromFile("resources/alamakot.ttf"))
	{
		MessageBox(NULL, "B��d podczas �adowania czcionki alamakot.ttf. Upewnij si�, �e czcionka znajduje si� w katalogu resources.", "ERROR", NULL);
		oknoTOP10.close();
	}

	BACK->load("resources/Black.conf");
	BACK->setText("OK!");
	BACK->setSize(300, 100);
	BACK->setPosition(430, 450);
	BACK->setTextColor(sf::Color::White);
	BACK->setTextSize(70);
	BACK->setTextFont(napisy);
	BACK->bindCallback(tgui::Button::LeftMouseClicked);
	BACK->setCallbackId(6);

	Zawarto��Top.setColor(sf::Color::Black);
	Zawarto��Top.setPosition(20, 20);
	Zawarto��Top.setFont(napisy);
	Zawarto��Top.setCharacterSize(35);

	Mapa1->load("resources/Black.conf");
	Mapa1->setText("Mapa 1");
	Mapa1->setPosition(520, 40);
	Mapa1->setTextColor(sf::Color::Black);
	Mapa1->setTextFont(napisy);
	Mapa1->bindCallback(tgui::Button::LeftMouseClicked);
	Mapa1->setCallbackId(1);
	Mapa1->check();

	Mapa2->load("resources/Black.conf");
	Mapa2->setText("Mapa 2");
	Mapa2->setPosition(520, 120);
	Mapa2->setTextColor(sf::Color::Black);
	Mapa2->setTextFont(napisy);
	Mapa2->bindCallback(tgui::Button::LeftMouseClicked);
	Mapa2->setCallbackId(2);

	Mapa3->load("resources/Black.conf");
	Mapa3->setText("Mapa 3");
	Mapa3->setPosition(520, 200);
	Mapa3->setTextColor(sf::Color::Black);
	Mapa3->setTextFont(napisy);
	Mapa3->bindCallback(tgui::Button::LeftMouseClicked);
	Mapa3->setCallbackId(3);

	Mapa4->load("resources/Black.conf");
	Mapa4->setText("Mapa 4");
	Mapa4->setPosition(520, 280);
	Mapa4->setTextColor(sf::Color::Black);
	Mapa4->setTextFont(napisy);
	Mapa4->bindCallback(tgui::Button::LeftMouseClicked);
	Mapa4->setCallbackId(4);

	Mapa5->load("resources/Black.conf");
	Mapa5->setText("Mapa 5");
	Mapa5->setPosition(520, 360);
	Mapa5->setTextColor(sf::Color::Black);
	Mapa5->setTextFont(napisy);
	Mapa5->bindCallback(tgui::Button::LeftMouseClicked);
	Mapa5->setCallbackId(5);

	wybrana_mapa();
}
void Okno::wybierz_map�(int numer)
{
	switch (numer)
	{
	case 1:
		Mapa1->enable();
		break;
	case 2:
		Mapa2->enable();
		break;
	case 3:
		Mapa3->enable();
		break;
	case 4:
		Mapa4->enable();
		break;
	case 5:
		Mapa5->enable();
		break;
	}

	wybrana_mapa();
}
void Okno::wybrana_mapa()
{
	Osoba *top;

	if (Mapa1->isChecked())
	{
		top = odczytaj_top_z_pliku("top/mapa_1.top");
	}
	else if (Mapa2->isChecked())
	{
		top = odczytaj_top_z_pliku("top/mapa_2.top");
	}
	else if (Mapa3->isChecked())
	{
		top = odczytaj_top_z_pliku("top/mapa_3.top");
	}
	else if (Mapa4->isChecked())
	{
		top = odczytaj_top_z_pliku("top/mapa_4.top");
	}
	else
	{
		top = odczytaj_top_z_pliku("top/mapa_5.top");
	}

	string bufor;

	for (int i = 0; i < 10; i++)
	{
		bufor += to_string(i+1);
		bufor += ". ";
		bufor += top[i].gracz;
		bufor += " - ";
		bufor += to_string(top[i].punkty);
		bufor += "\n";
	}

	Zawarto��Top.setString(bufor);
}

void top10()
{
	sf::RenderWindow oknoTOP10(sf::VideoMode(800, 600), "Top 10", sf::Style::Close);
	oknoTOP10.setFramerateLimit(120);
	tgui::Gui gui(oknoTOP10);
	sf::Image im;
	if (!im.loadFromFile("resources/icon.png"))
	{
		MessageBox(NULL, "B��d podczas �adowania obrazu icon.png. Upewnij si�, �e obraz znajduje si� w katalogu resources.", "ERROR", NULL);
		oknoTOP10.close();
	}

	sf::Texture T�o;
	sf::Sprite T�oSprajt;
	if (!T�o.loadFromFile("resources/t�o_menu.jpg"))
	{
		MessageBox(NULL, "B��d podczas �adowania obrazu t�o.jpg. Upewnij si�, �e obraz znajduje si� w katalogu resources.", "ERROR", NULL);
		oknoTOP10.close();
	}
	T�oSprajt.setTexture(T�o);

	//obiekty
	Okno okno(oknoTOP10, gui);
	//koniec obiekt�w

	while (oknoTOP10.isOpen())
	{
		sf::Event event;
		while (oknoTOP10.pollEvent(event))
		{
			switch (event.type)
			{
			case(sf::Event::MouseButtonPressed) :
				break;
			case(sf::Event::Closed) :
				oknoTOP10.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					oknoTOP10.close();
				}
				break;
			}

			gui.handleEvent(event);
		}

		tgui::Callback callback;
		while (gui.pollCallback(callback))
		{
			if (callback.id == 1)
			{
				audio.PlaySwitch();
				okno.wybierz_map�(1);
			}
			else if (callback.id == 2)
			{
				audio.PlaySwitch();
				okno.wybierz_map�(2);
			}
			else if (callback.id == 3)
			{
				audio.PlaySwitch();
				okno.wybierz_map�(3);
			}
			else if (callback.id == 4)
			{
				audio.PlaySwitch();
				okno.wybierz_map�(4);
			}
			else if (callback.id == 5)
			{
				audio.PlaySwitch();
				okno.wybierz_map�(5);
			}
			else if (callback.id == 6)
			{
				audio.PlayConfirm();
				oknoTOP10.close();
			}
		}

		oknoTOP10.clear();

		oknoTOP10.draw(T�oSprajt);
		okno.Wy�wietlTop(oknoTOP10);

		gui.draw();

		oknoTOP10.display();
	}
}
