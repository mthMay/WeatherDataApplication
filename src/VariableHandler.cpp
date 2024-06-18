//
// Created by May Thu Htun on 13/04/2024.
//
#include "../headers/VariableHandler.h"

/* function sendGetRequest() is modified from
 * https://gist.github.com/alghanmi/c5d7b761b2c9ab199157
 * date accessed 6 March 2024
 */
std::string VariableHandler::sendGetRequest(const std::string& url) {
    CURL *curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cout << "Error: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    return response;
}

bool VariableHandler::chooseVariables(std::string variableName){
    bool include;
    std::string choice;
    std::cout << "Include " << variableName << "? Y/N: ";
    std::cin >> choice;
    if(choice == "Y" || choice == "y"){
        include = true;
    }else{
        include = false;
    }
    return include;
}

std::string VariableHandler::formatVariables (std::vector<std::pair<std::string, std::string>> variables, std::string format){
    bool isFirstChoice = true;
    std::string chosenVariables = "";
    for (auto& pair:variables){
        bool include = chooseVariables(pair.first);
        if(include == true){
            if(isFirstChoice){
                chosenVariables += format + pair.second;
                isFirstChoice = false;
            } else  {
                chosenVariables += "," + pair.second;
            }
        }
    }
    return chosenVariables;
}

void VariableHandler::getDataFromAPI (std::string url, std::string cityName, std::string fileNameExtension){
    LocationManager locationManager;
    std::string response = sendGetRequest(url);
    if (!response.empty()) {
        std::cout << response << std::endl;
        std::string choice;
        std::cout << "\nDo you want to export the data as JSON? (y/n) : ";
        std::cin >> choice;
        if(choice == "Y" || choice == "y"){
            std::string fileName = "../Files/" + cityName + fileNameExtension;
            json data = json::parse(response);
            exportDataToJson(data, fileName);
        }
    } else {
        std::cout << "Failed to add location. Empty response from API.\n";
    }
}

/* code to exportDataToJson is modified from
* https://www.geeksforgeeks.org/json-dump-in-python/
* date accessed 29th March 2024
*/
void VariableHandler::exportDataToJson (json& data, std::string fileName){
    std::ofstream file(fileName);
    file << data.dump(6);
    std::cout << "Data exported to " << fileName << " successfully." << std::endl;
}
