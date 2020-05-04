#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct station{
	string callsign;
	double frequency;
	string genre;
	string nowPlaying;
};


int main(int argc, char *argv[]){
	if (argc != 2){
		cout << "Usage: ./a.out [RADIO_FILENAME]" << endl;
		return 0;
	}

	station currentStation[15];
	string filename = argv[1];
	ifstream infile;
	infile.open(filename.c_str());
	string junk;
	double freq;

	if (!infile)
	{
		cout << "No reception. Hope you have an aux cable!" << endl;
		return 0;
	}

	for(int j = 0; j < 15; j++)
	{
		getline(infile, currentStation[j].callsign);
		infile >> currentStation[j].frequency;
		getline(infile, junk);
		getline(infile, currentStation[j].genre);
		getline(infile, currentStation[j].nowPlaying);
		getline(infile, junk);
	}
	infile.close();

	cout << "Enter a frequency" << endl;
	cin >> freq;
    bool test = true;

	/*
	TO DO:
	Find and print out the radio station
	based on the given frequency
	*/

    for(int i = 0; i < 15; i++) {
        if(freq != currentStation[i].frequency) {
            test = false;
        }
        else{
            test = true;
            break;
        }
    }
    
    if(!test) {
        while(!test) {
            cout << "Nothing but static\n";
            cout << "Try Again\n";
            cin >> freq;
            for(int i = 0; i < 15; i++) {
                if(freq == currentStation[i].frequency) {
                    test = true;
                    break;
                }
            }
        }
    }
    if(test == true) {
        for(int i = 0; i < 15; i++) {
            if(freq == currentStation[i].frequency) {
                cout << "Now Playing: " << currentStation[i].nowPlaying << endl;
                cout << "Station Type: " << currentStation[i].genre << endl;
                cout << "Callsign: " << currentStation[i].callsign << endl;
                break;
            }
        }
    }
    
	return 0;
}
