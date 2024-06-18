//
// Created by May Thu Htun on 06/03/2024.
//

#include "../headers/MainMenu.h"

int MainMenu::getChoice() {
    return choice;
}

void MainMenu::setChoice(int tempChoice) {
    choice = tempChoice;
}

int MainMenu::menu() {
    double tempChoice;
    int choice;
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "\nWelcome to Weather Data Application.\n"
                         "1. Location Management\n"
                         "2. Weather Forecast\n"
                         "3. Historical Weather\n"
                         "4. Air Quality Forecast\n"
                         "5. Exit Program\n"
                         "Choose with you want to do: ";
            std::cin >> tempChoice;

            if(std::cin.fail() || tempChoice != static_cast<int>(tempChoice) || tempChoice < 1 || tempChoice > 5){
                /* Next 2 lines of code is modified from
                 * https://gist.github.com/leimao/418395bf920eb70b2b11fe89d7c1f738
                 * date accessed 9 March 2024
                 */
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Invalid choice. Must be between 1 to 5. \nPress enter to continue...");
            } else {
                choice = static_cast<int>(tempChoice);
                valid = true;
            }
        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    setChoice (choice);
    return getChoice();
}

int MainMenu::airQualityMenu() {
    double tempChoice;
    int choice;
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "\nAir Quality Forecast\n"
                         "--------------------\n"
                         "1. Add Hourly Air Quality Variables\n"
                         "2. Add European Air Quality Index\n"
                         "3. Add Current Conditions\n"
                         "4. Set Setting\n"
                         "5. Reset Variables\n"
                         "6. Display Air Quality Forecast Data\n"
                         "7. Exit Air Quality Forecast\n"
                         "Choose with you want to do: ";
            std::cin >> tempChoice;

            if(std::cin.fail() || tempChoice != static_cast<int>(tempChoice) || tempChoice < 1 || tempChoice > 7){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Invalid choice. Must be between 1 and 7. \nPress enter to continue...");
            } else {
                choice = static_cast<int>(tempChoice);
                valid = true;
            }
        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    setChoice (choice);
    return getChoice();
}

void MainMenu::airQualityMenuController(int choice) {
    std::string cityName;
    if(choice == 1){
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false){
            try{
                std::cout << "\n1. Add All Hourly Air Quality Variables\n"
                             "2. Choose Own Hourly Air Quality Variables\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if(std::cin.fail() || tempDecision != static_cast<int>(tempDecision) || tempDecision < 1 || tempDecision > 2){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else {
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1){
                        AirQuality::allHourlyVariables();
                        valid = true;
                    } else if(decision == 2){
                        AirQuality::chooseHourlyVariables();
                        valid = true;
                    }
                }
            }
            catch(std::exception& e){
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    } else if (choice == 2) {
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false) {
            try {
                std::cout << "\n1. Add All European Air Quality Index\n"
                             "2. Choose Own European Air Quality Index\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if (std::cin.fail() || tempDecision != static_cast<int>(tempDecision) || tempDecision < 1 || tempDecision > 2) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else {
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1) {
                        AirQuality::allEuropeanVariables();
                        valid = true;
                    } else if (decision == 2) {
                        AirQuality::chooseEuropeanVariables();
                        valid = true;
                    }
                }
            }
            catch (std::exception &e) {
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    } else if(choice == 3){
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false) {
            try {
                std::cout << "\n1. Add All Current Conditions\n"
                             "2. Choose Own Current Conditions\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if (std::cin.fail() || tempDecision != static_cast<int>(tempDecision) || tempDecision < 1 || tempDecision > 2) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else {
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1) {
                        AirQuality::allCurrentConditions();
                        valid = true;
                    } else if (decision == 2) {
                        AirQuality::chooseCurrentConditions();
                        valid = true;
                    }
                }
            }
            catch (std::exception &e) {
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    } else if(choice == 4){
        AirQuality::chooseSetting();
    } else if(choice == 5){
        AirQuality::setChosenVariables("");
    } else if(choice == 6){
        std::cout << "Enter the name of the city that you want to forecast: ";
        std::cin.ignore();
        std::getline(std::cin >> std::ws, cityName);
        cityName = LocationManager::capitalizeFirstLetter(cityName);
        AirQuality::getDataFromAPI(cityName, AirQuality::getChosenVariables());
    } else if (choice == 7){
        std::cout << "";
    }
}

int MainMenu::historicalWeatherMenu() {
    double tempChoice;
    int choice;
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "\nHistorical Weather\n"
                         "--------------------\n"
                         "1. Add Hourly Weather Variables\n"
                         "2. Add Additional Variables\n"
                         "3. Add Solar Radiation Variables\n"
                         "4. Add Reanalysis Models\n"
                         "5. Add Daily Weather Variables\n"
                         "6. Set Setting\n"
                         "7. Reset Variables\n"
                         "8. Display Weather Forecast Data\n"
                         "9. Exit Historical Weather\n"
                         "Choose with you want to do: ";
            std::cin >> tempChoice;

            if(std::cin.fail() || tempChoice != static_cast<int>(tempChoice) || tempChoice < 1 || tempChoice > 9){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Invalid choice. Must be between 1 and 9. \nPress enter to continue...");
            } else {
                choice = static_cast<int>(tempChoice);
                valid = true;
            }
        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    setChoice (choice);
    return getChoice();
}

void MainMenu::historicalWeatherMenuController(int choice) {
    std::string cityName;
    if(choice == 1){
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false) {
            try {
                std::cout << "\n1. Add All Hourly Weather Variables\n"
                             "2. Choose Own Hourly Weather Variables\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if (std::cin.fail() || tempDecision != static_cast<int>(tempDecision) || tempDecision < 1 || tempDecision > 2) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else {
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1) {
                        HistoricalWeather::allHourlyVariables();
                        valid = true;
                    } else if (decision == 2) {
                        HistoricalWeather::chooseHourlyVariables();
                        valid = true;
                    }
                }
            }
            catch (std::exception &e) {
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    } else if (choice == 2) {
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false) {
            try {
                std::cout << "\n1. Add All Additional Variables\n"
                             "2. Choose Own Additional Variables\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if (std::cin.fail() || decision != static_cast<int>(tempDecision) || decision < 1 || decision > 2) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else{
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1) {
                        HistoricalWeather::allAdditionalVariables();
                        valid = true;
                    } else if (decision == 2) {
                        HistoricalWeather::chooseAdditionalVariables();
                        valid = true;
                    }
                }

            }
            catch (std::exception &e) {
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    } else if(choice == 3){
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false) {
            try {
                std::cout << "\n1. Add All Solar Radiation Variables\n"
                             "2. Choose Own Solar Radiation Variables\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if (std::cin.fail() || decision != static_cast<int>(tempDecision) || decision < 1 || decision > 2) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else{
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1) {
                        HistoricalWeather::allSolarRadiationVariables();
                        valid = true;
                    } else if (decision == 2) {
                        HistoricalWeather::chooseSolarRadiationVaribales();
                        valid = true;
                    }
                }

            }
            catch (std::exception &e) {
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    } else if(choice == 4){
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false) {
            try {
                std::cout << "\n1. Add All Reanalysis Models\n"
                             "2. Choose Own Reanalysis Models\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if (std::cin.fail()|| decision != static_cast<int>(tempDecision) || decision < 1 || decision > 2) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else {
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1) {
                        HistoricalWeather::allReanalysisModels();
                        valid = true;
                    } else if (decision == 2) {
                        HistoricalWeather::chooseReanalysisModels();
                        valid = true;
                    }
                }

            }
            catch (std::exception &e) {
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    } else if(choice == 5){
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false) {
            try {
                std::cout << "\n1. Add All Daily Weather Variables\n"
                             "2. Choose Own Daily Weather Variables\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if (std::cin.fail() || decision != static_cast<int>(tempDecision) || decision < 1 || decision > 2) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else{
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1) {
                        HistoricalWeather::allDailyWeatherVariables();
                        valid = true;
                    } else if (decision == 2) {
                        HistoricalWeather::chooseDailyWeatherVariables();
                        valid = true;
                    }
                }
            }
            catch (std::exception &e) {
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    } else if(choice == 6){
        HistoricalWeather::chooseSetting();
    } else if(choice == 7){
        HistoricalWeather::setChosenVariables("");
    } else if(choice == 8){
        std::cout << "Enter the name of the city that you want to forecast: ";
        std::cin.ignore();
        std::getline(std::cin >> std::ws, cityName);
        cityName = LocationManager::capitalizeFirstLetter(cityName);
        HistoricalWeather::getDataFromAPI(cityName, HistoricalWeather::getChosenVariables());
    } else if (choice == 9){
        std::cout << "";
    }
}

int MainMenu::weatherForecastMenu() {
    double tempChoice;
    int choice;
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "\nWeather Forecast\n"
                         "--------------------\n"
                         "1. Add Hourly Weather Variables\n"
                         "2. Add Additional Variables\n"
                         "3. Add Solar Radiation Variables\n"
                         "4. Add Pressure Level Variables\n"
                         "5. Add Weather Models\n"
                         "6. Add Daily Weather Variables\n"
                         "7. Set Setting\n"
                         "8. Reset Variables\n"
                         "9. Display Weather Forecast Data\n"
                         "10. Exit Weather Forecast\n"
                         "Choose with you want to do: ";
            std::cin >> tempChoice;

            if(std::cin.fail() || tempChoice != static_cast<int>(tempChoice) || tempChoice < 1 || tempChoice > 10){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Invalid choice. Must be between 1 and 10. \nPress enter to continue...");
            } else {
                choice = static_cast<int>(tempChoice);
                valid = true;
            }
        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    setChoice (choice);
    return getChoice();
}

void MainMenu::weatherForecastMenuController(int choice) {
    std::string cityName;
    if(choice == 1){
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false) {
            try {
                std::cout << "\n1. Add All Hourly Weather Variables\n"
                             "2. Choose Own Hourly Weather Variables\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if (std::cin.fail() || tempDecision != static_cast<int>(tempDecision)|| tempDecision < 1 || tempDecision > 2) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else{
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1) {
                        WeatherForecast::allHourlyVariables();
                        valid = true;
                    } else if (decision == 2) {
                        WeatherForecast::chooseHourlyVariables();
                        valid = true;
                    }
                }
            }
            catch (std::exception &e) {
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    } else if (choice == 2) {
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false) {
            try {
                std::cout << "\n1. Add All Additional Variables\n"
                             "2. Choose Own Additional Variables\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if (std::cin.fail() || tempDecision != static_cast<int>(tempDecision)|| tempDecision < 1 || tempDecision > 2) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else{
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1) {
                        WeatherForecast::allAdditionalVariables();
                        valid = true;
                    } else if (decision == 2) {
                        WeatherForecast::chooseAdditionalVariables();
                        valid = true;
                    }
                }
            }
            catch (std::exception &e) {
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    } else if(choice == 3){
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false) {
            try {
                std::cout << "\n1. Add All Solar Radiation Variables\n"
                             "2. Choose Own Solar Radiation Variables\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if (std::cin.fail() || tempDecision != static_cast<int>(tempDecision)|| tempDecision < 1 || tempDecision > 2) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else {
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1) {
                        WeatherForecast::allSolarRadiationVariables();
                        valid = true;
                    } else if (decision == 2) {
                        WeatherForecast::chooseSolarRadiationVaribales();
                        valid = true;
                    }
                }
            }
            catch (std::exception &e) {
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    } else if(choice == 4){
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false) {
            try {
                std::cout << "\n1. Add All Pressure Level Variables\n"
                             "2. Choose Own Pressure Level Variables\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if (std::cin.fail() || tempDecision != static_cast<int>(tempDecision)|| tempDecision < 1 || tempDecision > 2) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else{
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1) {
                        WeatherForecast::allPressureLevelVariables();
                        valid = true;
                    } else if (decision == 2) {
                        WeatherForecast::choosePressureLevelVariables();
                        valid = true;
                    }
                }
            }
            catch (std::exception &e) {
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    } else if(choice == 5){
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false) {
            try {
                std::cout << "\n1. Add All Weather Models\n"
                             "2. Choose Own Weather Models\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if (std::cin.fail()|| tempDecision != static_cast<int>(tempDecision) || tempDecision < 1 || tempDecision > 2) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else{
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1) {
                        WeatherForecast::allWeatherModels();
                        valid = true;
                    } else if (decision == 2) {
                        WeatherForecast::chooseWeatherModels();
                        valid = true;
                    }
                }
            }
            catch (std::exception &e) {
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    } else if(choice == 6){
        double tempDecision;
        int decision;
        bool valid = false;
        while(valid == false) {
            try {
                std::cout << "\n1. Add All Daily Weather Variables\n"
                             "2. Choose Own Daily Weather Variables\n"
                             "Choose either 1 or 2: ";
                std::cin >> tempDecision;

                if (std::cin.fail()|| tempDecision != static_cast<int>(tempDecision) || tempDecision < 1 || tempDecision > 2) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    valid = false;
                    throw std::domain_error("Invalid choice. Must be either 1 or 2.\nPress enter to continue...");
                } else {
                    decision = static_cast<int>(tempDecision);
                    if (decision == 1) {
                        WeatherForecast::allDailyWeatherVariables();
                        valid = true;
                    } if (decision == 2) {
                        WeatherForecast::chooseDailyWeatherVariables();
                        valid = true;
                    }
                }

            }
            catch (std::exception &e) {
                std::cout <<  e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    }else if(choice == 7){
        WeatherForecast::chooseSetting();
    }else if(choice == 8){
        WeatherForecast::setChosenVariables("");
    } else if(choice == 9){
        std::cout << "Enter the name of the city that you want to forecast: ";
        std::cin.ignore();
        std::getline(std::cin >> std::ws, cityName);
        cityName = LocationManager::capitalizeFirstLetter(cityName);
        WeatherForecast::getDataFromAPI(cityName, WeatherForecast::getChosenVariables());
    } else if (choice == 10){
        std::cout << "";
    }
}


int MainMenu::locationMenu() {
    int choice;
    double tempChoice;
    bool valid = false;
    while (valid == false){
        try{
            std::cout << "\nLocation Management\n"
                         "--------------------\n"
                         "1. Add new location\n"
                         "2. Modify location data\n"
                         "3. Remove location\n"
                         "4. Search location\n"
                         "5. Set favourite locations\n"
                         "6. Show favourite locations\n"
                         "7. Show added locations\n"
                         "8. Exit Location Management\n"
                         "Choose with you want to do: ";
            std::cin >> tempChoice;

            if(std::cin.fail()|| tempChoice != static_cast<int>(tempChoice) || tempChoice < 1 || tempChoice > 8 ){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                valid = false;
                throw std::runtime_error ("Invalid choice. Must be between 1 to 8. \nPress enter to continue...");
            } else {
                choice = static_cast<int>(tempChoice);
                valid = true;
            }
        }
        catch (std::exception& e){
            std::cout <<  e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    setChoice (choice);
    return getChoice();
}

void MainMenu::locationMenuController(int choice) {
    int cityID;
    std::string cityName, newCityName;
    double newLatitude, newLongitude;
    if(choice == 1){
        std::cout << "Enter the name of the city that you want to add: ";
        std::cin.ignore();
        /* std::getline(std::cin >> std::ws, cityName); is taken from
         * https://www.reddit.com/r/cpp_questions/comments/15n91xf/comment/jvl3utt/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
         * date accessed 7 March 2024
         */
        std::getline(std::cin >> std::ws, cityName);
        cityName = LocationManager::capitalizeFirstLetter(cityName);
        LocationManager::addLocation(cityName);
    } else if (choice == 2) {
        std::cout << "Enter the name of the city that you want to modify: ";
        std::cin.ignore();
        std::getline(std::cin >> std::ws, cityName);
        cityName = LocationManager::capitalizeFirstLetter(cityName);
        cityID = LocationManager::locationExist(cityName);
        if(cityID != 0){
            std::cout << "Enter the new name of the city: ";
            std::getline(std::cin >> std::ws, newCityName);
            newCityName = LocationManager::capitalizeFirstLetter(newCityName);
            bool valid = false;
            while(valid == false){
                try{
                    std::cout << "Enter the new latitude of the city: ";
                    std::cin >> newLatitude;
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        valid = false;
                        throw std::runtime_error ("Invalid data. \nPress enter to continue...");
                    } else {
                        valid = true;
                    }
                }
                catch (std::exception& e){
                    std::cout <<  e.what() << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                }
            }

            bool valid2 = false;
            while(valid2 == false){
                try{
                    std::cout << "Enter the new longitude of the city: ";
                    std::cin >> newLongitude;
                    if(std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        valid2 = false;
                        throw std::runtime_error ("Invalid data. \nPress enter to continue...");
                    } else {
                        valid2 = true;
                    }
                }
                catch (std::exception& e){
                    std::cout <<  e.what() << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                }
            }
            LocationManager::modifyLocation(cityID, newCityName, newLatitude, newLongitude);
        } else {
            std::cout << "Location not found"<< std::endl;
        }
    } else if(choice == 3){
        std::cout << "Enter the name or ID of the city that you want to remove: ";
        std::cin.ignore();
        std::getline(std::cin >> std::ws, cityName);
        cityName = LocationManager::capitalizeFirstLetter(cityName);
        std::istringstream iss(cityName);
        if(iss >> cityID){
            LocationManager::removeLocationByID(cityID);
        }else {
            cityID = LocationManager::locationExist(cityName);
            if(cityID != 0){
                LocationManager::removeLocationByID(cityID);
            } else {
                std::cout << "Location name not found" << std::endl;
            }
        }
    } else if(choice == 4){
        std::cout << "Enter the name or ID of the city that you want to search: ";
        std::cin.ignore();
        std::getline(std::cin >> std::ws, cityName);
        std::istringstream iss(cityName);
        if(iss >> cityID){
            LocationManager::searchLocationByID(cityID);
        }else {
            LocationManager::searchLocationByName(cityName);
        }
    } else if(choice == 5){
        std::cout << "Enter the name of the city that you want to set favourite: ";
        std::cin.ignore();
        std::getline(std::cin >> std::ws, cityName);
        cityName = LocationManager::capitalizeFirstLetter(cityName);
        bool existedFavouriteLocation = LocationManager::checkFavouriteLocation(cityName);
        if(existedFavouriteLocation == false){
            LocationManager::addFavouriteLocation(cityName);
        } else {
            std::cout << cityName << " is already a favorite." << std::endl;
        }
    } else if(choice == 6){
        LocationManager::showFavouriteLocations();
    }else if(choice == 7){
        LocationManager::showLocations();
    } else if (choice == 8){
        std::cout << "";
    }
}