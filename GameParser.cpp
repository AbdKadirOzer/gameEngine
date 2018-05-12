#include "GameParser.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Berserk.h"
#include "Dummy.h"
#include "Pacifist.h"
#include "Tracer.h"
#include "Ambusher.h"
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
std::pair<int, std::vector<Player *> *> GameParser::parseFileWithName(const std::string& filename)
{
	std::fstream fayl;
	fayl.open(filename.c_str());
    std::string layn("");
    int siz=0,pikaunt=0,tempId=0;
    int i=0,x=0,y=0;
    std::vector < Player* > *vekt = new std::vector<Player*>;
    while(fayl>>layn)   
    {	
    	std::string result("");
    	x=0;
    	y=0;
        tempId = 0;
        if(i == 2)
        {
            siz= std::stoi(layn);
    	}
    	else if(i == 5)
    		pikaunt= std::stoi(layn);
    	else if(i > 5)
    	{
    		result= layn.substr(0,layn.find("::"));
    		tempId = std::stoi(result);
    		result = layn.substr(layn.find("::")+2,layn.length());
    		if(result[0] == 'B')
    		{
    			result=result.substr(result.find("k")+3,result.length());
    			x= std::stoi( result.substr(0,result.find(":") ) );
    			if(x >9 )
    				y= std::stoi(result.substr(4,result.length()));
    			else
    				y= std::stoi(result.substr(3,result.length()));	
    			vekt->push_back(new Berserk(tempId,x,y));
    		}
    		else if(result[0] == 'T')
    		{
    			result=result.substr(result.find("e")+4,result.length());
    			x= std::stoi( result.substr(0,result.find(":") ) );
    			if(x >9 )
    				y= std::stoi(result.substr(4,result.length()));
    			else
    				y= std::stoi(result.substr(3,result.length()));		    		
    			Player * ss= new Tracer(tempId,x,y);
    			vekt->push_back(ss);
    		}
    		else if(result[0] == 'D')
    		{   result=result.substr(result.find("y")+3,result.length());
    			x= std::stoi( result.substr(0,result.find(":") ) );
    			if(x >9 )
    				y= std::stoi(result.substr(4,result.length()));
    			else
    				y= std::stoi(result.substr(3,result.length()));	
    			vekt->push_back(new Dummy(tempId,x,y));
    		}  		
    		else if(result[0] == 'P')
    		{
    			result=result.substr(result.find("t")+3,result.length());
    			x= std::stoi( result.substr(0, result.find(":") ) );
    			if(x >9 )
    				y= std::stoi(result.substr(4,result.length()));
    			else
    				y= std::stoi(result.substr(3,result.length()));	
    			vekt->push_back(new Pacifist(tempId,x,y));
    		}
    		else if(result[0] == 'A')
    		{   
    			result=result.substr(result.find("r")+3,result.length());
    			x= std::stoi(result.substr(0,result.find(":")) );
    			if(x >9 )
    				y= std::stoi(result.substr(4,result.length()));
    			else
    				y= std::stoi(result.substr(3,result.length()));		    	
	    		vekt->push_back(new Ambusher(tempId,x,y));
	    	}
	    }
    	i++;
    	if(i > pikaunt+5)
    		break; 
	}
	fayl.close();
	return (std::make_pair(siz,vekt));
}
