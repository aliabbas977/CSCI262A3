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
 *     days to be analyzed.
 *
 *     $ Traffic <vehicle types file> <statistics file> <days to analyze>
 *
 * Limitations:
 *     The program checks for the appropriate command-line arguments but it
 *     otherwise assumes that the invocation is correct and assumes that all the
 *     text files specified on the command-line are correctly formatted. All
 *     command-line arguments past the third are ignored.
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

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "traffic.h"
using namespace std;

bool check_consistency(vector<vehicle_type>&, vector<vehicle_stats>&, ostream&);

int main(int argc, char *argv[])
{
    ifstream ifs;
    string buffer;
    vector<vehicle_type> vehicles;
    vector<vehicle_stats> stats;
    road_stats road;
    int days;

    /* PART ONE: INITIAL INPUT */

    // check for required command-line arguments and exit if there aren't enough
    if (argc < 4){
        cerr << "Not enough arguments specified on the command-line.\n"
             << "Usage: Traffic <vehicle types file> <statistics file> <days to analyze>" << endl;
        return 1;                   // abnormal program termination
    }

    // open first file specified on the command-line (usually Vehicles.txt) and read in data
    ifs.open(argv[1]);
    if (ifs.is_open()){
        int count; ifs >> count;
        // code
        if (vehicles.empty()){      // check that we actually read in some data
            cout << "No vehicle types found." << endl;
            return 1;               // abnormal program termination
        }
    } else {
        cerr << "Unable to open file " << argv[1] << endl;
        return 1;                   // abnormal program termination
    }
    ifs.close();

    // open second file specified on the command-line (usually Stats.txt) and read in data
    ifs.open(argv[2]);
    if (ifs.is_open()){
        int count, length, limit, spaces; ifs >> count >> length >> limit >> spaces;
        road.update(length, limit, spaces);
        road.print(cout);
        // code
        if (stats.empty()){         // check that we actually read in some data
            cout << "No vehicle statistics found." << endl;
            return 1;               // abnormal program termination
        }
    } else {
        cerr << "Unable to open file " << argv[2] << endl;
        return 1;                   // abnormal program termination
    }
    ifs.close();

    // check for inconsistencies between the two files read in
    check_consistency(vehicles, stats, cout);

    /* PART TWO: CALLING THE ACTIVITY ENGINE TO GENERATING AND LOG EVENTS */

    /* PART THREE: CALLING THE ANALYSIS ENGINE TO PRODUCE STATISTICS */

    /* PART FOUR GOES HERE: CALLING THE ALERT ENGINE TO CHECK CONSISTENCY BETWEEN "LIVE DATA" AND BASE LINE STATISTICS */

    return 0;
}

// checks for consistency between a vector of vehicle_types and a vector of vehicle_stats
//     if inconsistencies are found, it outputs details and returns false
//     if no inconsistencies are found, it outputs details and returns true
bool check_consistency(vector<vehicle_type>& vehicles, vector<vehicle_stats>& stats, ostream& out)
{
    bool consistent = true;
    int vehicle_count = vehicles.size();
    int stats_count = stats.size();

    // check if the same amount of vehicle types as there are vehicle stats
    if (vehicle_count != stats_count){
        out << "Count of vehicle types and count of vehicle stats differ.\n"
            << "Types Counted: " << vehicle_count << "\t\tStats Counted: " << stats_count << '\n';
        consistent = false;
    }

    // check that all vehicle types were monitored
    for (int i = 0; i < vehicle_count; i++){
        // stuff
    }

    // check that everything monitored is a vehicle type we are trying to monitor
    for (int i = 0; i < vehicle_count; i++){
        // stuff
    }

    /* ADD MORE CHECKS HERE IF YOU THINK OF THEM */

    if (consistent == true)
        out << "No inconsistencies found.\n";

    return consistent;
}
