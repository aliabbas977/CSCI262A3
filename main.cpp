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
 *     $ Traffic <vehicle types file> <statistics file> <number of days to analyze>
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

#include <iostream>
#include "traffic.h"
using namespace std;

int main(int argc, char *argv[])
{
    /* check for required command-line arguments and exit if there aren't enough */
    if (argc < 4){
        cerr << "Not enough arguments specified on the command-line.\n"
             << "Usage: Traffic <vehicle types file> <statistics file> <number of days to analyze>" << endl;
        return 1;   // abnormal program termination
    }

    return 0;
}
