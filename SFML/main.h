#pragma once

#include <iostream>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <Windows.h>
#include <list>
#include <map>
#include <stdlib.h> 
#include <time.h> 
#include <fstream>
#include <cmath> //abs
#include <SFML/Audio.hpp>
#include "Audio.h"

using namespace std;

void menu();
void gra();
void top10();
void odczyt_z_configu(map <string, string> &config);
void ustawienia();