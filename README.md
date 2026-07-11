# Air Defence War Game (ADWG) ✈️🚀
*Air Defence War Game is a simulated Air engagement system using C++, ECS data structure & SFML Graphics*
ADWG simulates two team made of a flock of fighter jet and a number between (1 - 3) of AWACS (Airborne Warning and Control System)
The objective of each team being to destroy the other team's AWACSes.
ADWG doesn't simulate Dogfights between fighter jet but rather the long range engagements through missile launch beyind visual range, like in real life.

ADWG has 3 types of entities:
- Fighters 🟥
- AWACS 🔴
- Missiles 🔺

## HIGHLIGHTS
ADWG prides itself on delivering a simulations close to real air confrontation through the simulation of multiple interesting and important aspects of modern air combat engagement
ADWG simulates:
- Cinetic flight of aircrafts (turn rate, acceleration, ascension & descension)
- Weight influencing of the craft's cinetic abilities
- Radar detection with range and Field of View
- AWACS' Datalink (intra-team communication)
- Possibility of blue-on-blue casualties

## Cinetic Simulation
The mechanics of flights are very complex to simulate, in ADWG they've been simplified to its core.
In ADWG an aircraft cannot accelerate, turn or ascend instantaniously, each action, whether it is turning, accelerating or descending will take a certain time defined by the weight of the aircraft.

## Weight
Aircraft come loaded with fuel and sometimes missiles, each have simulated weight 1 unit of fuel is a metric ton and 1 missile is a quarter of that 250kg, based on the approximate weight of the AIM-7 SPARROW
Further during flight an aircraft will both consumed fuel and launch missile, descreasing its effective weight and affecting its flight performance. 

