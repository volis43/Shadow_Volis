#include <SFML/Graphics.hpp>
#include "Header.h"

void GetKeySearchKey(int y, std::string mass[])
{
	std::cout << mass << std::endl;
}

int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, Red);
	
	sf::RenderWindow window(sf::VideoMode(400, 400), "Picter");
	sf::Texture Picture;
	
	int PointerX = 0;

	int* pointer = &PointerX;
	*pointer = 2;

	std::string customString = mass[PointerX];

	std::string hj = "sf";
	std::string answer = "";
	std::string GetNumber[] = {"fels"};
	
	int ElementOfArray = sizeof(mass) / sizeof(mass[0]);
	
	*px = ElementOfArray;

	std::cout << " Masic X" << std::endl;
	

	std::string* Value = new std::string[*px];


	for (int i = 0; i < *px; i++)
	{
		std::string fullpath = mass[Fifr[i]];
		size_t lastSlash = fullpath.find_last_of("/\\");
		std::string filename = fullpath.substr(lastSlash + 1);

		size_t dotposition = filename.find_last_of('.');
		
		if (dotposition != std::string::npos)
		{
			filename = filename.substr(0, dotposition);
		
		}
		Value[i] = filename;
	}

	for (int i = 0; i < *px; i++)
	{
		std::cout << Fifr[i] << " = " << Value[i] << std::endl;
	}

	std::cout << sizeof(mass) / sizeof(mass[0]) << std::endl;

	Picture.loadFromFile(customString);

	sf::Sprite Sprite1(Picture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/*for (std::string g : mass)
		{
			std::cout << g << std::endl;
		}*/

		window.clear(sf::Color::White);
		window.draw(Sprite1);
		window.display();

		std::cin >> answer;

		if (answer == hj)
		{
			std::cout << "yes, correct +1 point <3 " << std::endl;
		}
		else
		{
			std::cout << "fuck you! <3 +1 Error point" << hj << std::endl;
		}

	}
}