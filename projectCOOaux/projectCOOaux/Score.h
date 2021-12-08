#pragma once
#include <iostream>
#include<string>
class Score
{
	friend class Joueur;
private:
	int point;
	bool save;
public:
	Score();
	friend std::ostream& operator<<(std::ostream& os, const Score& t);
};

