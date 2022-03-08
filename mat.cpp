#include <iostream>
#include <string>
#include "mat.hpp"

using namespace std;
namespace ariel{
    string mat(int col, int row, char one, char two){
        if (col % 2 == 0) { 
            return "ok";
        }    
        return "not ok";
    }
}