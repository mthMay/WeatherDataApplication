//
// Created by May Thu Htun on 31/03/2024.
//

#ifndef SDICWK_AIRQUALITY_H
#define SDICWK_AIRQUALITY_H

#include "LocationManager.h"
#include "Setting.h"
#include "VariableHandler.h"
#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;

class AirQuality: public Setting, public VariableHandler {
private:
    const std::string API_ENDPOINT = "https://air-quality-api.open-meteo.com/v1/air-quality?";
    std::string chosenVariables;
    std::string domain;
    LocationManager locationManager;
public:
    std::string getChosenVariables();
    void setChosenVariables(std::string);
    std::string getDomain();
    void setDomain(std::string);
    std::string chooseDomain();
    void allHourlyVariables();
    void chooseHourlyVariables();
    void allEuropeanVariables();
    void chooseEuropeanVariables();
    void allCurrentConditions();
    void chooseCurrentConditions();
    void chooseSetting();
    void getDataFromAPI (std::string, std::string);
};

#endif //SDICWK_AIRQUALITY_H
