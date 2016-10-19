/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Declarations for analysis engine.
 */

#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <vector>
#include "traffic.h"

bool perform_analysis(const std::vector<Vehicle_Type>&, const Road_Stats&, int, bool baseline = false);

#endif /* ANALYSIS_H */
