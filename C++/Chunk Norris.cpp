#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <sstream>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    std::string MESSAGE;
    std::getline(std::cin, MESSAGE);

    std::string RESULT;
    short currentGroup = -1; //the current group. Uses boolean to conserve space.
    for (char c : MESSAGE)
    {
      std::bitset<7> c_bit(c); //the bitset used for this. The standard library provides, I'll happily use.
      int index = c_bit.size() - 1;

      for (bool bit = c_bit[index]; index >= 0; bit = c_bit[--index]) //use this to access individual bits
      {
        if (currentGroup != bit) //if the currentGroup is not the correct bit
        {
          if (currentGroup != -1)
            RESULT.append(" ");

          switch(bit)
          {
            case 0:
              RESULT.append("00 ");
              break;
            case 1:
              RESULT.append("0 ");
              break;
          }
          currentGroup = bit;
        }
        RESULT.append("0"); //appends the 0.
      }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    std::cout << RESULT << std::endl;
}