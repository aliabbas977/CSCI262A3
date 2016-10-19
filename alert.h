/* CSCI262 Assignment 3: Honeypot Event Modeller & IDS/Auditor System
 * Ali | Andrew | Rakish
 *
 * Declarations for alert engine.
 */

#ifndef ALERT_H
#define ALERT_H

#include "traffic.h"

int alert_engine(const std::vector<Vehicle_Type>&, int);

#endif /* ALERT_H */
