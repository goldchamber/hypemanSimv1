#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Hypeman
{
public:
	Hypeman(int likes = 0, int actions = 0);
	int m_YellCount = 0;
	int m_ThrowCount = 0;
	int m_Actions;
	void Yell();
	void Throw();
	void Record();
	void SetLikes(int likes);
	int GetLikes();
private: 
	int m_Likes;
	void ActionsTaken();

};

Hypeman::Hypeman(int likes, int actions) :
	m_Likes(likes),
	m_Actions(actions)
{}

void Hypeman::Yell() {
	//int yellCount = 0;

	int randomNumber = rand();
	srand(static_cast<unsigned int>(time(0)));
	int yellNum = (randomNumber % 5) + 1;

	std::cout << "You yell:\n\n";
	
	switch (yellNum) {
	case 1:
		m_YellCount += 1;
		std::cout << "WORLDSTAR!\n\n";
		
		break;
	case 2:
		m_YellCount += 1;
		std::cout << "He needs some milk!\n\n ";
		
		break;
	case 3:
		m_YellCount += 1;
		std::cout << "WOAHHHHHHH!\n\n";
		
		break;
	case 4:
		m_YellCount += 1;
		std::cout << "Subscribe to my Youtube tho!\n\n";
		
		break;
	case 5:
		m_YellCount += 1;
		std::cout << "Oh shit...\n\n";
		
		break;
	default:
		std::cout << "WORLDSTAR! WORLDSTAR!\n\n";
		m_YellCount += 1;
	}
	if (m_YellCount >= 5) {
		std::cout << "Your constant yelling angers viewers!\n";
		SetLikes(-50000);
	}
	else if (m_YellCount >= 3) {
		std::cout << "Your constant yelling begins to annoy viewers!\n";
		SetLikes(25000);
	}
	else if (m_YellCount > 0) {
		std::cout << "The viewers are going wild!\n";
		SetLikes(160000);
	}
	ActionsTaken();
}

void Hypeman::Throw() {

	int randomNumber = rand();
	srand(static_cast<unsigned int>(time(0)));
	int throwNum = (randomNumber % 6) + 1;

	std::cout << "You grab the nearest object and throw it toward the fight!";

	switch (throwNum) {
	case 1:
		std::cout << "You grab a shovel!\n";
		std::cout << "Boi 1 smacks Boi 2's face!\n";
		m_ThrowCount ++;

		break;
	case 2:
		std::cout << "You grab a shovel!\n";
		std::cout << "Boi 2 smacks Boi 1's face!\n";
		m_ThrowCount++;

		break;
	case 3:
		std::cout << "You throw a metal chair!\n";
		std::cout << "Boi 1 crushes Boi 2's back!\n";
		m_ThrowCount++;

		break;
	case 4:
		std::cout << "You throw a metal chair!\n";
		std::cout << "Boi 2 chucks the chair into Boi 2's stomach!\n";
		m_ThrowCount++;

		break;
	case 5:
		std::cout << "You throw a golf club!\n";
		std::cout << "Boi 1 swings and gets Boi 2 between the legs!\n";
		m_ThrowCount++;
		break;
	case 6:
		std::cout << "You throw a golf club!\n";
		std::cout << "Boi 2 swings overhead but misses by a hair!\n";
		m_ThrowCount++;
		break;
	default:
		std::cout << "WORLDSTAR! WORLDSTAR!\n\n";
		m_ThrowCount += 1;
	}

	if (m_ThrowCount >= 4) {
		SetLikes(-300000);
	}
	if (m_ThrowCount > 2) {
		std::cout << "Now he REALLY doesn't look too good... You should probably stop throwing stuff!\n\n";
		SetLikes(25000);
	}
	else if (m_ThrowCount >= 0) {
		std::cout << "Ohh! One of the bois ain't lookin too good...\n";
		SetLikes(160000);
	}
	ActionsTaken();

}

void Hypeman::Record() {
	int randomNumber = rand();
	srand(static_cast<unsigned int>(time(0)));
	int fightScene = (randomNumber % 6) + 1;
	std::cout << "You're recording the fight!\n";

	switch (fightScene) {
	case 1:
		std::cout << "Boi 1 posts up! Boi 1 jabs!\n\n";
		break;
	case 2:
		std::cout << "Boi 2 posts up! Boy 2 swings!\n\n";
		break;
	case 3:
		std::cout << "Boi 1 landing those haymakers!\n\n";
		break;
	case 4:
		std::cout << "Boi 2 doing some kung fu spinning shit!\n\n";
		break;
	case 5:
		std::cout << "Boi 1 is swinging on top of Boi 2!\n\n";
		break;
	case 6:
		std::cout << "Boi 2 coming in with the heavy hands!\n\n";
		break;
	default:
		std::cout << "WORLDSTAR! WORLDSTAR!\n\n";
		break;
	}
	SetLikes(60000); //max likes through viewership is 600,000
	ActionsTaken();

}

void Hypeman::ActionsTaken() {
	m_Actions += 1;
}

void Hypeman::SetLikes(int likes) {
	m_Likes += likes;
}
int Hypeman::GetLikes() {
	return m_Likes;
}
int main()
{
	Hypeman man;
	int choice;
	std::cout << "Welcome to Hypeman Simulator v1.0\n\n\n";

	std::cout << "Aw shit, here we go again. Another fight has broken out! ";
	std::cout << "You take out your phone and start filming.\n\n";

	std::cout << "You're streaming live.\n";
	std::cout << "Take advantage of the moment and get one million views!\n";
	std::cout << "But be careful not to annoy the viewers!\n\n";

	do {
		std::cout << "\n0 - Quit Streaming\n";
		std::cout << "1 - Record the Fight\n";
		std::cout << "2 - Comentate the Fight\n";
		std::cout << "3 - Throw a Weapon\n\n";

		std::cout << "Choice:  ";
		std::cin >> choice;

		switch (choice) {
		case 0:
			std::cout << "You stopped recording.\n";
			std::cout << "Goodbye!\n\n";
			break;
		case 1:
			man.Record();
			break;
		case 2:
			man.Yell();
			break;
		case 3: 
			man.Throw();
			break;
		default:
			std::cout << "That is not an option\n\n";
		}
	} while (choice != 0 && 
			man.m_ThrowCount < 4 &&
			man.m_Actions < 10);	

	if (man.m_ThrowCount > 3) {
		std::cout << "You threw too many weapons!\n";
		std::cout << "One of the bois needs medical attention!\n";
		std::cout << "You were arrested as an accomplice for murder!\n";
		std::cout << "The fight is over!\n\n";
	}

	if (man.m_Actions >= 10) {
		std::cout << "You finished recording.\n";
		std::cout << "You got " << man.GetLikes() << " views!\n\n";
		if (man.GetLikes() == 1000000) {
			std::cout << "Your stream had a million views! You're a content creating star!\n\n";
		}
		else {
			std::cout << "Not quite a million, but you almost got it.\n";
			std::cout << "Time to get back to the grind.\n\n";
		}
	}


	std::cout << "GAME OVER\n\n\n";

	return 0;
}

