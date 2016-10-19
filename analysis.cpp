/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Definitions for analysis engine.
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "analysis.h"
using namespace std;

#define MAX_DAYS 100

// analyzes log files and generates statistics
//     statistics files are named day1.stats, day2.stats, and so on
//     optional: passing 'true' as the final parameter generates base stats, which means filenames are base_daily.stats and base.stats
//               the final parameter defaults to 'false', in which case the filenames default to live_daily.stats and live.stats
//     if a file cannot be opened for writing, returns false
bool perform_analysis(const vector<Vehicle_Type>& vehicles, int days, bool baseline)
{
    int event_counter[MAX_DAYS][5] = {{}};
    string speeds[25][100] = {{""}};
    int num_mean, num_sd, speed_mean, speed_sd;
    ifstream ifs;
    ofstream ofs;

    cout << "Log analysis in progress.\n";
    int day, event, speed_index;
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
            // update counter
            event_counter[day-1][event-1]++;
            // if it's a vehicle arrival, skip time, get vehicle name, get vehicle speed, store
            if(event == 1){
                getline(iss, token, ':'); getline(iss, type, ':'); getline(iss, token, ':');
                for(int i = 0; i < 25; i++){
                    if(speeds[i][0] == ""){
                        speeds[i][0] = type;
                        speed_index = i;
                        break;
                    } else if(speeds[i][0] == type){
                        speed_index = i;
                        break;
                    }
                }
                speeds[speed_index][event_counter[day][event]+1] = token;
                cout << speeds[speed_index][0] << ' ' << speeds[speed_index][event_counter[day][event]+1] << '\n';
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
        for(int i = 0; i < days && ofs.good() == true; i++){
            ofs << i + 1 << ':';
            for(int j = 0; j < 5; j++)
                ofs << event_counter[i][j] << ':';
            ofs << '\n';
        }
    } else {
        cerr << "Unable to open file " << file << endl;
        return false;
    }
    ofs.close();
    // perform analysis
    // write statistics to stat file
    if (baseline == true){
        file = "base.stats";
    } else {
        file = "live.stats";
    }
    ofs.open(file.c_str());
    if (ofs.is_open()){
        while(ofs.good() == true){
            break; // code
        }
    } else {
        cerr << "Unable to open file " << file << endl;
        return false;
    }
    cout << endl;

    return true;
}
