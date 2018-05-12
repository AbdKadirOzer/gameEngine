#include "GameEngine.h"
#include <iostream>
#include <algorithm>

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
GameEngine::GameEngine(uint boardSize, std::vector<Player *> *players):board(boardSize,players){
	this->currentRound = 0;
	this->players = players;
    std::sort((*players).begin(),(*players).end(),Player::comp);
    }
GameEngine::~GameEngine(){
    for(int i=0 ; i< (*players).size();i++)
        delete (*players)[i];
    (*players).clear();
    delete players;
}

const Board& GameEngine::getBoard() const{
	return (this->board);
    }

    /**
     * Indexing.
     *
     * Find the player with given ID.
     *
     * nullptr if not exists.
     *
     * @param id ID of the player.
     * @return The player with given ID.
     */
Player* GameEngine::operator[](uint id) const{
	for(int i =0 ; i< (*players).size() ; i++)
		{ 
        if((*players)[i] == nullptr)
            continue;

        if( (*players)[i]->getID()  == id)
			return (*players)[i];
        }
	return nullptr;
}
    /**
     * Decide whether the game is finished.
     *
     * @return true if there is only 1 player (alive), on top of the hill; or there are 0 players. False otherwise.
     */
bool GameEngine::isFinished() const{
		if( ( (*players).size() == 0) || ((*players).size()==1 && board.isCoordHill((*players)[0]->getCoord())))
            return true;
	
    return false;

}

    /**
     * Take turn for every player.
     *
     * How-to:
     * - Announce turn start (cout).
     * Example: -- START ROUND 1  --
     * - board.updateStorm(currentRound)
     * - For every player (sorted according to their IDs) that isn't dead (HP <= 0):
     *      - takeTurnForPlayer(player).
     * - Announce turn end (cout).
     * Example: -- END ROUND 1 --
     */
void GameEngine::takeTurn(){
    currentRound++;
    std::cout<< "-- START ROUND "<< currentRound << " --\n";
    board.updateStorm(currentRound); 

    for(int i=0; i < (*players).size(); i++)
    {
  
        if(i<0) i++;
        takeTurnForPlayer((*players)[i]->getID());
        if(kontrol == 1)
        {
            kontrol = 0;
            i--;
        }


    }
    
    std:: cout << "--END ROUND " << currentRound << " --\n";

}

    /**
     * The most important (algorithm-wise) method.
     *
     * How-to:
     * - Get player with ID. Return NOOP if not exists.
     * - Get player's priority list.
     * - Get player's visibility from the board (visibleCoordsFromCoord).
     *
     * - If the player is in the storm (isStormInCoord), announce the damage and give player stormDamage.
     * - Example: Tracer01(10) is STORMED! (-10)
     *
     * - If dead, announce the death, remove player from the board/list/anywhere, and return NOOP.
     * - Example: Tracer01(0) DIED.
     *
     * - For MOVE in player's priority list:
     *          - If the MOVE is NOOP:
     *              - return NOOP.
     *          - Else if the MOVE is ATTACK:
     *              - Get all players that this player can attack (board[coord] for each in visibilityCoords).
     *              - If none, continue.
     *              - Else:
     *                  - Pick the one with most priority (lowest ID).
     *                  - isPlayerDead = player.attackTo(thatPlayer).
     *                  - if isPlayerIsDead:
     *                      - announce the death.
     *                      - remove thatPlayer from the board/list/anywhere.
     *                  - return ATTACK.
     *          - Else (UP/DOWN/LEFT/RIGHT):
     *              - calculateCoordWithMove(move).
     *              - If the new coordinate is different than the player's (meaning it's able to do that move)
     *              AND the player is getting closer to the hill;
     *                  - player.executeMove(MOVE).
     *                  - return MOVE.
     *              - Else:
     *                  - continue.
     *
     * // If the priority list is exhausted;
     * return NOOP.
     *
     * @param player Player ID to move.
     * @return move Decided move.
     */
Move GameEngine::takeTurnForPlayer(uint playerID)
{

    Player *oyuncu = nullptr;
    Player *dayakyiyen = nullptr;
    bool isPlayerDead;
    int i =0;
    for(i = 0 ; i<(*players).size() ; i++)
    {
        if((*players)[i] == nullptr)
            continue;
        if((*players)[i]->getID() == playerID )
        {
            oyuncu = (*players)[i];
            break;
        }    
    }

    if(oyuncu == nullptr)    
	   return NOOP;
    std::vector<Move> plist = oyuncu->getPriorityList();
    std::vector<Coordinate> cords= board.visibleCoordsFromCoord(oyuncu->getCoord());
    if( board.isStormInCoord( oyuncu->getCoord() ) )
        {
            std::cout << oyuncu->getFullName() <<"(" << oyuncu->getHP() << ") is STORMED! (-" <<  Entity::stormDamageForRound(currentRound) << ")\n";
            oyuncu->setHP(oyuncu->getHP()- Entity::stormDamageForRound(currentRound) );
            if(oyuncu->isDead())
            {    std::cout << oyuncu->getFullName() <<"(" <<oyuncu->getHP() <<") DIED." <<"\n";
                 delete oyuncu;
                 players->erase(players->begin() + i);
                 kontrol = 1;
                 return NOOP;
            }
        }
    for(int ct=0; ct < plist.size() ; ct++)
    {
        Move move= plist[ct];
        if(plist[ct] == NOOP)
            return NOOP;
        if(plist[ct] == ATTACK)
        {
            std::vector<Player*> *plinrange = new std::vector<Player*>;            
//            std::cout<<"::attacccc:: " << oyuncu->getFullName() << "\n";
//            std::cout<<"coordof: " << oyuncu->getFullName() << " is: " << oyuncu->getCoord() << "\n" ;
            for(int i=0; i<cords.size() ; i++)
            {
                if(board[cords[i]]  != nullptr)
                    plinrange->push_back(board[cords[i]]);

            }
            if(plinrange->size() <1){
                plinrange->clear();
                delete plinrange;
                continue;
            }
            std::sort(plinrange->begin(),plinrange->end(),Player::comp);
 
            //std::cout<<"KKK:::" << (*plinrange).size() <<"\n";
            dayakyiyen = (*plinrange)[0];
            //std::cout<<"ammmaaaa:::" << dayakyiyen->getFullName()<<"\n";
            int aydi= dayakyiyen->getID();
            isPlayerDead = oyuncu->attackTo(dayakyiyen);
            if(isPlayerDead)
            {    std::cout << dayakyiyen->getFullName() <<"(" << dayakyiyen->getHP() <<") DIED." <<"\n";
                 for(int j=0;j<(*players).size();j++)
                    if((*players)[j]->getID() == aydi){
                        if(aydi < playerID) kontrol=1;
                        delete this->operator[](aydi);
                        players->erase(players->begin()+j);
                    }            
                 
            }
            plinrange->clear();
            delete plinrange;  
            return ATTACK;
        }


        else{
//            std::cout<<"::MOWW:: " << oyuncu->getFullName() << "\n";    
            Coordinate b=oyuncu->getCoord();
            Coordinate sayz= Coordinate((board.getSize()-1)/2,(board.getSize()-1)/2);
            Coordinate a=board.calculateCoordWithMove(move,b);
            if(a != b &&  a - sayz < b-sayz)
            {    oyuncu->executeMove(move);
                 return move;
                }
            else
                continue;

        }


    }





return NOOP;

}

    /**
     * Find the winner player.
     *
     * nullptr if there are 0 players left, or the game isn't finished yet.
     *
     * @return The winner player.
     */
Player *GameEngine::getWinnerPlayer() const{
	int j=0;
	Player * temppl;
	if( isFinished() && (*players).size() == 1 )
		{
            return (*players)[0];
		}

	return nullptr;
}

    // DO NOT MODIFY THE UPPER PART
    // ADD OWN PUBLIC METHODS/PROPERTIES BELOW
