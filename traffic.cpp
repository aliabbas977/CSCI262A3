/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Definitions for types and statistics classes.
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "traffic.h"
using namespace std;

/* VEHICLE_TYPE */

// prints vehicle type information
void Vehicle_Type::print(std::ostream& out)
{
    out << "Vehicle Type: " << name << "\t\tRegistration Format: " << registration << "\t\tParking: " << ((parking == true) ? "Yes\n" : "No\n");
}

// returns the name of the vehicle type as a string
string Vehicle_Type::get_name()
{
    return name;
}

// generates a registration plate string according to the registration format
// used for activity engine
string Vehicle_Type::generate_plate()
{
    string plate;
    srand((unsigned)time(0));           // seed random number generator
    for (int i = 0; i < registration.size(); i++){
        if (registration[i] == 'L'){
            plate += static_cast<char>(rand()%26+65); // generate letter
        } else if (registration[i] == 'D'){
            plate += static_cast<char>(rand()%10);    // generate number
        }
    }
    return plate;
}

/* VEHICLE_STATS */

// prints vehicle statistics
void Vehicle_Stats::print(std::ostream& out)
{
    out << "Vehicle Type: " << type << "\t\tNumbers: " << num_mean << " (mean) " << num_sd << " (SD)\t\tSpeed: " << speed_mean << " (mean) " << speed_sd << " (SD)\n";
}

// returns the type of vehicle as a string
string Vehicle_Stats::get_type()
{
    return type;
}

/* ROAD_STATS */

// default constructor
Road_Stats::Road_Stats()
{
    road_length = 0;
    speed_limit = 0;
    parking_spaces = 0;
}

// constructor
Road_Stats::Road_Stats(int length, int limit, int spaces)
{
    road_length = length;
    speed_limit = limit;
    parking_spaces = spaces;
}

// update values
void Road_Stats::update(int length, int limit, int spaces)
{
    road_length = length;
    speed_limit = limit;
    parking_spaces = spaces;
}

// prints road statistics
void Road_Stats::print(std::ostream& out)
{
    out << "Road Length: " << road_length << "\t\tSpeed Limit: " << speed_limit << "\t\tParking Spaces Free: " << parking_spaces << '\n';
}
