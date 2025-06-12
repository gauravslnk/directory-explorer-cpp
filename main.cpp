#include <iostream>    
#include <dirent.h>     // For working with directories (POSIX)
#include <sys/stat.h>   // For checking file/folder type info
#include <iomanip>      // For formatting the output
#include <string>      

#ifdef _WIN32
#include <windows.h>    // For Windows-specific functions like system("pause")
#else
#include <unistd.h>     // For Unix-like systems (optional)
#endif

using namespace std;

int main() {
    DIR *directoryPointer;               // Pointer to the folder we're reading
    struct dirent *directoryEntry;       // Will store one file/folder at a time
    struct stat fileInfo;                // Used to get more info about each file/folder

    string directoryPath = "./";         // The folder we want to look into (current folder)

    directoryPointer = opendir(directoryPath.c_str());  // Try to open the folder

    if (directoryPointer != nullptr) {
        // Keep reading entries one by one until we reach the end
        while ((directoryEntry = readdir(directoryPointer)) != nullptr) {
            string entryName = directoryEntry->d_name;      // Get the name of current item

            // Skip the current and parent directory entries (not useful to display)
            if (entryName == "." || entryName == "..") continue;

            string fullPath = directoryPath + entryName;    // Build the full path to get info
            string type = "Unknown";                        // Default type if we can’t detect

            // Get file/folder details using stat
            if (stat(fullPath.c_str(), &fileInfo) == 0) {
                if (S_ISDIR(fileInfo.st_mode)) {            // Is it a folder?
                    type = "is a FOLDER.";
                } else if (S_ISREG(fileInfo.st_mode)) {     // Is it a file?
                    type = "is a FILE.";
                }
            }

            // Print the name and type nicely
            cout << left << setw(30) << entryName << " --> " << type << endl;
        }

        closedir(directoryPointer);      // Done reading, so close the folder
    } else {
        cout << "Error: Could not open the directory." << endl;  // If folder couldn't be opened
    }

    // Wait before exiting so user can see the output
#ifdef _WIN32
    system("pause");         // Windows way to pause
#else
    cout << "\nPress Enter to exit...";
    cin.get();               // Linux/macOS way to wait
#endif

    return 0;  // Exit the program
}
