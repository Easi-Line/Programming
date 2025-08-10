#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include <fstream>

using namespace std;

struct TimeLog {
    int id;
    string project;
    string startTime;
    string endTime;
    string description;
};

class TimeLogService {
public:
    bool saveTimeLog(const TimeLog& log) {
        logs.push_back(log);
        return true;
    }

    vector<TimeLog> fetchTimeLogs() {
        return logs;
    }

    bool removeTimeLog(int id) {
        for (auto it = logs.begin(); it != logs.end(); ++it) {
            if (it->id == id) {
                logs.erase(it);
                return true;
            }
        }
        return false;
    }

    // Save logs to file
    void saveToFile(const string& filename) {
        ofstream ofs(filename);
        for (const auto& log : logs) {
            ofs << log.id << "," << log.project << "," << log.startTime << ","
                << log.endTime << "," << log.description << "\n";
        }
    }

    // Load logs from file
    void loadFromFile(const string& filename) {
        logs.clear();
        ifstream ifs(filename);
        string line;
        while (getline(ifs, line)) {
            TimeLog log;
            size_t pos = 0;
            int field = 0;
            string token;
            vector<string> tokens;
            while ((pos = line.find(',')) != string::npos) {
                token = line.substr(0, pos);
                tokens.push_back(token);
                line.erase(0, pos + 1);
            }
            tokens.push_back(line);
            if (tokens.size() == 5) {
                log.id = stoi(tokens[0]);
                log.project = tokens[1];
                log.startTime = tokens[2];
                log.endTime = tokens[3];
                log.description = tokens[4];
                logs.push_back(log);
            }
        }
    }

private:
    vector<TimeLog> logs;
};

class TimeLogController {
public:
    TimeLogController(TimeLogService& service) : timeLogService(service) {}

    void createTimeLog(const TimeLog& log) {
        if (timeLogService.saveTimeLog(log)) {
            cout << "TimeLog created.\n";
        } else {
            cout << "Error creating TimeLog.\n";
        }
    }

    void getTimeLogs() {
        auto logs = timeLogService.fetchTimeLogs();
        for (const auto& log : logs) {
            cout << "ID: " << log.id << ", Project: " << log.project
                      << ", Start: " << log.startTime << ", End: " << log.endTime
                      << ", Desc: " << log.description << "\n";
        }
    }

    void deleteTimeLog(int id) {
        if (timeLogService.removeTimeLog(id)) {
            cout << "TimeLog deleted.\n";
        } else {
            cout << "Error deleting TimeLog.\n";
        }
    }

    void saveLogs(const string& filename) {
        timeLogService.saveToFile(filename);
        cout << "Logs saved to file.\n";
    }

    void loadLogs(const string& filename) {
        timeLogService.loadFromFile(filename);
        cout << "Logs loaded from file.\n";
    }

private:
    TimeLogService& timeLogService;
};

int main() {
    TimeLogService service;
    TimeLogController controller(service);

    int choice;
    string filename = "timelogs.csv";
    controller.loadLogs(filename);

    do {
        cout << "\nTime Tracking Tool\n";
        cout << "1. Add Time Log\n";
        cout << "2. View Time Logs\n";
        cout << "3. Delete Time Log\n";
        cout << "4. Save Logs\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            TimeLog log;
            cout << "Enter ID: ";
            cin >> log.id;
            cin.ignore();
            cout << "Enter Project Name: ";
            getline(cin, log.project);
            cout << "Enter Start Time: ";
            getline(cin, log.startTime);
            cout << "Enter End Time: ";
            getline(cin, log.endTime);
            cout << "Enter Description: ";
            getline(cin, log.description);
            controller.createTimeLog(log);
        } else if (choice == 2) {
            controller.getTimeLogs();
        } else if (choice == 3) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            controller.deleteTimeLog(id);
        } else if (choice == 4) {
            controller.saveLogs(filename);
        }
    } while (choice != 5);

    controller.saveLogs(filename);
    cout << "Goodbye!\n";

    return 0;
}