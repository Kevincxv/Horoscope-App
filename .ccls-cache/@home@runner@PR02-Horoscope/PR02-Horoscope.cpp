/*
Description : A horoscope menu that reads, creates, and extracts from csv or other file formats.
*/

#include <fstream>
#include <iomanip>
#include <iostream>

int main() {

  char const Fill = '-'; // column line
  char const Default = ' '; // white space separation
  char fileYN, aFile, ch; // yesNo question and defensive char 
  int choice, day, month;
  std::ifstream inputFile;
  std::ofstream outputFile;
  std::string fileName, rDay, rMonth, rYear; // To extract the information from the file

  do 
  {
    if (!inputFile) // Defensive file code
    {
      std::cerr << "Trouble locating the file.\nExiting....";
      exit(0);
    }
    
    std::cout << "Welcome to COP 1334 Horoscope App\n" // Display Header
              << "Please choose one of the following menu options\n"
              << "1. Process all records from a file\n"
              << "2. Process specific number of records\n"
              << "3. Enter data into a file\n"
              << "Your choice: ";
    std::cin >> choice;

    while (choice < 1 || choice > 3)  // Defensive code for choice
    {
      std::cin.clear();
      while (std::cin.get(ch) && ch != '\n'); // Ignores all characters
      std::cout << "Invalid entry!\nPlease enter 1, 2 or 3 only: ";
      std::cin >> choice;
    }

    if (choice == 1) 
    {
      int capricorn = 0, aquarius = 0, pisces = 0, aries = 0, taurus = 0, gemini = 0, 
          cancer = 0, leo = 0, virgo = 0, libra = 0, scorpio = 0, sagittarius = 0; // Counter

      std::cout << "Enter your data file name: "; // File name input
      std::cin >> fileName;
      inputFile.open(fileName); // string to open any file name

      while (!inputFile.eof()) // Process the file
      {
        getline(inputFile, rDay, ','); // Hold the file data as a string
        day = stoi(rDay); // Converts the string to an int
        getline(inputFile, rMonth, ',');
        month = stoi(rMonth);
        getline(inputFile, rYear, '\n');

        if (month == 3 && day >= 21 || month == 4 && day <= 19) // Process
          aries++;
        else if (month == 4 && day >= 20 || month == 5 && day <= 20)
          taurus++;
        else if (month == 5 && day >= 21 || month == 6 && day <= 20)
          gemini++;
        else if (month == 6 && day >= 21 || month == 7 && day <= 22)
          cancer++;
        else if (month == 7 && day >= 23 || month == 8 && day <= 22)
          leo++;
        else if (month == 8 && day >= 23 || month == 9 && day <= 22)
          virgo++;
        else if (month == 9 && day >= 23 || month == 10 && day <= 22)
          libra++;
        else if (month == 10 && day >= 23 || month == 11 && day <= 21)
          scorpio++;
        else if (month == 11 && day >= 22 || month == 12 && day <= 21)
          sagittarius++;
        else if (month == 12 && day >= 22 || month == 1 && day <= 19)
          capricorn++;
        else if (month == 1 && day >= 20 || month == 2 && day <= 18)
          aquarius++;
        else if (month == 2 && day >= 19 || month == 3 && day <= 20)
          pisces++;
      }
      
      inputFile.close(); // Closes the file

      const int count = 12; // Display output
      std::cout << "\nHoroscope Sign\t  Count\n"
                << std::setfill(Fill) << std::setw(25) << Fill 
                << "\n" << std::setfill(Default) << std::right 
                << "Capricorn  " << std::setw(count) << capricorn 
                << "\nAquarius   " << std::setw(count) << aquarius
                << "\nPisces     " << std::setw(count) << pisces 
                << "\nAries      " <<  std::setw(count) << aries 
                << "\nTaurus     " <<  std::setw(count) << taurus 
                << "\nGemini     " <<  std::setw(count) << gemini 
                << "\nCancer     " <<  std::setw(count) << cancer 
                << "\nLeo        " <<  std::setw(count) << leo 
                << "\nVirgo      " <<  std::setw(count) << virgo 
                << "\nLibra      " <<  std::setw(count) << libra 
                << "\nScorpio    " <<  std::setw(count) << scorpio 
                << "\nSagittarius" <<  std::setw(count) << sagittarius
                << "\nProcess another file (Y/n): ";
      std::cin >> fileYN; // Read if you want to process another file
    }
    else if (choice == 2) 
    {
      const int cBorn = 5, cSign = 20, cSpace = 2;
      int i, records;
      
      std::cout << "Enter your data file name: ";  // Display first read
      std::cin >> fileName;

      std::cout << "How many records would you like to process?: "; // Display secondary read
      std::cin >> records;
     
    while (records < 1) // Defensive code
    {
      std::cin.clear();
      while (std::cin.get(ch) && ch != '\n'); // Character defensive code
      std::cout << "Invalid entry!\nPlease enter a positive number: ";
      std::cin >> records;
    }
      
      std::cout << " Born on\t  Horoscope Sign\n" // Displays first part of the output
                  << std::setfill(Fill) << std::setw(28) << Fill 
                  << "\n" << std::right << std::setfill(Default);

      inputFile.open(fileName); // Open the file
      
      for (i = 0; i < records; i++) // Process the file 
      {
        getline(inputFile, rDay, ','); // Hold the file data as a string
        day = stoi(rDay); // Converts the string to an int
        getline(inputFile, rMonth, ',');
        month = stoi(rMonth);
        getline(inputFile, rYear, '\n');

        if (month == 3 && day >= 21 || month == 4 && day <= 19) // Process
          std::cout << std::setw(cBorn) << month << "/" 
                    << std::setw(cSpace) << day
                    << std::setw(cSign) << "Aries" 
                    << std::endl;

        else if (month == 4 && day >= 20 || month == 5 && day <= 20)
          std::cout << std::setw(cBorn) << month << "/" 
                    << std::setw(cSpace) << day
                    << std::setw(cSign) << "Taurus" 
                    << std::endl;

        else if (month == 5 && day >= 21 || month == 6 && day <= 20)
          std::cout << std::setw(cBorn) << month << "/" 
                    << std::setw(cSpace) << day
                    << std::setw(cSign) << "Gemini" 
                    << std::endl;

        else if (month == 6 && day >= 21 || month == 7 && day <= 22)
          std::cout << std::setw(cBorn) << month << "/" 
                    << std::setw(cSpace) << day
                    << std::setw(cSign) <<  "Cancer" 
                    << std::endl;

        else if (month == 7 && day >= 23 || month == 8 && day <= 22)
          std::cout << std::setw(cBorn) << month << "/" 
                    << std::setw(cSpace) << day
                    << std::setw(cSign) << "Leo" 
                    << std::endl;

        else if (month == 8 && day >= 23 || month == 9 && day <= 22)
          std::cout << std::setw(cBorn) << month << "/" 
                    << std::setw(cSpace) << day
                    << std::setw(cSign) << "Virgo" 
                    << std::endl;

        else if (month == 9 && day >= 23 || month == 10 && day <= 22)
          std::cout << std::setw(cBorn) << month << "/" 
                    << std::setw(cSpace) << day
                    << std::setw(cSign) << "Libra" 
                    << std::endl;

        else if (month == 10 && day >= 23 || month == 11 && day <= 21)
          std::cout << std::setw(cBorn) << month << "/" 
                    << std::setw(cSpace) << day
                    << std::setw(cSign) << "Scorpio" 
                    << std::endl;

        else if (month == 11 && day >= 22 || month == 12 && day <= 21)
          std::cout << std::setw(cBorn) << month << "/" 
                    << std::setw(cSpace) << day
                    << std::setw(cSign) << "Sagittarius" 
                    << std::endl;

        else if (month == 12 && day >= 22 || month == 1 && day <= 19)
          std::cout << std::setw(cBorn) << month << "/" 
                    << std::setw(cSpace) << day
                    << std::setw(cSign) << "Capricorn" 
                    << std::endl;

        else if (month == 1 && day >= 20 || month == 2 && day <= 18)
          std::cout << std::setw(cBorn) << month << "/" 
                    << std::setw(cSpace) << day
                    << std::setw(cSign) << "Aquarius" 
                    << std::endl;

        else if (month == 2 && day >= 19 || month == 3 && day <= 20)
          std::cout << std::setw(cBorn) << month << "/" 
                    << std::setw(cSpace) << day
                    << std::setw(cSign) << "Pisces" 
                    << std::endl;
      }
      std::cout << "\nProcess another file (Y/n): "; // Process another file
      std::cin >> fileYN;
      inputFile.close(); // Close the file
    }
    else if (choice == 3) 
    {
      std::cout << "Enter your data file name: "; // Display first read
      std::cin >> fileName;
      outputFile.open(fileName);

      do 
      {
        std::cout << "Enter the month of birth: "; // Display second read
        std::cin >> month;

        while (month < 1 || month > 12)  // Defensive code
        {
          std::cin.clear();
          while (std::cin.get(ch) && ch != '\n'); // Defensive code for characters
          std::cout << "Invalid entry!\nPlease enter 1..12 only: ";
          std::cin >> month;
        }

        std::cout << "Enter the day of birth: "; // Display third read
        std::cin >> day;

        while (day < 1 || day > 29)  // Defensive Code
        {
          std::cin.clear();
          while (std::cin.get(ch) && ch != '\n'); // Defensive code for characters
          std::cout << "Invalid entry!\nPlease enter 1..29 only: ";
          std::cin >> day;
        }

        outputFile << month << "," << day << ",2022" << std::endl; // Outputs the file 

        std::cout << "Enter another(Y/n)?: "; // Process another file
        std::cin >> aFile;
      } while (aFile  == 'y' || aFile == 'Y'); // Loop back incase of option Y
    }

    std::cout << "Thank you for using COP 1334 Horoscope App" << std::endl; // Display thank you message at the end

  } while (fileYN == 'Y' || fileYN == 'y'); // Loops the entire file back to the header incase of Y

  return 0;
}