//
// Created by May Thu Htun on 31/03/2024.
//

#include "../headers/AirQuality.h"

std::string AirQuality::getChosenVariables() {
    return chosenVariables;
}

void AirQuality::setChosenVariables(std::string variables) {
    chosenVariables = variables;
}

std::string AirQuality::getDomain(){
    return domain;
}

void AirQuality::setDomain(std::string variables) {
    domain = variables;
}

std::string AirQuality::chooseDomain() {
    int choice;
    double tempChoice;
    std::string chosenDomain = "";
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "Which domain you want to use?\n"
                         "1. Global + European (Default)\n"
                         "2. Global (40 km)\n"
                         "3. European (11 km)"<< std::endl;
            std::cin >> tempChoice;

            if(std::cin.fail() || tempChoice < 1 || tempChoice > 3 || tempChoice != static_cast<int>(tempChoice)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Choice must be either 1, 2 or 3. \nPress enter to continue...");
            }else {
                choice = static_cast<int>(tempChoice);
                valid = true;
            }
             if(choice == 1){
                chosenDomain = "";
                valid = true;
            }else if(choice == 2){
                chosenDomain = "&domains=cams_global";
                valid = true;
            } else if(choice == 3){
                chosenDomain = "&domains=cams_europe";
                valid = true;
            }
        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    setDomain(chosenDomain);
    return getDomain();
}

void AirQuality::allHourlyVariables() {
    std::string chosenHourlyVariables = getChosenVariables();
    chosenHourlyVariables += "&hourly=pm10,pm2_5,carbon_monoxide,nitrogen_dioxide,sulphur_dioxide,ozone,aerosol_optical_depth,dust,uv_index,uv_index_clear_sky,ammonia,alder_pollen,birch_pollen,grass_pollen,mugwort_pollen,olive_pollen,ragweed_pollen";
    setChosenVariables(chosenHourlyVariables);
}

void AirQuality::chooseHourlyVariables() {
    std::string chosenHourlyVariables =getChosenVariables();
    std::vector<std::pair<std::string, std::string>> hourlyVariables = {
            {"Particulate Matter PM10", "pm10"},
            {"Particulate Matter PM2.5", "pm2_5"},
            {"Carbon Monoxide CO", "carbon_monoxide"},
            {"Nitrogen Dioxide NO2", "nitrogen_dioxide"},
            {"Sulphur Dioxide SO2", "sulphur_dioxide"},
            {"Ozone O3", "ozone"},
            {"Aerosol Optical Depth", "aerosol_optical_depth"},
            {"Dust", "dust"},
            {"UV Index", "uv_index"},
            {"UV Index Clear Sky", "uv_index_clear_sky"},
            {"Ammonia NH3 (*)", "ammonia"},
            {"Alder Pollen (*)", "alder_pollen"},
            {"Birch Pollen (*)", "birch_pollen"},
            {"Grass Pollen (*)", "grass_pollen"},
            {"Mugwort Pollen (*)", "mugwort_pollen"},
            {"Olive Pollen (*)", "olive_pollen"},
            {"Ragweed Pollen (*)", "ragweed_pollen"}
    };
    chosenHourlyVariables += VariableHandler::formatVariables(hourlyVariables, "&hourly=");
    setChosenVariables(chosenHourlyVariables);
}

void AirQuality::allEuropeanVariables() {
    std::string chosenEuropeanVariable = getChosenVariables();
    chosenEuropeanVariable += "&hourly=european_aqi,european_aqi_pm2_5,european_aqi_pm10,european_aqi_nitrogen_dioxide,european_aqi_ozone,european_aqi_sulphur_dioxide";
    setChosenVariables(chosenEuropeanVariable);
}

void AirQuality::chooseEuropeanVariables() {
    std::string chosenEuropeanVariable = getChosenVariables();
    std::vector<std::pair<std::string, std::string>> europeanVariable = {
            {"European AQI", "european_aqi"},
            {"European AQI PM2.5", "european_aqi_pm2_5"},
            {"European AQI PM10", "european_aqi_pm10"},
            {"European AQI NO2", "european_aqi_nitrogen_dioxide"},
            {"European AQI O3", "european_aqi_ozone"},
            {"European AQI SO2", "european_aqi_sulphur_dioxide"}
    };
    chosenEuropeanVariable += VariableHandler::formatVariables(europeanVariable, "&hourly=");
    setChosenVariables(chosenEuropeanVariable);
}

void AirQuality::allCurrentConditions() {
    std::string chosenCurrentConditions = getChosenVariables();
    chosenCurrentConditions += "&current=european_aqi,us_aqi,pm10,pm2_5,carbon_monoxide,nitrogen_dioxide,sulphur_dioxide,ozone,aerosol_optical_depth,dust,uv_index,uv_index_clear_sky,ammonia,alder_pollen,birch_pollen,grass_pollen,mugwort_pollen,olive_pollen,ragweed_pollen";
    setChosenVariables(chosenCurrentConditions);
}

void AirQuality::chooseCurrentConditions() {
    std::string chosenCurrentConditions = getChosenVariables();
    std::vector<std::pair<std::string, std::string>> currentConditions = {
            {"European AQI", "european_aqi"},
            {"United States AQI", "us_aqi"},
            {"Particulate Matter PM10", "pm10"},
            {"Particulate Matter PM2.5", "pm2_5"},
            {"Carbon Monoxide CO", "carbon_monoxide"},
            {"Nitrogen Dioxide NO2", "nitrogen_dioxide"},
            {"Sulphur Dioxide SO2", "sulphur_dioxide"},
            {"Ozone O3", "ozone"},
            {"Aerosol Optical Depth", "aerosol_optical_depth"},
            {"Dust", "dust"},
            {"UV Index", "uv_index"},
            {"UV Index Clear Sky", "uv_index_clear_sky"},
            {"Ammonia NH3 (*)", "ammonia"},
            {"Alder Pollen (*)", "alder_pollen"},
            {"Birch Pollen (*)", "birch_pollen"},
            {"Grass Pollen (*)", "grass_pollen"},
            {"Mugwort Pollen (*)", "mugwort_pollen"},
            {"Olive Pollen (*)", "olive_pollen"},
            {"Ragweed Pollen (*)", "ragweed_pollen"}
    };
    chosenCurrentConditions += VariableHandler::formatVariables(currentConditions, "&current=");
    setChosenVariables(chosenCurrentConditions);
}

void AirQuality::chooseSetting() {
    std::string chosenSettingVariables = getChosenVariables();
    std::string chosenTimeFormat = Setting::chooseTimeFormat();
    std::string chosenTimeZone = Setting::chooseTimeZone();
    std::string chosenDomain = chooseDomain();
    int choice;
    double tempChoice;
    std::string chosenInterval = "";
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "Do you want to set \n"
                         "1. Forecast Days & Past Days\n"
                         "2. Start Date & End Date\n"
                         "3. None"<< std::endl;
            std::cin >> tempChoice;

            if(std::cin.fail() || tempChoice < 1 || tempChoice > 3 || tempChoice != static_cast<int>(tempChoice)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Choice must be either 1, 2 or 3. \nPress enter to continue...");
            }else{
                choice = static_cast<int>(tempChoice);
                valid = true;
            }
            if(choice == 1){
                chosenInterval += Setting::chooseForecastDays();
                chosenInterval += Setting::choosePastDays();
                valid = true;
            }else if(choice == 2){
                chosenInterval += Setting::chooseStartDate();
                chosenInterval += Setting::chooseEndDate();
                valid = true;
            } else if(choice == 3){
                chosenInterval = "";
                valid = true;
            }
        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    chosenSettingVariables = chosenTimeFormat + chosenTimeZone + chosenInterval + chosenDomain;
    setChosenVariables(chosenSettingVariables);
}

void AirQuality::getDataFromAPI(std::string cityName, std::string variables) {
    if(locationManager.locationExist(cityName)){
        std::string url = API_ENDPOINT + "latitude=" + locationManager.getLatitude(cityName) + "&longitude=" + locationManager.getLongitude(cityName);
        url += variables;
        VariableHandler::getDataFromAPI(url, cityName, "_air_quality.json");
    } else {
        std::cout << "Location does not exist." << std::endl;
    }
}

