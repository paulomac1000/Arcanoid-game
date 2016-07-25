#pragma once

#include "main.h"

extern Audio audio;

struct Osoba
{
	string gracz;
	int punkty;
};

void sprawdŸ_ewentualnie_zapisz_w_top(string mapa, Osoba wynik, bool wygrana = 0);

map <string, string> config;

//odczyt ustawieñ
string ustaw_nick();
int sprawdŸ_tryb_ekranu();
void ustaw_parametry(sf::RenderWindow &OKNO);

//obiekty gry
class Gracz
{
public:
	Gracz()	{}

	string ¿ycia_tekst = "¯ycia:";
	int ¿ycia = 3;
	string punkty_tekst = "Punkty:";
	long int punkty = 0;
	string czas_tekst = "Czas:";
	int minuty = 0;
	int sekundy = 0;
	string nazwa_gracza_tekst = "Gracz:";
	string nazwa_gracza = ustaw_nick();

	~Gracz(){}
};

struct Obiekt
{
	int x;
	int y;
};

class Klocek
	:public Obiekt
{
private:
	int wytrzyma³oœæ;
	int width;
	int heigth;
	int rodzaj;
	sf::Texture Model;
	sf::Sprite ModelSprajt;

public:
	Klocek(){}

	sf::Sprite GetSprajt()
	{
		return ModelSprajt;
	}
	
	int GetWytrzyma³oœæ()
	{
		return wytrzyma³oœæ;
	}

	void StwórzKlocek(int x, int y, int wytrzyma³oœæ, sf::RenderWindow &oknoGRA);

	void WyœwietlKlocek(sf::RenderWindow &oknoGRA)
	{
		oknoGRA.draw(ModelSprajt);
	}

	void Wytrzyma³oœæMinus(sf::RenderWindow &oknoGRA);

	~Klocek(){};
};

class Plansza
{
	int wybór;

	int tab[9][12];

	Klocek klocek[9][12];

	int wybierz_level(sf::RenderWindow &oknoGRA);

	void wczytaj_level(char *nazwa_pliku, sf::RenderWindow &oknoGRA);

public:

	Plansza(sf::RenderWindow &oknoGRA);

	void WyœwietlPlanszê(sf::RenderWindow &oknoGRA, Gracz &gracz);

	int CzyKolizja(float x, float y, sf::RenderWindow &oknoGRA);

	int GetWybranaMapa()
	{
		return wybór;
	}

	~Plansza(){};
};

class Paletka
	:public Obiekt
{
private:
	const float y = 440;
	float x = 348;
	float prêdkoœæ = 10;
	float d³ugoœæ = 180;
	float gruboœæ_ramki = 5;
	sf::Texture PaletkaObiekt;
	sf::Sprite PaletkaObiektSprajt;

public:

	Paletka(sf::RenderWindow &oknoGRA);

	float GetD³ugoœæ()
	{
		return d³ugoœæ;
	}

	void SetD³ugoœæ(float d³ugoœæ)
	{
		this->d³ugoœæ = d³ugoœæ;
	}

	void setX(int x)
	{
		this->x = (float)x;
	}

	float getX()
	{
		return x;
	}

	float getY()
	{
		return y;
	}

	void rysowanie(sf::RenderWindow &oknoGRA)
	{
		PaletkaObiektSprajt.setPosition(x, y);
		oknoGRA.draw(PaletkaObiektSprajt);
	}

	void prawo(sf::RenderWindow &oknoGRA);

	void lewo(sf::RenderWindow &oknoGRA);

	~Paletka(){}
};

class Pi³ka
	:public Obiekt
{
private:
	bool czy_w_ruchu = false;
	float x = 392;
	float y = 416;
	float prêdkoœæ = 2;
	float prêdkoœæ_x = 3 * prêdkoœæ;
	float prêdkoœæ_y = -(5 - abs(prêdkoœæ_x / prêdkoœæ)) * prêdkoœæ;
	sf::Texture Pi³kaObiekt;
	sf::Sprite Pi³kaObiektSprajt;

public:

	Pi³ka(sf::RenderWindow &oknoGRA);

	void pi³ka_start()
	{
		czy_w_ruchu = true;
	}

	void pi³ka_ruch()
	{
		x += prêdkoœæ_x;
		y += prêdkoœæ_y;
	}

	void rysowanie(sf::RenderWindow &oknoGRA)
	{
		Pi³kaObiektSprajt.setPosition(x, y);
		oknoGRA.draw(Pi³kaObiektSprajt);
	}

	void ruch(Paletka &paletka, Plansza &plansza, Gracz &gracz, sf::RenderWindow &oknoGRA);
};

//silnik gry
//do skopiowania póŸniej

//funkcja g³ówna
void gra();