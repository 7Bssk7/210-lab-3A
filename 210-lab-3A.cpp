// COMSC-210 | Lab 3A | Arkhip Fisnki
// IDE used: Visual Studio Code

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int NUM_RESTAURANTS = 4;

//Restaurant structure, inside includes name, address, rating, capacity of people and status (open or closed).
struct Restaurant{
    string name;
    string address;
    double rating;
    int capacity;
    bool isOpen;
};

Restaurant Place();
void outputR(const Restaurant &);

int main(){
    //Vector for storing information about restaurants entered by the user.
    vector<Restaurant> places;

    for(int i = 0; i < NUM_RESTAURANTS; ++i){
        cout << "Enter the information about Restaurant #" << i + 1 << endl;
        places.push_back(Place());
    }
    //Outputting every element stored in the vector
    for( int i = 0; i < NUM_RESTAURANTS; ++i){
        cout << "Outputting information about Restaurant #" << i + 1 << endl;

        outputR(places.at(i));
    }

    return 0;
}

//Function that reads users inputs from the console 
//Returns: Restaurant's data type with information provided by the user
Restaurant Place(){
    Restaurant temp;
    char status;
    
    cout << "Enter the Name of the Restaurant: ";
    getline(cin, temp.name);
    cout << "Enter the address of the Restaurant: ";
    getline(cin, temp.address);
    cout << "Enter the Rating of the Restaurant(1-5): ";
    cin >> temp.rating;
    while((temp.rating < 1) || (temp.rating > 5)){
        cout << "Invalid input, Rating of the Restaurant must be in the range between 1 and 5." << endl;
        cout << "Enter the Rating of the Restaurant(1-5): ";
        cin >> temp.rating;
    }
    cout<< "Enter the Maximum Capacity of the Restaurant(number must be greater than 0): ";
    cin >> temp.capacity;
    while(temp.capacity <= 0){
        cout << "Invalid input, please answer the question again!"<< endl;
        cout << "Enter the Maximum Capacity of the Restaurant(number must be greater than 0): ";
        cin >> temp.capacity;
    }
    cout << "Is the Restaurant Currently Open(y - yes, it is open|n - no, it is closed): ";
    cin >> status;
    status = tolower(status);
    while((status != 'n') && (status != 'y')){
        cout << "Invalid input, please answer the question again!" << endl;
        cout << "Is the Restaurant Currently Open(y - yes, it is open|n - no, it is closed): ";
        cin >> status;
        
        status = tolower(status);
    }
    if(status == 'y'){
        temp.isOpen = true;
    }
    else{
        temp.isOpen = false;
    }
    cin.ignore();
    cout << "\n";

    return temp;
}

//Function that outputs users inputs 
//Argument: const Restaurant &r, gets the data of type restaurant(for display), which cannot be edited 
void outputR(const Restaurant &r){
    cout << "Restaurant: " << r.name << endl;
    cout << "Restaurant's Address: " << r.address << endl;
    cout << "Restaurant's Rating: " << r.rating << endl;
    cout << "Restaurant's Capacity: " << r.capacity << endl;
    cout << "Is Restaurant is currently open: ";
    if(r.isOpen == 1){
        cout << "Yes! It's open." << endl;
    }
    else{
        cout << "No. It's closed" << endl;
    }
    cout << "\n";

}