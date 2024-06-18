//
// Created by May Thu Htun on 05/03/2024.
//

#include "../headers/LocationManager.h"

/* function urlEncode() is taken from
 * https://stackoverflow.com/a/154627
 * date access 6 March 2024
 */
std::string LocationManager::urlEncode( std::string value) {
    const auto encoded_value = curl_easy_escape(nullptr, value.c_str(), static_cast<int>(value.length()));
    std::string result(encoded_value);
    curl_free(encoded_value);
    return result;
}

std::string LocationManager::capitalizeFirstLetter(std::string cityName) {
    if (!cityName.empty()) {
        cityName[0] = std::toupper(cityName[0]);
    }
    return cityName;
}

void LocationManager::addLocation( std::string cityName) {
    VariableHandler variableHandler;
    setLocationFromFile();
    if (locationExist(cityName) != 0) {
        std::cout << "Failed to add location. City already exists.\n";
    } else {
        std::string encodedCityName = urlEncode(cityName);
        std::string url = API_ENDPOINT + "?q=" + encodedCityName + "&limit=1&appid=" + apiKey;
        std::string response = variableHandler.sendGetRequest(url);
        if (!response.empty()) {
            parseLocationResponse(response);
        } else {
            std::cout << "Failed to add location. Empty response from API.\n";
        }
    }
}

std::string LocationManager::getLatitude( std::string cityName) {
    setLocationFromFile();
    double latitude = 0;
    for (const Location& loc: locations){
        if(loc.name == cityName){
            latitude = loc.latitude;
        }
    }
    /* code to change from double to string is modified form
     * https://www.geeksforgeeks.org/cpp-program-for-double-to-string-conversion/
     */
    std::ostringstream stringstream;
    stringstream << latitude;
    std::string latitudeString = stringstream.str();
    return latitudeString;
}

std::string LocationManager::getLongitude( std::string cityName) {
    setLocationFromFile();
    double longitude = 0;
    for (const Location& loc: locations){
        if(loc.name == cityName){
            longitude = loc.longitude;
        }
    }

    std::ostringstream stringstream;
    stringstream << longitude;
    std::string longitudeString = stringstream.str();
    return longitudeString;
}

int LocationManager::locationExist( std::string cityName) {
    setLocationFromFile();
    int isExist = 0;
    for (const Location& loc : locations) {
        if (loc.name == cityName) {
            isExist = loc.id;
        }
    }
    return isExist;
}

void LocationManager::modifyLocation(int id,  std::string newName, double newLatitude, double newLongitude) {
    setLocationFromFile();
    for (size_t i = 0; i < locations.size(); ++i) {
        if(locations[i].id == id){
            locations[i].name = newName;
            locations[i].latitude = newLatitude;
            locations[i].longitude = newLongitude;
            std::cout << "Location modified successfully.\n";
            writeToFile(locations, fileName);
            setLocationFromFile();
        }
    }
}

void LocationManager::removeLocationByID(int id) {
    setLocationFromFile();
    bool locationFound = false;
    for(auto it = locations.begin(); it != locations.end();){
        if(it->id == id){
            it = locations.erase(it);
            locationFound = true;
        }else{
            ++it;
        }
    }

    for(auto it = favouriteLocations.begin(); it != favouriteLocations.end();){
        if(it->id == id){
            it = favouriteLocations.erase(it);
            locationFound = true;
        }else{
            ++it;
        }
    }

    if(locationFound) {
        writeToFile(locations, fileName);
        setLocationFromFile();
        std::cout << "Location removed successfully.\n";
    } else {
        std::cout << "Location not found.\n";
    }
}

void LocationManager::searchLocationByName( std::string query) {
    setLocationFromFile();
    bool locationFound = false;
    for (const Location& loc : locations) {
        if (loc.name.find(query) != std::string::npos) {
            std::cout << "Location found: " << loc.name << "\nLatitude: "<< loc.latitude
                      << "\nLongitude: " << loc.longitude << std::endl;
            locationFound = true;
        }
    }
    if (!locationFound) {
        std::cout << "Location name not found.\n";
    }
}

void LocationManager::searchLocationByID(int id) {
    setLocationFromFile();
    bool locationFound = false;
    for (const Location& loc : locations) {
        if (loc.id == id) {
            std::cout << "Location found: " << loc.name << "\nLatitude: "<< loc.latitude
                      << "\nLongitude: " << loc.longitude << std::endl;
            locationFound = true;
        }
    }
    if (!locationFound) {
        std::cout << "Location ID not found.\n";
    }
}

void LocationManager::showLocations() {
    setLocationFromFile();
    if (locations.empty()) {
        std::cout << "No locations found.\n";
    } else {
        std::cout << "Locations:\n";
        for (const Location& loc : locations) {
            std::cout << "ID: " << loc.id << ", Name: " << loc.name << ", Latitude: " << loc.latitude
                      << ", Longitude: " << loc.longitude << std::endl;
        }
    }
}

bool LocationManager::checkFavouriteLocation( std::string  cityName) {
    bool isExisted = false;
    for (const auto& location : favouriteLocations) {
        if (location.name == cityName) {
            isExisted = true;
        }
    }
    return isExisted;
}

void LocationManager::addFavouriteLocation( std::string cityName){
    bool locationFound = false;
    setLocationFromFile();
    for (const auto& location : locations) {
        if (location.name == cityName) {
            favouriteLocations.push_back(location);
            std::cout << cityName << " is added to favorites." << std::endl;
            locationFound = true;
        }
    }
    if (!locationFound) {
        std::cout << "Location ID not found.\n";
    }
}

void LocationManager::showFavouriteLocations() {
    if (favouriteLocations.empty()) {
        std::cout << "No locations found.\n";
    } else {
        std::cout << "Favourite Locations:\n";
        for (const Location& loc : favouriteLocations) {
            std::cout << "ID: " << loc.id << ", Name: " << loc.name << ", Latitude: " << loc.latitude
                      << ", Longitude: " << loc.longitude << std::endl;
        }
    }
}

double LocationManager::roundToTwoDecimalPoints (double value){
    return std::round(value * 100) / 100;
};

void LocationManager::parseLocationResponse( std::string response) {
    try {
        json data = json::parse(response);

        if (!data.empty() && data[0].contains("name") && data[0]["name"].is_string()) {
            Location newLocation;
            int lastId = locations.empty() ? 0 : locations.back().id;
            newLocation.id = lastId + 1;
            newLocation.name = data[0]["name"].get<std::string>();
            double latitude = roundToTwoDecimalPoints(data[0]["lat"].get<double>());
            newLocation.latitude = latitude;
            double longitude = roundToTwoDecimalPoints(data[0]["lon"].get<double>());
            newLocation.longitude = longitude;
            locations.push_back(newLocation);
            writeToFile(locations, fileName);
            std::cout << "Location added successfully.\n";
        } else {
            std::cout << "Failed to add location. No valid data received from API.\n";
        }
    } catch (const json::parse_error& e) {
        std::cout << "Error parsing JSON: " << e.what() << std::endl;
    }
}

void LocationManager::writeToFile( std::vector<Location>& locations, std::string filename) {
    std::ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (const Location& loc : locations) {
            outputFile << loc.id << ","
                       << loc.name << ","
                       << loc.latitude << ","
                       << loc.longitude << "\n";
        }
        outputFile.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

std::vector<LocationManager::Location> LocationManager::readFromFile( std::string filename) {
    std::vector<Location> locations;
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            Location loc;
            char comma;
            if (iss >> loc.id >> comma && std::getline(iss, loc.name, ',') &&
                iss >> loc.latitude >> comma >> loc.longitude) {
                locations.push_back(loc);
            } else {
                std::cout << "Error reading line from file" << std::endl;
            }
        }
        inputFile.close();
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
    }
    return locations;
}

void LocationManager::setLocationFromFile() {
    locations = readFromFile(fileName);
}
