#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void saveProjectFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        std::cout << "[SUCCESS] File saved: " << filename << std::endl;
    } else {
        std::cerr << "[ERROR] Could not save file: " << filename << std::endl;
    }
}

void runLimeCompiler(const std::string& command) {
    std::cout << "[LAUNCHING] Executing terminal routine: " << command << std::endl;
    
    int result = std::system(command.c_str());
    
    if (result == 0) {
        std::cout << "[SUCCESS] Game process ended clean." << std::endl;
    } else {
        std::cerr << "[ERROR] Compilation or execution failed with code: " << result << std::endl;
    }
}

void simulateWebviewBridge(const std::string& action, const std::string& target, const std::string& extraData = "") {
    if (action == "save") {
        saveProjectFile(target, extraData);
    } else if (action == "run") {
        runLimeCompiler(target);
    } else {
        std::cout << "[UNKNOWN] Received unhandled internal window pipeline request." << std::endl;
    }
}

int main() {
    std::cout << "--- Funkin Code Backend Engine Initialized ---" << std::endl;

    simulateWebviewBridge("save", "PlayState.hx", "class PlayState extends MusicBeatState\n{\n    override function create() {\n        super.create();\n        trace('Injected from system.cpp');\n    }\n}");
    
    simulateWebviewBridge("run", "lime test windows -debug");

    return 0;
}
