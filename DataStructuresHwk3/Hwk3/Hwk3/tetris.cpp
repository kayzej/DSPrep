//
//  tetris.cpp
//  Hwk3
//
//  Created by Jeffrey Kayzerman on 8/19/15.
//  Copyright (c) 2015 Jeffrey Kayzerman. All rights reserved.
//

#include "tetris.h"
#include <iostream>
#include <cassert>

char** new_piece;

tetris::tetris()
{
    width = 6;
    heights = new int[width];
    data = new char*[width];
}

tetris::tetris( int aWidth )
{
    width = aWidth;
    heights = new int[width]();
    data = new char*[width];
}

int tetris::get_width()
{
    return width;
}

void tetris::add_piece( char piece, int degree, int col )
{
    //Storing old values
    int* old_heights = heights;
    char** old_data  = data;
    int piece_width  = 0;
    
    int max_height = old_heights[col];
    for(unsigned int i=col+1; i<col+piece_width; ++i)
        max_height = (heights[i] > max_height) ? heights[i] : max_height;
    
    //I { 'I', 'I', 'I', 'I' } || { {'I'}, {'I'} ...
    if( piece == 'I' )
    {
        if(degree == 0 || degree % 180 == 0)
        {
            piece_width = 1;
            heights[col] = max_height + 4;
            
            //New array with only one row
            new_piece = new char*[1];
            
            //New array with 4 rows representing the columns
            new_piece[0] = new char[4];
            for(unsigned int i=0; i<4; ++i)
                new_piece[0][i] = 'I';
        } else
        {
            piece_width  = 4;
            new_piece = new char*[4];
            
            for(unsigned int i=0; i<4; ++i)
            {
                heights[i] += 4;
                new_piece[i] = new char[1];
                new_piece[i][0] = 'I';
            }
        }
    }
    
    std::cout << "well hello there" << std::endl;
    
    for(int i=col; i<col + piece_width; ++i)
    {
        data[i] = new char[heights[i]]();
        
        std::cout << "setting old data" << std::endl;
        
        for(int j=0; j<old_heights[i]; ++j)
        {
            data[i][j] = old_data[i][j];
            std::cout << "i: " << i << " j: " << j << " " << data[i][j] <<std::endl;
        }

        std::cout << "setting new data old_heights: " << old_heights[i] << "new_heights: " << heights[i] << " " << std::endl;
        
        for(unsigned int j=old_heights[i]; j<heights[i]; ++j)
        {
            data[i][j] = new_piece[i-col][j-old_heights[i]];
            std::cout << "i: " << i << " j: " << j << " " << data[i][j] <<std::endl;
        }
    }
    
    //O
//    if( piece == 'O')
//    {
//        piece_width = 2;
//        char new_piece[2][2] = { {'O', 'O'},
//                                   {'O', 'O'} };
//    }
}

    
//        //There are only two orientations, straight up or flat
//        if (degree == 0 || degree % 180 == 0)
//        {
//            //Setting new values
//            heights[col] += 4;
//            data[col] = new char[heights[col]];
//            
//            for(unsigned int i=0; i<old_heights[col]; ++i)
//                data[col][i] = old_data[col][i];
//                
//            for(unsigned int i=old_heights[col]; i<heights[col]; ++i)
//                data[col][i] = piece;
//        }
//        else
//        {
//            //Looping through the affected cols and finding the maximum height
//            int max_height=heights[col];
//            for( unsigned int i=col+1; i<col+4; i++)
//                max_height = (heights[i] > max_height) ? heights[i] : max_height;
//            
//            //Looping through affected cols and setting appropriate values for heights
//            for( unsigned int i=col; i<col+4; ++i)
//            {
//                //Storing old values
//                int old_height = heights[i];
//                char *old_values = data[i];
//                
//                //Declaring new values
//                heights[i] = max_height+1;
//                data[i] = new char[max_height+1]();
//                
//                //Setting new characters
//                for(unsigned int j=0; j<old_height; ++j)
//                    data[i][j] = old_values[j];
//                
//                data[i][max_height] = piece;
//            }
//            
//        }
//    }
    
//    for( int i=0; i<prev_height; ++i)
//        data[col][i] = temp[i];
//    
//    for( int i=prev_height; i<heights[col]; ++i)
//        data[col][i] = true;

int tetris::remove_full_rows()
{
    return 0;
}

int tetris::get_max_height() const
{
    int max = heights[0];
    
    for(unsigned int i=1; i<width; ++i)
        max = (heights[i]>max) ? heights[i] : max;
           
    return max;
}

// ======================================================================
// ======================================================================
// This helper function prints an ASCII representation of the tetris board.
//
// NOTE: Normally this function would be placed in tetris.cpp, the
// implementation file for the tetris class.  Because we provide this
// function to you, we are placing it in the main.cpp file.

void tetris::print() const
{
    
    std::cout << std::endl;
    
    // This tetris member function returns the height of the tallest
    // column on the board
    int max_height = get_max_height();
    
    // print each row of the board, from top to bottom
    for (int h = max_height-1; h >= 0; h--) {
        for (int w = 0; w < width; w++) {
            if (h < heights[w]) {
                std::cout << data[w][h];
            } else {
                // print a blank if this column is shorter than the current height
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
    
    // print a horizontal bar of appropriate length at the bottom of the board
    std::cout << std::string (width,'-') << std::endl;
    
    // print out the column height,
    // if the height is 2 digits, print them vertically
    
    // this only works for a maximum of 99 rows!
    assert (max_height <= 99);
    
    // print out the tens digit (if necessary)
    if (max_height > 9) {
        for (int w = 0; w < width; w++) {
            if (heights[w] > 9)
                std::cout << heights[w]/10;
            else
                std::cout << ' ';
        }
        std::cout << std::endl;
    }
    
    // print out the ones digit
    for (int w = 0; w < width; w++) {
        std::cout << heights[w]%10;
    }
    
    std::cout << std::endl << std::endl;
}

// ======================================================================
// ======================================================================


