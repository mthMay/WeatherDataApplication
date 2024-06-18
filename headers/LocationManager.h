//
// Created by May Thu Htun on 05/03/2024.
//

#ifndef SDICWK_LOCATIONMANAGER_H
#define SDICWK_LOCATIONMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <fstream>
#include <sstream>
#include <curl/curl.h>
#include "json.hpp"
#include "VariableHandler.h"

using json = nlohmann::json;

class LocationManager {
private :
    const std::string API_ENDPOINT = "http://api.openweathermap.org/geo/1.0/direct";
    const std::string apiKey = "75a4747f99c3ddf0d7ec1c4c568a91be";
    std::string fileName = "../Files/Locations.txt";
    struct Location {
        int id;
        std::string name;
        double latitude;
        double longitude;
    };
    std::vector<Location> locations;
    std::vector<Location> favouriteLocations;
    int nextId;

public:
    std::string urlEncode(std::string);
    std::string capitalizeFirstLetter(std::string);
    void addLocation(std::string);
    std::string getLatitude ( std::string );
    std::string getLongitude ( std::string );
    int locationExist( std::string );
    void modifyLocation(int,  std::string , double, double);
    void removeLocationByID(int);
    void searchLocationByName( std::string);
    void searchLocationByID(int);
    void showLocations();
    bool checkFavouriteLocation( std::string);
    void addFavouriteLocation( std::string);
    void showFavouriteLocations();
    double roundToTwoDecimalPoints (double);
    void parseLocationResponse( std::string);
    void writeToFile( std::vector<Location>&,  std::string);
    std::vector<Location> readFromFile( std::string);
    void setLocationFromFile();
};
#endif //SDICWK_LOCATIONMANAGER_H
