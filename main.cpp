/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * This program implements a honeypot/IDS/auditing system for vehicle traffic.
 * Two files detailing vehicles types and traffic statistics are opened and their
 * contents read in. An activity engine then generates event logs from the data,
 * an analysis engine examines the event data, and finally an alert engine
 * generates reports of any anomalies discovered in the data.
 *
 * Compilation:
 *     $ make
 *
 * Usage:
 *     This program takes three command-line inputs, a vehicle types text file, a
 *     traffic statistics text file, and an integer representing the number of
 *     days to be analyzed. All command-line arguments past the third one are
 *     ignored.
 *
 *     $ Traffic <vehicle types file> <statistics file> <days to analyze>
 *
 * Limitations:
 *     The program checks for the appropriate command-line arguments but it
 *     otherwise assumes that the the text files specified on the command-line
 *     are correctly formatted.
 *     Limits usage to between 1 and 500 days to prevent resource exhaustion
 *     and adjusts input below or above those values accordingly.
 *
 * Expected Input Format (vehicle types file):
 *     6
 *     Bus:0:LLLDDD:3:2:
 *     Motorbike:0:LLDDLL:1:1:
 *     Red car:1:LDLLDL:1:1:
 *     Elephant:1:LD:2:5:
 *     Taxi:0:LDDL:0:2:
 *     Emergency:0:LLDD:3:0:
 *
 * Expected Input Format (statistics file):
 *     6 5 60 20
 *     Bus:3:1:40:10:
 *     Motorbike:10:3:55:5:
 *     Red car:20:4:50:4:
 *     Elephant:2:1:10:10:
 *     Taxi:5:2:53:7:
 *     Emergency:1:0.5:60:10:
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "activity.h"
#include "alert.h"
#include "analysis.h"
#include "traffic.h"
using namespace std;

const int MIN_DAYS = 1;
const int MAX_DAYS = 500;

bool load_vehicles(const char*, vector<Vehicle_Type>&);
bool load_stats(const char*, vector<Vehicle_Stats>&, Road_Stats&);
int enforce_days(int);
bool check_consistency(const vector<Vehicle_Type>&, const vector<Vehicle_Stats>&);

int main(int argc, char *argv[])
{
    vector<Vehicle_Type> vehicles;
    vector<Vehicle_Stats> base_stats, live_stats;
    Road_Stats base_road, live_road;
    int base_days, live_days;
    string buffer;

    /* PART ONE: INITIAL INPUT (BASELINE) */

    // check for required command-line arguments and exit if there aren't enough
    if (argc < 4){
        cerr << "Not enough arguments specified on the command-line.\n"
             << "Usage: Traffic <vehicle types file> <statistics file> <days to analyze>" << endl;
        return 1;
    }

    // open first file specified on the command-line (usually Vehicles.txt) and read in data
    // exit if file cannot be opened or is empty
    if (load_vehicles(argv[1], vehicles) == false)
        return 1;

    // open second file specified on the command-line (usually Stats.txt) and read in data
    // exit if file cannot be opened or is empty
    if (load_stats(argv[2], base_stats, base_road) == false)
        return 1;

    // store the number of days to be analyzed and enforce it to be between MIN_DAYS and MAX_DAYS
    base_days = atoi(argv[3]);
    base_days = enforce_days(base_days);

    // check for inconsistencies between the data from the two files read in
    cout << "Checking for inconsistencies...\n";
    check_consistency(vehicles, base_stats);

    /* PART TWO: CALL THE ACTIVITY ENGINE TO GENERATE AND LOG EVENTS (BASELINE) */
    generate_activity(vehicles, base_stats, base_road, base_days, 'true');

    /* PART THREE: CALL THE ANALYSIS ENGINE TO PRODUCE STATISTICS (BASELINE) */
    perform_analysis(vehicles, base_road, base_days, 'true');

    /* PART FOUR: PROMPT USER, CALL ACTIVITY ENGINE AND ANALYSIS ENGINE TO GENERATE LIVE DATA, THEN CALL ALERT ENGINE TO CHECK CONSISTENCY BETWEEN LIVE DATA AND BASELINE */
    while(true){
        cout << "Please specify a file to analyze or enter 'Q' to quit: ";
        cin >> buffer;
        if (buffer == "Q")
            break;
        cout << '\n';
        // try to open the specified live stats file and read in data
        // if file cannot be opened or is empty then ask for another file
        if (load_stats(buffer.c_str(), live_stats, live_road) == false)
            continue;
        cout << "\nPlease enter the number of days to analyze: ";
        // store the number of live days to be analyzed and enforce it to be between MIN_DAYS and MAX_DAYS
        cin >> live_days;
        live_days = enforce_days(live_days);
        cout << endl;
        // generate live data and generate log files
        generate_activity(vehicles, live_stats, live_road, live_days);
        // analyze live data and generate stat files
        perform_analysis(vehicles, live_road, live_days);
        // check for consistency between live data and baseline by calling the alert engine
        // output the total number of alerts raised
        cout << alert_engine(live_days) << " alerts raised.\n";
    };

    return 0;
}

// loads a specified vehicles type file into a vector of Vehicle_Type
//     if unable to open file, returns false
bool load_vehicles(const char* file, vector<Vehicle_Type>& vehicles)
{
    ifstream ifs;
    ifs.open(file);
    if (ifs.is_open()){
        string buffer;
        Vehicle_Type temp;
        int count; ifs >> count;
        cout << "Reading in vehicle types from " << file << "...\n";
        while (ifs.eof() == false){
            getline(ifs, buffer);
            if(buffer.empty() == true)    // fix for banshee text format
                continue;
            temp.update(buffer);
            temp.print(cout);
            vehicles.push_back(temp);
        }
        if (vehicles.empty()){            // check that we actually read in some data and exit if we didn't
            cerr << "No vehicle types found." << endl;
            return 1;
        }
        if (vehicles.size() != count)     // check for internal consistency
            cerr << file << ": Mismatch between vehicle type count (" << count << ") and number of vehicle types listed (" << vehicles.size() << ")\n";
    } else {
        cerr << "Unable to open file " << file << endl;
        return 1;
    }
    cout << '\n';
    ifs.close();
    return true;
}

// loads a specified traffic statistics file into a vector of Vehicle_Stats and a Roads_Stats
//     if unable to open file, returns false
bool load_stats(const char* file, vector<Vehicle_Stats>& stats, Road_Stats& road)
{
    ifstream ifs;
    ifs.open(file);
    if (ifs.is_open()){
        string buffer;
        Vehicle_Stats temp;
        int count, length, limit, spaces; ifs >> count >> length >> limit >> spaces;
        road.update(length, limit, spaces);
        cout << "Reading in road statistics from " << file << "...\n";
        road.print(cout); cout << '\n';
        cout << "Reading in vehicle statistics from " << file << "...\n";
        while (ifs.eof() == false){
            getline(ifs, buffer);
            if(buffer.empty() == true)    // fix for banshee text format
                continue;
            temp.update(buffer);
            temp.print(cout);
            stats.push_back(temp);
        }
        if (stats.empty()){               // check that we actually read in some data and exit if we didn't
            cerr << "No vehicle statistics found." << endl;
            return false;
        }
        if (stats.size() != count)        // check for internal consistency
            cerr << file << ": Mismatch between vehicle type count (" << count << ") and number of vehicle types listed (" << stats.size() << ")\n";
    } else {
        cerr << "Unable to open file " << file << endl;
        return false;
    }
    cout << '\n';
    ifs.close();
    return true;
}

// enforce days to be between MIN_DAYS and MAX_DAYS
int enforce_days(int days)
{
    if (days < MIN_DAYS){
        cerr << "Warning: This program can only analyze between " << MIN_DAYS << " and " << MAX_DAYS << " days worth of data.\n"
             << days << " days specified.\n"
             << "Analyzing " << MIN_DAYS << " day instead." << endl;
       days = MIN_DAYS;
    } else if (days > MAX_DAYS){
        cerr << "Warning: This program can only analyze between " << MIN_DAYS << " and " << MAX_DAYS << " days worth of data.\n"
             << days << " days specified.\n"
             << "Analyzing " << MAX_DAYS << " days instead." << endl;
        days = MAX_DAYS;
    }
    return days;
}

// checks for consistency between a vector of Vehicle_Types and a vector of Vehicle_Stats
//     if inconsistencies are found, it outputs details and returns false
//     if no inconsistencies are found, it outputs details and returns true
bool check_consistency(const vector<Vehicle_Type>& vehicles, const vector<Vehicle_Stats>& stats)
{
    bool consistent = true;
    int vehicle_count = vehicles.size();
    int stats_count = stats.size();

    // check if the same amount of vehicle types as there are vehicle stats
    if (vehicle_count != stats_count){
        cerr << "Count of vehicle types and count of vehicle stats differ.\n"
             << "Types Counted: " << vehicle_count << "\nStats Counted: " << stats_count << '\n';
        consistent = false;
    }

    // check that all vehicle types were monitored
    for (int i = 0; i < vehicle_count; i++){
        string test = vehicles[i].get_type();
        bool found = false;
        for (int j = 0; j < stats_count; j++){
            if (test == stats[j].get_type()){
                found = true;
                break;
            }
        }
        if (found == false){
            cerr << "Vehicle type " << test << " not found in stats.\n";
            consistent = false;
        }
    }

    // check that everything monitored is a vehicle type we are trying to monitor
    for (int i = 0; i < stats_count; i++){
        string test = stats[i].get_type();
        bool found = false;
        for (int j = 0; j < vehicle_count; j++){
            if (test == vehicles[j].get_type()){
                found = true;
                break;
            }
        }
        if (found == false){
            cerr << "Vehicle statistics for " << test << " exist but it is not a monitored type.\n";
            consistent = false;
        }
    }

    /* ADD MORE CHECKS HERE IF YOU THINK OF THEM */

    if (consistent == true)
        cout << "No inconsistencies found.\n";

    cout << '\n';

    return consistent;
}
