/*

Skyrim Text Game
Create by Braeden Kuether
8/16/2018

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "Player.hpp"
#include "Space.hpp"
#include "WhiteSpace.hpp"

using namespace std;

int main() {
	srand(time(NULL));
	Space* start = new WhiteSpace;
	start->board();
	Player x;
	x.set_location(start);
	x.game();
	return 0;
}
