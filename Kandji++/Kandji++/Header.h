#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

HANDLE hConsole;

long int Point = 0;
long int Error = 0;

int Xnamber = 0;
int* px = &Xnamber;


enum ColorInConsole
{
	Red = 4,
	Blue = 3
};

// void random() { random number }; int massiv[0,1,2, ...] && == mass[]; 0 = kuchi, 1 = tsuki, 2 = hito ...
			//         0															1												2
int Fifr[100]{0,1,2,3};

std::string mass[] = { "C:/Users/volis/source/repos/Kandji++/kuchi.png", "C:/Users/volis/source/repos/Kandji++/tsuki.jpg", "C:/Users/volis/source/repos/Kandji++/hito.jpg", "/lol.png"};






