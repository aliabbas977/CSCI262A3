/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Definitions for activity engine.
 */

#include <iostream>
#include <vector>
#include "activity.h"
#include "traffic.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

// generates activity and logs events
//     logs are named day1.log, day2.log, and so on
//     optional: passing 'true' as the final parameter generates base logs, which means filenames are prefixed with '_', as in _day2.log
//               the final parameter defaults to 'false'
//     if a file cannot be opened for writing, returns false
bool generate_activity(const vector<Vehicle_Type>& vehicles, const vector<Vehicle_Stats>& stats, const Road_Stats& road, int days, bool baseline)
{
	int number_of_vehicles_in_the_system = 0;
    const int time_blocks = 24 * 60;                      // use 1 minute blocks of time (24 hours * 60 minutes)
	ofstream myfile;
	myfile.open ("examplelog.txt");
    cout << "Activity generation in progress.\n";
    for(int i = 1; i <= days; i++){
        cout << "Processing activity for day " << i << "...\n";
        /*
         * actual event generation goes here!!!
         *
         * "You are attempting to produce statistics approximately consistent with the statistics specified in the file."
         *
         * a single log file is created (it is later read by analysis.cpp)
         * you must check if 'baseline' is true, if it is the log file must be called base.log, if it is false it must be called live.log
         * if you can't open the file for writing or something else goes wrong, output an error message to cerr and return false
         *
         * you may need to add some methods to the classes to get the relevant information from them!
         *
         * event generation needs to take place in 1 minute blocks of time
         * so you may want to add an inner for loop here for that, like...
         *     for(int time = 0; time < time_blocks; time++)
         *
         * the output format (log file format) should be one event per line
         * each part of data on the line should be followed by a ':' (similar to the Vehicles.txt and Stats.txt files)
         * the first part of the data should be the day number
         * the second part of the data should be the type of event (number 1-5, see below)
         * the third part of data should be the time
         * the fourth part of the data should be the vehicle type/name (e.g. "Elephant")
         * if the type of event is '1' (i.e. the vehicle arrives) then fifth part of data should be the vehicle speed (this is needed for the analysis engine)
         * you need to decide what else to log, if anything (some things might be needed by the alert engine so consider it carefully), so for example...
         *     1:1:6334:Motorbike:56:<etc>:<etc>:<etc>:
         *     1:1:6780:Elephant:32:<etc>:<etc>:<etc>:
         *     1:2:7809:Motorbike:<etc>:<etc>:<etc>:
         * in other words, this means the format should be:
         *     Day:Event Number:Time:Vehicle Name:<Speed>:<etc>:<etc>:
         *
         * you have to decide which generated events should be logged
         *
         * types of events (specified in the assignment file)
         *     1. Vehicle arrival.
         *     2. Vehicle departure via a side road. The vehicle is then out of the road system.
         *     3. Vehicle departure via the end of the road. Test for the average speed to see if it has exceeded the speed limit. The vehicle is then out of the road system.
         *     4. Vehicle parks or stops parking.
         *     5. Vehicle moves and possibly changes speed.
         * "You should think about appropriate probabilities for each of those activities."
         * "You can clear all activity at midnight."
         *
         * finally you have to detect obvious problems, and raise an alarm immediately.
         *
         * don't forget to write up the relevant details in the report.md file. i have already answered one of the questions about the logfile format, but you can add to it if you like.
         */
		 
		 int j=0;
        for(int time = 0; time < time_blocks; time++){
			/*
            cout << i << ":" << "1" <<":"<< time << ":" << vehicles.at(j).get_type()<<endl;;
			*/
			int v = rand() % vehicles.size();
			//cout << i << ":" << "1" <<":"<< time << ":" << vehicles.at(v).get_type()<<endl;
			myfile << i << ":" << "1" <<":"<< time << ":" << vehicles.at(v).get_type()<<"\n";
        }
    }
	
	myfile.close();
    cout << "Event generation complete.\n\n";

    return true;
}
