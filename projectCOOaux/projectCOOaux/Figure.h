//valentin, Mask
#pragma once
#include <iostream>
#include<string>
#include<array>

using namespace std;

class Figure {
	friend class Lancer;
protected:
	string name;
	string desc;
	int points;
	int numberDe;
public:
	Figure() :points(0),numberDe(0) {};
	int getPoints() {
		return this->points;
	};
	int getNumberDe() {
		return this->numberDe;
	}
	virtual bool verif(const array<int, 5> tabDe)=0;
	friend std::ostream& operator<<(std::ostream& os,const Figure& t) {
		return os << "name : " << t.name << ", description : " << t.desc << " Nombre de Points : " << t.points;
	};

};