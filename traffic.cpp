/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Definitions for types and statistics classes.
 */

#include "traffic.h"

road_stats::road_stats()
{
    road_length = 0;
    speed_limit = 0;
    parking_spaces = 0;
}

road_stats::road_stats(int length, int limit, int spaces)
{
    road_length = length;
    speed_limit = limit;
    parking_spaces = spaces;
}


void road_stats::update(int length, int limit, int spaces)
{
    road_length = length;
    speed_limit = limit;
    parking_spaces = spaces;
}

void road_stats::print(std::ostream& out)
{
    out << "Road Length: " << road_length << "\t\tSpeed Limit: " << speed_limit << "\t\tParking Spaces Free: " << parking_spaces << '\n';
}
