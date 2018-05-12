#include "Player.h"
#include <string>
#include <stdlib.h>
#include <iostream>

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
Player::Player(uint id, int x, int y):id(id),coordinate(x,y){
	this->HP=0;

    }
Player::~Player(){}

uint Player::getID() const{ return this->id;}
const Coordinate& Player::getCoord() const{ return this->coordinate;}

int Player::getHP() const{
	return this->HP;

}

    /**
     * Board ID is two-decimal ID for the Player.
     *
     * Player ID = 0, 91
     * Board ID = "00", "91"
     *
     * @return BoardID of the user.
     */
std::string Player::getBoardID() const{

	std::string asd = std::to_string(this->id);
	if(this->id < 10)
		return "0"+ asd;
	else
		return asd;

}

    /**
     * Every player has a different priority move list.
     * It's explained in the Players' header.
     *
     * @return The move priority list for the player.
     */

    /**
     * Get the full name of the player.
     *
     * Example (Tracer with ID 92) = "Tracer92"
     * Example (Tracer with ID 1)  = "Tracer01"
     *
     * @return Full name of the player.
     */

    /**
     * Decide whether the player is dead.
     *
     * @return true if the player's hp <= 0, false otherwise.
     */
bool Player::isDead() const{
	int eycpi = this->HP;
	if (eycpi <= 0 )
		return true;
	else
		return false;
}
    /**
     * Execute the given move for the player's coordinates.
     *
     * Important note: Priority list does NOT matter here.
     *
     * NOOP and ATTACK are no-op.
     *
     * Do not forget to print the move.
     * "-playerFullName(playerHP)- moved UP/DOWN/LEFT/RIGHT."
     *
     * "Tracer00(100) moved UP."
     *
     * @param move Move to make.
     */
void Player::executeMove(Move move){
	this->coordinate = coordinate + move;
    std::string a;
    switch(move)
    {
        case 1:
            a="UP";
            break;
        case 2:
            a="DOWN";
            break;
        case 3:
            a="LEFT";
            break;
        case 4:
            a="RIGHT";
            break;        
    }
	std::cout<< this->getFullName() << "(" << this->HP << ") moved " << a << "." << std::endl;   
    }

    /**
     * Attack the given player, and decide whether the attacked player is dead.
     *
     * Important note: Priority list does NOT matter here.
     *
     * Formulae : RHS's HP -= max((LHS's damage - RHS's armor), 0)
     *
     * Do not forget to print the attack.
     *
     * "-lhsFullName(lhsHP)- ATTACKED -rhsFullName(rhsHP)-! (-damageDone-)
     *
     * "Tracer00(100) ATTACKED Tracer01(100)! (-10)"
     *
     * @param player Player to be attacked.
     * @return true if attacked player is dead, false otherwise.
     */
bool Player::attackTo(Player *player){
	if(this == player)
        return false;
    int demic = Entity::damageForWeapon( this->getWeapon() ) - Entity::damageReductionForArmor(player->getArmor() );
	demic = std::max(demic , 0);
	std::cout<< this->getFullName() << "(" << this->getHP() << ")"
	<< " ATTACKED " << player->getFullName() << "(" 
	<< player->getHP() << ")! (-" << demic <<")"<<std::endl;
    player->HP -= demic;
    return player->isDead() ;  
}

    /**
     * Return different colors for different Player classes (override!).
     *
     * Note: This method is optional. You may leave this as-is.
     *
     * @return The associated color code with the class.
     */