#pragma once

#include "main.h"

class Audio
{
	sf::Music MuzykaMenu;
	sf::Music Switch;
	sf::Music Confirm;
	sf::Music MuzykaGra;
	sf::Music Klocek;
	sf::Music Paletka;
	sf::Music Œciana;
	sf::Music Strata;
	sf::Music Wygrana;

	bool active = true;

	void SetLoud();

public:
	Audio();

	void PlayMuzykaMenu()
	{
		if (active == true)
		{
			MuzykaMenu.setLoop(true);
			MuzykaMenu.play();
		}
	}

	void StopMuzykaMenu()
	{
		MuzykaMenu.setLoop(false);
		MuzykaMenu.stop();
	}

	void PlaySwitch()
	{
		if (active == true)
		{
			Switch.play();
		}
	}

	void PlayConfirm()
	{
		if (active == true)
		{
			Confirm.play();
		}
	}

	void PlayKlocek()
	{
		if (active == true)
		{
			Klocek.play();
		}
	}

	void PlayPaletka()
	{
		if (active == true)
		{
			Paletka.play();
		}
	}

	void PlayŒciana()
	{
		if (active == true)
		{
			Œciana.play();
		}
	}

	void PlayStrata()
	{
		if (active == true)
		{
			Strata.play();
		}
	}

	void PlayWygrana()
	{
		if (active == true)
		{
			Wygrana.play();
		}
	}

	void PlayMuzykaGra()
	{
		if (active == true)
		{
			MuzykaGra.setLoop(true);
			MuzykaGra.play();
		}
	}

	void StopMuzykaGra()
	{
		MuzykaGra.setLoop(false);
		MuzykaGra.stop();
	}

	void Aktywacja(bool active)
	{
		this->active = active;
	}

	bool CzyAktywny()
	{
		return active;
	}

	~Audio(){};
};

