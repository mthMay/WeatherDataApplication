//
// Created by May Thu Htun on 14/03/2024.
//

#include "../headers/WeatherForecast.h"

std::string WeatherForecast::getChosenVariables() {
    return chosenVariables;
}

void WeatherForecast::setChosenVariables(std::string variables) {
    chosenVariables = variables;
}

void WeatherForecast::allHourlyVariables() {
    std::string chosenHourlyVariables = getChosenVariables();
    chosenHourlyVariables += "&hourly=temperature_2m,relative_humidity_2m,dew_point_2m,apparent_temperature,precipitation_probability,precipitation,rain,showers,snowfall,snow_depth,weather_code,pressure_msl,surface_pressure,cloud_cover,cloud_cover_low,cloud_cover_mid,cloud_cover_high,visibility,evapotranspiration,et0_fao_evapotranspiration,vapour_pressure_deficit,wind_speed_10m,wind_speed_80m,wind_speed_120m,wind_speed_180m,wind_direction_10m,wind_direction_80m,wind_direction_120m,wind_direction_180m,wind_gusts_10m,temperature_80m,temperature_120m,temperature_180m,soil_temperature_0cm,soil_temperature_6cm,soil_temperature_18cm,soil_temperature_54cm,soil_moisture_0_to_1cm,soil_moisture_1_to_3cm,soil_moisture_3_to_9cm,soil_moisture_9_to_27cm,soil_moisture_27_to_81cm";
    setChosenVariables(chosenHourlyVariables);
}

void WeatherForecast::chooseHourlyVariables() {
    std::string chosenHourlyVariables =getChosenVariables();
    /* code for vector pair is modified from
     * https://www.reddit.com/r/cpp_questions/comments/xh5rb8/how_to_create_stdmap_that_preserves_the_order_of/
     * date accessed 28 March 2024
     */
    std::vector<std::pair<std::string, std::string>> hourlyVariables = {
        {"Temperature (2 m)", "temperature_2m"},
        {"Relative Humidity (2 m)", "relative_humidity_2m"},
        {"Dewpoint (2 m)", "dew_point_2m"},
        {"Apparent Temperature", "apparent_temperature"},
        {"Precipitation Probability", "precipitation_probability"},
        {"Precipitation (rain + showers + snow)", "precipitation"},
        {"Rain", "rain"},
        {"Showers", "showers"},
        {"Snowfall", "snowfall"},
        {"Snow Depth", "snow_depth"},
        {"Weather code", "weather_code"},
        {"Sealevel Pressure", "pressure_msl"},
        {"Surface Pressure", "surface_pressure"},
        {"Cloud cover Total", "cloud_cover"},
        {"Cloud cover Low", "cloud_cover_low"},
        {"Cloud cover Mid", "cloud_cover_mid"},
        {"Cloud cover High", "cloud_cover_high"},
        {"Visibility", "visibility"},
        {"Evapotranspiration", "evapotranspiration"},
        {"Reference Evapotranspiration (ET₀)", "et0_fao_evapotranspiration"},
        {"Vapour Pressure Deficit", "vapour_pressure_deficit"},
        {"Wind Speed (10 m)", "wind_speed_10m"},
        {"Wind Speed (80 m)", "wind_speed_80m"},
        {"Wind Speed (120 m)", "wind_speed_120m"},
        {"Wind Speed (180 m)", "wind_speed_180m"},
        {"Wind Direction (10 m)", "wind_direction_10m"},
        {"Wind Direction (80 m)", "wind_direction_80m"},
        {"Wind Direction (120 m)", "wind_direction_120m"},
        {"Wind Direction (180 m)", "wind_direction_180m"},
        {"Wind Gusts (10 m)", "wind_gusts_10m"},
        {"Temperature (80 m)", "temperature_80m"},
        {"Temperature (120 m)", "temperature_120m"},
        {"Temperature (180 m)", "temperature_180m"},
        {"Soil Temperature (0 cm)", "soil_temperature_0cm"},
        {"Soil Temperature (6 cm)", "soil_temperature_6cm"},
        {"Soil Temperature (18 cm)", "soil_temperature_18cm"},
        {"Soil Temperature (54 cm)", "soil_temperature_54cm"},
        {"Soil Moisture (0-1 cm)", "soil_moisture_0_to_1cm"},
        {"Soil Moisture (1-3 cm)", "soil_moisture_1_to_3cm"},
        {"Soil Moisture (3-9 cm)", "soil_moisture_3_to_9cm"},
        {"Soil Moisture (9-27 cm)", "soil_moisture_9_to_27cm"},
        {"Soil Moisture (27-81 cm)", "soil_moisture_27_to_81cm"}
    };
    chosenHourlyVariables += VariableHandler::formatVariables(hourlyVariables, "&hourly=");
    setChosenVariables(chosenHourlyVariables);
}

void WeatherForecast::allAdditionalVariables() {
    std::string chosenAdditionalVariables = getChosenVariables();
    chosenAdditionalVariables += "&hourly=uv_index,uv_index_clear_sky,is_day,cape,freezing_level_height,sunshine_duration";
    setChosenVariables(chosenAdditionalVariables);
}

void WeatherForecast::chooseAdditionalVariables() {
    std::string chosenAdditionalVariables = getChosenVariables();
    std::vector<std::pair<std::string, std::string>> additionalVariables = {
        {"UV Index", "uv_index"},
        {"UV Index Clear Sky", "uv_index_clear_sky"},
        {"Is Day or Night", "is_day"},
        {"CAPE", "cape"},
        {"Freezing Level Height", "freezing_level_height"},
        {"Sunshine Duration", "sunshine_duration"}
    };
    chosenAdditionalVariables += VariableHandler::formatVariables(additionalVariables, "&hourly=");
    setChosenVariables(chosenAdditionalVariables);
}

void WeatherForecast::allSolarRadiationVariables() {
    std::string chosenSolarVariables = getChosenVariables();
    chosenSolarVariables += "&hourly=shortwave_radiation,direct_radiation,diffuse_radiation,direct_normal_irradiance,global_tilted_irradiance,terrestrial_radiation,shortwave_radiation_instant,direct_radiation_instant,diffuse_radiation_instant,direct_normal_irradiance_instant,global_tilted_irradiance_instant,terrestrial_radiation_instant";
    setChosenVariables(chosenSolarVariables);
}

void WeatherForecast::chooseSolarRadiationVaribales() {
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

std::string WeatherForecast::choosePressureVariable() {
    int choice;
    double tempChoice;
    std::string pressureVariableAPIFormat = "";
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "Which pressure level you want to add?\n"
                         "1. Temperature\n"
                         "2. Relative Humidity\n"
                         "3. Cloud cover\n"
                         "4. Wind Speed\n"
                         "5. Wind Direction\n"
                         "6. Geopotential Height\n"
                         "Choose what kind of pressure level you want to add: ";
            std::cin >> tempChoice;

            if(std::cin.fail() || tempChoice < 1 || tempChoice > 6 || tempChoice != static_cast<int>(tempChoice)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Invalid choice. Must be between 1 to 6. \nPress enter to continue...");
            }else{
                choice = static_cast<int>(tempChoice);
                valid = true;
            }
             if(choice == 1){
                pressureVariableAPIFormat = "temperature_";
                valid = true;
            }else if(choice == 2){
                pressureVariableAPIFormat = "relative_humidity_";
                valid = true;
            }else if(choice == 3){
                pressureVariableAPIFormat = "cloud_cover_";
                valid = true;
            }else if(choice == 4){
                pressureVariableAPIFormat = "windspeed_";
                valid = true;
            }else if(choice == 5){
                pressureVariableAPIFormat = "winddirection_";
                valid = true;
            }else if(choice == 6){
                pressureVariableAPIFormat = "geopotential_height_";
                valid = true;
            }
        }
        catch (std::exception& e){
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    return pressureVariableAPIFormat;
}

void WeatherForecast::allPressureLevelVariables() {
    std::string pressureVariable = choosePressureVariable();
    std::string chosenPressureLevel = getChosenVariables();
    if(pressureVariable == "temperature_"){
        chosenPressureLevel += "&hourly=temperature_1000hPa,temperature_975hPa,temperature_950hPa,temperature_925hPa,temperature_900hPa,temperature_850hPa,temperature_800hPa,temperature_700hPa,temperature_600hPa,temperature_500hPa,temperature_400hPa,temperature_300hPa,temperature_250hPa,temperature_200hPa,temperature_150hPa,temperature_100hPa,temperature_70hPa,temperature_50hPa,temperature_30hPa";
    } else if(pressureVariable == "relative_humidity_"){
        chosenPressureLevel += "&hourly=relative_humidity_1000hPa,relative_humidity_975hPa,relative_humidity_950hPa,relative_humidity_925hPa,relative_humidity_900hPa,relative_humidity_850hPa,relative_humidity_800hPa,relative_humidity_700hPa,relative_humidity_600hPa,relative_humidity_500hPa,relative_humidity_400hPa,relative_humidity_300hPa,relative_humidity_250hPa,relative_humidity_200hPa,relative_humidity_150hPa,relative_humidity_100hPa,relative_humidity_70hPa,relative_humidity_50hPa,relative_humidity_30hPa";
    } else if(pressureVariable == "cloud_cover_"){
        chosenPressureLevel += "&hourly=cloud_cover_1000hPa,cloud_cover_975hPa,cloud_cover_950hPa,cloud_cover_925hPa,cloud_cover_900hPa,cloud_cover_850hPa,cloud_cover_800hPa,cloud_cover_700hPa,cloud_cover_600hPa,cloud_cover_500hPa,cloud_cover_400hPa,cloud_cover_300hPa,cloud_cover_250hPa,cloud_cover_200hPa,cloud_cover_150hPa,cloud_cover_100hPa,cloud_cover_70hPa,cloud_cover_50hPa,cloud_cover_30hPa";
    } else if(pressureVariable == "windspeed_"){
        chosenPressureLevel += "&hourly=windspeed_1000hPa,windspeed_975hPa,windspeed_950hPa,windspeed_925hPa,windspeed_900hPa,windspeed_850hPa,windspeed_800hPa,windspeed_700hPa,windspeed_600hPa,windspeed_500hPa,windspeed_400hPa,windspeed_300hPa,windspeed_250hPa,windspeed_200hPa,windspeed_150hPa,windspeed_100hPa,windspeed_70hPa,windspeed_50hPa,windspeed_30hPa";
    } else if(pressureVariable == "winddirection_"){
        chosenPressureLevel += "&hourly=winddirection_1000hPa,winddirection_975hPa,winddirection_950hPa,winddirection_925hPa,winddirection_900hPa,winddirection_850hPa,winddirection_800hPa,winddirection_700hPa,winddirection_600hPa,winddirection_500hPa,winddirection_400hPa,winddirection_300hPa,winddirection_250hPa,winddirection_200hPa,winddirection_150hPa,winddirection_100hPa,winddirection_70hPa,winddirection_50hPa,winddirection_30hPa";
    } else if (pressureVariable == "geopotential_height_"){
        chosenPressureLevel += "&hourly=geopotential_height_1000hPa,geopotential_height_975hPa,geopotential_height_950hPa,geopotential_height_925hPa,geopotential_height_900hPa,geopotential_height_850hPa,geopotential_height_800hPa,geopotential_height_700hPa,geopotential_height_600hPa,geopotential_height_500hPa,geopotential_height_400hPa,geopotential_height_300hPa,geopotential_height_250hPa,geopotential_height_200hPa,geopotential_height_150hPa,geopotential_height_100hPa,geopotential_height_70hPa,geopotential_height_50hPa,geopotential_height_30hPa";
    }
    setChosenVariables(chosenPressureLevel);
}

void WeatherForecast::choosePressureLevelVariables() {
    std::string chosenPressureLevel = getChosenVariables();
    std::string pressureVariable = choosePressureVariable();
    std::vector<std::pair<std::string, std::string>> pressureLevel = {
            {"1000 hPa (110 m)", "1000hPa"},
            {"975 hPa (320 m)", "975hPa"},
            {"950 hPa (500 m)", "950hPa"},
            {"925 hPa (800 m)", "925hPa"},
            {"900 hPa (1000 m)", "900hPa"},
            {"850 hPa (1500 m)", "850hPa"},
            {"800 hPa (1900 m)", "800hPa"},
            {"700 hPa (3 km)", "700hPa"},
            {"600 hPa (4.2 km)", "600hPa"},
            {"500 hPa (5.6 km)", "500hPa"},
            {"400 hPa (7.2 km)", "400hPa"},
            {"300 hPa (9.2 km)", "300hPa"},
            {"250 hPa (10.4 km)", "250hPa"},
            {"200 hPa (11.8 km)", "200hPa"},
            {"150 hPa (13.5 km)", "150hPa"},
            {"100 hPa (15.8 km)", "100hPa"},
            {"70 hPa (17.7 km)", "70hPa"},
            {"50 hPa (19.3 km)", "50hPa"},
            {"30 hPa (22 km)", "30hPa"}
    };
    chosenPressureLevel += VariableHandler::formatVariables(pressureLevel, "&hourly=");
    setChosenVariables(chosenPressureLevel);
};

void WeatherForecast::allWeatherModels(){
    std::string chosenWeatherModels = getChosenVariables();
    chosenWeatherModels += "&models=best_match,ecmwf_ifs04,ecmwf_ifs025,ecmwf_aifs025,cma_grapes_global,bom_access_global,metno_nordic,gfs_seamless,gfs_global,gfs_hrrr,gfs_graphcast025,jma_seamless,jma_msm,jma_gsm,icon_seamless,icon_global,icon_eu,icon_d2,gem_seamless,gem_global,gem_regional,gem_hrdps_continental,meteofrance_seamless,meteofrance_arpege_world,meteofrance_arpege_europe,meteofrance_arome_france,meteofrance_arome_france_hd,arpae_cosmo_seamless,arpae_cosmo_2i,arpae_cosmo_2i_ruc,arpae_cosmo_5m";
    setChosenVariables(chosenWeatherModels);
}

void WeatherForecast::chooseWeatherModels() {
    std::string chosenWeatherModels = getChosenVariables();
    std::vector<std::pair<std::string, std::string>> weatherModels = {
            {"Best match", "best_match"},
            {"ECMWF IFS 0.4°", "ecmwf_ifs04"},
            {"ECMWF IFS 0.25°", "ecmwf_ifs025"},
            {"ECMWF AIFS 0.25°", "ecmwf_aifs025"},
            {"CMA GRAPES Global", "cma_grapes_global"},
            {"BOM ACCESS Global", "bom_access_global"},
            {"MET Norway Nordic", "metno_nordic"},
            {"DWD ICON Seamless", "icon_seamless"},
            {"DWD ICON Global", "icon_global"},
            {"DWD ICON EU", "icon_eu"},
            {"DWD ICON D2", "icon_d2"},
            {"GFS Seamless", "gfs_seamless"},
            {"GFS Global", "gfs_global"},
            {"GFS HRRR", "gfs_hrrr"},
            {"JMA Seamless", "jma_seamless"},
            {"JMA MSM", "jma_msm"},
            {"JMA GSM", "jma_gsm"},
            {"GEM Seamless", "gem_seamless"},
            {"GEM Global", "gem_global"},
            {"GEM Regional", "gem_regional"},
            {"GEM HRDPS Continental", "gem_hrdps_continental"},
            {"Météo-France Seamless", "meteofrance_seamless"},
            {"Météo-France ARPEGE World", "meteofrance_arpege_world"},
            {"Météo-France ARPEGE Europe", "meteofrance_arpege_europe"},
            {"Météo-France AROME France", "meteofrance_arome_france"},
            {"Météo-France AROME France HD", "meteofrance_arome_france_hd"},
            {"ARPAE Seamless", "arpae_cosmo_seamless"},
            {"ARPAE COSMO 2I", "arpae_cosmo_2i"},
            {"ARPAE COSMO 2I RUC", "arpae_cosmo_2i_ruc"},
            {"ARPAE COSMO 5M", "arpae_cosmo_5m"}
    };
    chosenWeatherModels += VariableHandler::formatVariables(weatherModels, "&models=");
    setChosenVariables(chosenWeatherModels);
}

void WeatherForecast::allDailyWeatherVariables() {
    std::string chosenDailyWeatherVariables = getChosenVariables();
    chosenDailyWeatherVariables += "&daily=weather_code,temperature_2m_max,temperature_2m_min,apparent_temperature_max,apparent_temperature_min,sunrise,sunset,daylight_duration,sunshine_duration,uv_index_max,uv_index_clear_sky_max,precipitation_sum,rain_sum,showers_sum,snowfall_sum,precipitation_hours,precipitation_probability_max,wind_speed_10m_max,wind_gusts_10m_max,wind_direction_10m_dominant,shortwave_radiation_sum,et0_fao_evapotranspiration";
    setChosenVariables(chosenDailyWeatherVariables);
}

void WeatherForecast::chooseDailyWeatherVariables() {
    std::string chosenDailyWeatherVariables = getChosenVariables();
    std::vector<std::pair<std::string, std::string>> dailyWeatherVariables = {
            {"Weather code", "weather_code"},
            {"Maximum Temperature (2 m)", "temperature_2m_max"},
            {"Minimum Temperature (2 m)", "temperature_2m_min"},
            {"Maximum Apparent Temperature (2 m)", "apparent_temperature_max"},
            {"Minimum Apparent Temperature (2 m)", "apparent_temperature_min"},
            {"Sunrise", "sunrise"},
            {"Sunset", "sunset"},
            {"Daylight Duration", "daylight_duration"},
            {"Sunshine Duration", "sunshine_duration"},
            {"UV Index", "uv_index_max"},
            {"UV Index Clear Sky", "uv_index_clear_sky_max"},
            {"Precipitation Sum", "precipitation_sum"},
            {"Rain Sum", "rain_sum"},
            {"Showers Sum", "showers_sum"},
            {"Snowfall Sum", "snowfall_sum"},
            {"Precipitation Hours", "precipitation_hours"},
            {"Precipitation Probability Max", "precipitation_probability_max"},
            {"Maximum Wind Speed (10 m)", "wind_speed_10m_max"},
            {"Maximum Wind Gusts (10 m)", "wind_gusts_10m_max"},
            {"Dominant Wind Direction (10 m)", "wind_direction_10m_dominant"},
            {"Shortwave Radiation Sum", "shortwave_radiation_sum"},
            {"Reference Evapotranspiration (ET₀)", "et0_fao_evapotranspiration"}
    };
    chosenDailyWeatherVariables += VariableHandler::formatVariables(dailyWeatherVariables, "&daily=");
    setChosenVariables(chosenDailyWeatherVariables);
}

void WeatherForecast::chooseSetting() {
    std::string chosenSettingVariables = getChosenVariables();
    std::string chosenTemperatureUnit = Setting::chooseTemperatureUnit();
    std::string chosenWindSpeedUnit = Setting::chooseWindSpeedUnit();
    std::string chosenPrecipitationUnit = Setting::choosePrecipitationUnit();
    std::string chosenTimeFormat = Setting::chooseTimeFormat();
    std::string chosenTimeZone = Setting::chooseTimeZone();
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

            if(std::cin.fail() ||tempChoice <1 || tempChoice>3 || tempChoice != static_cast<int>(tempChoice)){
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
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    chosenSettingVariables = chosenTemperatureUnit + chosenWindSpeedUnit + chosenPrecipitationUnit + chosenTimeFormat + chosenTimeZone + chosenInterval;
    setChosenVariables(chosenSettingVariables);
}

void WeatherForecast::getDataFromAPI(std::string cityName, std::string variables) {
    if(locationManager.locationExist(cityName)){
        std::string url = API_ENDPOINT + "latitude=" + locationManager.getLatitude(cityName) + "&longitude=" + locationManager.getLongitude(cityName);
        url += variables;
        VariableHandler::getDataFromAPI(url, cityName, "_weather_forecast.json");
    } else {
        std::cout << "Location does not exist." << std::endl;
    }
}
