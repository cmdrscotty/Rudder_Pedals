## Files to print

STL files are placed in the STL folder subfoldered into how many of each needs to be printed of each file.

Credited to the following Thingiverse uploads:
* https://www.thingiverse.com/thing:6976619
* https://www.thingiverse.com/thing:7283101
* https://www.thingiverse.com/thing:7422177

There are different versions of the pedals based on your comfort needs (18 degree tilt, 12 degree tilt, and 8 degree tilt)

## Config files

MW5_2.xml is for Joystick Gremlin to use with vjoy (You can ignore the definition for SaiTek x45 if you are using a different HOTAS)

HOTASMappings.Remap is for MW5 and goes in %localappdata%\MW5Mercs\Saved\SavedHOTAS

## Helpful tips

Recommend to print in PETG or ABS. PLA is too soft for this. 20% gyroid infill.

Having a set of M3, M4, and M6 taps will help greatly in assembly. I often had to chase threads in the head set inserts using taps to clean out any plastic goop.

Shoulder bolts don't *need* inserts as the plastic is thick enough to accommodate tapping it, but don't go crazy with tapping/torquing, since it's plastic you can strip it out easily. (will look at remixing the front/rear cross bars to allow for heatset inserts)

for the pedals, put the bearings in first, then heat set inserts, this will ensure the plastic doesn't deform and prevent you from being able to insert the bearing.

M3 inserts are only needed on the pedals (x3) the shock mounts (2x on each pedal mount) and one in the back for the centering shock

M4 inserts are used everywhere else.

For setting the heatset inserts, use a soldering iron with an adjustable temperature and set it to 500F. This will heat the brass up enough to slowly melt it into the plastic but not so hot it liquefies the material.

Before gluing in the magnets with hot glue (so they don't fall out) check the magnetic polarity to ensure the sensors behave correctly

## Wiring

The 49E Hall Effect Sensor only uses three pins.

With the label facing you the pins are left-right:
1. 5v
2. GND
3. Signal

with no magnet near it'll read roughly 2.5v
South will bring the voltage to 5v
North will bring the voltage to 0v

For wiring to the Arduino, wire pin 1 of all sensors to 5v, pin 2 to GND, then pin three to each respective pin:

A0 Rudder Yaw (sensor below the Arduino)
A1 Left Toe Sensor
A2 Right Toe Sensor

Use Joystick Gremlin to further dial in the calibration. Base calibration from 

## License

[![License: CC BY-NC-SA 4.0](https://shields.io)](https://creativecommons.org)

This project (including all Arduino code and STL files) is licensed under the **Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License**. 

**Commercial Use Note:** If you want to manufacture, sell 3D-printed kits, or commercially distribute components based on this project, you must obtain explicit written permission from the author first. Please open an issue to request permission.
