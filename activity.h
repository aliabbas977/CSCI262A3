/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Declarations for activity engine.
 */

#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
#include "traffic.h"

void generate_activity(const vector<Vehicle_Type>&, const vector<Vehicle_Stats>&, const Road_Stats, std::ostream&, bool base = false);

#endif /* ACTIVITY_H */
