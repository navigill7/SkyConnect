#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Flight {
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::string airline;
    std::string date;
    std::string departureTime;
    std::string arrivalTime;
    double basePrice;
    int totalSeats;
    int seatsAvailable;
    int seatsBooked;
    double rating;
};

// Function to display flight information
void displayFlights(const std::vector<Flight>& flights) {
    std::cout << "Flight Number\tOrigin\tDestination\tAirline\tDate\tDeparture\tArrival\tBase Price\tSeats Available\tSeats Booked\tRating\n";
    for (const auto& flight : flights) {
        std::cout << flight.flightNumber << "\t\t" << flight.origin << "\t" << flight.destination
                  << "\t" << flight.airline << "\t" << flight.date << "\t" << flight.departureTime
                  << "\t" << flight.arrivalTime << "\t" << flight.basePrice << "\t\t" << flight.seatsAvailable
                  << "\t\t" << flight.seatsBooked << "\t\t" << flight.rating << "\n";
    }
}

// Function to modify flight data
void modifyFlights(std::vector<Flight>& flights) {
    std::string flightNumber;
    std::cout << "Enter the flight number to modify: ";
    std::cin >> flightNumber;

    for (auto& flight : flights) {
        if (flight.flightNumber == flightNumber) {
            std::cout << "Enter new flight number: ";
            std::cin >> flight.flightNumber;

            std::cout << "Enter new origin: ";
            std::cin >> flight.origin;

            std::cout << "Enter new destination: ";
            std::cin >> flight.destination;

            std::cout << "Enter new airline: ";
            std::cin >> flight.airline;

            std::cout << "Enter new date: ";
            std::cin >> flight.date;

            std::cout << "Enter new departure time: ";
            std::cin >> flight.departureTime;

            std::cout << "Enter new arrival time: ";
            std::cin >> flight.arrivalTime;

            std::cout << "Enter new base price: ";
            std::cin >> flight.basePrice;

            std::cout << "Enter new total seats: ";
            std::cin >> flight.totalSeats;

            std::cout << "Enter new seats available: ";
            std::cin >> flight.seatsAvailable;

            std::cout << "Enter new seats booked: ";
            std::cin >> flight.seatsBooked;

            std::cout << "Enter new rating: ";
            std::cin >> flight.rating;

            std::cout << "Flight data modified successfully.\n";
            return;
        }
    }

    std::cout << "Flight not found!\n";
}

// Function to read flight data from the given format
Flight readFlightData(std::ifstream& inFile) {
    Flight flight;
    inFile >> flight.flightNumber >> flight.origin >> flight.destination >> flight.airline
             >> flight.date >> flight.departureTime >> flight.arrivalTime >> flight.basePrice
             >> flight.totalSeats >> flight.seatsAvailable >> flight.seatsBooked >> flight.rating;
    return flight;
}

// Function to write flight data to the file
void writeFlightData(std::ofstream& outFile, const std::vector<Flight>& flights) {
    for (const auto& flight : flights) {
        outFile << flight.flightNumber << ' ' << flight.origin << ' ' << flight.destination
                << ' ' << flight.airline << ' ' << flight.date << ' ' << flight.departureTime
                << ' ' << flight.arrivalTime << ' ' << flight.basePrice << ' ' << flight.totalSeats
                << ' ' << flight.seatsAvailable << ' ' << flight.seatsBooked << ' ' << flight.rating << '\n';
    }
}

// Function to add a new flight to the existing file
void addNewFlight(std::vector<Flight>& flights) {
    Flight newFlight;
    std::cout << "Enter new flight information:\n";
    std::cout << "Flight number: ";
    std::cin >> newFlight.flightNumber;

    std::cout << "Origin: ";
    std::cin >> newFlight.origin;

    std::cout << "Destination: ";
    std::cin >> newFlight.destination;

    std::cout << "Airline: ";
    std::cin >> newFlight.airline;

    std::cout << "Date: ";
    std::cin >> newFlight.date;

    std::cout << "Departure time: ";
    std::cin >> newFlight.departureTime;

    std::cout << "Arrival time: ";
    std::cin >> newFlight.arrivalTime;

    std::cout << "Base price: ";
    std::cin >> newFlight.basePrice;

    std::cout << "Total seats: ";
    std::cin >> newFlight.totalSeats;

    std::cout << "Seats available: ";
    std::cin >> newFlight.seatsAvailable;

    std::cout << "Seats booked: ";
    std::cin >> newFlight.seatsBooked;

    std::cout << "Rating: ";
    std::cin >> newFlight.rating;

    flights.push_back(newFlight);
    std::cout << "New flight added successfully.\n";
}

int main() {
    std::vector<Flight> flights;

    // Read flights from the file
    std::ifstream inFile("DFlights.txt");
    if (!inFile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    while (inFile.peek() != EOF) {
        flights.push_back(readFlightData(inFile));
    }

    int choice;
    do {
        std::cout << "Admin Menu:\n";
        std::cout << "1. Modify Flights\n";
        std::cout << "2. Add New Flight\n";
        std::cout << "3. Display Flights\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                modifyFlights(flights);
                break;
            case 2:
                addNewFlight(flights);
                break;
            case 3:
                displayFlights(flights);
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    // Write modified flights back to the file
    std::ofstream outFile("DFlights.txt");
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return 1;
    }

    writeFlightData(outFile, flights);

    return 0;
}
