# Report

## Part One - Initial Input

**1. How you are going to store the vehicle types and statistics internally.**

After meeting and deciding we were going to develop our program in C++ since we all had experience in that language, we decided to code in a 'C++ way' using classes and objects rather than seperate data structures and functions as would be the case in C. We also decided to take advantage of the C++ Standard Library by using 'strings' and other library classes to avoid having to manage too many low-level details.

Vehicles.txt

>We created a vehicle_type class with private data members representing the inputs. The vehicle name was represented internally as a string, the parking flag as a bool, the registration format as a char array, and the volume weight and speed as ints. A constructor was written for the class allowing the class to be initialized with a line of the Vehicles.txt file read in as a string.

>The number of vehicle types being monitored was not stored, instead each object was added to a vector allowing the number of vehicle types to be determined by checking the length of the vector.

Stats.txt

>We also created a vehicle_stats class with private data members representing the inputs in order to allow for future extension to multiple roads. The vehicle type was represented interally as a string, while the number mean, number standard deviation, speed mean, and speed standard deviation, were stored as ints (following the lead of Stats.txt). A constructor was written for the class allowing the class to be initialized with a line of the Stats.txt file read in as a string.

>To store the road statistics a simple class road_stats consisting of ints to store the data was created (and once again, number of vehicle types was ignored). This is simple enough for our purposes and still allows easy modification if future extensions are made, by wrapping the road_stats and vehicle_stats types into a higher type.

**2. Potential inconsistencies between Vehicles.txt and Stats.txt. You should attempt to detect those inconsistencies. If there are inconsistencies you are aware of but haven’t attempted to detect them, note this in your report.**

We checked for external inconsistencies between Vehicles.txt and Stats.txt (for example, the appearance of vehicle types in Stats.txt that do not appear in Vehicles.txt, and vice versa).

Although it is also possible for internal inconsistencies to arise, as in the number of vehicle types specified in Vehicles.txt not matching up with the actual number of vehicle types listed in Vehicles.txt, since the assignment did not specify to check for internal inconsistencies we decided to assume that the input was correct and skip these kinds of checks.

## Part Two - Activity Engine and the Logs

**1. The process used to generate events approximately consistent with the particular distribution. Note that while the vehicle arrivals are discrete events, the speed of the vehicle is effectively continuous so the way you generate something in accordance with the distribution will likely differ.**

Place answer here.

**2. The name and format of the log file, with justification for the format. You will need to be able to read the log entries for subsequent parts of the program. The log file needs to be human readable.**

Place answer here.

**3. Any alarms that may be raised during the activity, so an immediate detection of a problem.**

Place answer here.

## Part Three - Analysis Engine

**1. Specify the file containing the daily totals for the events.**

Place answer here.

**2. Possible anomalies in reading the logs.**

Place answer here.

**3. Possible anomalies in determing the statistics.**

Place answer here.

## Part Four - Alert Engine

*No questions specified*
