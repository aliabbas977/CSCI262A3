/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Definitions for alert engine.
 */

#include <iostream>
#include "alert.h"
using namespace std;

// checks for consistency between baseline data and live data
//     returns a count of alerts raised
int alert_engine(const std::vector<Vehicle_Type>& vehicles, int days)
{
    int alerts_raised = 0;

    cout << "Checking for possible intrusions.\n";
    for(int i = 1; i <= days; i++){
       /* This is where you implement the alert engine
        *
        * This is the relevant part of the assignment specficiation that has to be done here.
        *
        *     For each day generated you need to report on whether the there is an intrusion detected by comparing
        *     an anomaly counter with a threshold. You calculate the anomaly counter by adding up the weighted
        *     number of standard deviations each specific tested event value is from the mean for that event, where
        *     the standard deviation and mean are those you have generated from the base data and reported, and the
        *     weight is taken from the original Vehicles.txt file.
        *
        *     For example, if the mean number of Elephants per day is 2 and the standard deviation is 1; then if we
        *     get 1 Elephant in a day we are 1 standard deviation from the mean. Referrring back to the weight of the
        *     Elephant vehicle type we see it was 2 so the Elephant contributes 2 to our overall anomaly counter.
        *
        *     The threshold for detecting an intrusion is 2∗(Sums of weights) where the weights are taken from
        *     Vehicles.txt. If the anomaly counter is greater than the threshold you should report this as an anomaly.
        *     There are to be distinct analyses for the Vehicle volume and for the Vehicle speed.
        *
        *     You should output the threshold, and give the anomaly counter for each day as well as stating each
        *     day as okay or flagged as having an alert detected.
        *
        * Note: when he says "Vehicle volume" he means "vehicle count" (i.e. the number of vehicles of that type that day)
        *
        * Please note that the weights specified in 'Vehicles.txt' *have already been read in and stored* in the vector<Vehicle_Type> passed into the function as 'vehicles'
        * In other words *you should not open Vehicles.txt to get these values*, you should just add functions/methods to the Vehicle_Type class that return these weights
        * See 'traffic.h' and 'traffic.cpp' for the Vehicle_Type details
        *
        * You will only need to read in the baseline stat files, and the live data stat files!!!
        * Check the analysis.h and analysis.cpp files for details on their format and naming
        * The report.md file may also help describe their format and naming
        *     Baseline:  _day1.stats  _day2.stats
        *     Live Data:  day1.stats   day2.stats
        *
        * When you find a problem and raise an alert, increment alerts_raised (alerts_raised++;)
        *
        * don't forget to write up the relevant details in the report.md file.
        */
    }
    cout << endl;

    return alerts_raised;
}
