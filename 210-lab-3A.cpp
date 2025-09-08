#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

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
    Restaurant myRestaurant1 = Place();
    outputR(myRestaurant1);

    return 0;
}

//Function that reads users inputs from the console 
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
    cout<< "Enter the Maximum Capacity of the Restaurant: ";
    cin >> temp.capacity;
    cout << "Is Restaurant is Currently Open(y - yes, it is open|n - no, it is closed): ";
    cin >> status;
    status = tolower(status);
    while((status != 'n') && (status != 'y')){
        cout << "Invalid input, please answer the question again!" << endl;
        cout << "Is Restaurant is Currently Open(y - yes, it is open|n - no, it is closed): ";
        cin >> status;
        status = tolower(status);
    }
    if(status == 'y'){
        temp.isOpen = true;
    }
    else{
        temp.isOpen = false;
    }

    return temp;
}

//Function that outputs users inputs 
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

}