//
// Created by May Thu Htun on 30/03/2024.
//

#ifndef SDICWK_HISTORICALWEATHER_H
#define SDICWK_HISTORICALWEATHER_H

#include "LocationManager.h"
#include "Setting.h"
#include "VariableHandler.h"
#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;

class HistoricalWeather: public Setting, public VariableHandler {
private:
    const std::string API_ENDPOINT = "https://archive-api.open-meteo.com/v1/archive?";
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
    void allReanalysisModels();
    void chooseReanalysisModels();
    void allDailyWeatherVariables();
    void chooseDailyWeatherVariables();
    void chooseSetting();
    void getDataFromAPI (std::string, std::string);
};

#endif //SDICWK_HISTORICALWEATHER_H
