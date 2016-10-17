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

// returns the name of the vehicle type as a string
string vehicle_type::get_name()
{
    return name;
}

// generates a registration plate string according to the registration format
// used for activity engine
string vehicle_type::generate_plate()
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

// returns the type of vehicle as a string
string vehicle_stats::get_type()
{
    return type;
}

// default constructor
road_stats::road_stats()
{
    road_length = 0;
    speed_limit = 0;
    parking_spaces = 0;
}

// constructor
road_stats::road_stats(int length, int limit, int spaces)
{
    road_length = length;
    speed_limit = limit;
    parking_spaces = spaces;
}

// update values
void road_stats::update(int length, int limit, int spaces)
{
    road_length = length;
    speed_limit = limit;
    parking_spaces = spaces;
}

// prints road statistics
void road_stats::print(std::ostream& out)
{
    out << "Road Length: " << road_length << "\t\tSpeed Limit: " << speed_limit << "\t\tParking Spaces Free: " << parking_spaces << '\n';
}
