//
// Created by May Thu Htun on 28/03/2024.
//

#include "../headers/Setting.h"

std::string Setting::getTemperatureUnit() {
    return temperatureUnit;
}

void Setting::setTemperatureUnit(std::string choice) {
    temperatureUnit = choice;
}

std::string Setting::getWindSpeedUnit(){
    return windSpeedUnit;
}

void Setting::setWindSpeedUnit(std::string choice){
    windSpeedUnit = choice;
}

std::string Setting::getPrecipitationUnit(){
    return precipitationUnit;
}

void Setting::setPrecipitationUnit(std::string choice){
    precipitationUnit = choice;
}

std::string Setting::getTimeFormat(){
    return timeFormat;
}

void Setting::setTimeFormat(std::string choice){
    timeFormat = choice;
}

std::string Setting::getTimeZone(){
    return timeZone;
}

void Setting::setTimeZone(std::string choice){
    timeZone = choice;
}

std::string Setting::getPastDays(){
    return pastDays;
}

void Setting::setPastDays(std::string choice){
    pastDays = choice;
}

std::string Setting::getForecastDays() {
    return forecastDays;
}

void Setting::setForecastDays(std::string choice) {
    forecastDays = choice;
}

std::string Setting::getStartDate(){
    return startDate;
}

void Setting::setStartDate(std::string date){
    startDate = date;
}

std::string Setting::getEndDate(){
    return endDate;
}

void Setting::setEndDate(std::string date){
    endDate = date;
}

std::string Setting::chooseTemperatureUnit(){
    int choice;
    double tempChoice;
    std::string chosenTemperatureUnit = "";
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "Which temperature unit you want to use?\n"
                         "1. Celsius °C (Default)\n"
                         "2. Fahrenheit °F" << std::endl;
            std::cin >> tempChoice;

            if(std::cin.fail() || tempChoice < 1 || tempChoice > 2 || tempChoice != static_cast<int>(tempChoice)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Choice must be either 1 or 2. \nPress enter to continue...");
            }
            else{
                choice = static_cast<int>(tempChoice);
                if(choice == 1){
                    chosenTemperatureUnit = "";
                    valid = true;
                }else if(choice == 2){
                    chosenTemperatureUnit = "&temperature_unit=fahrenheit";
                    valid = true;
                }
            }

        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    setTemperatureUnit(chosenTemperatureUnit);
    return getTemperatureUnit();
}

std::string Setting::chooseWindSpeedUnit(){
    int choice;
    double tempChoice;
    std::string chosenWindSpeedUnit = "";
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "Which wind speed unit you want to use?\n"
                         "1. Km/h (Default)\n"
                         "2. m/s\n"
                         "3. Mph\n"
                         "4. Knots"<< std::endl;
            std::cin >> tempChoice;

            if(std::cin.fail() || tempChoice < 1 || tempChoice > 4 || tempChoice != static_cast<int>(tempChoice)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Choice must be between 1 to 4. \nPress enter to continue...");
            }
            else{
                choice = static_cast<int>(tempChoice);
                if(choice == 1){
                    chosenWindSpeedUnit = "";
                    valid = true;
                }else if(choice == 2){
                    chosenWindSpeedUnit = "&wind_speed_unit=ms";
                    valid = true;
                }else if(choice == 3){
                    chosenWindSpeedUnit = "&wind_speed_unit=mph";
                    valid = true;
                }else if(choice == 4){
                    chosenWindSpeedUnit = "&wind_speed_unit=kn";
                    valid = true;
                }
            }
        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    setWindSpeedUnit(chosenWindSpeedUnit);
    return getWindSpeedUnit();
}

std::string Setting::choosePrecipitationUnit(){
    int choice;
    double tempChoice;
    std::string chosenPrecipitationUnit = "";
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "Which precipitation unit you want to use?\n"
                         "1. Millimeter (Default)\n"
                         "2. Inch" << std::endl;
            std::cin >> tempChoice;

            if(std::cin.fail() || tempChoice < 1 || tempChoice > 2 || tempChoice != static_cast<int>(tempChoice)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Choice must be either 1 or 2. \nPress enter to continue...");
            }
            else{
                choice = static_cast<int>(tempChoice);
                if(choice == 1){
                    chosenPrecipitationUnit = "";
                    valid = true;
                }else if(choice == 2){
                    chosenPrecipitationUnit = "&precipitation_unit=inch";
                    valid = true;
                }
            }

        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    setPrecipitationUnit(chosenPrecipitationUnit);
    return getPrecipitationUnit();
}

std::string Setting::chooseTimeFormat(){
    int choice;
    double tempChoice;
    std::string chosenTimeFormat = "";
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "Which timeformat you want to use?\n"
                         "1. ISO 8602 (e.g. 2022-12-31) (Default)\n"
                         "2. Unix Timestamp" << std::endl;
            std::cin >> tempChoice;

            if(std::cin.fail() || tempChoice < 1 || tempChoice > 2 || tempChoice != static_cast<int>(tempChoice)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Choice must either 1 or 2. \nPress enter to continue...");
            }
            else {
                choice = static_cast<int>(tempChoice);
                if(choice == 1){
                    chosenTimeFormat = "";
                    valid = true;
                }else if(choice == 2){
                    chosenTimeFormat = "&timeformat=unixtime";
                    valid = true;
                }
            }

        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    setTimeFormat(chosenTimeFormat);
    return getTimeFormat();
}

std::string Setting::chooseTimeZone() {
    int choice;
    double tempChoice;
    std::string chosenTimeZone = "";
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "Which timezone you want to use?\n"
                         "1. GMT + 0 (Default)\n"
                         "2. America/Anchorage\n"
                         "3. America/Los_Angeles\n"
                         "4. America/Denver\n"
                         "5. America/Chicago\n"
                         "6. America/New_York\n"
                         "7. America/Sao_Paulo\n"
                         "8. Automatically detect time zone\n"
                         "9. Europe/London\n"
                         "10. Europe/Berlin\n"
                         "11. Europe/Moscow\n"
                         "12. Africa/Cairo\n"
                         "13. Asia/Bangkok\n"
                         "14. Asia/Singapore\n"
                         "15. Asia/Tokyo\n"
                         "16. Australia/Sydney\n"
                         "17. Pacific/Auckland" << std::endl;
            std::cin >> tempChoice ;

            if(std::cin.fail() || tempChoice < 1 || tempChoice > 17 || tempChoice != static_cast<int>(tempChoice)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Choice must be between 1 and 17.. \nPress enter to continue...");
            }
            else{
                choice = static_cast<int>(tempChoice);
                if(choice == 1){
                    chosenTimeZone = "";
                    valid = true;
                }else if(choice == 2){
                    chosenTimeZone = "&timezone=America%2FAnchorage";
                    valid = true;
                }else if(choice == 3){
                    chosenTimeZone = "&timezone=America%2FLos_Angeles";
                    valid = true;
                }else if(choice == 4){
                    chosenTimeZone = "&timezone=America%2FDenver";
                    valid = true;
                }else if(choice == 5){
                    chosenTimeZone = "&timezone=America%2FChicago";
                    valid = true;
                }else if(choice == 6){
                    chosenTimeZone = "&timezone=America%2FNew_York";
                    valid = true;
                }else if(choice == 7){
                    chosenTimeZone = "&timezone=America%2FSao_Paulo";
                    valid = true;
                }else if(choice == 8){
                    chosenTimeZone = "&timezone=auto";
                    valid = true;
                }else if(choice == 9){
                    chosenTimeZone = "&timezone=Europe%2FLondon";
                    valid = true;
                }else if(choice == 10){
                    chosenTimeZone = "&timezone=Europe%2FBerlin";
                    valid = true;
                }else if(choice == 11){
                    chosenTimeZone = "&timezone=Europe%2FMoscow";
                    valid = true;
                }else if(choice == 12){
                    chosenTimeZone = "&timezone=Africa%2FCairo";
                    valid = true;
                }else if(choice == 13){
                    chosenTimeZone = "&timezone=Asia%2FBangkok";
                    valid = true;
                }else if(choice == 14){
                    chosenTimeZone = "&timezone=Asia%2FSingapore";
                    valid = true;
                }else if(choice == 15){
                    chosenTimeZone = "&timezone=Asia%2FTokyo";
                    valid = true;
                }else if(choice == 16){
                    chosenTimeZone = "&timezone=Australia%2FSydney";
                    valid = true;
                }else if(choice == 17){
                    chosenTimeZone = "&timezone=Pacific%2FAuckland";
                    valid = true;
                }
            }

        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    setTimeZone(chosenTimeZone);
    return getTimeZone();
}

std::string Setting::chooseForecastDays() {
    int choice;
    double tempChoice;
    std::string chosenForecastDays = "";
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "Choose your desire forecast days: \n"
                         "1. 1 day\n"
                         "2. 3 days\n"
                         "3. 7 days (Default)\n"
                         "4. 14 days\n"
                         "5. 16 days"<< std::endl;
            std::cin >> tempChoice;

            if(std::cin.fail() || tempChoice < 1 || tempChoice > 5 || tempChoice != static_cast<int>(tempChoice)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Choice must be between 1 to 5. \nPress enter to continue...");
            }
            else{
                choice = static_cast<int>(tempChoice);
                if(choice == 1){
                    chosenForecastDays = "&forecast_days=1";
                    valid = true;
                }else if(choice == 2){
                    chosenForecastDays = "&forecast_days=3";
                    valid = true;
                }else if(choice == 3){
                    chosenForecastDays = "";
                    valid = true;
                }else if(choice == 4){
                    chosenForecastDays = "&forecast_days=14";
                    valid = true;
                }else if(choice == 5){
                    chosenForecastDays = "&forecast_days=16";
                    valid = true;
                }
            }

        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    setForecastDays(chosenForecastDays);
    return getForecastDays();
}

std::string Setting::choosePastDays() {
    int choice;
    double tempChoice;
    std::string chosenPastDays = "";
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "Choose your desire past days\n"
                         "1. 0 (Default)\n"
                         "2. 1\n"
                         "3. 2\n"
                         "4. 3\n"
                         "5. 5\n"
                         "6. 1 week\n"
                         "7. 2 weeks\n"
                         "8. 1 month\n"
                         "9. 2 months\n"
                         "10. 3 months" << std::endl;
            std::cin >> tempChoice;

            if(std::cin.fail() || tempChoice < 1 || tempChoice > 10 || tempChoice != static_cast<int>(tempChoice)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Choice must be between 1 to 10. \nPress enter to continue...");
            }
            else {
                choice = static_cast<int>(tempChoice);
                if(choice == 1){
                    chosenPastDays = "";
                    valid = true;
                }else if(choice == 2){
                    chosenPastDays = "&past_days=1";
                    valid = true;
                }else if(choice == 3){
                    chosenPastDays = "&past_days=2";
                    valid = true;
                }else if(choice == 4){
                    chosenPastDays = "&past_days=3";
                    valid = true;
                }else if(choice == 5){
                    chosenPastDays = "&past_days=5";
                    valid = true;
                }else if(choice == 6){
                    chosenPastDays = "&past_days=7";
                    valid = true;
                }else if(choice == 7){
                    chosenPastDays = "&past_days=14";
                    valid = true;
                }else if(choice == 8){
                    chosenPastDays = "&past_days=31";
                    valid = true;
                }else if(choice == 9){
                    chosenPastDays = "&past_days=61";
                    valid = true;
                }else if(choice == 10){
                    chosenPastDays = "&past_days=92";
                    valid = true;
                }
            }

        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    setPastDays(chosenPastDays);
    return getPastDays();
}

std::string Setting::chooseStartDate() {
    /* code to get current date and time is modifed from
     * https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
     * https://www.geeksforgeeks.org/date-and-time-parsing-in-cpp/
     * date accessed 29 March 2024
     */
    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* currentTime = std::localtime(&now);
    std::stringstream ss;
    ss << std::put_time(currentTime, "%Y-%m-%d");
    std::string currentDate = ss.str();
    std::string currentYear = currentDate.substr(0, 4);
    std::string currentMonth = currentDate.substr(5, 2);
    std::string currentDay = currentDate.substr(8, 2);
    int currentYearInt = stoi(currentYear);
    int currentMonthInt = stoi(currentMonth);
    int currentDayInt = stoi(currentDay);
    int startDay, startMonth, startYear;
    std::string date, startMonthString, startYearString, startDayString;
    bool valid = false;
    bool valid2 = false;
    bool valid3 = false;
    double input, input2, input3;
    while (valid == false){
        try{
            std::cout << "Start Date\n"
                         "Enter Year: ";
            std::cin >> input;

            if(std::cin.fail() || input != static_cast<int>(input)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Year must be an integer. \nPress enter to continue...");
            } else {
                startYear = static_cast<int>(input);
                if(startYear < 0){
                    valid = false;
                    throw std::domain_error("Negative value not accepted.");
                }
                if(std::to_string(startYear).length() != 4){
                    valid = false;
                    throw std::domain_error ("Year must be 4 digits.");
                }
                if(startYear > currentYearInt){
                    valid = false;
                    throw std::domain_error("Input year exceeds current year.");
                }
                else {
                    startYearString = std::to_string(startYear);
                    valid = true;
                }
            }
        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    while (valid2 == false){
        try{
            std::cout << "Enter Month: ";
            std::cin >> input2;

            if(std::cin.fail() || input2 != static_cast<int>(input2)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid2 = false;
                throw std::runtime_error ("Month must be an integer. \nPress enter to continue...");
            } else{
                startMonth = static_cast<int>(input2);
                if(currentYearInt == startYear && startMonth > currentMonthInt){
                    valid2 = false;
                    throw std::domain_error("Out of Range.");
                }
                if(startMonth < 1 || startMonth > 12 ){
                    valid2 = false;
                    throw std::domain_error("Value not accepted.");
                }
                if(startMonth < 10 && startMonth > 0){
                    startMonthString = "0" + std::to_string(startMonth);
                    valid2 = true;
                }
                if(startMonth == 10 || startMonth == 11 || startMonth == 12 ){
                    startMonthString = std::to_string(startMonth);
                    valid2 = true;
                }
            }
        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    while (valid3 == false){
        try{
            std::cout << "Enter day: ";
            std::cin >> input3;

            if(std::cin.fail() || input3 != static_cast<int>(input3)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid3 = false;
                throw std::runtime_error ("Day must be an integer. \nPress enter to continue...");
            } else{
                startDay =static_cast<int>(input3);
                if(currentYearInt == startYear && currentMonthInt == startMonth && startDay > currentDayInt){
                    valid3 = false;
                    throw std::domain_error("Out of Range.");
                }
                if(startMonth == 9 || startMonth == 4 || startMonth == 6 || startMonth == 11) {
                    if (startDay < 1 || startDay > 30) {
                        valid3 = false;
                        throw std::domain_error("Value not accepted.");
                    } else {
                        if(startDay < 10 && startDay > 0){
                            startDayString = "0" + std::to_string(startDay);
                        } else{
                            startDayString = std::to_string(startDay);
                        }
                        valid3 = true;
                    }
                } else if(startMonth == 2){
                    if (startDay < 1 || startDay > 28) {
                        valid3 = false;
                        throw std::domain_error("Value not accepted.");
                    } else {
                        if(startDay < 10 && startDay > 0){
                            startDayString = "0" + std::to_string(startDay);
                        } else{
                            startDayString = std::to_string(startDay);
                        }
                        valid3 = true;
                    }
                } else if (startMonth != 9 && startMonth != 4 && startMonth != 6 && startMonth != 11 && startMonth != 2){
                    if (startDay < 1 || startDay > 31) {
                        valid3 = false;
                        throw std::domain_error("Value not accepted.");
                    } else {
                        if(startDay < 10 && startDay > 0){
                            startDayString = "0" + std::to_string(startDay);
                        } else{
                            startDayString = std::to_string(startDay);
                        }
                        valid3 = true;
                    }
                }
            }

        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    date = "&start_date=" + startYearString + "-" + startMonthString + "-" + startDayString;
    setStartDate(date);
    return getStartDate();
}

std::string Setting::chooseEndDate() {
    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* currentTime = std::localtime(&now);
    std::stringstream ss;
    ss << std::put_time(currentTime, "%Y-%m-%d");
    std::string currentDate = ss.str();
    std::string currentYear = currentDate.substr(0, 4);
    std::string currentMonth = currentDate.substr(5, 2);
    std::string currentDay = currentDate.substr(8, 2);
    int currentYearInt = stoi(currentYear);
    int currentMonthInt = stoi(currentMonth);
    int currentDayInt = stoi(currentDay);
    int endDay, endMonth, endYear;
    std::string date, endMonthString, endYearString, endDayString;
    bool valid = false;
    bool valid2 = false;
    bool valid3 = false;
    double input, input2, input3;
    while (valid == false){
        try{
            std::cout << "End Date\n"
                         "Enter Year: ";
            std::cin >> input;

            if(std::cin.fail() || input != static_cast<int>(input)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Year must be an integer. \nPress enter to continue...");
            }else{
                endYear = static_cast<int>(input);
                if(endYear < 0){
                    valid = false;
                    throw std::domain_error("Negative value not accepted.");
                }
                if(std::to_string(endYear).length() != 4){
                    valid = false;
                    throw std::domain_error ("Year must be 4 digits.");
                }
                if(endYear > currentYearInt){
                    valid = false;
                    throw std::domain_error("Input year exceeds current year.");
                }
                else {
                    endYearString = std::to_string(endYear);
                    valid = true;
                }
            }
        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    while (valid2 == false){
        try{
            std::cout << "Enter Month: ";
            std::cin >> input2;

            if(std::cin.fail() || input2 != static_cast<int>(input2)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid2 = false;
                throw std::runtime_error ("Month must be an integer. \nPress enter to continue...");
            } else{
                endMonth = static_cast<int>(input2);
                if(currentYearInt == endYear && endMonth > currentMonthInt){
                    valid2 = false;
                    throw std::domain_error("Out of Range.");
                }
                if(endMonth < 1 || endMonth > 12 ){
                    valid2 = false;
                    throw std::domain_error("Value not accepted.");
                }
                if(endMonth < 10 && endMonth > 0){
                    endMonthString = "0" + std::to_string(endMonth);
                    valid2 = true;
                }
                if(endMonth == 11 || endMonth == 12){
                    endMonthString = std::to_string(endMonth);
                    valid2 = true;
                }
            }

        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    while (valid3 == false){
        try{
            std::cout << "Enter day: ";
            std::cin >> input3;

            if(std::cin.fail() || input3 != static_cast<int>(input3)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid3 = false;
                throw std::runtime_error ("Day must be an integer. \nPress enter to continue...");
            } else{
                endDay = static_cast<int>(input3);
                if(currentYearInt == endYear && currentMonthInt == endMonth && endDay > currentDayInt){
                    valid3 = false;
                    throw std::domain_error("Out of Range.");
                }
                if(endMonth == 9 || endMonth == 4 || endMonth == 6 || endMonth == 11) {
                    if (endDay < 1 || endDay > 30) {
                        valid3 = false;
                        throw std::domain_error("Value not accepted.");
                    } else {
                        if(endDay < 10 && endDay > 0){
                            endDayString = "0" + std::to_string(endDay);
                        } else{
                            endDayString = std::to_string(endDay);
                        }
                        valid3 = true;
                    }
                } else if(endMonth == 2){
                    if (endDay < 1 || endDay > 28) {
                        valid3 = false;
                        throw std::domain_error("Value not accepted.");
                    } else {
                        if(endDay < 10 && endDay > 0){
                            endDayString = "0" + std::to_string(endDay);
                        } else{
                            endDayString = std::to_string(endDay);
                        }
                        valid3 = true;
                    }
                } else if (endMonth != 9 && endMonth != 4 && endMonth != 6 && endMonth != 11 && endMonth != 2){
                    if (endDay < 1 || endDay > 31) {
                        valid3 = false;
                        throw std::domain_error("Value not accepted.");
                    } else {
                        if(endDay < 10 && endDay > 0){
                            endDayString = "0" + std::to_string(endDay);
                        } else{
                            endDayString = std::to_string(endDay);
                        }
                        valid3 = true;
                    }
                }
            }
        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    date = "&end_date=" + endYearString + "-" + endMonthString + "-" + endDayString;
    setEndDate(date);
    return getEndDate();
}