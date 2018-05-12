#include "Tracer.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
Tracer::Tracer(uint id, int x, int y):Player(id,x,y){
	this->HP = 100;
}

Armor Tracer::getArmor()const{
	return Armor::BRICK;
}
Weapon Tracer::getWeapon()const {
    	return Weapon::SHOVEL;
    }
std::vector<Move> Tracer::getPriorityList()const{
	return {Move::UP,Move::LEFT,Move:DOWN,Move::RIGHT,Move::ATTACK};
}
const std::string Tracer::getFullName()const{
   	std::string sitring = getBoardID();
   	return "Tracer"+ sitring;

    }
   Color::Code Tracer::getColorID()const {
    	return Color::FG_YELLOW;
    }