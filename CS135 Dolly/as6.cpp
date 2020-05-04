/* File: as5.cpp
*
*  Name: 
*
*  Input: The input of this program utiilized a lot of resources of assignment 4. However, this assignment testing our
*         ability to use infile and outfile to create a program that read in a file and printed out a file with
*         certain values in play. Specifically calucations in this assignemnt
*  
*  Output: The output of this program displays a calculation table that allows people to enter certain units and have it 
*          print out the needed materials and the correct units to achieve construction. Even the amount of dump trucks needed
*
*/

/* Algorithm: 
*  1. Created program with main
*  2. Added if statement to determine yes or no to open all files
*  3. If no allowed them to enter number of how many to process
*  4. If yes all recordings would be processed
*  5. Used while loops to look recordings
*  6. Used switch statements to create different cases
*  7. used else if for the "no" segment
*  8. Outputted errors if any occured during processing
*  9. Did not print out anything if an incorrect input file was not entered.
*/



#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

    double surfaceArea, Volume, Height, STVR, b;   
    int err = 0, x = 1, y = 0, rOnly = 0, intrType;;
    string fName;
    string lName;
    string rType;
    string in;
    string out;
    double amount, tCount, tReq;
    char answer;
    ifstream infile;
    ofstream ofile;
    
    cout << " " << endl;
    cout << "****************************************************" << endl;
    cout << "Welcome to Slate Rock and Gravel Delivery Calculator" << endl;
    cout << "****************************************************" << endl;
    cout << " " << endl;
    
    cout << "Enter file name to process: ";
    cin >> in;
    infile.open(in);
    if(infile.is_open() == false) {
        cout << "Error opening file" << endl;
        
        return 0;
    }
    
    cout << "Enter output file name: ";
    cin >> out;
    ofile.open(out);

    cout << "Would you like to process all the records in the file? (y/n) ";
    cin >> answer;
    if (answer == 'n') {
        cout << "Enter number of records to process: ";

        cin >> rOnly;
        if(cin.fail()) {
            while(cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "XXXXXXXXXX Errir 0 bib byneruc vakye detectedm try again" << endl;
                cout << "Enter number of records to process: ";
                cin >> answer;
            }
        }

    while (y < rOnly) {
        if(infile.eof()) {
            infile.close();
            cout << "End of File detected, " << x - 1 << " records read " << endl;
            ofile.close();
            if(err > 0) {
                cout << "****File contains errors****" << endl;
                cout << err << " Records with illegal values have been detected." << endl;
                cout << "Please check file " << out << " for flagged records" << endl;
            }
            
            break;
        }
        else {
            cout << "Record: " << setw(5) << x << endl;
            infile >> fName;
            cout << fName << " ";
            
            infile >> lName;
            cout << lName << " ";
        
            infile >> rType;
            cout << rType << " ";

            if (rType == "PentagonalPyramid") {
                intrType = 0;
            }
            else if (rType == "PentagonalBipyramid") {
                intrType = 1;
            }
            else if (rType == "GyroelongatedSquareDipyramid") {
                intrType = 2;
            }
            else if (rType == "Gyrobifastigium") {
                intrType = 3;
            }
            else if (rType == "ElongatedPentagonalPyramid") {
                intrType = 4;
            }

            infile >> b;
            cout << "Size: " << b;

            infile >> amount;
            cout << "Qty: " << b;
            switch (intrType) {
                case(0):
                    if (2.00 < b && b < 500.00) {
                        cout << "-----------------------------------" << endl;
                        cout << "Calucation for a Pentagonal Pyramid" << endl;
                        cout << fixed << setprecision(2) << "Edge Length: " << b << endl;
                        cout << "-----------------------------------" << endl;

                        surfaceArea = (sqrt(25+10*sqrt(5))/4+5*sqrt(3)/4)*pow(b,2);
                        Volume = (5+sqrt(5))/24*pow(b,3);
                        Height = sqrt((5-sqrt(5))/10)*b;
                        STVR = (surfaceArea/Volume);
                        tCount = amount*Volume/27;
                        tReq = tCount/1250;

                        cout << "Surface Area: " << surfaceArea << " Square feet" << endl;
                        cout << "Volume: " << Volume << " Cubic feet" << endl;
                        cout << "Height: " << Height << " feet" << endl;
                        cout << setprecision(3) << "Surface to Volume Ratio: " << STVR << endl;
                        cout << "Order total volume require for delivery: " << tCount << " Cubic Yards" << endl;
                        cout << setprecision(0) << "Bronto-Dump trucks required: " << tReq;
                        cout << " " << endl;
                        
                        ofile << "Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " ";
                        ofile << " Surface Area: " << surfaceArea << " Square feet " << " Volume: " << Volume << " Cubic feet " << " Height: " << Height << " feet ";
                        ofile << " Surface to Volume Ratio: " << STVR << " Order total volume require for delivery: " << tCount << " Cubic Yards ";
                        ofile << " Bronto-Dump trucks required: " << tReq << endl;

                        break;
                    }
                    else {
                        ofile << "Error edge length--- Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " " << endl;
                        err=+1;
                        cout << "*********************************************************" << endl;
                        cout << "Error - edge length out of range" << endl;
                        cout << "Edge length specified: " << b << " Valid range is between 2.00 and 500.00" << endl;
                        cout << "*********************************************************" << endl;
                        
                        break;
                    }

                case(1):
                     if (1.00 < b && b < 750.00) {
                        cout << "-------------------------------------" << endl;
                        cout << "Calucation for a Pentagonal Bipyramid" << endl;
                        cout << fixed << setprecision(2) << "Edge Length: " << b << endl;
                        cout << "-------------------------------------" << endl;

                        surfaceArea = 5*sqrt(3)/2*pow(b,2);
	            		Volume = (5+sqrt(5))/12*pow(b,3);
			            Height = 2*sqrt((5-sqrt(5))/10) * b;
			            STVR = (surfaceArea/Volume);
                        tCount = amount*Volume/27;
                        tReq = tCount/1250;

                        cout << "Surface Area: " << surfaceArea << " Square feet" << endl;
                        cout << "Volume: " << Volume << " Cubic feet" << endl;
                        cout << "Height: " << Height << " feet" << endl;
                        cout << setprecision(3) << "Surface to Volume Ratio: " << STVR << endl;
                        cout << "Order total volume require for delivery: " << tCount << " Cubic Yards" << endl;
                        cout << setprecision(0) << "Bronto-Dump trucks required: " << tReq;
                        cout << " " << endl;
                        
                        ofile << "Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " ";
                        ofile << " Surface Area: " << surfaceArea << " Square feet " << " Volume: " << Volume << " Cubic feet " << " Height: " << Height << " feet ";
                        ofile << " Surface to Volume Ratio: " << STVR << " Order total volume require for delivery: " << tCount << " Cubic Yards ";
                        ofile << " Bronto-Dump trucks required: " << tReq << endl;

                        break;
                    }
                    else {
                        ofile << "Error edge length--- Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " " << endl;
                        err=+1;
                        cout << "*********************************************************" << endl;
                        cout << "Error - edge length out of range" << endl;
                        cout << "Edge length specified: " << b << " Valid range is between 2.00 and 500.00" << endl;
                        cout << "*********************************************************" << endl;
                        
                        break;
                    }
                case(2):
                     if (7.00 < b && b < 1502.00) {
                        cout << "----------------------------------------------" << endl;
                        cout << "Calucation for a Gyrolongated Square Dipyramid" << endl;
                        cout << fixed << setprecision(2) << "Edge Length: " << b << endl;
                        cout << "----------------------------------------------" << endl;

                      	surfaceArea = 4*sqrt(3)*pow(b,2);
			            Volume = (sqrt(2)+sqrt(4+3*sqrt(2)))/3*pow(b,3);
			            Height = (sqrt(1-1/(2+sqrt(2)))+2/sqrt(2))*b;
	            		STVR = (surfaceArea/Volume);
                        tCount = amount*Volume/27;
                        tReq = tCount/1250;

                        cout << "Surface Area: " << surfaceArea << " Square feet" << endl;
                        cout << "Volume: " << Volume << " Cubic feet" << endl;
                        cout << "Height: " << Height << " feet" << endl;
                        cout << setprecision(3) << "Surface to Volume Ratio: " << STVR << endl;
                        cout << "Order total volume require for delivery: " << tCount << " Cubic Yards" << endl;
                        cout << setprecision(0) << "Bronto-Dump trucks required: " << tReq;
                        cout << " " << endl;
                        
                        ofile << "Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " ";
                        ofile << " Surface Area: " << surfaceArea << " Square feet " << " Volume: " << Volume << " Cubic feet " << " Height: " << Height << " feet ";
                        ofile << " Surface to Volume Ratio: " << STVR << " Order total volume require for delivery: " << tCount << " Cubic Yards ";
                        ofile << " Bronto-Dump trucks required: " << tReq << endl;

                        break;
                    }
                    else {
                        ofile << "Error edge length--- Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " " << endl;
                        err=+1;
                        cout << "*********************************************************" << endl;
                        cout << "Error - edge length out of range" << endl;
                        cout << "Edge length specified: " << b << " Valid range is between 2.00 and 500.00" << endl;
                        cout << "*********************************************************" << endl;
                        
                        break;
                    }
                case(3):
                    if (0.00 < b && b < 1740.00) {
                        cout << "--------------------------------" << endl;
                        cout << "Calucation for a Gyrobifastigium" << endl;
                        cout << fixed << setprecision(2) << "Edge Length: " << b << endl;
                        cout << "--------------------------------" << endl;
                        
                        surfaceArea = (4+sqrt(3))*pow(b,2);
		            	Volume = sqrt(3)/2*pow(b,3);
			            Height = sqrt(3) * b;
		            	STVR = (surfaceArea/Volume);
                        tCount = amount*Volume/27;
                        tReq = tCount/1250;

                        cout << "Surface Area: " << surfaceArea << " Square feet" << endl;
                        cout << "Volume: " << Volume << " Cubic feet" << endl;
                        cout << "Height: " << Height << " feet" << endl;
                        cout << setprecision(3) << "Surface to Volume Ratio: " << STVR << endl;
                        cout << "Order total volume require for delivery: " << tCount << " Cubic Yards" << endl;
                        cout << setprecision(0) << "Bronto-Dump trucks required: " << tReq;
                        cout << " " << endl;
                        
                        ofile << "Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " ";
                        ofile << " Surface Area: " << surfaceArea << " Square feet " << " Volume: " << Volume << " Cubic feet " << " Height: " << Height << " feet ";
                        ofile << " Surface to Volume Ratio: " << STVR << " Order total volume require for delivery: " << tCount << " Cubic Yards ";
                        ofile << " Bronto-Dump trucks required: " << tReq << endl;

                        break;
                    }
                    else {
                        ofile << "Error edge length--- Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " " << endl;
                        err=+1;
                        cout << "*********************************************************" << endl;
                        cout << "Error - edge length out of range" << endl;
                        cout << "Edge length specified: " << b << " Valid range is between 2.00 and 500.00" << endl;
                        cout << "*********************************************************" << endl;
                        
                        break;
                    }


                case(4):
                    if (0.52 < b && b < 2751.00) {
                        cout << "--------------------------------------------------------" << endl;
                        cout << "Calucation for a Elongated Pentagonal Pyramid Calculator" << endl;
                        cout << fixed << setprecision(2) << "Edge Length: " << b << endl;
                        cout << "--------------------------------------------------------" << endl;

			            surfaceArea = (sqrt(25+10*sqrt(5)) / 4+5*sqrt(3)/4+5)*pow(b,2);
            			Volume = ((5+sqrt(5))/24+sqrt(25+10*sqrt(5))/4)*pow(b,3);
			            Height = (sqrt((5-sqrt(5))/10)+1)*b;
            			STVR = (surfaceArea/Volume);
                        tCount = amount*Volume/27;
                        tReq = tCount/1250;

                        cout << "Surface Area: " << surfaceArea << " Square feet" << endl;
                        cout << "Volume: " << Volume << " Cubic feet" << endl;
                        cout << "Height: " << Height << " feet" << endl;
                        cout << setprecision(3) << "Surface to Volume Ratio: " << STVR << endl;
                        cout << "Order total volume require for delivery: " << tCount << " Cubic Yards" << endl;
                        cout << setprecision(0) << "Bronto-Dump trucks required: " << tReq;
                        cout << " " << endl;
                        
                        ofile << "Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " ";
                        ofile << " Surface Area: " << surfaceArea << " Square feet " << " Volume: " << Volume << " Cubic feet " << " Height: " << Height << " feet ";
                        ofile << " Surface to Volume Ratio: " << STVR << " Order total volume require for delivery: " << tCount << " Cubic Yards ";
                        ofile << " Bronto-Dump trucks required: " << tReq << endl;

                        break;
                    }
                    else {
                        ofile << "Error edge length--- Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " " << endl;
                        err=+1;
                        cout << "*********************************************************" << endl;
                        cout << "Error - edge length out of range" << endl;
                        cout << "Edge length specified: " << b << " Valid range is between 2.00 and 500.00" << endl;
                        cout << "*********************************************************" << endl;
                        
                        break;
                    }
                case('q'):
                case('Q'):
                    cout << "Quitting..." << endl;
                    
                    break;
                default:
                    cout << "Error - invalid entry" << endl;
                    
                    break;
                }

                cout << " " << endl;
                x=+1;
                y=+1;
            }
        }
    }
    else if (answer == 'y') {
        while (!infile.eof()) {
            cout << "Record: " << setw(5) << x << endl;
            infile >> fName;
            cout << fName << " ";
            
            infile >> lName;
            cout << lName << " ";
        
            infile >> rType;
            cout << rType << " ";

            if (rType == "PentagonalPyramid") {
                intrType = 0;
            }
            else if (rType == "PentagonalBipyramid") {
                intrType = 1;
            }
            else if (rType == "GyroelongatedSquareDipyramid") {
                intrType = 2;
            }
            else if (rType == "Gyrobifastigium") {
                intrType = 3;
            }
            else if (rType == "ElongatedPentagonalPyramid") {
                intrType = 4;
            }

            infile >> b;
            cout << "Size: " << b;

            infile >> amount;
            cout << "Qty: " << b;
            switch (intrType) {
                case(0):
                    if (2.00 < b && b < 500.00) {
                        cout << "-----------------------------------" << endl;
                        cout << "Calucation for a Pentagonal Pyramid" << endl;
                        cout << fixed << setprecision(2) << "Edge Length: " << b << endl;
                        cout << "-----------------------------------" << endl;

                        surfaceArea = (sqrt(25+10*sqrt(5))/4+5*sqrt(3)/4)*pow(b,2);
                        Volume = (5+sqrt(5))/24*pow(b,3);
                        Height = sqrt((5-sqrt(5))/10)*b;
                        STVR = (surfaceArea/Volume);
                        tCount = amount*Volume/27;
                        tReq = tCount/1250;

                        cout << "Surface Area: " << surfaceArea << " Square feet" << endl;
                        cout << "Volume: " << Volume << " Cubic feet" << endl;
                        cout << "Height: " << Height << " feet" << endl;
                        cout << setprecision(3) << "Surface to Volume Ratio: " << STVR << endl;
                        cout << "Order total volume require for delivery: " << tCount << " Cubic Yards" << endl;
                        cout << setprecision(0) << "Bronto-Dump trucks required: " << tReq;
                        cout << " " << endl;
                        
                        ofile << "Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " ";
                        ofile << " Surface Area: " << surfaceArea << " Square feet " << " Volume: " << Volume << " Cubic feet " << " Height: " << Height << " feet ";
                        ofile << " Surface to Volume Ratio: " << STVR << " Order total volume require for delivery: " << tCount << " Cubic Yards ";
                        ofile << " Bronto-Dump trucks required: " << tReq << endl;

                        break;
                    }
                    else {
                        ofile << "Error edge length--- Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " " << endl;
                        err=+1;
                        cout << "*********************************************************" << endl;
                        cout << "Error - edge length out of range" << endl;
                        cout << "Edge length specified: " << b << " Valid range is between 2.00 and 500.00" << endl;
                        cout << "*********************************************************" << endl;
                        
                        break;
                    }

                case(1):
                     if (1.00 < b && b < 750.00) {
                        cout << "-------------------------------------" << endl;
                        cout << "Calucation for a Pentagonal Bipyramid" << endl;
                        cout << fixed << setprecision(2) << "Edge Length: " << b << endl;
                        cout << "-------------------------------------" << endl;

                        surfaceArea = 5*sqrt(3)/2*pow(b,2);
	            		Volume = (5+sqrt(5))/12*pow(b,3);
			            Height = 2*sqrt((5-sqrt(5))/10) * b;
			            STVR = (surfaceArea/Volume);
                        tCount = amount*Volume/27;
                        tReq = tCount/1250;

                        cout << "Surface Area: " << surfaceArea << " Square feet" << endl;
                        cout << "Volume: " << Volume << " Cubic feet" << endl;
                        cout << "Height: " << Height << " feet" << endl;
                        cout << setprecision(3) << "Surface to Volume Ratio: " << STVR << endl;
                        cout << "Order total volume require for delivery: " << tCount << " Cubic Yards" << endl;
                        cout << setprecision(0) << "Bronto-Dump trucks required: " << tReq;
                        cout << " " << endl;
                        
                        ofile << "Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " ";
                        ofile << " Surface Area: " << surfaceArea << " Square feet " << " Volume: " << Volume << " Cubic feet " << " Height: " << Height << " feet ";
                        ofile << " Surface to Volume Ratio: " << STVR << " Order total volume require for delivery: " << tCount << " Cubic Yards ";
                        ofile << " Bronto-Dump trucks required: " << tReq << endl;

                        break;
                    }
                    else {
                        ofile << "Error edge length--- Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " " << endl;
                        err=+1;
                        cout << "*********************************************************" << endl;
                        cout << "Error - edge length out of range" << endl;
                        cout << "Edge length specified: " << b << " Valid range is between 2.00 and 500.00" << endl;
                        cout << "*********************************************************" << endl;
                        
                        break;
                    }
                case(2):
                     if (7.00 < b && b < 1502.00) {
                        cout << "----------------------------------------------" << endl;
                        cout << "Calucation for a Gyrolongated Square Dipyramid" << endl;
                        cout << fixed << setprecision(2) << "Edge Length: " << b << endl;
                        cout << "----------------------------------------------" << endl;

                      	surfaceArea = 4*sqrt(3)*pow(b,2);
			            Volume = (sqrt(2)+sqrt(4+3*sqrt(2)))/3*pow(b,3);
			            Height = (sqrt(1-1/(2+sqrt(2)))+2/sqrt(2))*b;
	            		STVR = (surfaceArea/Volume);
                        tCount = amount*Volume/27;
                        tReq = tCount/1250;

                        cout << "Surface Area: " << surfaceArea << " Square feet" << endl;
                        cout << "Volume: " << Volume << " Cubic feet" << endl;
                        cout << "Height: " << Height << " feet" << endl;
                        cout << setprecision(3) << "Surface to Volume Ratio: " << STVR << endl;
                        cout << "Order total volume require for delivery: " << tCount << " Cubic Yards" << endl;
                        cout << setprecision(0) << "Bronto-Dump trucks required: " << tReq;
                        cout << " " << endl;
                        
                        ofile << "Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " ";
                        ofile << " Surface Area: " << surfaceArea << " Square feet " << " Volume: " << Volume << " Cubic feet " << " Height: " << Height << " feet ";
                        ofile << " Surface to Volume Ratio: " << STVR << " Order total volume require for delivery: " << tCount << " Cubic Yards ";
                        ofile << " Bronto-Dump trucks required: " << tReq << endl;

                        break;
                    }
                    else {
                        ofile << "Error edge length--- Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " " << endl;
                        err=+1;
                        cout << "*********************************************************" << endl;
                        cout << "Error - edge length out of range" << endl;
                        cout << "Edge length specified: " << b << " Valid range is between 2.00 and 500.00" << endl;
                        cout << "*********************************************************" << endl;
                        
                        break;
                    }
                case(3):
                    if (0.00 < b && b < 1740.00) {
                        cout << "--------------------------------" << endl;
                        cout << "Calucation for a Gyrobifastigium" << endl;
                        cout << fixed << setprecision(2) << "Edge Length: " << b << endl;
                        cout << "--------------------------------" << endl;
                        
                        surfaceArea = (4+sqrt(3))*pow(b,2);
		            	Volume = sqrt(3)/2*pow(b,3);
			            Height = sqrt(3) * b;
		            	STVR = (surfaceArea/Volume);
                        tCount = amount*Volume/27;
                        tReq = tCount/1250;

                        cout << "Surface Area: " << surfaceArea << " Square feet" << endl;
                        cout << "Volume: " << Volume << " Cubic feet" << endl;
                        cout << "Height: " << Height << " feet" << endl;
                        cout << setprecision(3) << "Surface to Volume Ratio: " << STVR << endl;
                        cout << "Order total volume require for delivery: " << tCount << " Cubic Yards" << endl;
                        cout << setprecision(0) << "Bronto-Dump trucks required: " << tReq;
                        cout << " " << endl;
                        
                        ofile << "Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " ";
                        ofile << " Surface Area: " << surfaceArea << " Square feet " << " Volume: " << Volume << " Cubic feet " << " Height: " << Height << " feet ";
                        ofile << " Surface to Volume Ratio: " << STVR << " Order total volume require for delivery: " << tCount << " Cubic Yards ";
                        ofile << " Bronto-Dump trucks required: " << tReq << endl;

                        break;
                    }
                    else {
                        ofile << "Error edge length--- Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " " << endl;
                        err=+1;
                        cout << "*********************************************************" << endl;
                        cout << "Error - edge length out of range" << endl;
                        cout << "Edge length specified: " << b << " Valid range is between 2.00 and 500.00" << endl;
                        cout << "*********************************************************" << endl;
                        
                        break;
                    }


                case(4):
                    if (0.52 < b && b < 2751.00) {
                        cout << "--------------------------------------------------------" << endl;
                        cout << "Calucation for a Elongated Pentagonal Pyramid Calculator" << endl;
                        cout << fixed << setprecision(2) << "Edge Length: " << b << endl;
                        cout << "--------------------------------------------------------" << endl;

			            surfaceArea = (sqrt(25+10*sqrt(5)) / 4+5*sqrt(3)/4+5)*pow(b,2);
            			Volume = ((5+sqrt(5))/24+sqrt(25+10*sqrt(5))/4)*pow(b,3);
			            Height = (sqrt((5-sqrt(5))/10)+1)*b;
            			STVR = (surfaceArea/Volume);
                        tCount = amount*Volume/27;
                        tReq = tCount/1250;

                        cout << "Surface Area: " << surfaceArea << " Square feet" << endl;
                        cout << "Volume: " << Volume << " Cubic feet" << endl;
                        cout << "Height: " << Height << " feet" << endl;
                        cout << setprecision(3) << "Surface to Volume Ratio: " << STVR << endl;
                        cout << "Order total volume require for delivery: " << tCount << " Cubic Yards" << endl;
                        cout << setprecision(0) << "Bronto-Dump trucks required: " << tReq;
                        cout << " " << endl;
                        
                        ofile << "Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " ";
                        ofile << " Surface Area: " << surfaceArea << " Square feet " << " Volume: " << Volume << " Cubic feet " << " Height: " << Height << " feet ";
                        ofile << " Surface to Volume Ratio: " << STVR << " Order total volume require for delivery: " << tCount << " Cubic Yards ";
                        ofile << " Bronto-Dump trucks required: " << tReq << endl;

                        break;
                    }
                    else {
                        ofile << "Error edge length--- Record: " << x << " " << fName << " " << lName << " " << rType << " " << b << " " << amount << " " << endl;
                        err=+1;
                        cout << "*********************************************************" << endl;
                        cout << "Error - edge length out of range" << endl;
                        cout << "Edge length specified: " << b << " Valid range is between 2.00 and 500.00" << endl;
                        cout << "*********************************************************" << endl;
                        
                        break;
                    }
                case('q'):
                case('Q'):
                    cout << "Quitting..." << endl;
                    
                    break;
                default:
                    cout << "Error - invalid entry" << endl;
                    
                    break;
                
                }
                cout << " " << endl;
                x=+1;
            }
            
            cout << "End of file detected, " << x - 1 << " records read " << endl;
            ofile.close();
            if(err>0) {
                cout << "***file contains errors****" << endl;
                cout << err << " Records with illegal values have been detected." << endl;
                cout << "Please check file " << out << " for flagged records" << endl;
            }
        }
    
    
    cout << "File processing finished" << endl;
    cout << " " << endl;

    

    return 0;



}
