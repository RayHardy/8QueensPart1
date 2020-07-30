
//
//  main.cpp
//  8Queens
//
//  Created by Raymon Hardy on 3/8/18.
//  Copyright © 2018 Raymon Hardy. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;
#include "queen.hpp"

// main!
int main( int argc, const char * argv[] )
{
    // create a vector "v" with size of BOARD_SIZE + 1
    queen_vec_t v( BOARD_SIZE + 1 );
    
    // call for loop that will create a pointers to each queen
    for( int i = 1; i <= BOARD_SIZE; i++ )
    {
        Queen::lastQueen = new Queen( i, Queen::lastQueen );
    }
    
    // now that the queens point to each other call the move function on the last queen created. Pass the vector "v" to check each value
    Queen::lastQueen->move( v );
    
    // deletes all queens
    Queen * tmp;
    while( nullptr != Queen::lastQueen )
    {
        tmp = Queen::lastQueen;
        Queen::lastQueen = Queen::lastQueen->next();
        delete tmp;
    }
    
    
}






