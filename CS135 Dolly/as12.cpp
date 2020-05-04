/* File: as12.cpp
 *
 * Name: 
 *
 * Input: The input of this program includes a struct that we refer to
 *        and assure that our options are valid and our values are valid 
 *        for the parsed arguments. We use 2 functions besides main.
 *        The first function is displaying the count of command line arguments,
 *        and the second function runs various tests to check which arguments have
 *        truly valid options and have values, or valid options with no values, or 
 *        if an option is invalid. If there are no options, a message will be displayed.
 * 
 * Output: The outpout of this program simply outputs the raw argument vectors from linux,
 *         and separates them from the correctly parsed options and values. If there are no options,
 *         a message will be outputed. 
*/

#include <iostream>

using namespace std;

struct optionType{
    string option;
    string value;
    bool optionValid;
    bool valueValid;
};

bool getNextOption(int argc, char* argv[], optionType& opt  );
void printCmdArgs( int argc, char* argv[]);

int main(int argc, char* argv[] ){

    optionType myOptions;
    bool more = false;

    // print out the arguments as passed from Linux
    printCmdArgs( argc, argv );

    cout << endl;
    cout << "-------------------------" << endl;
    cout << "Parsed Options and Values" << endl;
    
    // process the arguments, one at a time.
    // loop repeats until more is set to false. 
    do{
         more = getNextOption( argc, argv, myOptions);
         if ( myOptions.optionValid ){
            cout << "option: " << myOptions.option ;
            if ( myOptions.valueValid )
                cout << " value: " << myOptions.value << endl;
            else
                cout << endl;
          }
    }while( more );
}

/* function: printCmdArgs()
 *
 * function_identifier: This function is used to print the raw arguments from the
 *                      command line and separate them accordingly              
 * 
 * parameters: This punctions parameters are void printCmdArgs( int argc, char* argv[])
 * 
 * return value: This function has no return value
*/

void printCmdArgs( int argc, char* argv[]) {

    //Output display message 
    cout << "Raw argv from Linux" << endl;
    //Outputs the number of command line arguments
    cout << "Command line argument count: " << argc << endl;

    //Declared variables
    string s;
    s = argv[0];

    //Displaying the initial ./a.out
    cout << "Arg #0 " << "[" << s << "]" << endl;

    //Displaying each respective argument after ./a.out
    for(int i = 1; i < argc; i++) {
        cout << "Arg #" << i << " " << "[" << argv[i] << "]" << endl;
    }

    //Return where called
    return;
}
               
/* function: getNextOption()
 *
 * function_identifier: This function is used to parse the arguments and filter
 *                      which arguments have truly valid options and have valid values,  
 *                      or valid options with no valid values, or if an option is invalid.
 * 
 * parameters: This punctions parameters are bool getNextOption(int argc, char* argv[], optionType& opt)
 * 
 * return value: The return value is true UNTIL the argument count and counter are equal, then it is set to false
*/
bool getNextOption(int argc, char* argv[], optionType& opt) {

    //Declared static variable
    static int counter = 0;

    /*This if statement tests if there is only ./a.out.
      This stops the program from outputting any parsed lines
      and displays a message that states there aren't any options
    */
    if(argc <= 1) {
        cout << "*There are no available options*" << endl << endl;

        opt.optionValid = false;
        opt.valueValid = false;

        return false;
    }
    /*This if statement executes once argc and counter are equal
     *This is so that there are not any issues with segmentation fault
     * and so that the function returns false once all arguments
     * have been processed
    */
    if(argc == counter) {
        opt.optionValid = false;
        opt.valueValid = false;

        return false;
    }

    //Declared variables
    string s;
    s = argv[counter];
    
    //Initially setting struct booleans to false
    opt.optionValid = false;
    opt.valueValid = false;

    //This tests if statement tests if the first character of the string is a hyphen
    if(s[0] == '-') {

        opt.optionValid = true;
        opt.option = s[1];

        //If the first character is a hyphen, this if statement tests if there is a 3rd character in the string
        if(s[2]) {

            opt.valueValid = true;
            opt.value = s.substr(2, s.length());

        }
        //This else if statement executes if there is no 3rd character 
        //in the string, BUT the next argument is a valid value for this option
        else if(argv[counter + 1] && argv[counter + 1][0] != '-') {
            opt.valueValid = true;
            opt.value = argv[counter + 1];
        }
    }

    //This if statement tests if the length of the string is less than 3 AND if it does NOT start with a hyphen
    //These are requirements for a option to be valid
    if(s.length() < 3 && s[0] != '-') {
        cout << "Error - invalid option " << s << endl;
        opt.optionValid = false;
    }

    //This counts up and is held by the declared static int
    counter++;

    //Return true to be processed again
    return true;
}
