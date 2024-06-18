#include "../headers/MainMenu.h"

int main() {
    MainMenu mainMenu;
    int menuChoice, locationMenuChoice, weatherForecastMenuChoice, historicalWeatherMenuChoice, airQualityMenuChoice;
    std::string repeat;
    bool exit = false;
    while(exit == false){
        menuChoice = mainMenu.menu();
        if(menuChoice == 1){
            do{
                locationMenuChoice = mainMenu.locationMenu();
                mainMenu.locationMenuController(locationMenuChoice);
                if(locationMenuChoice == 8) {
                    repeat = "N";
                } else {
                    std::cout << "\nDo you want to stay in location management center? Y/N : ";
                    std::cin >> repeat;
                }
            } while (repeat == "Y" || repeat == "y");
            std::cout << "\nThank you for visiting." << std::endl;
            exit = false;
        } else if (menuChoice == 2) {
            do{
                weatherForecastMenuChoice = mainMenu.weatherForecastMenu();
                mainMenu.weatherForecastMenuController(weatherForecastMenuChoice);
                if(weatherForecastMenuChoice == 10){
                    repeat = "N";
                } else {
                    std::cout << "\nDo you want to stay in weather forecast center? Y/N : ";
                    std::cin >>repeat;
                }
            } while (repeat == "Y" || repeat == "y");
            std::cout << "\nThank you for visiting." << std::endl;
            exit = false;
        } else if (menuChoice == 3) {
            do{
                historicalWeatherMenuChoice = mainMenu.historicalWeatherMenu();
                mainMenu.historicalWeatherMenuController( historicalWeatherMenuChoice);
                if(historicalWeatherMenuChoice == 9){
                    repeat = "N";
                } else{
                    std::cout << "\nDo you want to stay in historical weather center? Y/N : ";
                    std::cin >>repeat;
                }
            } while (repeat == "Y" || repeat == "y");
            std::cout << "\nThank you for visiting." << std::endl;
            exit = false;
        } else if (menuChoice == 4) {
            do{
                airQualityMenuChoice = mainMenu.airQualityMenu();
                mainMenu.airQualityMenuController( airQualityMenuChoice);
                if(airQualityMenuChoice == 7){
                    repeat = "N";
                }else {
                    std::cout << "\nDo you want to stay in air quality forecast center? Y/N : ";
                    std::cin >>repeat;
                }
            } while (repeat == "Y" || repeat == "y");
            std::cout << "\nThank you for visiting." << std::endl;
            exit = false;
        } else if (menuChoice == 5){
            std::cout << "\nThank you for using my Weather Data Application." << std::endl;
            exit = true;
        }
    }

    return 0;
}
