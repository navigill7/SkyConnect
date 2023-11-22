#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string.h>
#include <cstdlib>
using namespace std;
// class AirportNode{
//     public:
//     string Flight_code , city;
//     AirportNode *next;

//     AirportNode(string &Flight_code , string& city ): Flight_code(Flight_code) , city(city) , next(nullptr){}
// };
// class Airport{
//     AirportNode *head;
//     public :
//     void addFlight(string Flight_code , string city);
//     void DisplayAirport();
// };

// void Airport:: addFlight(string Flight_code , string city){
//     AirportNode * newAirport = new AirportNode(Flight_code , city);
//     newAirport->next = head;
//     head = newAirport;
// }

// void Airport:: DisplayAirport(){
//     AirportNode *p = head;
//     while(p!=nullptr){
//         cout<<"Airport Code : "<<p->Flight_code<<endl;
//         cout<<"City : "<<p->city<<endl;
//         cout<<"-----------------------------------------------------"<<endl;
//         p = p->next;
//     }
// }

class flightNode{
    public:
    string flightNumber , source , dest , brand , date , departuretime , arrivalTime ;
    int price , economic_seats ,  bc_seats , first_class_seats ;
    float rating;
    flightNode * next;

   flightNode(const string& fNumber, const string& source, const string& dest, const string& brand, const string& date, const string& departuretime, const string& arrivalTime, int price, int economic_seats, int bc_seats, int first_class_seats, float rating)
        : flightNumber(fNumber), source(source), dest(dest), brand(brand), date(date), departuretime(departuretime), arrivalTime(arrivalTime), price(price), economic_seats(economic_seats), bc_seats(bc_seats),first_class_seats(first_class_seats), rating(rating), next(nullptr) {}
};


class Flight {
    flightNode * head;

public:
    void addFlight(const string& fNumber, const string& source, const string& dest , const string& brand, const string& date, const string& departuretime, const string& arrivalTime,  int price, int economic_seats, int bussiness_class_seats, int first_class_seats, float rating);
    void display2();
    bool FlightsAvailable(const string& choice , int searchOption);
    void search_flight2(const string& choice , int searchOption);
    void book_ticket2();
    void calc2(string & flightNumber , int p , int s , int c1);
    void hotel();
    void info();
    
};
void Flight :: addFlight( const string& fNumber, const string& source, const string& dest, const string& brand, const string& date, const string& departuretime, const string& arrivalTime, int price, int economic_seats, int business_class_seats, int first_class_seats, float rating) {
        flightNode* newFlight = new flightNode(fNumber, source, dest, brand, date, departuretime, arrivalTime, price, economic_seats, business_class_seats, first_class_seats, rating);
        newFlight->next = head;
        head = newFlight;
}
void Flight ::  display2(){
    flightNode * current = head;
     // Get the current time
    time_t currentTime = time(nullptr);
    

    // Convert the current time to the local time
    tm* localTime = localtime(&currentTime);
     currentTime += 2 * 60 * 60;
    // Format the current date as a string
    char dateString[100];
    strftime(dateString, sizeof(dateString), "%Y-%m-%d", localTime);
     tm* adjustedTime = localtime(&currentTime);
      char timeString[100];
    strftime(timeString, sizeof(timeString), "%I:%M %p", adjustedTime);


    // Display the current date
    cout << "Current Date: " << dateString << endl;


    while(current !=nullptr){
        cout<<"Flight Number : "<<current->flightNumber<<endl;
        cout<<"Source : "<<current->source<<endl;
        cout<<"Destination : "<<current->dest<<endl;
        cout<<"Company : "<<current->brand<<endl;
        cout<<"Date : "<<dateString<<endl;
        cout<<"Departure Time : "<<current->departuretime<<endl;
        cout<<"Arrival Time : "<<current->arrivalTime<<endl;
        cout<<"Price : "<<current->price<<endl;
        cout<<"Economic Class Seats : "<<current->economic_seats<<endl;
        cout<<"Bussiness Class Seats : "<<current->bc_seats<<endl;
        cout<<"First Class Seats : "<<current->first_class_seats<<endl;
        cout<<"Rating : "<<current->rating<<endl;
        cout<<endl;
        cout<<"----------------------------------------------------------------------"<<endl;
        current = current->next;
    }
}


bool Flight:: FlightsAvailable(const string& choice, int searchOption) {
    flightNode* current = head;
    while (current != nullptr) {
        bool match = false;

        if (searchOption == 1) {
            match = (choice == current->source);
        } else if (searchOption == 2) {
            match = (choice == current->dest);
        } else if (searchOption == 3) {
            match = (choice == current->date);
        }

        if (match) {
            // Flights are found, return true
            return true;
        }

        current = current->next;
    }

    // No flights found
    return false;
}

void Flight::search_flight2(const string& choice, int searchOption) {
    flightNode* current = head;
    int temp;
    temp = 0;
    
    // Get the current time
    time_t currentTime = time(nullptr);
    

    // Convert the current time to the local time
    tm* localTime = localtime(&currentTime);
     currentTime += 2 * 60 * 60;
    // Format the current date as a string
    char dateString[100];
    strftime(dateString, sizeof(dateString), "%Y-%m-%d", localTime);
     tm* adjustedTime = localtime(&currentTime);
      char timeString[100];
    strftime(timeString, sizeof(timeString), "%I:%M %p", adjustedTime);


    // Display the current date
    cout << "Current Date: " << dateString << endl;


    while (current != nullptr) {
        bool match = false;

        if (searchOption == 1) {
            match = (choice == current->source);
        } else if (searchOption == 2) {
            match = (choice == current->dest);
        } else if (searchOption == 3) {
            match = (choice == current->date);
        }

        if (match) {
            cout << "Flight number : " << current->flightNumber << "\n";
            cout << "Starting from : " << current->source << "\n";
            cout << "Destination : " << current->dest << "\n";
            cout << "Company : " << current->brand << "\n";
            cout << "Date : " << current->date << "\n";
            cout << "Departure time : " << current->departuretime << "\n";
            cout << "Arrival time : " << current->arrivalTime << "\n";
            cout << "Price per ticket : " << current->price << "\n";
            cout << "Number of economy class seats available : " << current->economic_seats << "\n";
            cout << "Number of business class seats available : " << current->bc_seats << "\n";
            cout << "Number of first class seats available : " << current->first_class_seats << "\n";
            cout << "Rating : " << current->rating << "\n";
            cout << "\n";
            cout << "--------------------------------------------------\n";
            temp++;
        }
        current = current->next;
    }

    if (temp == 0) {
        cout << "Error! No flights found for the provided information.\n";
    }
}


void Flight :: book_ticket2(){
    flightNode *current = head;
    int ch;
    cout<<"You are right now on booking window : "<<endl;
    
    cout<<"------------------------------------------"<<endl;
    string fnumber ;
    cout<<"Enter the Flight Number of the flight you wish to book the ticket for : ";
    cin>>fnumber;
    cout<<endl;
    cout << "Press 1 if you want to book economy class tickets (No extra charge)\n";
    cout << "Press 2 if you want to book business class tickets (Rs.10000 extra per ticket)\n";
    cout << "Press 3 if you want to book first class tickets (Rs.15000 extra per ticket)\n";
    cout << "Enter your choice : ";
    cin >> ch;
    cout<<endl;
    while(current!=nullptr){
        if(current->flightNumber == fnumber){
            switch (ch)
            {
            case  1 :
                calc2(current->flightNumber , current->price , current->economic_seats , ch);
                break;
            case 2 :
                calc2(current->flightNumber , current->price , current->bc_seats , ch);
                break;
            case 3 :
               calc2(current->flightNumber , current->price , current->first_class_seats , ch);
               break;
            default:
                cout<<"Please Enter a Valid Number for your choice of seats !! "<<endl;
                break;
            }
        }
        current  = current->next;
    }

}




void Flight :: calc2(string& fNumber, int p, int s, int c1) {
    int n1, n2, n3, N;
    float p1, p2, p3, amt;

    flightNode* current = head;
    while (current != nullptr && current->flightNumber != fNumber) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Flight not found\n";
        return;
    }

    if (c1 == 1) {
        cout << "Number of economy class seats available : " << s << "\n";
    } else if (c1 == 2) {
        cout << "Number of business class seats available : " << s << "\n";
    } else if (c1 == 3) {
        cout << "Number of first class seats available : " << s << "\n";
    }
    cout << "\n";
    cout << "Enter the number of adults traveling (No discount) : ";
    cin >> n1;
    cout << "Enter the number of children (less than 18 years old) traveling (10% discount) : ";
    cin >> n2;
    cout << "Enter the number of senior citizens (above 65 years old) traveling (12.5% discount) : ";
    cin >> n3;
    cout << "\n";
    switch (c1) {
    case 1:
        p1 = n1 * p;
        p2 = n2 * (p - 0.1 * p);
        p3 = n3 * (p - 0.125 * p);
        amt = p1 + p2 + p3;
        N = n1 + n2 + n3;
        if (N <= s) {
            cout << "Booking successful\n";
            cout << "You have opted for economy class seats\n";
            cout << "Total number of seats : " << N << "\n";
            cout << "Total amount is : " << amt << "\n";
            cout << "\n";
            cout << "---------------------------------------------------\n";
        } else {
            cout << "Seats are not available\n";
        }
        break;
    case 2:
        p = p + 10000;
        p1 = n1 * p;
        p2 = n2 * (p - 0.1 * p);
        p3 = n3 * (p - 0.125 * p);
        amt = p1 + p2 + p3;
        N = n1 + n2 + n3;
        if (N <= s) {
            cout << "Booking successful\n";
            cout << "You have opted for business class seats\n";
            cout << "Total number of seats : " << N << "\n";
            cout << "Total amount is : " << amt << "\n";
            cout << "\n";
            cout << "---------------------------------------------------\n";
        } else {
            cout << "Seats not available\n";
        }
        break;
    case 3:
        p = p + 15000;
        p1 = n1 * p;
        p2 = n2 * (p - 0.1 * p);
        p3 = n3 * (p - 0.125 * p);
        amt = p1 + p2 + p3;
        N = n1 + n2 + n3;
        if (N <= s) {
            cout << "Booking successful\n";
            cout << "You have opted for first class seats\n";
            cout << "Total number of seats : " << N << "\n";
            cout << "Total amount is : " << amt << "\n";
            cout << "\n";
            cout << "---------------------------------------------------\n";
        } else {
            cout << "Seats not available\n";
        }
        break;
    default:
        cout << "Invalid input\n";
    }
}

void Flight::hotel() {
    int e = 0;
    char ch[30], city[30], hname[30], web[30], no[15];
    ifstream f4;
    f4.open("Hotels.txt", ios::in | ios::binary);
    if (!f4) {
        cout << "File cannot be opened\n";
    } else {
        do {
            cout << "Enter the city in which you wish to look for a hotel\n";
            cin >> ch;
            while (f4 >> city >> hname >> web >> no) {
                if (strcmp(ch, city) == 0) {
                    cout << "City : " << city << "\n";
                    cout << "Hotel Name : " << hname << "\n";
                    cout << "Hotel Website : " << web << "\n";
                    cout << "Hotel Contact Number : " << no << "\n";
                    cout << "\n";
                    cout << "--------------------------------------------------\n";
                }
            }
            cout << "Press 1 if you want to exit\n";
            cin >> e;
        } while (e != 1);
    }
    f4.close();
}

void Flight::info() {
    char code[5], city[30];
    ifstream f5;
    f5.open("FInfo.txt", ios::in | ios::binary);
    while (f5 >> code >> city) {
        cout << "Airport Code : " << code << "\n";
        cout << "City : " << city << "\n";
        cout << "\n";
        cout << "--------------------------------------------------\n";
    }
    f5.close();
}


int main() {
    int choice, choice2;
    string choice_str;
    int h;
    Flight flightList;
    // Airport Air;
    cout << "Welcome to SkyConnect " << endl;
    cout << "About : It is an online portal for booking Flight's And Accomodation for the city you are taking Flights to " << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    // cout<<"We are associated With these Airport In INDIA "<<endl;
    // ifstream input("Airport.txt");
    // if(!input.is_open()){
    //     cerr<<"Failed To Load The Data OF AIRPORT "<<endl;
    //     return -1;
    // }
    //  string Flight_code , city;
    //  while(input>>Flight_code>>city){
    //     Air.addFlight(Flight_code , city);
    //  }

    //  Air.DisplayAirport();
    cout << "You are taking Flight for ___" << endl;
    while(choice != 1 && choice !=2){
    cout << "Enter 1 for  Local Flight (Within the Country )" << endl;
    cout << "Enter 2 for  International Flight (for foreign country ) " << endl;
    cin >> choice;

    if (choice == 1) {
        // Code for local flights
         ifstream inputFile("DFlights.txt");

        if(!inputFile.is_open()){
            cerr<<"Failed to Load the Data For Local Flight's "<<endl;
            return -1;
        }

        string fNumber, source, dest, brand, date, departuretime, arrivalTime;
        int price, economic_seats, business_class_seats, first_class_seats;
        float rating;
        
        // reading the file from the txt ; 
        while (inputFile >> fNumber >> source >> dest >> brand >> date >> departuretime >> arrivalTime >> price >> economic_seats >> business_class_seats >> first_class_seats >> rating) {
            flightList.addFlight(fNumber, source, dest, brand, date, departuretime, arrivalTime, price, economic_seats, business_class_seats, first_class_seats, rating);
        }

        inputFile.close();
        cout<<"These are all the flights details Which are Ongoing ----"<<endl;
        cout<<endl;
        flightList.display2();

        cout<<"Search Your Flight Now : "<<endl;
        while(choice2!= 1 && choice2 !=2 && choice2 != 3){
        cout<<"Enter Your Choice : "<<endl;
        
        cout<<"Chioce 1 : search flight by providing source information : "<<endl;
        cout<<"Choice 2 : search flight by providing destination information "<<endl;
        cout<<"Choice 3 : search flight by providing date information "<<endl;
        cin>>choice2;
        
        
        cout<<endl;
        if(choice2==1){
            cout<<"Enter The Place From Where Taking The Flight "<<endl;
            cin>>choice_str;
            // flightList.search_flight2(choice_str , choice2);
            bool fight_found = flightList.FlightsAvailable(choice_str , choice2);
            if(fight_found){
            cout<<"These Flights Are Available Based On Your Source Info : "<<endl;
            flightList.search_flight2(choice_str , choice2);
            }
            else{
                // write the code for exiting the program

                cout<<"No Flights Are Available for the provided information "<<endl;
                int reenter;
                cout<<"Enter 1 for Re-Enter the Choice OR any Other key to exit the program  "<<endl;
                cin>>reenter;
                if(reenter ==1){
                    //
                }
                else{
                    cout<<"Exiting The Program "<<endl;
                    return 0;
                }


            }

        }
        else if(choice2 ==2){
            cout<<"Enter The Place For Which You are Taking The Flight "<<endl;
            cin>>choice_str;
            cout<<"These Flights Are Available Based On Your Destination Info : "<<endl;
            flightList.search_flight2(choice_str , choice2);
        }
        else if(choice2 ==3){
            cout<<"Enter The Date For Which You are Taking The Flight "<<endl;
            cin>>choice_str;
            cout<<"These Flights Are Available Based On Your Destination Info : "<<endl;
            flightList.search_flight2(choice_str , choice2);
        }
        else{
            cout<<" Invalid Choice !! "<<endl<<"Please Enter a Choice From the given Option Below "<<endl;
        }
        }
        

        cout<<"Now It's Time to Book a Ticket "<<endl;
        flightList.book_ticket2();

        // ... (same as before)

    } else if (choice == 2) {
        ifstream inputFile("IFlights.txt");

        if (!inputFile.is_open()) {
            cerr << "Failed to Load the Data For International Flights " << endl;
            return -1;
        }

        string fNumber, source, dest, brand, date, departuretime, arrivalTime;
        int price, economic_seats, business_class_seats, first_class_seats;
        float rating;

        while (inputFile >> fNumber >> source >> dest >> brand >> date >> departuretime >> arrivalTime >> price >> economic_seats >> business_class_seats >> first_class_seats >> rating) {
            flightList.addFlight(fNumber, source, dest, brand, date, departuretime, arrivalTime, price, economic_seats, business_class_seats, first_class_seats, rating);
        }

        inputFile.close();

        cout << "These are all the international flights details Which are Ongoing ----" << endl;
        cout << endl;
        flightList.display2();

        cout << "Search Your Flight Now : " << endl;
        cout << "Enter Your Choice : " << endl;
        cout << "Choice 1 : search flight by providing source information : " << endl;
        cout << "Choice 2 : search flight by providing destination information " << endl;
        cout << "Choice 3 : search flight by providing date information " << endl;
        cin >> choice2;
        cout << endl;

        if (choice2 == 1) {
            cout << "Enter The Place From Where Taking The Flight " << endl;
            cin >> choice_str;
            cout << "These Flights Are Available Based On Your Source Info : " << endl;
            flightList.search_flight2(choice_str, choice2);

        } else if (choice2 == 2) {
            cout << "Enter The Place For Which You are Taking The Flight " << endl;
            cin >> choice_str;
            cout << "These Flights Are Available Based On Your Destination Info : " << endl;
            flightList.search_flight2(choice_str, choice2);
        } else if (choice2 == 3) {
            cout << "Enter The Date For Which You are Taking The Flight " << endl;
            cin >> choice_str;
            cout << "These Flights Are Available Based On Your Destination Info : " << endl;
            flightList.search_flight2(choice_str, choice2);
        } else {
            cout << "No Flights are available ---" << endl;
        }

        cout << "Now It's Time to Book a Ticket " << endl;
        flightList.book_ticket2();

    } else {
        cout << "Invalid choice. Please choose 1 or 2." << endl;
    }
}
    
}
