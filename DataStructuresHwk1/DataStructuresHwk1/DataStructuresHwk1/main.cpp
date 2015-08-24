//
//  main.cpp
//  DataStructuresHwk1
//
//  Created by Jeffrey Kayzerman on 8/16/15.
//  Copyright (c) 2015 Jeffrey Kayzerman. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> replace( std::vector<std::string> pixels, char bad, char good)
{
    for( unsigned int i=0; i<pixels.size(); i++ )
    {
        for( unsigned int j=0; j<pixels[i].length(); j++ )
        {
            //bad is the char to be replaced, replace it or output the original char
            if( pixels[i][j] == bad )
                pixels[i][j] = good;
        }
    }
    
    return pixels;
}

std::vector<std::string> dilate( std::vector<std::string> pixels, char dilatee )
{
    std::vector<std::string> out(pixels);
    
    for( unsigned int i=1; i<pixels.size(); i++ )
    {
        for( unsigned int j=1; j<pixels[i].length(); j++ )
        {
            //If any of the surrounding pixels match, add the new pixel
            if(   pixels[i][j-1] == dilatee
               || pixels[i][j+1] == dilatee
               || pixels[i-1][j] == dilatee
               || pixels[i+1][j] == dilatee
              )
            {
                out[i][j] = dilatee;
            }
        }
    }
    
    return out;
}


std::vector<std::string> erode( std::vector<std::string> pixels, char erodee, char eroder )
{
    std::vector<std::string> out(pixels);
    
    //Looping through each character in each string and checking the surrounding pixels
    for( unsigned int i=1; i<pixels.size(); i++ )
    {
        for( unsigned int j=1; j<pixels[i].length(); j++ )
        {
            //If all of the surround pixels don't match the pixel must be removed
            if( !( pixels[i][j-1] == erodee
                && pixels[i][j+1] == erodee
                && pixels[i-1][j] == erodee
                && pixels[i+1][j] == erodee )
               )
            {
                out[i][j] = eroder;
            }
        }
    }
    
    return out;
}

std::vector<std::string> floodfill( std::vector<std::string> pixels, int row, int col, char replacee, char replacer )
{
    if( pixels[row][col] == replacee )
        pixels[row][col] = replacer;
    
    if( pixels[row - 1][col] == replacee)
        pixels = floodfill(pixels, row-1, col, replacee, replacer);
    
    if( pixels[row + 1][col] == replacee)
        pixels = floodfill(pixels, row+1, col, replacee, replacer);
    
    if( pixels[row][col+1] == replacee)
        pixels = floodfill(pixels, row, col+1, replacee, replacer);

    if( pixels[row][col-1] == replacee)
        pixels = floodfill(pixels, row, col-1, replacee, replacer);
    
    return( pixels );
}

int main(int argc, const char * argv[])
{
    //Reading input file and error checking
    std::ifstream input(argv[1]);
    if (!input.good())
    {
        std::cerr << "Can not open the input file " << argv[1] << "\n";
        return 1;
    }

    std::vector<std::string> pixels, out;
    
    std::string line;
    
    //Reading file into a vector of strings line by line
    while( getline(input, line) )
        pixels.push_back(line);
 
    if (pixels.size() == 0)
    {
        std::cout << "No pixels entered. Please try again!" << std::endl;
        return 1; // program exits with error code = 1
    }

    if( std::strcmp( argv[3], "replace" ) == 0 )
        out = replace( pixels, *argv[4], *argv[5]);
    
    if( std::strcmp( argv[3], "dilation" ) == 0 )
        out = dilate( pixels, *argv[4] );
    
    if( std::strcmp( argv[3], "erosion" ) == 0 )
        out = erode( pixels, *argv[4], *argv[5] );

    if( std::strcmp( argv[3], "floodfill" ) == 0 )
    {
        int start = atoi(argv[4]);
        int end   = atoi(argv[5]);
        
        char replacee = pixels[start][end];
        char replacer = *argv[6];
        
        out = floodfill(pixels, start, end, replacee, replacer );
    }
    
    std::ofstream output(argv[2]);
    
    if (!output.good())
    {
        std::cerr << "Can't open " << argv[2] << " to write.\n";
        exit(1);
    }
    
    //Outputting
    for( unsigned int i=0; i<out.size(); i++)
        output << out[i] << std::endl;

    return 0;
}