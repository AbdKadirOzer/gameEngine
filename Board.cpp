#include "Board.h"
#include <iostream>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
Board::Board(uint boardSize, std::vector<Player *> *players):boardSize(boardSize),players(players){
    this->stormct=0;
    }
Board::~Board(){
}

uint Board::getSize() const{
	return this->boardSize;
}
    /**
     * Decide whether the coordinate is in the board limits.
     *
     * @param coord Coordinate to search.
     * @return true if coord is in limits, false otherwise.
     */
bool Board::isCoordInBoard(const Coordinate& coord) const{
	int sayz= this->boardSize;
	int x = coord.x;
	int y = coord.y;
	if(x<0 || y<0 || x>=sayz || y>=sayz)
		return false;
	else
		return true;
    }
    /**
     * Decide whether the given coordinate is in storm.
     *
     * @param coord Coordinate to search.
     * @return true if covered in storm, false otherwise.
     */
bool Board::isStormInCoord(const Coordinate &coord) const{
    int i =0;
    int j= this->boardSize-1;
    for(i=0;i < stormct ; i++)
    {    
        if( coord.y == 0+i || coord.x == 0+i || coord.y == j-i  || coord.x == j-i )
            return true;
    }
	return false;
}

    /**
     * Decide whether the given coordinate is the hill.
     *
     * @param coord Coordinate to search.
     * @return true if the coord is at the very center of the board, false otherwise.
     */
bool Board::isCoordHill(const Coordinate& coord) const{
	int sayz= this->boardSize;
	int x = coord.x;
	int y = coord.y;
	sayz=(sayz-1)/2;

	if(x== sayz && y==sayz)
		return true;
	else
		return false;
}
    /**
     * Indexing.
     *
     * Find the player in coordinate.
     *
     * nullptr if player does not exists in given coordinates, or !isCoordInBoard
     *
     * @param coord  The coordinate to search.
     * @return The player in coordinate.
     */
Player *Board::operator[](const Coordinate& coord) const{
	if( !(isCoordInBoard(coord)))
		return nullptr;
	for(int i=0 ; i < (*players).size() ; i ++)
	{	
		if( (*players)[i]->getCoord() ==  coord )
			return (*players)[i];

	}
	return nullptr;

}
    /**
     * Calculate the new coordinate with the given move and coordinate.
     *
     * NOOP and ATTACK are no-op, return coord.
     *
     * The new coordinate cannot be outside of the borders.
     * If it's the case, return coord.
     *
     * Also, if there's another player in the new coordinate,
     * return coord.
     *
     * @param move Move to be made.
     * @param coord The coordinate to be moved.
     * @return Calculated coordinate after the move.
     */
    //ELEGANT SECTOR ******
Coordinate Board::calculateCoordWithMove(Move move, const Coordinate &coord) const{
    switch(move)
    {
        case UP:
            return (*this)[coord+UP]  == nullptr ? isCoordInBoard(coord+UP) ? coord+UP  : coord : (coord);
            break;  
        case DOWN:
            return (*this)[coord+DOWN]  == nullptr ? isCoordInBoard(coord+DOWN) ? coord+DOWN  : coord : (coord);
            break;
        case LEFT:
            return (*this)[coord+LEFT]  == nullptr ? isCoordInBoard(coord+LEFT) ? coord+LEFT  : coord : (coord);           
            break;
        case RIGHT:
            return (*this)[coord+RIGHT]  == nullptr ? isCoordInBoard(coord+RIGHT) ? coord+RIGHT  : coord : (coord);      
            break;
        case NOOP:
            return coord;
        case ATTACK:
            return coord;
    }

    return coord;
}

    /**
     * Find the visible coordinates from given coordinate.
     *
     * Explanation: The immediate UP/DOWN/LEFT/RIGHT tiles must be calculated.
     *
     * There could be max of 4 tiles, and min of 2 tiles (on corners).
     * Every found coordinate must be in the board limits.
     *
     * If the given coordinate is not in board, return a vector with size = 0. Order does NOT matter.
     *
     * Example:
     *
     * 01----
     * 02HH--
     * ------
     *
     * visibleCoordsFromCoord(Coordinate(0, 0)) == { (1, 0), (0, 1) }
     * visibleCoordsFromCoord(Coordinate(1, 1)) == { (1, 0), (2, 1), (1, 2), (0, 1) }
     * visibleCoordsFromCoord(Coordinate(-1, 0)) == { }
     *
     * @param coord The coordinate to search.
     * @return All coordinates visible.
     */
std::vector<Coordinate> Board::visibleCoordsFromCoord(const Coordinate &coord) const{
    std::vector<Coordinate> vktr;
    if(!isCoordInBoard(coord))
        return vktr;
    if( isCoordInBoard(coord+UP))
        vktr.push_back(coord+UP);
    if( isCoordInBoard(coord+DOWN))
        vktr.push_back(coord+DOWN);
    if( isCoordInBoard(coord+LEFT))
        vktr.push_back(coord+LEFT);
    if( isCoordInBoard(coord+RIGHT))
        vktr.push_back(coord+RIGHT);
    return vktr;
}

    /**
     * Calculate the storm according to the currentRound.
     *
     * @param currentRound The current round being played.
     */
void Board::updateStorm(uint currentRound){
    if(stormct == (boardSize-1)/2)
        return;
    if(currentRound% 5 == 1 )
		stormct= Entity::stormWidthForRound(currentRound);
	else
		return;
}

