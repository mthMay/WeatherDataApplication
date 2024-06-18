//
// Created by May Thu Htun on 30/03/2024.
//

#include "../headers/HistoricalWeather.h"
std::string HistoricalWeather::getChosenVariables() {
    return chosenVariables;
}

void HistoricalWeather::setChosenVariables(std::string variables) {
    chosenVariables = variables;
}

void HistoricalWeather::allHourlyVariables() {
    std::string chosenHourlyVariables = getChosenVariables();
    chosenHourlyVariables += "&hourly=temperature_2m,relative_humidity_2m,dew_point_2m,apparent_temperature,precipitation,rain,snowfall,snow_depth,weather_code,pressure_msl,surface_pressure,cloud_cover,cloud_cover_low,cloud_cover_mid,cloud_cover_high,et0_fao_evapotranspiration,vapour_pressure_deficit,wind_speed_10m,wind_speed_100m,wind_direction_10m,wind_direction_100m,wind_gusts_10m,soil_temperature_0_to_7cm,soil_temperature_7_to_28cm,soil_temperature_28_to_100cm,soil_temperature_100_to_255cm,soil_moisture_0_to_7cm,soil_moisture_7_to_28cm,soil_moisture_28_to_100cm,soil_moisture_100_to_255cm";
    setChosenVariables(chosenHourlyVariables);
}

void HistoricalWeather::chooseHourlyVariables() {
    std::string chosenHourlyVariables =getChosenVariables();
    std::vector<std::pair<std::string, std::string>> hourlyVariables = {
            {"Temperature (2 m)", "temperature_2m"},
            {"Relative Humidity (2 m)", "relative_humidity_2m"},
            {"Dewpoint (2 m)", "dew_point_2m"},
            {"Apparent Temperature", "apparent_temperature"},
            {"Precipitation (rain + showers + snow)", "precipitation"},
            {"Rain", "rain"},
            {"Snowfall", "snowfall"},
            {"Snow Depth", "snow_depth"},
            {"Weather code", "weather_code"},
            {"Sealevel Pressure", "pressure_msl"},
            {"Surface Pressure", "surface_pressure"},
            {"Cloud cover Total", "cloud_cover"},
            {"Cloud cover Low", "cloud_cover_low"},
            {"Cloud cover Mid", "cloud_cover_mid"},
            {"Cloud cover High", "cloud_cover_high"},
            {"Reference Evapotranspiration (ET₀)", "et0_fao_evapotranspiration"},
            {"Vapour Pressure Deficit", "vapour_pressure_deficit"},
            {"Wind Speed (10 m)", "wind_speed_10m"},
            {"Wind Speed (100 m)", "wind_speed_100m"},
            {"Wind Direction (10 m)", "wind_direction_10m"},
            {"Wind Direction (100 m)", "wind_direction_100m"},
            {"Wind Gusts (10 m)", "wind_gusts_10m"},
            {"Soil Temperature (0-7 cm)", "soil_temperature_0_to_7cm"},
            {"Soil Temperature (7-28 cm)", "soil_temperature_7_to_28cm"},
            {"Soil Temperature (28-100 cm)", "soil_temperature_28_to_100cm"},
            {"Soil Temperature (100-255 cm)", "soil_temperature_100_to_255cm"},
            {"Soil Moisture (0-7 cm)", "soil_moisture_0_to_7cm"},
            {"Soil Moisture (7-28 cm)", "soil_moisture_7_to_28cm"},
            {"Soil Moisture (28-100 cm)", "soil_moisture_28_to_100cm"},
            {"Soil Moisture (100-255 cm)", "soil_moisture_100_to_255cm"},
    };
    chosenHourlyVariables += VariableHandler::formatVariables(hourlyVariables, "&hourly=");
    setChosenVariables(chosenHourlyVariables);
}

void HistoricalWeather::allAdditionalVariables() {
    std::string chosenAdditionalVariables = getChosenVariables();
    chosenAdditionalVariables += "&hourly=is_day,sunshine_duration";
    setChosenVariables(chosenAdditionalVariables);
}

void HistoricalWeather::chooseAdditionalVariables() {
    std::string chosenAdditionalVariables = getChosenVariables();
    std::vector<std::pair<std::string, std::string>> additionalVariables = {
            {"Is Day or Night", "is_day"},
            {"Sunshine Duration", "sunshine_duration"}
    };
    chosenAdditionalVariables += VariableHandler::formatVariables(additionalVariables, "&hourly=");
    setChosenVariables(chosenAdditionalVariables);
}

void HistoricalWeather::allSolarRadiationVariables() {
    std::string chosenSolarVariables = getChosenVariables();
    chosenSolarVariables += "&hourly=shortwave_radiation,direct_radiation,diffuse_radiation,direct_normal_irradiance,global_tilted_irradiance,terrestrial_radiation,shortwave_radiation_instant,direct_radiation_instant,diffuse_radiation_instant,direct_normal_irradiance_instant,global_tilted_irradiance_instant,terrestrial_radiation_instant";
    setChosenVariables(chosenSolarVariables);
}

void HistoricalWeather::chooseSolarRadiationVaribales() {
    std::string chosenSolarVariables = getChosenVariables();
    std::vector<std::pair<std::string, std::string>> solarVariables = {
            {"Shortwave Solar Radiation GHI", "shortwave_radiation"},
            {"Direct Solar Radiation", "direct_radiation"},
            {"Diffuse Solar Radiation DHI", "diffuse_radiation"},
            {"Direct Normal Irradiance DNI", "direct_normal_irradiance"},
            {"Global Tilted Radiation GTI", "global_tilted_irradiance"},
            {"Terrestrial Solar Radiation", "terrestrial_radiation"},
            {"Shortwave Solar Radiation GHI (Instant)", "shortwave_radiation_instant"},
            {"Direct Solar Radiation (Instant)", "direct_radiation_instant"},
            {"Diffuse Solar Radiation DHI (Instant)", "diffuse_radiation_instant"},
            {"Direct Normal Irradiance DNI (Instant)", "direct_normal_irradiance_instant"},
            {"Global Tilted Radiation GTI", "global_tilted_irradiance_instant"},
            {"Terrestrial Solar Radiation (Instant)", "terrestrial_radiation_instant"}
    };
    chosenSolarVariables += VariableHandler::formatVariables(solarVariables, "&hourly=");
    setChosenVariables(chosenSolarVariables);
}

void HistoricalWeather::allReanalysisModels() {
    std::string chosenReanalysisModels = getChosenVariables();
    chosenReanalysisModels += "models=best_match,ecmwf_ifs,era5_seamless,era5,era5_land,cerra";
    setChosenVariables(chosenReanalysisModels);
}

void HistoricalWeather::chooseReanalysisModels() {
    std::string chosenReanalysisModels = getChosenVariables();
    std::vector<std::pair<std::string, std::string>> reanalysisModels = {
            {"Best match (ECMWF IFS & ERA5)", "best_match"},
            {"ECMWF IFS (9 km, Global, 2017 onwards)", "ecmwf_ifs"},
            {"ERA5-Seamless (ERA5 & ERA5-Land combined)", "era5_seamless"},
            {"ERA5 (25 km, Global)", "era5"},
            {"ERA5-Land (10 km, Global)", "era5_land"},
            {"MCERRA (5 km, Europe, 1985 to June 2021)", "cerra"}
    };
    chosenReanalysisModels += VariableHandler::formatVariables(reanalysisModels, "&models=");
    setChosenVariables(chosenReanalysisModels);
}

void HistoricalWeather::allDailyWeatherVariables() {
    std::string chosenDailyWeatherVariables = getChosenVariables();
    chosenDailyWeatherVariables += "daily=weather_code,temperature_2m_max,temperature_2m_min,temperature_2m_mean,apparent_temperature_max,apparent_temperature_min,apparent_temperature_mean,sunrise,sunset,daylight_duration,sunshine_duration,precipitation_sum,rain_sum,snowfall_sum,precipitation_hours,wind_speed_10m_max,wind_gusts_10m_max,wind_direction_10m_dominant,shortwave_radiation_sum,et0_fao_evapotranspiration";
    setChosenVariables(chosenDailyWeatherVariables);
}

void HistoricalWeather::chooseDailyWeatherVariables() {
    std::string chosenDailyWeatherVariables = getChosenVariables();
    std::vector<std::pair<std::string, std::string>> dailyWeatherVariables = {
            {"Weather code", "weather_code"},
            {"Maximum Temperature (2 m)", "temperature_2m_max"},
            {"Minimum Temperature (2 m)", "temperature_2m_min"},
            {"Mean Temperature (2 m)", "temperature_2m_mean"},
            {"Maximum Apparent Temperature (2 m)", "apparent_temperature_max"},
            {"Minimum Apparent Temperature (2 m)", "apparent_temperature_min"},
            {"Mean Apparent Temperature (2 m)", "apparent_temperature_mean"},
            {"Sunrise", "sunrise"},
            {"Sunset", "sunset"},
            {"Daylight Duration", "daylight_duration"},
            {"Sunshine Duration", "sunshine_duration"},
            {"Precipitation Sum", "precipitation_sum"},
            {"Rain Sum", "rain_sum"},
            {"Snowfall Sum", "snowfall_sum"},
            {"Precipitation Hours", "precipitation_hours"},
            {"Maximum Wind Speed (10 m)", "wind_speed_10m_max"},
            {"Maximum Wind Gusts (10 m)", "wind_gusts_10m_max"},
            {"Dominant Wind Direction (10 m)", "wind_direction_10m_dominant"},
            {"Shortwave Radiation Sum", "shortwave_radiation_sum"},
            {"Reference Evapotranspiration (ET₀)", "et0_fao_evapotranspiration"}
    };
    chosenDailyWeatherVariables += VariableHandler::formatVariables(dailyWeatherVariables, "&daily=");
    setChosenVariables(chosenDailyWeatherVariables);
}

void HistoricalWeather::chooseSetting() {
    std::string chosenSettingVariables = getChosenVariables();
    std::string chosenTemperatureUnit = Setting::chooseTemperatureUnit();
    std::string chosenWindSpeedUnit = Setting::chooseWindSpeedUnit();
    std::string chosenPrecipitationUnit = Setting::choosePrecipitationUnit();
    std::string chosenTimeFormat = Setting::chooseTimeFormat();
    std::string chosenTimeZone = Setting::chooseTimeZone();
    chosenSettingVariables = chosenTemperatureUnit + chosenWindSpeedUnit + chosenPrecipitationUnit + chosenTimeFormat + chosenTimeZone;
    setChosenVariables(chosenSettingVariables);
}

void HistoricalWeather::getDataFromAPI(std::string cityName, std::string variables) {
    if(locationManager.locationExist(cityName)){
        std::string startDate = Setting::chooseStartDate();
        std::string endDate = Setting::chooseEndDate();
        std::string url = API_ENDPOINT + "latitude=" + locationManager.getLatitude(cityName) + "&longitude=" + locationManager.getLongitude(cityName);
        url += startDate + endDate + variables;
        VariableHandler::getDataFromAPI(url, cityName, "_historical_weather.json");
    } else {
        std::cout << "Location does not exist." << std::endl;
    }
}
