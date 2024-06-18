//
// Created by May Thu Htun on 12/04/2024.
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ErrorCheckingTests
#include <boost/test/unit_test.hpp>
#include "../headers/LocationManager.h"

BOOST_AUTO_TEST_SUITE(LocationManagerTests)
    BOOST_AUTO_TEST_CASE(urlEncodeTest)
    {
        LocationManager locationManager;
        std::string input = "San Francisco";
        std::string expectedOutput = "San%20Francisco";
        BOOST_CHECK_EQUAL(locationManager.urlEncode(input), expectedOutput);
    }

    BOOST_AUTO_TEST_CASE(capitalizeFirstLetterTest)
    {
        LocationManager locationManager;
        std::string input = "san Francisco";
        std::string expectedOutput = "San Francisco";
        BOOST_CHECK_EQUAL(locationManager.capitalizeFirstLetter(input), expectedOutput);
    }

    BOOST_AUTO_TEST_CASE(addLocationTest)
    {
        /* code how to use rdbuf is modified from
         * https://en.cppreference.com/w/cpp/io/basic_ios/rdbuf
         * data accessed 13 April 2024
         */
        LocationManager locationManager;
        {
            std::string cityName = "Vijayanagara";
            std::ostringstream output; // capture output of local output
            auto expectedOutput = std::cout.rdbuf(); // restore the original output
            std::cout.rdbuf(output.rdbuf()); // redirects the output so it will be in output ostringstream
            locationManager.addLocation(cityName);
            std::cout.rdbuf(expectedOutput); // restore the original output
            std::string actualOutput = output.str();
            BOOST_CHECK(actualOutput.find("Location added successfully.") != std::string::npos);
        }
        {
            std::string unexistCityName = "justrandomstringtotest";
            std::ostringstream output;
            auto expectedOutput = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf());
            locationManager.addLocation(unexistCityName);
            std::cout.rdbuf(expectedOutput);
            std::string actualOutput = output.str();
            BOOST_CHECK(actualOutput.find("Failed to add location. No valid data received from API.") != std::string::npos);
        }
        {
            std::string existCityName = "Vijayanagara";
            std::ostringstream output;
            auto expectedOutput = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf());
            locationManager.addLocation(existCityName);
            std::cout.rdbuf(expectedOutput);
            std::string actualOutput = output.str();
            BOOST_CHECK(actualOutput.find("Failed to add location. City already exists.") != std::string::npos);
        }
    }

    BOOST_AUTO_TEST_CASE(getLatitudeTest)
    {
        LocationManager locationManager;
        std::string cityName = "Vijayanagara";
        std::string expectedLatitude = "12.32";
        BOOST_CHECK_EQUAL(locationManager.getLatitude(cityName), expectedLatitude);
    }

    BOOST_AUTO_TEST_CASE(getLongitudeTest)
    {
        LocationManager locationManager;
        std::string cityName = "Vijayanagara";
        std::string expectedLatitude = "76.59";
        BOOST_CHECK_EQUAL(locationManager.getLongitude(cityName), expectedLatitude);
    }

    BOOST_AUTO_TEST_CASE(locationExistTest)
    {
        LocationManager locationManager;
        std::string cityName = "Vijayanagara";
        BOOST_CHECK_NE(locationManager.locationExist(cityName), 0);
    }

    BOOST_AUTO_TEST_CASE(modifyLocationTest)
    {
        LocationManager locationManager;
        std::string cityName = "Mandalay";
        locationManager.addLocation(cityName);
        int id = locationManager.locationExist(cityName);
        std::string newCityName = "Mdy";
        double newLatitude = 0;
        double newLongitude = 0;
        std::ostringstream output;
        auto expectedOutput = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());
        locationManager.modifyLocation(id, newCityName, newLatitude, newLongitude);
        std::cout.rdbuf(expectedOutput);
        std::string actualOutput = output.str();
        BOOST_CHECK_EQUAL(std::stod(locationManager.getLatitude(newCityName)), newLatitude);
        BOOST_CHECK_EQUAL(std::stod(locationManager.getLongitude(newCityName)), newLongitude);
        BOOST_CHECK(actualOutput.find("Location modified successfully.") != std::string::npos);

    }

    BOOST_AUTO_TEST_CASE(removeLocationByIDTest)
    {
        LocationManager locationManager;
        std::string cityNameToRemove = "Mdy";
        int id = locationManager.locationExist(cityNameToRemove);
        std::cout << id;
        locationManager.removeLocationByID(id);
        int idCheck = locationManager.locationExist(cityNameToRemove);
        BOOST_CHECK_EQUAL(idCheck, 0);
    }

    BOOST_AUTO_TEST_CASE(searchLocationByNameTest)
    {
        LocationManager locationManager;
        {
            std::string cityName = "Vijayanagara";
            std::ostringstream output;
            auto expectedOutput = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf());
            locationManager.searchLocationByName(cityName);
            std::cout.rdbuf(expectedOutput);
            std::string actualOutput = output.str();
            BOOST_CHECK(actualOutput.find("Location found") != std::string::npos);
        }
        {
            std::string unknownCityName = "Old";
            std::ostringstream output;
            auto expectedOutput = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf());
            locationManager.searchLocationByName(unknownCityName);
            std::cout.rdbuf(expectedOutput);
            std::string actualOutput = output.str();
            BOOST_CHECK(actualOutput.find("Location name not found.") != std::string::npos);
        }
    }

    BOOST_AUTO_TEST_CASE(searchLocationByIDTest)
    {
        LocationManager locationManager;
        {
            int id = 1;
            std::ostringstream output;
            auto expectedOutput = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf());
            locationManager.searchLocationByID(id);
            std::cout.rdbuf(expectedOutput);
            std::string actualOutput = output.str();
            BOOST_CHECK(actualOutput.find("Location found") != std::string::npos);
        }
        {
            int unknownID = 100;
            std::ostringstream output;
            auto expectedOutput = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf());
            locationManager.searchLocationByID(unknownID);
            std::cout.rdbuf(expectedOutput);
            std::string actualOutput = output.str();
            BOOST_CHECK(actualOutput.find("Location ID not found.") != std::string::npos);
        }
    }

    BOOST_AUTO_TEST_CASE(showLocationsTest)
    {
        LocationManager locationManager;
        {
            std::ostringstream output;
            auto expectedOutput = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf());
            locationManager.showLocations();
            std::cout.rdbuf(expectedOutput);
            std::string actualOutput = output.str();
            BOOST_CHECK(actualOutput.find("Name: Vijayanagara") != std::string::npos);
        }
        {
            locationManager.removeLocationByID(1);
            std::ostringstream output;
            auto expectedOutput = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf());
            locationManager.showLocations();
            std::cout.rdbuf(expectedOutput);
            std::string actualOutput = output.str();
            BOOST_CHECK(actualOutput.find("No locations found.") != std::string::npos);
        }
    }

    BOOST_AUTO_TEST_CASE(checkFavouriteLocationTest)
    {
        LocationManager locationManager;
        std::string cityName = "Vijayanagara";
        locationManager.addLocation(cityName);
        BOOST_CHECK_EQUAL(locationManager.checkFavouriteLocation(cityName), false);
    }

    BOOST_AUTO_TEST_CASE(addFavouriteLocationTest)
    {
        LocationManager locationManager;
        std::string cityName = "Vijayanagara";
        std::ostringstream output;
        auto expectedOutput = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());
        locationManager.addFavouriteLocation(cityName);
        std::cout.rdbuf(expectedOutput);
        std::string actualOutput = output.str();
        BOOST_CHECK(actualOutput.find("Vijayanagara is added to favorites.") != std::string::npos);
    }

    BOOST_AUTO_TEST_CASE(showFavouriteLocationsTest)
    {
        LocationManager locationManager;
        {
            std::ostringstream output;
            auto expectedOutput = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf());
            locationManager.showFavouriteLocations();
            std::cout.rdbuf(expectedOutput);
            std::string actualOutput = output.str();
            BOOST_CHECK(actualOutput.find("No locations found.") != std::string::npos);

        }
        {
            std::string cityName = "Vijayanagara";
            locationManager.addFavouriteLocation(cityName);
            std::ostringstream output;
            auto expectedOutput = std::cout.rdbuf();
            std::cout.rdbuf(output.rdbuf());
            locationManager.showFavouriteLocations();
            std::cout.rdbuf(expectedOutput);
            std::string actualOutput = output.str();
            BOOST_CHECK(actualOutput.find("Name: Vijayanagara") != std::string::npos);
        }
    }

    BOOST_AUTO_TEST_CASE(roundToTwoDecimalPointsTest)
    {
        LocationManager locationManager;
        BOOST_CHECK_EQUAL(locationManager.roundToTwoDecimalPoints(12.121212), 12.12);
    }

BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
