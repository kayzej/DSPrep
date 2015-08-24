//
//  tetris.h
//  Hwk3
//
//  Created by Jeffrey Kayzerman on 8/19/15.
//  Copyright (c) 2015 Jeffrey Kayzerman. All rights reserved.
//

#ifndef Hwk3_tetris_h
#define Hwk3_tetris_h

class tetris{
public:
    tetris();
    tetris( int aWidth );
    int get_width();
    void add_piece( char piece, int degree, int col );
    int remove_full_rows();
    void print() const;
    int get_max_height() const;
private:
    int width;
    int* heights;
    char** data;
};

#endif
