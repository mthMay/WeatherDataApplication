//
// Created by May Thu Htun on 06/03/2024.
//

#ifndef SDICWK_MAINMENU_H
#define SDICWK_MAINMENU_H

#include <iostream>
#include <limits>
#include "LocationManager.h"
#include "AirQuality.h"
#include "HistoricalWeather.h"
#include "WeatherForecast.h"

class MainMenu: public AirQuality, public HistoricalWeather, public WeatherForecast , public LocationManager {
private:
    int choice;
public:
    int getChoice();
    void setChoice(int);
    int menu();
    int airQualityMenu();
    void airQualityMenuController(int);
    int historicalWeatherMenu();
    void historicalWeatherMenuController (int);
    int weatherForecastMenu();
    void weatherForecastMenuController (int);
    int locationMenu();
    void locationMenuController (int);
};

#endif //SDICWK_MAINMENU_H
