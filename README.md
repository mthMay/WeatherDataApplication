# WeatherDataApplication
### Description
The Weather Data Application is a C++ console program designed to manage locations and provide users with weather forecasts, historical weather data, and air quality information. Users can easily add, modify, or remove locations, set favorites for quick access, and export weather data in JSON format. The application features a robust location management system and implements BOOST testing for verification, ensuring reliability and accuracy.

### Features
• **Location Management**: Add, modify, and remove locations. Search for specific locations and set favorites for quick access.<br>
• **Weather Forecasting**: Access real-time weather forecasts and historical weather data for selected locations.<br>
• **Air Quality Information**: Retrieve air quality data alongside weather forecasts for a comprehensive overview.<br>
• **Data Export**: Export weather data in JSON format for easy sharing and integration with other applications.<br>
• **BOOST Testing**: Integrated BOOST testing for the Location Management class, ensuring reliability and accuracy.<br>
• **User-Friendly Interface**: Intuitive console interface to navigate through various functionalities.<br>

### How to Run
#### Requirements
• A C++ compiler such as g++ or clang++<br>
• CMake (optional for build automation)
• BOOST library (for testing)

#### Instructions
1. Clone the repository:<br>
   ```git clone https://github.com/mthMay/WeatherDataApplication.git```
2. Navigate to the project directory:<br>
   ```cd WeatherDataApplication```
3. Build the program:<br>
   ```
      mkdir build
      cd build
      cmake ..
      make
   ```
4. Run the program:<br>
   ```./SDIcwk```

### How to Run Tests
1. Clear existing location data:<br>
 Before running tests, ensure that the data in ../Files/Locations.txt is deleted to avoid errors during testing.
2. Run the tests:<br>
   ```./ErrorChecking```

### How to Use
1. **Start the Application**: Upon running, the application will present a main menu with options to manage locations and view weather data.<br>
2. **Manage Locations**: Use the menu options to add, modify, or remove locations. You can also search for specific locations and mark them as favorites.<br>
3. **View Weather Data**: Select a location to view its current weather forecast, historical weather data, and air quality information.<br>
4. **Export Data**: Utilize the export function to save weather data as JSON files for external use.<br>
5. **Run Tests**: To ensure proper functionality, run BOOST tests for the Location Management class after clearing any existing data in ../Files/Locations.txt.
