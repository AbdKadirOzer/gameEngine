#include "Dummy.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
Dummy::Dummy(uint id, int x, int y):Player(id,x,y){
	this->HP = 1000;
}

Armor Dummy::getArmor()const{
	return Armor::NOARMOR;
}
Weapon Dummy::getWeapon()const {
    	return Weapon::NOWEAPON;
    }
std::vector<Move> Dummy::getPriorityList()const{
	return {Move::NOOP};
}
    const std::string Dummy::getFullName()const{
    	std::string sitring = getBoardID();
    	return "Dummy"+ sitring;
    }
    Color::Code Dummy::getColorID()const {
    	return Color::FG_DEFAULT;
    }