/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Declarations for activity engine.
 */

#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <vector>
#include "traffic.h"

bool generate_activity(const std::vector<Vehicle_Type>&, const std::vector<Vehicle_Stats>&, const Road_Stats&, int, bool baseline = false);

#endif /* ACTIVITY_H */
