/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Declarations for types and statistics classes.
 */

#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <iostream>
#include <string>

class vehicle_type{
    public:
        vehicle_type(std::string);              // Example: vehicle_type bus("Bus:0:LLLDDD:3:2:");
        void print(std::ostream&);              // Example: bus.print(cout);
        std::string get_name();                 // Example: string name = bus.getname();
        std::string generate_plate();           // Example: string license = bus.generate_plate();
    private:
        std::string name;
        bool parking;
        std::string registration;
        int volume_weight;
        int volume_speed;
};

class vehicle_stats{
    public:
        vehicle_stats(std::string);             // Example: vehicle_stats bus_stats("Bus:3:1:40:10:");
        void print(std::ostream&);              // Example: bus_stats.print(cout);
        std::string get_type();                 // Example: string type = bus_stats.gettype();
    private:
        std::string type;
        int num_mean;
        int num_std;
        int speed_mean;
        int speed_std;
};

class road_stats{
    public:
        road_stats();
        road_stats(int, int, int);              // Example: road_stats elm_street(5, 60, 20);
        void update(int, int, int);             // Example: elm_street.update(6, 50, 10);
        void print(std::ostream&);              // Example: elm_street.print(cout);
    private:
        int road_length;
        int speed_limit;
        int parking_spaces;
};

#endif /* TRAFFIC_H */
