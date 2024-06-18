//
// Created by May Thu Htun on 28/03/2024.
//

#ifndef SDICWK_SETTING_H
#define SDICWK_SETTING_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Setting {
protected:
    std::string temperatureUnit;
    std::string windSpeedUnit;
    std::string precipitationUnit;
    std::string timeFormat;
    std::string timeZone;
    std::string pastDays;
    std::string forecastDays;
    std::string startDate;
    std::string endDate;
public:
    std::string getTemperatureUnit();
    void setTemperatureUnit(std::string);
    std::string getWindSpeedUnit();
    void setWindSpeedUnit(std::string);
    std::string getPrecipitationUnit();
    void setPrecipitationUnit(std::string);
    std::string getTimeFormat();
    void setTimeFormat(std::string);
    std::string getTimeZone();
    void setTimeZone(std::string);
    std::string getPastDays();
    void setPastDays(std::string);
    std::string getForecastDays();
    void setForecastDays(std::string);
    std::string getStartDate();
    void setStartDate(std::string);
    std::string getEndDate();
    void setEndDate(std::string);
    std::string chooseTemperatureUnit();
    std::string chooseWindSpeedUnit();
    std::string choosePrecipitationUnit();
    std::string chooseTimeFormat();
    std::string chooseTimeZone();
    std::string chooseForecastDays();
    std::string choosePastDays();
    std::string chooseStartDate();
    std::string chooseEndDate();
};
#endif //SDICWK_SETTING_H
