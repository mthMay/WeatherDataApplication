# SDIcwk

**Location Management**
- Add new location
- Modify location data
- Remove location
- Search for location
- Set favourite locations

**Weather Forecast/ Historical Weather/ Air Quality Forecast**
- Add data variables
- Set setting
- Display data
- Export data as JSON

**Test Running**
BOOST Testing implemented in this program is only for Location Management class. To be able to run the test successfully, data in the ../Files/Locations.txt must be deleted.\
Modify line 24 of CMakeLists.txt accordingly to your boost installed path

https://www.jetbrains.com/help/clion/boost-test-support.html
This is the reference link to help with boost configuration on Clion ide.

<br>

**This program cannot be run from Terminal right after cloning, need an ide (personally used Clion) to open the source code first. After opening the source code from an ide,**

**TO RUN THE TEST From Terminal after using ide to open the source code** go to cmake-build-debug and type ErrorChecking, prefixed with "./"

**TO RUN THE PROGRAM From Terminal after using ide to open the source code** go to cmake-build-debug and type SDIcwk, prefixed with "./"
