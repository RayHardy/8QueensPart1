//
//  queen.hpp
//  8Queens
//
//  Created by Raymon Hardy on 3/8/18.
//  Copyright © 2018 Raymon Hardy. All rights reserved.
//

//#ifndef queen_hpp
#define queen_hpp

#include <stdio.h>

#pragma once

#include <vector>

using namespace std;

// a variable that can be used anywhere #macro
#define BOARD_SIZE 8

// declares a vector of integers named queen_vec_t
typedef vector<int> queen_vec_t;

class Queen {
    
    public:
    // reference that points to the lastQueen created
    static Queen * lastQueen;
    
    // constructor
    Queen( int, Queen * );
    
    // Queen's functions
    bool verifySolution();
    bool move( queen_vec_t & v );
    
    // getters of column and row
    int returnColumn() const { return _column; }
    int returnRow()    const { return _row;    }
    
    // returns the Queens next Queen
    Queen * next()           { return _neighbor; }
    // Sees if the Queen has a lastQueen or if its null
    bool    hasNext()  const { return nullptr != _neighbor; }
    
    // sees if there is a Queen that will attack by passing in row and column
    bool canAttack( const int r, const int c ) const;
    // goes to the next row
    void advanceRow();
    
    
    private:
    // the Queens row can be moved
    // the Queens column cannot be moved
    // the Queen's neighbor
    
    // gives the Queen an initi
    int         _row;
    const int   _column;
    Queen     * _neighbor;
    
    void _print_solution();
    void _print_qc();
    
};

