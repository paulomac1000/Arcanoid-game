#include "Audio.h"

void Audio::SetLoud()
{
	MuzykaMenu.setVolume(70);
	MuzykaGra.setVolume(70);


	Switch.setVolume(70);
	Confirm.setVolume(100);
	Klocek.setVolume(30);
	Paletka.setVolume(10);
	Œciana.setVolume(80);

	Strata.setVolume(100);
	Wygrana.setVolume(100);
}

Audio::Audio()
{
	if (!MuzykaMenu.openFromFile("music/menu.ogg"))
	{
		MessageBox(NULL, "B³¹d podczas ³adowania muzyki menu. Upewnij siê, ¿e plik menu.ogg znajduje siê w katalogu music.", "ERROR", NULL);
	}
	if (!Switch.openFromFile("sounds/switch.ogg"))
	{
		MessageBox(NULL, "B³¹d podczas ³adowania dŸwiêku przesuwania. Upewnij siê, ¿e plik switch.ogg znajduje siê w katalogu sounds.", "ERROR", NULL);
	}
	if (!Confirm.openFromFile("sounds/confirm.ogg"))
	{
		MessageBox(NULL, "B³¹d podczas ³adowania dŸwiêku zatwierdzenia. Upewnij siê, ¿e plik confirm.ogg znajduje siê w katalogu sounds.", "ERROR", NULL);
	}
	if (!MuzykaGra.openFromFile("music/gra.ogg"))
	{
		MessageBox(NULL, "B³¹d podczas ³adowania muzyki gry. Upewnij siê, ¿e plik gra.ogg znajduje siê w katalogu music.", "ERROR", NULL);
	}
	if (!Klocek.openFromFile("sounds/klocek.ogg"))
	{
		MessageBox(NULL, "B³¹d podczas ³adowania dŸwiêku uderzenia w klocek. Upewnij siê, ¿e plik klocek.ogg znajduje siê w katalogu sounds.", "ERROR", NULL);
	}
	if (!Paletka.openFromFile("sounds/paletka.ogg"))
	{
		MessageBox(NULL, "B³¹d podczas ³adowania dŸwiêku uderzenia w paletkê. Upewnij siê, ¿e plik paletka.ogg znajduje siê w katalogu sounds.", "ERROR", NULL);
	}
	if (!Œciana.openFromFile("sounds/sciana.ogg"))
	{
		MessageBox(NULL, "B³¹d podczas ³adowania dŸwiêku uderzenia w œcianê. Upewnij siê, ¿e plik sciana.ogg znajduje siê w katalogu sounds.", "ERROR", NULL);
	}
	if (!Strata.openFromFile("sounds/strata.wav"))
	{
		MessageBox(NULL, "B³¹d podczas ³adowania dŸwiêku straconego ¿ycia. Upewnij siê, ¿e plik strata.wav znajduje siê w katalogu sounds.", "ERROR", NULL);
	}
	if (!Wygrana.openFromFile("sounds/wygrana.wav"))
	{
		MessageBox(NULL, "B³¹d podczas ³adowania dŸwiêku wygranej. Upewnij siê, ¿e plik wygrana.wav znajduje siê w katalogu sounds.", "ERROR", NULL);
	}

	SetLoud();
}

