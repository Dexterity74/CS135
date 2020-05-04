#include <iostream>
#include <string>
using namespace std;

struct myHobby{
    string favoriteHobby;
};

void output(myHobby& hobby);

int main() {

    myHobby hobby;
    
    output(hobby);

    return 0;
}

void output(myHobby& hobby) {

    hobby.favoriteHobby = "I like to ride dirtbikes";

    if(hobby.favoriteHobby == "I like to ride dirtbikes") {
        cout << hobby.favoriteHobby << endl;
        return;
    }
    else {
        cout << " error " << endl;
        exit(0);
    }
}