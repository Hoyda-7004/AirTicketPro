// Program name: main.cpp
// Author: Hoyda Al Yahiri
// Date last updated: 5/7/2024
/* The AirTikePro project is a comprehensive airline management system designed to streamline various aspects of airline operations. 
It includes features such as flight management, airline management, booking management, seat management, loyalty program management, 
and notification management. The project aims to provide airline professionals with efficient tools to retrieve and manage crucial data, 
remove outdated entries, and handle notifications effectively. Through modular design, robust data management, and error handling 
mechanisms, AirTikePro offers a user-friendly and reliable solution for optimizing airline operations.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

// Define structures to store data

struct User {
    int userID;
    std::string username;
    std::string email;
    int loyaltyProgramID;
};

struct Flight {
    int flightID;
    std::string schedule;
    double price;
    int airlineID;
    double carbonEmissions;
};

struct Airline {
    int airlineID;
    std::string airlineName;
    std::string collaborations;
};

struct Booking {
    int bookingID;
    std::string seatNumber;
    std::string bookingTime;
    int userID;
};

struct Seat {
    std::string seatNumber;
    bool availability;
    std::string seatClass;
};

struct LoyaltyProgramEntry {
    int loyaltyProgramID;
    int points;
    std::string tier;
    int userID;
};

struct Notification {
    int notificationID;
    std::string content;
    std::string timestamp;
    int userID;
};

// Function prototypes
void executeTransaction();
void removeDataMenu();
void retrieveDataMenu();
void retrieveUserData();
void retrieveFlightData();
void retrieveAirlineData();
void retrieveBookingData();
void retrieveSeatData();
void retrieveLoyaltyProgramData();
void retrieveNotificationData();
void addDataMenu();
void updateDataMenu();
void addUser();
void updateUser();
void addFlight();
void updateFlight();
void addAirline();
void updateAirline();
void addBooking();
void updateBooking();
void addSeat();
void updateSeat();
void addLoyaltyProgram();
void updateLoyaltyProgram();
void addNotification();
void updateNotification();
void outputUserInfoToFile(const User& user);
void removeUser();
void removeFlight();
void removeAirline();
void removeBooking();
void removeSeat();
void removeLoyaltyProgram();
void removeNotification();

int main() {
    int choice;
    do {
        std::cout << "AirTicketPro Menu" << std::endl;
        std::cout << "1. Add Data" << std::endl;
        std::cout << "2. Update Data" << std::endl;
        std::cout << "3. Remove Data" << std::endl;
        std::cout << "4. Execute Transaction" << std::endl;
        std::cout << "5. Retrieve Data" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addDataMenu();
                break;
            case 2:
                updateDataMenu();
                break;
            case 3:
                std::cout << "Removing Data..." << std::endl;
                removeDataMenu();
                std::cout << "Data Removed Successfully." << std::endl;
                break;
            case 4:
                executeTransaction();
                break;
            case 5:
                std::cout << "Retrieving Data..." << std::endl;
                retrieveDataMenu();
                break;
            case 6:
                std::cout << "Exiting Program. Thank you!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
        
        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 6);

    return 0;
}

// Function to handle adding data
void addDataMenu() {
    int addChoice;
    do {
        std::cout << "Add Data Menu" << std::endl;
        std::cout << "1. Add User" << std::endl;
        std::cout << "2. Add Flight" << std::endl;
        std::cout << "3. Add Airline" << std::endl;
        std::cout << "4. Add Booking" << std::endl;
        std::cout << "5. Add Seat" << std::endl;
        std::cout << "6. Add Loyalty Program" << std::endl;
        std::cout << "7. Add Notification" << std::endl;
        std::cout << "8. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> addChoice;

        switch (addChoice) {
            case 1:
                addUser();
                break;
            case 2:
                addFlight();
                break;
            case 3:
                addAirline();
                break;
            case 4:
                addBooking();
                break;
            case 5:
                addSeat();
                break;
            case 6:
                addLoyaltyProgram();
                break;
            case 7:
                addNotification();
                break;
            case 8:
                std::cout << "Returning to Main Menu." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (addChoice != 8);
}

// Function to handle updating data
void updateDataMenu() {
    int updateChoice;
    do {
        std::cout << "Update Data Menu" << std::endl;
        std::cout << "1. Update User" << std::endl;
        std::cout << "2. Update Flight" << std::endl;
        std::cout << "3. Update Airline" << std::endl;
        std::cout << "4. Update Booking" << std::endl;
        std::cout << "5. Update Seat" << std::endl;
        std::cout << "6. Update Loyalty Program" << std::endl;
        std::cout << "7. Update Notification" << std::endl;
        std::cout << "8. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> updateChoice;

        switch (updateChoice) {
            case 1:
                updateUser();
                break;
            case 2:
                updateFlight();
                break;
            case 3:
                updateAirline();
                break;
            case 4:
                updateBooking();
                break;
            case 5:
                updateSeat();
                break;
            case 6:
                updateLoyaltyProgram();
                break;
            case 7:
                updateNotification();
                break;
            case 8:
                std::cout << "Returning to Main Menu." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (updateChoice != 8);
}


void retrieveDataMenu() {
    int retrieveChoice;
    do {
        std::cout << "Retrieve Data Menu" << std::endl;
        std::cout << "1. Retrieve User Data" << std::endl;
        std::cout << "2. Retrieve Flight Data" << std::endl;
        std::cout << "3. Retrieve Airline Data" << std::endl;
        std::cout << "4. Retrieve Booking Data" << std::endl;
        std::cout << "5. Retrieve Seat Data" << std::endl;
        std::cout << "6. Retrieve Loyalty Program Data" << std::endl;
        std::cout << "7. Retrieve Notification Data" << std::endl;
        std::cout << "8. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> retrieveChoice;

        switch (retrieveChoice) {
            case 1:
                retrieveUserData();
                break;
            case 2:
                retrieveFlightData();
                break;
            case 3:
                retrieveAirlineData();
                break;
            case 4:
                retrieveBookingData();
                break;
            case 5:
                retrieveSeatData();
                break;
            case 6:
                retrieveLoyaltyProgramData();
                break;
            case 7:
                retrieveNotificationData();
                break;
            case 8:
                std::cout << "Returning to Main Menu." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (retrieveChoice != 8);
}

// Function to handle removing data
void removeDataMenu() {
    int removeChoice;
    do {
        std::cout << "Remove Data Menu" << std::endl;
        std::cout << "1. Remove User" << std::endl;
        std::cout << "2. Remove Flight" << std::endl;
        std::cout << "3. Remove Airline" << std::endl;
        std::cout << "4. Remove Booking" << std::endl;
        std::cout << "5. Remove Seat" << std::endl;
        std::cout << "6. Remove Loyalty Program" << std::endl;
        std::cout << "7. Remove Notification" << std::endl;
        std::cout << "8. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> removeChoice;

        switch (removeChoice) {
            case 1:
                removeUser();
                break;
            case 2:
                removeFlight();
                break;
            case 3:
                removeAirline();
                break;
            case 4:
                removeBooking();
                break;
            case 5:
                removeSeat();
                break;
            case 6:
                removeLoyaltyProgram();
                break;
            case 7:
                removeNotification();
                break;
            case 8:
                std::cout << "Returning to Main Menu." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (removeChoice != 8);
    
}

// Function to retrieve booking data
void retrieveBookingData() {
    // Open the file containing booking data
    std::ifstream inputFile("bookingdata.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl; // Output each line of booking data
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

// Function to retrieve seat data
void retrieveSeatData() {
    // Open the file containing seat data
    std::ifstream inputFile("seatdata.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl; // Output each line of seat data
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

// Function to retrieve loyalty program data
void retrieveLoyaltyProgramData() {
    // Open the file containing loyalty program data
    std::ifstream inputFile("loyaltyprogramdata.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl; // Output each line of loyalty program data
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

// Function to retrieve notification data
void retrieveNotificationData() {
    // Open the file containing notification data
    std::ifstream inputFile("notificationdata.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl; // Output each line of notification data
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}


// Function to add a user
void addUser() {
    std::cout << "Adding User" << std::endl;

    User user;
    std::cout << "Enter UserID: ";
    std::cin >> user.userID;

    std::cout << "Enter Username: ";
    std::cin.ignore();
    std::getline(std::cin, user.username);

    std::cout << "Enter Email: ";
    std::cin >> user.email;

    std::cout << "Enter LoyaltyProgramID: ";
    std::cin >> user.loyaltyProgramID;

    // Display the user information
    std::cout << "User added successfully:" << std::endl;
    std::cout << "UserID: " << user.userID << std::endl;
    std::cout << "Username: " << user.username << std::endl;
    std::cout << "Email: " << user.email << std::endl;
    std::cout << "LoyaltyProgramID: " << user.loyaltyProgramID << std::endl;

    // Save user information to file
    outputUserInfoToFile(user);
}

// Function to update a user
void updateUser() {
    std::cout << "Updating User" << std::endl;

    int userID, loyaltyProgramID;
    std::string username, email;

    // Prompt user for input
    std::cout << "Enter UserID of the user you want to update: ";
    std::cin >> userID;

    // Prompt user for updated information
    std::cout << "Enter new Username: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, username);
    std::cout << "Enter new Email: ";
    std::cin >> email;
    std::cout << "Enter new LoyaltyProgramID: ";
    std::cin >> loyaltyProgramID;

    // Perform necessary operations to update user
    std::cout << "User with UserID " << userID << " updated successfully." << std::endl;
}

// Function to add a flight
void addFlight() {
    std::cout << "Adding Flight" << std::endl;

    int flightID, airlineID;
    std::string schedule;
    double price, carbonEmissions;

    // Prompt user for flight information
    std::cout << "Enter FlightID: ";
    std::cin >> flightID;

    std::cout << "Enter Schedule (YYYY-MM-DD HH:MM:SS): ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, schedule);

    std::cout << "Enter Price: ";
    std::cin >> price;

    std::cout << "Enter AirlineID: ";
    std::cin >> airlineID;

    std::cout << "Enter Carbon Emissions: ";
    std::cin >> carbonEmissions;

    // Display the flight information (simulating adding to the database)
    std::cout << "Flight added successfully:" << std::endl;
    std::cout << "FlightID: " << flightID << std::endl;
    std::cout << "Schedule: " << schedule << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "AirlineID: " << airlineID << std::endl;
    std::cout << "Carbon Emissions: " << carbonEmissions << std::endl;
}

// Function to update a flight
void updateFlight() {
    std::cout << "Updating Flight" << std::endl;

    int flightID;
    std::string schedule;
    double price, carbonEmissions;
    int airlineID;

    // Prompt user for input
    std::cout << "Enter the FlightID of the flight to update: ";
    std::cin >> flightID;

    // Prompt the user for the fields to update
    std::cout << "Enter new Schedule (YYYY-MM-DD HH:MM:SS): ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, schedule);

    std::cout << "Enter new Price: ";
    std::cin >> price;

    std::cout << "Enter new AirlineID: ";
    std::cin >> airlineID;

    std::cout << "Enter new Carbon Emissions: ";
    std::cin >> carbonEmissions;

    // Update flight in the system with new information
    std::cout << "Flight with FlightID " << flightID << " updated successfully." << std::endl;
}

// Function to add an airline
void addAirline() {
    std::cout << "Adding Airline" << std::endl;

    int airlineID;
    std::string airlineName, collaborations;

    // Prompt user for airline information
    std::cout << "Enter AirlineID: ";
    std::cin >> airlineID;

    std::cout << "Enter Airline Name: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, airlineName);

    std::cout << "Enter Collaborations: ";
    std::getline(std::cin, collaborations);

    // Display the airline information (simulating adding to the database)
    std::cout << "Airline added successfully:" << std::endl;
    std::cout << "AirlineID: " << airlineID << std::endl;
    std::cout << "Airline Name: " << airlineName << std::endl;
    std::cout << "Collaborations: " << collaborations << std::endl;
}

// Function to update an airline
void updateAirline() {
    std::cout << "Updating Airline" << std::endl;

    int airlineID;
    std::string airlineName, collaborations;

    // Prompt user for input
    std::cout << "Enter the AirlineID of the airline to update: ";
    std::cin >> airlineID;

    // Prompt the user for updated information
    std::cout << "Enter new Airline Name: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, airlineName);

    std::cout << "Enter new Collaborations: ";
    std::getline(std::cin, collaborations);

    // Update airline in the system with new information
    std::cout << "Airline with AirlineID " << airlineID << " updated successfully." << std::endl;
}

// Function to add a booking
void addBooking() {
    std::cout << "Adding Booking" << std::endl;

    int bookingID, userID;
    std::string seatNumber, bookingTime;

    // Prompt user for booking information
    std::cout << "Enter BookingID: ";
    std::cin >> bookingID;

    std::cout << "Enter Seat Number: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, seatNumber);

    std::cout << "Enter Booking Time (YYYY-MM-DD HH:MM:SS): ";
    std::getline(std::cin, bookingTime);

    std::cout << "Enter UserID: ";
    std::cin >> userID;

    // Display the booking information (simulating adding to the database)
    std::cout << "Booking added successfully:" << std::endl;
    std::cout << "BookingID: " << bookingID << std::endl;
    std::cout << "Seat Number: " << seatNumber << std::endl;
    std::cout << "Booking Time: " << bookingTime << std::endl;
    std::cout << "UserID: " << userID << std::endl;
}

// Function to update a booking
void updateBooking() {
    std::cout << "Updating Booking" << std::endl;

    int bookingID, userID;
    std::string seatNumber, bookingTime;

    // Prompt user for input
    std::cout << "Enter the BookingID of the booking to update: ";
    std::cin >> bookingID;

    // Prompt user for updated information
    std::cout << "Enter new Seat Number: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, seatNumber);

    std::cout << "Enter new Booking Time (YYYY-MM-DD HH:MM:SS): ";
    std::getline(std::cin, bookingTime);

    std::cout << "Enter new UserID: ";
    std::cin >> userID;

    // Update booking in the system with new information
    std::cout << "Booking with BookingID " << bookingID << " updated successfully." << std::endl;
}

// Function to add a seat
void addSeat() {
    std::cout << "Adding Seat" << std::endl;

    std::string seatNumber, seatClass;
    bool availability;

    // Prompt user for seat information
    std::cout << "Enter Seat Number: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, seatNumber);

    std::cout << "Enter Seat Class: ";
    std::getline(std::cin, seatClass);

    std::cout << "Enter Availability (1 for available, 0 for not available): ";
    std::cin >> availability;

    // Display the seat information (simulating adding to the database)
    std::cout << "Seat added successfully:" << std::endl;
    std::cout << "Seat Number: " << seatNumber << std::endl;
    std::cout << "Seat Class: " << seatClass << std::endl;
    std::cout << "Availability: " << (availability ? "Available" : "Not Available") << std::endl;
}

// Function to update a seat
void updateSeat() {
    std::cout << "Updating Seat" << std::endl;

    std::string seatNumber, seatClass;
    bool availability;

    // Prompt user for input
    std::cout << "Enter the Seat Number of the seat to update: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, seatNumber);

    // Prompt user for updated information
    std::cout << "Enter new Seat Class: ";
    std::getline(std::cin, seatClass);

    std::cout << "Enter new Availability (1 for available, 0 for not available): ";
    std::cin >> availability;

    // Update seat in the system with new information
    std::cout << "Seat with Seat Number " << seatNumber << " updated successfully." << std::endl;
}

// Function to add a loyalty program entry
void addLoyaltyProgram() {
    std::cout << "Adding Loyalty Program Entry" << std::endl;

    int loyaltyProgramID, points, userID;
    std::string tier;

    // Prompt user for loyalty program information
    std::cout << "Enter LoyaltyProgramID: ";
    std::cin >> loyaltyProgramID;

    std::cout << "Enter Points: ";
    std::cin >> points;

    std::cout << "Enter Tier: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, tier);

    std::cout << "Enter UserID: ";
    std::cin >> userID;

    // Display the loyalty program information (simulating adding to the database)
    std::cout << "Loyalty Program Entry added successfully:" << std::endl;
    std::cout << "LoyaltyProgramID: " << loyaltyProgramID << std::endl;
    std::cout << "Points: " << points << std::endl;
    std::cout << "Tier: " << tier << std::endl;
    std::cout << "UserID: " << userID << std::endl;
}

// Function to update a loyalty program entry
void updateLoyaltyProgram() {
    std::cout << "Updating Loyalty Program Entry" << std::endl;

    int loyaltyProgramID, points, userID;
    std::string tier;

    // Prompt user for input
    std::cout << "Enter the LoyaltyProgramID of the loyalty program entry to update: ";
    std::cin >> loyaltyProgramID;

    // Prompt user for updated information
    std::cout << "Enter new Points: ";
    std::cin >> points;

    std::cout << "Enter new Tier: ";
    std::cin.ignore(); 
    std::getline(std::cin, tier);

    std::cout << "Enter new UserID: ";
    std::cin >> userID;

    // Update loyalty program entry in the system with new information
    std::cout << "Loyalty Program Entry with LoyaltyProgramID " << loyaltyProgramID << " updated successfully." << std::endl;
}

// Function to add a notification
void addNotification() {
    std::cout << "Adding Notification" << std::endl;

    int notificationID, userID;
    std::string content, timestamp;

    // Prompt user for notification information
    std::cout << "Enter NotificationID: ";
    std::cin >> notificationID;

    std::cout << "Enter Content: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, content);

    std::cout << "Enter Timestamp (YYYY-MM-DD HH:MM:SS): ";
    std::getline(std::cin, timestamp);

    std::cout << "Enter UserID: ";
    std::cin >> userID;

    // Display the notification information (simulating adding to the database)
    std::cout << "Notification added successfully:" << std::endl;
    std::cout << "NotificationID: " << notificationID << std::endl;
    std::cout << "Content: " << content << std::endl;
    std::cout << "Timestamp: " << timestamp << std::endl;
    std::cout << "UserID: " << userID << std::endl;
}

// Function to update a notification
void updateNotification() {
    std::cout << "Updating Notification" << std::endl;

    int notificationID, userID;
    std::string content, timestamp;

    // Prompt user for input
    std::cout << "Enter the NotificationID of the notification to update: ";
    std::cin >> notificationID;

    // Prompt user for updated information
    std::cout << "Enter new Content: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, content);

    std::cout << "Enter new Timestamp (YYYY-MM-DD HH:MM:SS): ";
    std::getline(std::cin, timestamp);

    std::cout << "Enter new UserID: ";
    std::cin >> userID;

    // Update notification in the system with new information
    std::cout << "Notification with NotificationID " << notificationID << " updated successfully." << std::endl;
}

// Function to execute a transaction
void executeTransaction() {
    std::cout << "Executing Transaction..." << std::endl;
    // Simulate executing a transaction
    std::cout << "Transaction executed successfully." << std::endl;
}



// Function to output user information to a file
void outputUserInfoToFile(const User& user) {
    std::ofstream outputFile("userdata.txt", std::ios::app);
    if (outputFile.is_open()) {
        outputFile << "UserID: " << user.userID << ", ";
        outputFile << "Username: " << user.username << ", ";
        outputFile << "Email: " << user.email << ", ";
        outputFile << "LoyaltyProgramID: " << user.loyaltyProgramID << std::endl;
        outputFile.close();
        std::cout << "User information written to file." << std::endl;
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

// Function to retrieve user data
void retrieveUserData() {
    // Open the file containing user data
    std::ifstream inputFile("userdata.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl; // Output each line of user data
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

void removeUser() {
    std::cout << "Executing removeUser()..." << std::endl; // Debug message

    int userID;
    std::cout << "Enter UserID of the user you want to remove: ";
    std::cin >> userID;

    std::ifstream inputFile("userdata.txt");
    if (inputFile.is_open()) {
        std::ofstream tempFile("temp.txt");
        std::string line;
        bool found = false;
        while (std::getline(inputFile, line)) {
            if (line.find("UserID: " + std::to_string(userID)) != std::string::npos) {
                found = true;
                continue; // Skip writing this line to the temporary file
            }
            tempFile << line << std::endl;
        }
        inputFile.close();
        tempFile.close();

        // Debugging message
        std::cout << "User removal process completed." << std::endl;

        // Remove the original file and rename the temporary file
        if (found) {
            remove("userdata.txt");
            rename("temp.txt", "userdata.txt");
            std::cout << "User with UserID " << userID << " removed successfully." << std::endl;
        } else {
            std::cout << "User with UserID " << userID << " not found." << std::endl;
        }
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
        
    }
}


// Assuming flight data is stored in a file named "flightdata.txt"
void retrieveFlightData() {
    std::ifstream inputFile("flightdata.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

// Assuming airline data is stored in a file named "airlinedata.txt"
void retrieveAirlineData() {
    std::ifstream inputFile("airlinedata.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

void removeFlight() {
    std::cout << "Removing Flight..." << std::endl; // Debugging message

    int flightID;
    std::cout << "Enter FlightID of the flight you want to remove: ";
    std::cin >> flightID;

    std::ifstream inputFile("flightdata.txt");
    if (inputFile.is_open()) {
        std::ofstream tempFile("temp.txt");
        std::string line;
        bool found = false;
        while (std::getline(inputFile, line)) {
            if (line.find("FlightID: " + std::to_string(flightID)) != std::string::npos) {
                found = true;
                continue; // Skip writing this line to the temporary file
            }
            tempFile << line << std::endl;
        }
        inputFile.close();
        tempFile.close();

        // Debugging message
        std::cout << "Flight removal process completed." << std::endl;

        if (found) {
            remove("flightdata.txt");
            rename("temp.txt", "flightdata.txt");
            std::cout << "Flight with FlightID " << flightID << " removed successfully." << std::endl;
        } else {
            std::cout << "Flight with FlightID " << flightID << " not found." << std::endl;
        }
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

void removeAirline() {
    std::cout << "Removing Airline..." << std::endl; // Debugging message

    int airlineID;
    std::cout << "Enter AirlineID of the airline you want to remove: ";
    std::cin >> airlineID;

    std::ifstream inputFile("airlinedata.txt");
    if (inputFile.is_open()) {
        std::ofstream tempFile("temp.txt");
        std::string line;
        bool found = false;
        while (std::getline(inputFile, line)) {
            if (line.find("AirlineID: " + std::to_string(airlineID)) != std::string::npos) {
                found = true;
                continue; // Skip writing this line to the temporary file
            }
            tempFile << line << std::endl;
        }
        inputFile.close();
        tempFile.close();

        // Debugging message
        std::cout << "Airline removal process completed." << std::endl;

        if (found) {
            remove("airlinedata.txt");
            rename("temp.txt", "airlinedata.txt");
            std::cout << "Airline with AirlineID " << airlineID << " removed successfully." << std::endl;
        } else {
            std::cout << "Airline with AirlineID " << airlineID << " not found." << std::endl;
        }
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}


// Assuming booking data is stored in a file named "bookingdata.txt"
void removeBooking() {
    std::cout << "Remove Booking..." << std::endl; // Debugging message

    int bookingID;
    std::cout << "Enter BookingID of the booking you want to remove: ";
    std::cin >> bookingID;

    std::ifstream inputFile("bookingdata.txt");
    if (inputFile.is_open()) {
        std::ofstream tempFile("temp.txt");
        std::string line;
        bool found = false;
        while (std::getline(inputFile, line)) {
            if (line.find("BookingID: " + std::to_string(bookingID)) != std::string::npos) {
                found = true;
                continue; // Skip writing this line to the temporary file
            }
            tempFile << line << std::endl;
        }
        inputFile.close();
        tempFile.close();

        if (found) {
            remove("bookingdata.txt");
            rename("temp.txt", "bookingdata.txt");
            std::cout << "Booking with BookingID " << bookingID << " removed successfully." << std::endl;
        } else {
            std::cout << "Booking with BookingID " << bookingID << " not found." << std::endl;
        }
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

// Assuming seat data is stored in a file named "seatdata.txt"
void removeSeat() {
    std::cout << "Remove Seat..." << std::endl; // Debugging message
    
    std::string seatNumber;
    std::cout << "Enter Seat Number of the seat you want to remove: ";
    std::cin >> seatNumber;

    std::ifstream inputFile("seatdata.txt");
    if (inputFile.is_open()) {
        std::ofstream tempFile("temp.txt");
        std::string line;
        bool found = false;
        while (std::getline(inputFile, line)) {
            if (line.find("Seat Number: " + seatNumber) != std::string::npos) {
                found = true;
                continue; // Skip writing this line to the temporary file
            }
            tempFile << line << std::endl;
        }
        inputFile.close();
        tempFile.close();

        if (found) {
            remove("seatdata.txt");
            rename("temp.txt", "seatdata.txt");
            std::cout << "Seat with Seat Number " << seatNumber << " removed successfully." << std::endl;
        } else {
            std::cout << "Seat with Seat Number " << seatNumber << " not found." << std::endl;
        }
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

// Assuming loyalty program data is stored in a file named "loyaltydata.txt"
void removeLoyaltyProgram() {
    std::cout << "Remove LoyaltyProgram..." << std::endl; // Debugging message
        
    int loyaltyID;
    std::cout << "Enter Loyalty Program ID of the entry you want to remove: ";
    std::cin >> loyaltyID;

    std::ifstream inputFile("loyaltydata.txt");
    if (inputFile.is_open()) {
        std::ofstream tempFile("temp.txt");
        std::string line;
        bool found = false;
        while (std::getline(inputFile, line)) {
            if (line.find("Loyalty Program ID: " + std::to_string(loyaltyID)) != std::string::npos) {
                found = true;
                continue; // Skip writing this line to the temporary file
            }
            tempFile << line << std::endl;
        }
        inputFile.close();
        tempFile.close();

        if (found) {
            remove("loyaltydata.txt");
            rename("temp.txt", "loyaltydata.txt");
            std::cout << "Loyalty program entry with ID " << loyaltyID << " removed successfully." << std::endl;
        } else {
            std::cout << "Loyalty program entry with ID " << loyaltyID << " not found." << std::endl;
        }
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

// Function to remove a notification by ID
void removeNotification() {
    std::cout << "Remove Notification..." << std::endl; // Debugging message
    
    int notificationID;
    std::cout << "Enter Notification ID of the notification you want to remove: ";
    std::cin >> notificationID;

    // Open the file containing notification data
    std::ifstream inputFile("notificationdata.txt");
    if (inputFile.is_open()) {
        std::ofstream tempFile("temp.txt");
        std::string line;
        bool found = false;
        while (std::getline(inputFile, line)) {
            if (line.find("NotificationID: " + std::to_string(notificationID)) != std::string::npos) {
                found = true;
                continue; // Skip writing this line to the temporary file
            }
            tempFile << line << std::endl;
        }
        inputFile.close();
        tempFile.close();

        if (found) {
            remove("notificationdata.txt");
            rename("temp.txt", "notificationdata.txt");
            std::cout << "Notification with ID " << notificationID << " removed successfully." << std::endl;
        } else {
            std::cout << "Notification with ID " << notificationID << " not found." << std::endl;
        }
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

// Function to search for occurrences of removeNotification() in the main.cpp file
void searchForRemoveNotification(const std::string& filename) {
    // The implementation of the searchForRemoveNotification function goes here...
}