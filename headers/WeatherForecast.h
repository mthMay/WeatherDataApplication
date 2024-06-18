//
// Created by May Thu Htun on 14/03/2024.
//

#ifndef SDICWK_WEATHERFORECAST_H
#define SDICWK_WEATHERFORECAST_H

#include "LocationManager.h"
#include "Setting.h"
#include "VariableHandler.h"
#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;

class WeatherForecast: public Setting, public VariableHandler {
private:
    const std::string API_ENDPOINT = "https://api.open-meteo.com/v1/forecast?";
    std::string chosenVariables;
    LocationManager locationManager;
public:
    std::string getChosenVariables();
    void setChosenVariables(std::string);
    void allHourlyVariables();
    void chooseHourlyVariables();
    void allAdditionalVariables();
    void chooseAdditionalVariables();
    void allSolarRadiationVariables();
    void chooseSolarRadiationVaribales();
    std::string choosePressureVariable();
    void allPressureLevelVariables();
    void choosePressureLevelVariables();
    void allWeatherModels();
    void chooseWeatherModels();
    void allDailyWeatherVariables();
    void chooseDailyWeatherVariables();
    void chooseSetting();
    void getDataFromAPI (std::string, std::string);
};

#endif //SDICWK_WEATHERFORECAST_H
