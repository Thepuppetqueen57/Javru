#include "jvrl.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Function to execute a command to compile Java
int cmdd(string& arg) {
    // Construct the command string for javac
    string cmd = "javac " + arg + ".java";

    // Execute the javac command
    int result = system(cmd.c_str());

    // Check if the javac command was successful
    if (result != 0) {
        cerr << "Error: Failed to execute the javac command." << endl;
        return 1;
    }

    return 0;
}

// Function to run the Java class
int run_class(const string& arg) {
    string nodecmd = "java " + arg;
    int result = system(nodecmd.c_str());

    if (result != 0) {
        cerr << "Error: Failed to execute the java command." << endl;
        return 1;
    }

    return 0;
}

// Function to delete the generated class file
int delete_file(const string& arg) {
    string deletecmd = "del " + arg + ".class";
    int result = system(deletecmd.c_str());

    if (result != 0) {
        cerr << "Error: Failed to execute the delete command." << endl;
        return 1;
    }

    return 0;
}
