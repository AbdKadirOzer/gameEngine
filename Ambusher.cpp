#include "Ambusher.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
Ambusher::Ambusher(uint id, int x, int y):Player(id,x,y){
	this->HP = 100;
}

Armor Ambusher::getArmor()const{
	return Armor::NOARMOR;
}
Weapon Ambusher::getWeapon()const {
    	return Weapon::SEMIAUTO;
    }
std::vector<Move> Ambusher::getPriorityList()const{
	return {Move::ATTACK};
}
    const std::string Ambusher::getFullName()const{
    	std::string sitring = getBoardID();
    	return "Ambusher"+ sitring;

    }
    Color::Code Ambusher::getColorID()const {
    	return Color::FG_BLUE;
    }