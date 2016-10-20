/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Definitions for analysis engine.
 */

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "analysis.h"
using namespace std;

// analyzes log files and generates statistics
//     optional: passing 'true' as the final parameter generates base stats, which means filenames are base_daily.stats and base.stats
//               the final parameter defaults to 'false', in which case the filenames default to live_daily.stats and live.stats
//     if a file cannot be opened for writing, returns false
bool perform_analysis(const vector<Vehicle_Type>& vehicles, int days, bool baseline)
{
    Events_Data events_data;
    vector<Vehicle_Data> vehicle_data;
    ifstream ifs;
    ofstream ofs;

    cout << "Log analysis in progress.\n";
    int day, event;
    string file, buffer, token, type;
    istringstream iss;
    // open the log file and read in relevant data
    if (baseline == true){
        file = "base.log";
    } else {
        file = "live.log";
    }
    ifs.open(file.c_str());
    if (ifs.is_open()){
        while (ifs.eof() == false){
            getline(ifs, buffer);
            if(buffer.empty() == true)    // fix for banshee text format
                continue;
            iss.str(buffer);
            // get day number token
            getline(iss, token, ':');
            day = atoi(token.c_str());
            // get event type token
            getline(iss, token, ':');
            event = atoi(token.c_str());
            // update counts
            events_data.increment(day - 1, event - 1);
            // if it's a vehicle arrival, skip time, get vehicle name, get vehicle speed, find object in vector, update data appropriately
            if(event == 1){
                getline(iss, token, ':'); getline(iss, type, ':'); getline(iss, token, ':');
                int it = -1;
                Vehicle_Data temp;
                for(int i = 0; i < vehicle_data.size(); i++){
                    if(vehicle_data[i].get_type() == type){
                        it = i;
                        break;
                    }
                }
                if(it == -1){                          // not found so add a new one to vector
                    temp.update(day, token, type);
                    vehicle_data.push_back(temp);
                } else {
                    vehicle_data[it].update(day, token, type);
                }
            }
        }
    } else {
        cerr << "Unable to open file " << file << endl;
        return false;
    }
    ifs.close();
    // write daily statistics to the daily stat file
    if (baseline == true){
        file = "base_daily.stats";
    } else {
        file = "live_daily.stats";
    }
    ofs.open(file.c_str());
    if (ofs.is_open()){
        events_data.print(days, ofs);
    } else {
        cerr << "Unable to open file " << file << endl;
        return false;
    }
    ofs.close();
    // write statistics to stat file
    if (baseline == true){
        file = "base.stats";
    } else {
        file = "live.stats";
    }
    ofs.open(file.c_str());
    if (ofs.is_open()){
        for(int i = 0; i < vehicle_data.size() && ofs.good() == true; i++){
            vehicle_data[i].print(days, ofs);
        }
    } else {
        cerr << "Unable to open file " << file << endl;
        return false;
    }
    cout << endl;

    return true;
}

/* Events_Data */

// default constructor
Events_Data::Events_Data()
{
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 5; j++){
            counts[i][j] = 0;
        }
    }
}

// increment a counter for a specific event on a given day
void Events_Data::increment(int day, int event_num)
{
    counts[day][event_num]++;
}

// print events data
void Events_Data::print(int days, ostream& out) const
{
    for(int i = 0; i < days; i++){
        out << i + 1 << ':';
        for(int j = 0; j < 5; j++){
            out << counts[i][j] << ':';
        }
        out << '\n';
    }
}

/* Vehicle_Data */

// default constructor
Vehicle_Data::Vehicle_Data()
{
    type = "";
    num_mean = 0;
    num_sd = 0;
    speed_mean = 0;
    speed_sd = 0;
}

void Vehicle_Data::update(int day, string speed, string vehicle_type)
{
    type = vehicle_type;
    speeds[day].push_back(speed);
}

// print vehicle data
void Vehicle_Data::print(int days, ostream& out)
{
    calculate(days);
    out << type << ':' << num_mean << ':' << num_sd << ':' << speed_mean << ':' << speed_sd << ":\n";
}

// used for find function
string Vehicle_Data::get_type() const
{
    return type;
}

// Updates means and SDs based on current data
void Vehicle_Data::calculate(int days)
{
    vector<int> num_working, speeds_working;

    // clear current values
    num_mean = 0;
    num_sd = 0;
    speed_mean = 0;
    speed_sd = 0;
    // add all volumes and speeds to linear working buffers
    for(int i = 0; i < days; i++){
        num_working.push_back(speeds[i].size());
        for(int j = 0; j < speeds[j].size(); j++){
            speeds_working.push_back(atoi(speeds[i][j].c_str()));
        }
    }
    // calculate means
    for(int i = 0; i < num_working.size(); i++){
        num_mean += num_working[i];
    }
    num_mean = num_mean / days;
    for(int i = 0; i < speeds_working.size(); i++){
        speed_mean += speeds_working[i];
    }
    speed_mean = speed_mean / days;
    // calculate SDs
    for(int i = 0; i < num_working.size(); i++){
        num_sd += pow((num_working[i] - num_mean), 2);
    }
    num_sd = num_sd / days;
    num_sd = sqrt(num_sd);
    for(int i = 0; i < speeds_working.size(); i++){
        speed_sd += pow((speeds_working[i] - speed_mean), 2);
    }
    speed_sd = speed_sd / days;
    speed_sd = sqrt(speed_sd);

    return;
}
