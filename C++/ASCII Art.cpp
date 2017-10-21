/** Coding Game URL: https://www.codingame.com/ide/puzzle/ascii-art **/

#include <iostream>
#include <string>
#include <sstream>
#include <locale>
#include <vector>
#include <algorithm>

#define letterA 'a' //this constant will be used to identify the very first letter, A.

using namespace std;

int main()
{
  int L; //According to the game input, L
  cin >> L; cin.ignore();
  int H; //and H will always be the same. 0 < (L=H) < 30
  cin >> H; cin.ignore();
  string T; //This string will contain the string that I'm supposed to be printing
  getline(cin, T);

  unsigned int seeker = 0; //the seeker for the following array.
  int *letterMapping = new int[T.size()]; //creates a new letter mapping based on the string size.

  for (auto&& it : T)
  {
    it = tolower(it); //lowers the alphabet.

    if (it - letterA > 26 || it < letterA)
    {
      letterMapping[seeker++] = L * 26; //this SHOULD in theory get mapping to reach the question mark.
      continue; //it's not an alphabet! abort mission!
    }

    letterMapping[seeker++] = L * (it - letterA); //this will point the map to the correct ascii letter. Hopefully.
  }

  stringstream asciiArt; //the string that stores the ascii art.
  seeker = 0; //resets the seeker.

  for (int i = 0; i < H; i++)
  {
    string ROW; //Gets the ASCII representation line by line.
    getline(cin, ROW);

    for (int current = letterMapping[0]; seeker < T.size(); current = letterMapping[++seeker]) //Loops through the letter mapping to figure out what to put into the asciiArt string stream.
      asciiArt << ROW.substr(current, L); //adds the row of ascii into the ascii art stream, and then adds a space behind.

    asciiArt << std::endl; //adds a line, preparing for the next wave for ascii.
    seeker = 0;
  }

  // Write an action using cout. DON'T FORGET THE "<< endl"
  // To debug: cerr << "Debug messages..." << endl;
  cout << asciiArt.str() << endl;
  delete[] letterMapping; //removes the array
}
