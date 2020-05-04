#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(int argc, char **argv)
{

  ifstream infile;
  string filename;

  if (argc < 2)
    {
      cout << "Not enough arguments" << endl;
      return 0;
    }

  infile.open("input.txt");
  if(infile.is_open() == false)
    {
      cout << "Error opening file" << endl;
      return 0;
    }

  string input;
  string anagram = argv[1];
  int match_count = 0;

  while (infile >> input)
    {
      if (anagram.length() != input.length())
	  cout << input << " is not an anagram" << endl;
      
      for (int i = 0; i < anagram.length(); i++)
		for (int j = 0; j < input.length(); j++)
			if (anagram[i] == input[j])
				match_count++;

      if (match_count != anagram.length())
		  cout << input << " is not an anagram" << endl;
      else
          cout << input << " is an anagram" << endl;
          match_count = 0;
    }

}