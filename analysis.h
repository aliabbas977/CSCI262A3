/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Declarations for analysis engine.
 */

#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <iostream>
#include <vector>
#include "traffic.h"

/* Using '100' based on MAX_DAYS in main.cpp - need to find a better solution */

class Events_Data{
    public:
        Events_Data();
        void increment(int, int);                                 // Example: events_data.update(x, y, 50);
        void print(int, std::ostream&) const;                     // Example: events_data.print(5, ofs);
    private:
        int counts[100][5];                                       // Stores event counter by day
};

class Vehicle_Data{
    public:
        Vehicle_Data();
        void update(int, std::string, std::string);               // Example: vehicle_data.update(2, "22", "Emergency");
        void print(int, std::ostream&);                           // Example: vehicle_data.print(5, ofs);
        std::string get_type() const;                             // Example: string type = bus.get_type();
    private:
        void calculate(int);                                      // Updates means and SDs based on current data
        std::string type;
        std::vector<std::string> speeds[100];                     // Stores speeds by day
        int num_mean;
        int num_sd;
        int speed_mean;
        int speed_sd;
};

bool perform_analysis(const std::vector<Vehicle_Type>&, int days, bool baseline = false);

#endif /* ANALYSIS_H */
