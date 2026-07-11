# Air Defence War Game (ADWG) ✈️🚀
*Air Defence War Game is a simulated Air engagement system using C++, ECS data structure & SFML Graphics*<br>
ADWG simulates two team made of a flock of fighter jets and a number between (1 - 3) of AWACS (Airborne Warning and Control System).
The objective of each team being to destroy the other team's AWACSes.<br>
ADWG doesn't simulate Dogfights between fighter jet but rather the long range engagements through missile launches beyond visual range, like in real life ! 🙂

ADWG has 3 types of entities:
- Fighters 🟥
- AWACS 🔴
- Missiles 🔺

### Technical HIGHLIGHTS
- ECS data structure
- Game object as Entities & Components
- Graphic API as Interface (enable graphics port to order graphical pipelines)
- CMAKE install SFML & builds it
- Vectorial calculation, Azimut detections

## HIGHLIGHTS
ADWG prides itself on delivering a simulation close to real air confrontations, through the simulation of multiple interesting and important aspects of modern air combat engagement.
ADWG simulates:
- Cinetic flight of aircrafts (turn rate, acceleration, ascension & descension)
- Weight influencing of the craft's cinetic abilities
- Radar detection with range and Field of View
- AWACS' Datalink (intra-team communication)
- Possibility of blue-on-blue casualties

## Cinetic Simulation
The mechanics of flights are very complex to simulate, in ADWG they've been simplified to their core.<br>
In ADWG an aircraft cannot accelerate, turn or ascend instantaniously, each action, whether it is turning, accelerating or descending will take a certain time defined by the weight of the aircraft.

## Weight
Aircrafts come loaded with fuel and sometimes missiles, each have simulated weights, 1 unit of fuel is a metric ton and 1 missile is a quarter of that; 250kg, based on the approximate weight of the AIM-7 SPARROW.<br>
Furthermore during flight an aircraft will both consume fuel and launch missiles, descreasing its effective weight and affecting its flight performance. 

## RADAR simulation
During combat, aircrafts will use RADAR to detect and target their opponents.<br>
In ADWG this is simulated via a cone of vision with a limited range, that will return the coordinate of targets in that cone.

![Screenshot](readme_img/azimuthal_detect.png)

The radar cone is fixed to the aircraft's orientation, therefore, not only can opponents stay out of range of detection, they can also bypass detection through maneuvering.

## AWACS' Datalink
During real engagements, information is paramount, knowing where the enemy might be is the first step to victory.<br>
AWACS is a tool made for the information war, it is equiped with a radar with much wider range and Datalink.<br>
In ADWG, Datalink is a tool that will allow the AWACS to share targets with their fighters.
This sharing of informations forms the backbone of the AWACS' defense but also the team's overall attack effectiveness.

## Blue-on-blue casualties
In air engagement is it not uncommon to launch a missile and leave it unsupervised, these missiles are dubbed "fire & forget", but a missile can sometime fail to track the right target, landing unfortunately on an ally, in the worst cases.<br>

In ADWG, this is simulated by following missile behaviour, when launched from an aircraft, the missile will go to the closest enemy detedted in the radar cone of the launching aircraft. If the enemy leaves the radar cone of the launching aircraft, the missile default to going to the closest entity on the missile's radar.
