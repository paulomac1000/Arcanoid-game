#include "Ustawienia.h"

void zapis_do_configu(map <string, string> &config)
{
	ofstream plik;
	plik.open("config.cfg", std::ios::out);
	if (plik.is_open())
	{
		plik << "obraz ";
		plik << config["obraz"] << endl;
		plik << "fps ";
		plik << config["fps"] << endl;
		plik << "glebia ";
		plik << config["glebia"] << endl;
		plik << "nick ";
		plik << config["nick"] << endl;
		plik << "dzwiek ";
		plik << config["dzwiek"] << endl;

	}
	else
	{
		MessageBox(NULL, "B≥πd z zapisem configu do pliku! Sprawdü, czy aplikacja ma prawa do zapisu w tej lokalizacji lub czy plik nie jest \"tylko do odczytu\"", "ERROR", NULL);
	}
	plik.close();
}

void odczyt_z_configu(map <string, string> &config)
{
	string bufor;
	string standardowa_komenda[5] = { "obraz", "fps", "glebia", "nick", "dzwiek" };
	string standardowa_wartoúÊ[5] = { "window", "120", "32", "Player", "1" };

	ifstream plik;

	for (int i = 0; i < 5; i++)
	{
		plik.open("config.cfg", std::ifstream::in);

		if (plik.is_open())
		{

			bool znaleziono = false;
			for (int j = 0; j < 10; j++)
			{
				plik >> bufor;
				if (bufor == standardowa_komenda[i])
				{
					plik >> config[standardowa_komenda[i]];
					znaleziono = true;
				}
			}

			if (znaleziono == false)
			{
				config[standardowa_komenda[i]] = standardowa_wartoúÊ[i];
			}

		}
		else
		{

		}

		plik.close();
	}
}

T≥o::T≥o(sf::RenderWindow &oknoUSTAWIENIA)
{
	if (!T≥oTekstura.loadFromFile("resources/t≥o_menu.jpg"))
	{
		MessageBox(NULL, "B≥πd podczas ≥adowania obrazu t≥o_menu.jpg. Upewnij siÍ, øe obraz znajduje siÍ w katalogu resources.", "ERROR", NULL);
		oknoUSTAWIENIA.close();
	}
	T≥oSprajt.setTexture(T≥oTekstura);
}

Obraz::Obraz(sf::RenderWindow &oknoUSTAWIENIA, tgui::Gui &gui, map <string, string> &config)
{
	tgui::Checkbox::Ptr bufor(gui);
	tgui::Checkbox::Ptr bufor2(gui);
	if (!tytu≥.loadFromFile("resources/SpriteGraffiti.otf"))
	{
		MessageBox(NULL, "B≥πd podczas ≥adowania czcionki SpriteGraffiti.otf. Upewnij siÍ, øe czcionka znajduje siÍ w katalogu resources.", "ERROR", NULL);
		oknoUSTAWIENIA.close();
	}
	if (!napisy.loadFromFile("resources/alamakot.ttf"))
	{
		MessageBox(NULL, "B≥πd podczas ≥adowania czcionki alamakot.ttf. Upewnij siÍ, øe czcionka znajduje siÍ w katalogu resources.", "ERROR", NULL);
		oknoUSTAWIENIA.close();
	}
	RadioFULLSCREEN = bufor;
	RadioWINDOW = bufor2;

	OBRAZ.setColor(sf::Color::Red);
	OBRAZ.setFont(tytu≥);
	OBRAZ.setString("OBRAZ");
	OBRAZ.setPosition(100, 20);
	OBRAZ.setCharacterSize(60);


	RadioFULLSCREEN->load("resources/Black.conf");
	RadioFULLSCREEN->setPosition(100, 100);
	RadioFULLSCREEN->bindCallback(tgui::Button::LeftMouseClicked);
	RadioFULLSCREEN->setCallbackId(1);
	RadioFULLSCREEN->setTextColor(sf::Color::Black);
	RadioFULLSCREEN->setTextFont(napisy);
	RadioFULLSCREEN->setText("FULLSCREEN");


	RadioWINDOW->load("resources/Black.conf");
	RadioWINDOW->setPosition(100, 150);
	RadioWINDOW->bindCallback(tgui::Button::LeftMouseClicked);
	RadioWINDOW->setCallbackId(2);
	RadioWINDOW->setTextColor(sf::Color::Black);
	RadioWINDOW->setTextFont(napisy);
	RadioWINDOW->setText("W OKNIE");


	if (config["obraz"] == "window")
	{

		RadioFULLSCREEN->uncheck();
		RadioWINDOW->check();
	}
	else
	{
		RadioWINDOW->uncheck();
		RadioFULLSCREEN->check();
	}

}
void Obraz::WciúniÍtoFULLSCREEN(map <string, string> &config)
{
	config["obraz"] = "fullscreen";
	RadioFULLSCREEN->check();
	RadioWINDOW->uncheck();
}
void Obraz::WciúniÍtoWINDOW(map <string, string> &config)
{
	config["obraz"] = "window";
	RadioWINDOW->check();
	RadioFULLSCREEN->uncheck();
}

Fps::Fps(sf::RenderWindow &oknoUSTAWIENIA, tgui::Gui &gui, map <string, string> &config)
{
	tgui::Checkbox::Ptr bufor(gui);
	tgui::Checkbox::Ptr bufor2(gui);
	tgui::EditBox::Ptr bufor3(gui);

	if (!tytu≥.loadFromFile("resources/SpriteGraffiti.otf"))
	{
		MessageBox(NULL, "B≥πd podczas ≥adowania czcionki SpriteGraffiti.otf. Upewnij siÍ, øe czcionka znajduje siÍ w katalogu resources.", "ERROR", NULL);
		oknoUSTAWIENIA.close();
	}
	if (!napisy.loadFromFile("resources/alamakot.ttf"))
	{
		MessageBox(NULL, "B≥πd podczas ≥adowania czcionki alamakot.ttf. Upewnij siÍ, øe czcionka znajduje siÍ w katalogu resources.", "ERROR", NULL);
		oknoUSTAWIENIA.close();
	}

	RadioWPISYWANIE = bufor;
	RadioSYNCHRONIZACJA = bufor2;
	EditBoxWPISYWANIE = bufor3;

	FPS.setColor(sf::Color::Red);
	FPS.setFont(tytu≥);
	FPS.setString("FPS");
	FPS.setPosition(450, 20);
	FPS.setCharacterSize(60);

	RadioWPISYWANIE->load("resources/Black.conf");
	RadioWPISYWANIE->setPosition(450, 100);
	RadioWPISYWANIE->bindCallback(tgui::Button::LeftMouseClicked);
	RadioWPISYWANIE->setCallbackId(3);
	/////
	EditBoxWPISYWANIE->load("resources/Black.conf");
	EditBoxWPISYWANIE->setPosition(490, 100);
	EditBoxWPISYWANIE->bindCallback(tgui::Button::LeftMouseClicked);
	EditBoxWPISYWANIE->setCallbackId(4);
	EditBoxWPISYWANIE->setTextColor(sf::Color::White);
	EditBoxWPISYWANIE->setTextFont(napisy);
	EditBoxWPISYWANIE->setText(config["fps"]);
	EditBoxWPISYWANIE->setSize(200, 35);

	RadioSYNCHRONIZACJA->load("resources/Black.conf");
	RadioSYNCHRONIZACJA->setPosition(450, 150);
	RadioSYNCHRONIZACJA->bindCallback(tgui::Button::LeftMouseClicked);
	RadioSYNCHRONIZACJA->setCallbackId(5);
	RadioSYNCHRONIZACJA->setTextColor(sf::Color::Black);
	RadioSYNCHRONIZACJA->setTextFont(napisy);
	RadioSYNCHRONIZACJA->setText("Synchronizacja\npionowa");

	if (config["fps"] == "0")
	{
		RadioSYNCHRONIZACJA->check();
		RadioWPISYWANIE->uncheck();

		EditBoxWPISYWANIE->disable();
	}
	else
	{
		config["fps"] = EditBoxWPISYWANIE->getText();
		bool zawiera_znaki = false;
		for (unsigned int i = 0; i < config["fps"].length(); i++)
		{
			if (config["fps"][i] < 48 || config["fps"][i] > 57)
			{
				zawiera_znaki = true;
			}
		}
		if (zawiera_znaki == true)
		{
			MessageBox(NULL, "Podano nieprawid≥owy znak(i)!", "ERROR", NULL);
			config["fps"] == "120";
			EditBoxWPISYWANIE->setText(config["fps"]);
		}


		bool za_d≥ugie = false;
		if (config["fps"].length() > 5)
		{
			za_d≥ugie = true;
		}
		if (za_d≥ugie == true)
		{
			MessageBox(NULL, "Podana iloúÊ FPS jest za duøa!", "ERROR", NULL);
			config["fps"] == "120";
			EditBoxWPISYWANIE->setText(config["fps"]);
		}

		RadioWPISYWANIE->check();
		RadioSYNCHRONIZACJA->uncheck();

		EditBoxWPISYWANIE->enable();
	}
}
void Fps::WciúniÍtoWPISYWANIE(map <string, string> &config)
{
	config["fps"] = EditBoxWPISYWANIE->getText();
	RadioSYNCHRONIZACJA->uncheck();
	RadioWPISYWANIE->check();
	EditBoxWPISYWANIE->enable();
}
void Fps::WciúniÍtoFPS(map <string, string> &config)
{
	EditBoxWPISYWANIE->enable();
	RadioWPISYWANIE->check();
	RadioSYNCHRONIZACJA->uncheck();
	EditBoxWPISYWANIE->enable();
}
void Fps::ZatwierdzonoFPS(map <string, string> &config)
{
	config["fps"] = EditBoxWPISYWANIE->getText();
	bool zawiera_znaki = false;
	for (unsigned int i = 0; i < config["fps"].length(); i++)
	{
		if (config["fps"][i] < 48 || config["fps"][i] > 57)
		{
			zawiera_znaki = true;
		}
	}
	if (zawiera_znaki == true)
	{
		MessageBox(NULL, "Podano nieprawid≥owy znak(i)!", "ERROR", NULL);
		config["fps"] == "120";
		EditBoxWPISYWANIE->setText(config["fps"]);
	}


	bool za_d≥ugie = false;
	if (config["fps"].length() > 5)
	{
		za_d≥ugie = true;
	}
	if (za_d≥ugie == true)
	{
		MessageBox(NULL, "Podana iloúÊ FPS jest za duøa!", "ERROR", NULL);
		config["fps"] == "120";
		EditBoxWPISYWANIE->setText(config["fps"]);
	}
}
void Fps::WciúniÍtoSYNCHRONIZACJA(map <string, string> &config)
{
	config["fps"] = "0";
	RadioSYNCHRONIZACJA->check();
	RadioWPISYWANIE->uncheck();

	EditBoxWPISYWANIE->disable();
}

G≥Íbia::G≥Íbia(sf::RenderWindow &oknoUSTAWIENIA, tgui::Gui &gui, map <string, string> &config)
{
	tgui::Checkbox::Ptr bufor(gui);
	tgui::Checkbox::Ptr bufor2(gui);
	if (!tytu≥.loadFromFile("resources/SpriteGraffiti.otf"))
	{
		MessageBox(NULL, "B≥πd podczas ≥adowania czcionki SpriteGraffiti.otf. Upewnij siÍ, øe czcionka znajduje siÍ w katalogu resources.", "ERROR", NULL);
		oknoUSTAWIENIA.close();
	}
	if (!napisy.loadFromFile("resources/alamakot.ttf"))
	{
		MessageBox(NULL, "B≥πd podczas ≥adowania czcionki alamakot.ttf. Upewnij siÍ, øe czcionka znajduje siÍ w katalogu resources.", "ERROR", NULL);
		oknoUSTAWIENIA.close();
	}
	Radio16BIT = bufor;
	Radio32BIT = bufor2;

	G£ BIA.setColor(sf::Color::Red);
	G£ BIA.setFont(tytu≥);
	G£ BIA.setString("GLEBIA");
	G£ BIA.setPosition(100, 230);
	G£ BIA.setCharacterSize(60);


	Radio16BIT->load("resources/Black.conf");
	Radio16BIT->setPosition(100, 310);
	Radio16BIT->bindCallback(tgui::Button::LeftMouseClicked);
	Radio16BIT->setCallbackId(6);
	Radio16BIT->setTextColor(sf::Color::Black);
	Radio16BIT->setTextFont(napisy);
	Radio16BIT->setText("16 bit");


	Radio32BIT->load("resources/Black.conf");
	Radio32BIT->setPosition(100, 360);
	Radio32BIT->bindCallback(tgui::Button::LeftMouseClicked);
	Radio32BIT->setCallbackId(7);
	Radio32BIT->setTextColor(sf::Color::Black);
	Radio32BIT->setTextFont(napisy);
	Radio32BIT->setText("32 bit");

	if (config["glebia"] == "32")
	{
		Radio32BIT->check();
		Radio16BIT->uncheck();
	}
	else
	{
		Radio16BIT->check();
		Radio32BIT->uncheck();
	}

}
void G≥Íbia::WciúniÍto32BIT(map <string, string> &config)
{
	config["glebia"] = "32";
	Radio32BIT->check();
	Radio16BIT->uncheck();
}
void G≥Íbia::WciúniÍto16BIT(map <string, string> &config)
{
	config["glebia"] = "16";
	Radio16BIT->check();
	Radio32BIT->uncheck();
}

DüwiÍk::DüwiÍk(sf::RenderWindow &oknoUSTAWIENIA, tgui::Gui &gui, map <string, string> &config)
{
	tgui::Checkbox::Ptr bufor(gui);
	tgui::Checkbox::Ptr bufor2(gui);
	if (!tytu≥.loadFromFile("resources/SpriteGraffiti.otf"))
	{
		MessageBox(NULL, "B≥πd podczas ≥adowania czcionki SpriteGraffiti.otf. Upewnij siÍ, øe czcionka znajduje siÍ w katalogu resources.", "ERROR", NULL);
		oknoUSTAWIENIA.close();
	}
	if (!napisy.loadFromFile("resources/alamakot.ttf"))
	{
		MessageBox(NULL, "B≥πd podczas ≥adowania czcionki alamakot.ttf. Upewnij siÍ, øe czcionka znajduje siÍ w katalogu resources.", "ERROR", NULL);
		oknoUSTAWIENIA.close();
	}
	RadioDèWI KON = bufor;
	RadioDèWI KOFF = bufor2;

	DèWI K.setColor(sf::Color::Red);
	DèWI K.setFont(tytu≥);
	DèWI K.setString("DZWIEK");
	DèWI K.setPosition(450, 230);
	DèWI K.setCharacterSize(60);


	RadioDèWI KON->load("resources/Black.conf");
	RadioDèWI KON->setPosition(450, 310);
	RadioDèWI KON->bindCallback(tgui::Button::LeftMouseClicked);
	RadioDèWI KON->setCallbackId(8);
	RadioDèWI KON->setTextColor(sf::Color::Black);
	RadioDèWI KON->setTextFont(napisy);
	RadioDèWI KON->setText("TAK");


	RadioDèWI KOFF->load("resources/Black.conf");
	RadioDèWI KOFF->setPosition(450, 360);
	RadioDèWI KOFF->bindCallback(tgui::Button::LeftMouseClicked);
	RadioDèWI KOFF->setCallbackId(9);
	RadioDèWI KOFF->setTextColor(sf::Color::Black);
	RadioDèWI KOFF->setTextFont(napisy);
	RadioDèWI KOFF->setText("NIE");

	if (config["dzwiek"] == "1")
	{
		RadioDèWI KON->check();
		RadioDèWI KOFF->uncheck();
	}
	else
	{
		RadioDèWI KOFF->check();
		RadioDèWI KON->uncheck();
	}

}
void DüwiÍk::WciúniÍtoDèWI KON(map <string, string> &config)
{
	config["dzwiek"] = "1";
	RadioDèWI KON->check();
	audio.Aktywacja(true);
	RadioDèWI KOFF->uncheck();
	audio.PlayMuzykaMenu();
}
void DüwiÍk::WciúniÍtoDèWI KOFF(map <string, string> &config)
{
	audio.StopMuzykaMenu();
	audio.Aktywacja(false);
	config["dzwiek"] = "0";
	RadioDèWI KOFF->check();
	RadioDèWI KON->uncheck();
}

Nick::Nick(sf::RenderWindow &oknoUSTAWIENIA, tgui::Gui &gui, map <string, string> &config)
{
	tgui::EditBox::Ptr bufor(gui);

	if (!tytu≥.loadFromFile("resources/SpriteGraffiti.otf"))
	{
		MessageBox(NULL, "B≥πd podczas ≥adowania czcionki SpriteGraffiti.otf. Upewnij siÍ, øe czcionka znajduje siÍ w katalogu resources.", "ERROR", NULL);
		oknoUSTAWIENIA.close();
	}
	if (!napisy.loadFromFile("resources/alamakot.ttf"))
	{
		MessageBox(NULL, "B≥πd podczas ≥adowania czcionki alamakot.ttf. Upewnij siÍ, øe czcionka znajduje siÍ w katalogu resources.", "ERROR", NULL);
		oknoUSTAWIENIA.close();
	}

	NICK.setColor(sf::Color::Red);
	NICK.setFont(tytu≥);
	NICK.setString("NICK");
	NICK.setPosition(100, 430);
	NICK.setCharacterSize(60);

	EditBoxNICK = bufor;
	EditBoxNICK->load("resources/Black.conf");
	EditBoxNICK->setText(config["nick"]);
	EditBoxNICK->setCallbackId(10);
	EditBoxNICK->setSize(200, 40);
	EditBoxNICK->setPosition(100, 510);
	EditBoxNICK->bindCallback(tgui::Button::LeftMouseClicked);
	EditBoxNICK->setTextColor(sf::Color::White);
	EditBoxNICK->setTextFont(napisy);


	if (config["nick"].length() > 7)
	{
		MessageBox(NULL, "Nazwa gracza nie moøe byÊ d≥uøsza niø 7 znakÛw.", "ERROR", NULL);
		config["nick"] = "Player";
		EditBoxNICK->setText(config["nick"]);
	}
	else
	{
		EditBoxNICK->setText(config["nick"]);
	}

}
void Nick::ZatwierdzonoNICK(map <string, string> &config)
{
	config["nick"] = EditBoxNICK->getText();
	if (config["nick"].length() > 7)
	{
		MessageBox(NULL, "Nazwa gracza nie moøe byÊ d≥uøsza niø 7 znakÛw.", "ERROR", NULL);
		config["nick"] = "Player";
		EditBoxNICK->setText(config["nick"]);
	}
}

Back::Back(sf::RenderWindow &oknoUSTAWIENIA, tgui::Gui &gui)
{
	tgui::Button::Ptr bufor(gui);
	BACK = bufor;
	if (!napisy.loadFromFile("resources/DejaVuSans.ttf"))
	{
		MessageBox(NULL, "B≥πd podczas ≥adowania czcionki DejaVuSans.ttf. Upewnij siÍ, øe czcionka znajduje siÍ w katalogu resources.", "ERROR", NULL);
		oknoUSTAWIENIA.close();
	}
	BACK->load("resources/Black.conf");
	BACK->setPosition(430, 450);
	BACK->setTextFont(napisy);
	BACK->setText("Zapisz!");
	BACK->setSize(300, 100);
	BACK->setTextColor(sf::Color::White);
	BACK->bindCallback(tgui::Button::LeftMouseClicked);
	BACK->setCallbackId(11);
}


void ustawienia()
{
	sf::RenderWindow oknoUSTAWIENIA(sf::VideoMode(800, 600, 32), "Ustawienia", sf::Style::Close);
	oknoUSTAWIENIA.setFramerateLimit(120);

	tgui::Gui gui(oknoUSTAWIENIA);
	sf::Image im;


	if (!im.loadFromFile("resources/icon.png"))
	{
		MessageBox(NULL, "B≥πd podczas ≥adowania obrazu icon.png. Upewnij siÍ, øe obraz znajduje siÍ w katalogu resources.", "ERROR", NULL);
		oknoUSTAWIENIA.close();
	}


	map <string, string> config;
	odczyt_z_configu(config);


	T≥o t≥o(oknoUSTAWIENIA);
	Obraz obraz(oknoUSTAWIENIA, gui, config);
	Fps fps(oknoUSTAWIENIA, gui, config);
	G≥Íbia g≥Íbia(oknoUSTAWIENIA, gui, config);
	DüwiÍk düwiÍk(oknoUSTAWIENIA, gui, config);
	Nick nick(oknoUSTAWIENIA, gui, config);
	Back back(oknoUSTAWIENIA, gui);

	
	while (oknoUSTAWIENIA.isOpen())
	{
		sf::Event event;
		while (oknoUSTAWIENIA.pollEvent(event))
		{
			switch (event.type)
			{
			case(sf::Event::MouseButtonPressed) :
				break;
			case(sf::Event::Closed) :
				audio.PlayConfirm();
				zapis_do_configu(config);
				oknoUSTAWIENIA.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					audio.PlayConfirm();
					zapis_do_configu(config);
					oknoUSTAWIENIA.close();
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					audio.PlaySwitch();
					fps.ZatwierdzonoFPS(config);
					nick.ZatwierdzonoNICK(config);
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
				obraz.WciúniÍtoFULLSCREEN(config);
			}
			if (callback.id == 2)
			{
				audio.PlaySwitch();
				obraz.WciúniÍtoWINDOW(config);
			}
			if (callback.id == 3)
			{
				audio.PlaySwitch();
				fps.WciúniÍtoWPISYWANIE(config);
			}
			if (callback.id == 4)
			{
				audio.PlaySwitch();
				fps.WciúniÍtoFPS(config);
			}
			if (callback.id == 5)
			{
				audio.PlaySwitch();
				fps.WciúniÍtoSYNCHRONIZACJA(config);
			}
			if (callback.id == 6)
			{
				audio.PlaySwitch();
				g≥Íbia.WciúniÍto16BIT(config);
			}
			if (callback.id == 7)
			{
				audio.PlaySwitch();
				g≥Íbia.WciúniÍto32BIT(config);
			}
			if (callback.id == 8)
			{
				audio.PlaySwitch();
				düwiÍk.WciúniÍtoDèWI KON(config);
			}
			if (callback.id == 9)
			{
				audio.PlaySwitch();
				düwiÍk.WciúniÍtoDèWI KOFF(config);
			}
			if (callback.id == 10)
			{
				audio.PlaySwitch();
				nick.WciúniÍtoNICK(config);
			}
			if (callback.id == 11)
			{
				audio.PlayConfirm();
				zapis_do_configu(config);
				oknoUSTAWIENIA.close();
			}
		}

		oknoUSTAWIENIA.clear();

		t≥o.WyúwietlT≥o(oknoUSTAWIENIA);
		obraz.WyúwietlObraz(oknoUSTAWIENIA);
		fps.WyúwietlFps(oknoUSTAWIENIA);
		g≥Íbia.WyúwietlG≥Íbia(oknoUSTAWIENIA);
		düwiÍk.WyúwietlDüwiÍk(oknoUSTAWIENIA);
		nick.WyúwietlNick(oknoUSTAWIENIA);

		gui.draw();


		oknoUSTAWIENIA.display();
	}
}
