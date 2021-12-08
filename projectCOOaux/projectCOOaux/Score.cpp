#include "Score.h"

Score::Score() :point(0), save(false) {};

std::ostream& operator<<(std::ostream& os, const Score& t) {
	return os << "points : " << t.point;
}