#include <iostream>
#include <string>
#include "lib/jvrl.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // Check if the correct amount of arguments are taken
    if (argc < 2 || argc > 3) {
        cerr << "Usage: javru <arg> [k|j] (file extension is optional)" << std::endl;
        return 1;
    }

    // Convert argv[1] to a string
    string arg = argv[1];

    // Determine the language (Java by default)
    string language = "java";
    if (argc == 3) {
        string lang_arg = argv[2];
        if (lang_arg == "k") {
            language = "kotlin";
        } else if (lang_arg != "j") {
            cerr << "Invalid language option. Use 'k' for Kotlin or 'j' for Java." << endl;
            return 1;
        }
    }

    // Remove the file extension if present
    if (language == "java" && arg.size() > 5 && arg.substr(arg.size() - 5) == ".java") {
        arg = arg.substr(0, arg.size() - 5);
    } else if (language == "kotlin" && arg.size() > 3 && arg.substr(arg.size() - 3) == ".kt") {
        arg = arg.substr(0, arg.size() - 3);
    }

    // Call the cmdd function from the library
    int cmdd_result = cmdd(arg, language);

    // Check the result of cmdd
    if (cmdd_result != 0) {
        cerr << "cmdd function failed. Exiting program." << endl;
        return cmdd_result;
    }

    // Call the run execution function
    int runresult = run_class(arg, language);

    // Check if the run command was successful
    if (runresult != 0) {
        cerr << "Error: Failed to execute the run command." << endl;
        return runresult;
    }

    // Call the delete function
    int deleteresult = delete_file(arg, language);

    // Check if the delete command was successful
    if (deleteresult != 0) {
        cerr << "Error: Failed to execute the delete command." << endl;
        return deleteresult;
    }

    return 0;
}
