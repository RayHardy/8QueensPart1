


// queen.cpp : Defines the entry point for the application.
//
#include "queen.hpp"

#include <iostream>
using namespace std;

Queen * Queen::lastQueen = nullptr;
static int qc = 0;

// checking horizontally if it can attack
bool Queen::canAttack( const int r, const int c ) const
{
    if( _column == c ){
        return true;
    }
    if( _row    == r ){
         return true;
    }
    
    if( abs(_column-c) == abs(_row-r) ){
         return true;
    }
    
    return false;
}

// constructor for each Queen, set them all at row 1, and use i in for loop to create column
Queen::Queen( int col, Queen * ngh ) : _column( col ), _neighbor( ngh )
{
    _row = 1;
}


bool Queen::verifySolution( void )
{
    if( nullptr == next() )
    return true;
    
    for( Queen * tmp = next(); nullptr != tmp; tmp = tmp->next() )
    {
        if( tmp->canAttack( _row, _column ) )
        return false;
    }
    
    return next()->verifySolution();
}

// recursive method to move the queen up and down, the vector is passed and dereferenced,
bool Queen::move( queen_vec_t & v )
{
    // if the row is 1 move it up
    if( 1 == _row ){
        v[_row]++;
    }
    
    // checks to see if it hasNext by returning true of false, also 
    if( hasNext() && next()->move(v) ){
        return true;
    }
    
    v[_row]--;
    
    _row++;
    
    while( _row <= BOARD_SIZE && v[_row]>0 ) _row++;
    
    // move the queen up if its within the max row size.
    if( _row <= BOARD_SIZE )
    {
        v[_row]++;
    }
    // if not reset the row to 1
    else
    {
        _row = 1;
        return false;
    }
    
    // now check to see
    if( lastQueen->verifySolution() )
    {
        _print_solution();
        _print_qc();
    }
    
    // recursive call to move the queen up and down
    return move(v);
}

void Queen::_print_solution()
{
    for( Queen * tmp = lastQueen; nullptr != tmp; tmp = tmp->next() )
    {
        cout << tmp->_row << " " << tmp->_column << endl;
    }
    cout << endl << endl;
    
    qc++;
}

void Queen::_print_qc(){
    cout << "possible known solutions: " << qc << endl << endl;
}


