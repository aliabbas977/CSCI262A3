/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Declarations for types and statistics classes.
 */

#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <iostream>
#include <string>

class Vehicle_Type{
    public:
        Vehicle_Type();
        Vehicle_Type(std::string);              // Example: Vehicle_Type bus("Bus:0:LLLDDD:3:2:");
        void update(std::string);               // Example: bus.update("Bus:0:LLLDDD:3:2:");
        void print(std::ostream&);              // Example: bus.print(cout);
        std::string get_name();                 // Example: string name = bus.getname();
        std::string generate_plate();           // Example: string registration = bus.generate_plate();
    private:
        std::string name;
        bool parking;
        std::string registration;
        int volume_weight;
        int volume_speed;
};

class Vehicle_Stats{
    public:
        Vehicle_Stats();
        Vehicle_Stats(std::string);             // Example: Vehicle_Stats bus_stats("Bus:3:1:40:10:");
        void update(std::string);               // Example: bus_stats.update("Bus:3:1:40:10:");
        void print(std::ostream&);              // Example: bus_stats.print(cout);
        std::string get_type();                 // Example: string type = bus_stats.gettype();
    private:
        std::string type;
        int num_mean;
        int num_sd;
        int speed_mean;
        int speed_sd;
};

class Road_Stats{
    public:
        Road_Stats();
        Road_Stats(int, int, int);              // Example: Road_Stats elm_street(5, 60, 20);
        void update(int, int, int);             // Example: elm_street.update(5, 60, 20);
        void print(std::ostream&);              // Example: elm_street.print(cout);
    private:
        int road_length;
        int speed_limit;
        int parking_spaces;
};

#endif /* TRAFFIC_H */
