#include "Pacifist.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
Pacifist::Pacifist(uint id, int x, int y):Player(id,x,y){
	this->HP = 100;
}

Armor Pacifist::getArmor()const{
	return Armor::METAL;
}
Weapon Pacifist::getWeapon()const {
    	return Weapon::NOWEAPON;
    }
std::vector<Move> Pacifist::getPriorityList()const{
	return {Move::UP, Move::LEFT ,Move::DOWN ,Move::RIGHT};
}
    const std::string Pacifist::getFullName()const{
    	std::string sitring = getBoardID();
    	return "Pacifist"+ sitring;

    }
    Color::Code Pacifist::getColorID()const {
    	return Color::FG_GREEN;
    }
