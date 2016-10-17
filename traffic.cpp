/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Definitions for types and statistics classes.
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include "traffic.h"
using namespace std;

/* VEHICLE_TYPE */

// default constructor
Vehicle_Type::Vehicle_Type()
{
    name = "NULL";
    parking = false;
    registration = "";
    volume_weight = 0;
    volume_speed = 0;
}

// constructor
Vehicle_Type::Vehicle_Type(string type)
{
    update(type);
}

// update values
void Vehicle_Type::update(string type)
{
    istringstream ss(type);
    string token;
    getline(ss, token, ':'); name = token;
    getline(ss, token, ':'); parking = atoi(token.c_str());
    getline(ss, token, ':'); registration = token;
    getline(ss, token, ':'); volume_weight = atoi(token.c_str());
    getline(ss, token, ':'); volume_speed = atoi(token.c_str());
}

// prints vehicle type information
void Vehicle_Type::print(ostream& out)
{
    out << name << ' ' << registration << ((parking == true) ? " (can park)\n" : "\n");
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

// default constructor
Vehicle_Stats::Vehicle_Stats()
{
    type = "NULL";
    num_mean = 0;
    num_sd = 0;
    speed_mean = 0;
    speed_sd = 0;
}

// constructor
Vehicle_Stats::Vehicle_Stats(string stats)
{
    update(stats);
}

// update values
void Vehicle_Stats::update(string stats)
{
    istringstream ss(stats);
    string token;
    getline(ss, token, ':'); type = token;
    getline(ss, token, ':'); num_mean = atoi(token.c_str());
    getline(ss, token, ':'); num_sd = atoi(token.c_str());
    getline(ss, token, ':'); speed_mean = atoi(token.c_str());
    getline(ss, token, ':'); speed_sd = atoi(token.c_str());
}

// prints vehicle statistics
void Vehicle_Stats::print(ostream& out)
{
    out << type << ' ' << num_mean << "/" << num_sd << ' ' << speed_mean << "/" << speed_sd << '\n';
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
    update(length, limit, spaces);
}

// update values
void Road_Stats::update(int length, int limit, int spaces)
{
    road_length = length;
    speed_limit = limit;
    parking_spaces = spaces;
}

// prints road statistics
void Road_Stats::print(ostream& out)
{
    out << road_length << "km " << speed_limit << "km/h " << parking_spaces << " spaces\n";
}
