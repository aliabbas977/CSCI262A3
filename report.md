# Report

## Part One - Initial Input

**1. How you are going to store the vehicle types and statistics internally.**

After meeting and deciding we were going to develop our program in C++ since we all had experience in that language, we decided to code in a 'C++ way' using classes and objects rather than seperate data structures and functions as would be the case in C. We also decided to take advantage of the C++ Standard Library by using 'strings' and other library classes to avoid having to manage too many low-level details.

Vehicles.txt

>We created a vehicle_type class with private data members representing the inputs. The vehicle name was represented internally as a string, the parking flag as a bool, the registration format as another string, and the volume weight and speed as ints. A constructor was written for the class allowing the class to be initialized with a line of the Vehicles.txt file read in as a string.

>The number of vehicle types being monitored was not stored, instead each object was added to a vector allowing the number of vehicle types to be determined by checking the length of the vector. It is however checked once for internal consistency, when the file is open and read.

Stats.txt

>We also created a vehicle_stats class with private data members representing the inputs in order to allow for future extension to multiple roads. The vehicle type was represented interally as a string, while the number mean, number standard deviation, speed mean, and speed standard deviation, were stored as ints (following the lead of Stats.txt). A constructor was written for the class allowing the class to be initialized with a line of the Stats.txt file read in as a string.

>To store the road statistics a simple class road_stats consisting of ints to store the data was created (and once again, number of vehicle types was not stored permanently but checked once on open and read). This is simple enough for our purposes and still allows easy modification if future extensions are made, by wrapping the road_stats and vehicle_stats types into a higher type.

**2. Potential inconsistencies between Vehicles.txt and Stats.txt. You should attempt to detect those inconsistencies. If there are inconsistencies you are aware of but haven’t attempted to detect them, note this in your report.**

We checked for external inconsistencies between the data from Vehicles.txt and data from Stats.txt (for example, the appearance of vehicle types in Stats.txt that do not appear in Vehicles.txt, and vice versa).

Although it is also possible for internal inconsistencies to arise, as in the number of vehicle types specified in Vehicles.txt not matching up with the actual number of vehicle types listed in Vehicles.txt, since the assignment did not specify to check for internal inconsistencies we decided to assume that the input was correct and skip these kinds of checks.

## Part Two - Activity Engine and the Logs

**1. The process used to generate events approximately consistent with the particular distribution. Note that while the vehicle arrivals are discrete events, the speed of the vehicle is effectively continuous so the way you generate something in accordance with the distribution will likely differ.**

Place answer here.

**2. The name and format of the log file, with justification for the format. You will need to be able to read the log entries for subsequent parts of the program. The log file needs to be human readable.**

We decided to have a separate log file for each individual day, and named the log files accordingly: day 1 is named day1.log, day 2 is named day2.log, etc.

We also decided to keep separate log files for the baseline statistics, and the live statistics. We implemented this by optionally passing in a token parameter to the activity engine that specified that the logs generated were to be baseline logs (we could have simply checked if the baseline log file existed and assumed the logs were baseline if they did not, however performing this check could cause problems across different platforms, so we decided on a simpler way). If the token parameter was there to indicate the generation log files were to be base log files, the filenames were prefixed with '_' to identify them as such: day 1 baseline is named _day1.log, day 2 baseline is named _day2.log, etc.

We decided to use a similar format to the vehicle types file and the statistics file for consistency, that is we decided to have each event on it's own line, with relevant data postfixed by a ':'. This not only kept things consistent, but also kept the log files concise and human readable. Types of events were indicated by the associated number outlined in the assignment specification (e.g. '1' for vehicle arrival), time and vehicle type were also logged, along with relevant data.

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

Write something here.
