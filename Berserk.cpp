#include "Berserk.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
Berserk::Berserk(uint id, int x, int y):Player(id,x,y){
	this->HP = 100;
}

    // Name     : Berserk
    // Priority : { ATTACK, UP, LEFT, DOWN, RIGHT }

    // Armor    : WOODEN
    // Weapon   : PISTOL
    // HP       : 100

    // DO NOT MODIFY THE UPPER PART
    // ADD OWN PUBLIC METHODS/PROPERTIES/OVERRIDES BELOW
Armor Berserk::getArmor()const{
	return Armor::WOODEN;
}
Weapon Berserk::getWeapon()const {
    	return Weapon::PISTOL;
    }
std::vector<Move> Berserk::getPriorityList()const{
	return {Move::ATTACK ,Move::UP,  Move::LEFT ,Move::DOWN ,Move::RIGHT};
}
const std::string Berserk::getFullName()const{
    	std::string sitring = getBoardID();
    	return "Berserk"+ sitring;
    }
    Color::Code Berserk::getColorID()const {
    	return Color::FG_RED;
    }

