#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iomanip>
#include <cctype>
#include <algorithm>

using namespace std;

struct TimeEntry {
    string projectName;
    string category;
    string startTime; //HH:MM
    string endTime; //HH:MM
    int durationMinutes;
};

//the trim function removes all leading white spaces from a given string
static inline string trim(const string& s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

//Parses time "HH:MM" into total minutes past midnight. Return -1 on invalid unput.
int parseTimeToMinutes(const string& raw) {
    string s =trim(raw);
    if (s.size () < 4 || s.size () > 5) return -1;
    //minimal time is "0:00" to "23:59"

    int h = 0, m = 0; //h - hours and m - minutes
    char colon = 0;
    stringstream ss(s);
    ss >> h >> colon >> m;
    if (ss.fail() || colon != ':') return -1;
    if (h < 0 || h > 23 || m < 0 || m > 59) return -1;
    return h * 60 + m; //converting hour into total minutes.
}

//calculating the duration in minutes and handling overnight spans.
int calculateDuration(const string& start, const string& end) {
    int s = parseTimeToMinutes(start);
    int e = parseTimeToMinutes(end);
    if (s < 0 || e < 0) return -1;
    int difference = e - s; //the difference btn the start and the end i.e the total time in hours.
    if (difference < 0) difference += 60 * 24; //time in minutes if the total time in hours is 24. i.e crossed midnight
    return difference;
}

string formatDuration (int minutes) {
    int hrs = minutes / 60;
    int mins = minutes % 60;
    stringstream ss;
    ss << hrs << " hrs " << mins << " mins";
    return ss.str();
}

void logTime(vector<TimeEntry>& logs) {
    TimeEntry entry;
    cout << "Project name: ";
    getline(cin, entry.projectName);
    cout <<"Category: ";
    getline(cin, entry.category);
    cout << "Start time(HH:MM): ";
    getline(cin, entry.startTime);
    cout << "End time (HH:00): ";
    getline(cin, entry.endTime);

    //trim inputs
    entry.projectName = trim(entry.projectName);
    entry.category = trim(entry.category);
    entry.startTime = trim(entry.startTime);
    entry.endTime = trim(entry.endTime);

    int duration = calculateDuration(entry.startTime, entry.endTime);
    if (duration < 0) {
        cout << "\nError: invalid time format or values. Please use HH:MM (00:00 to 23:59). \n";
        return;
    }
    entry.durationMinutes = duration;
    logs.push_back(entry);
    cout << "Logged " << formatDuration(entry.durationMinutes) << " (" << entry.durationMinutes << " mins)\n";
}

void  showLogs( const vector<TimeEntry>& logs) {
    if (logs.empty()) {
        cout << "\nNo entries logged yet.\n";
        return;
    }
    cout << "\n---- All Time Logs ----\n";
    for (const auto& e: logs) {
        cout << "Project: " << e.projectName
             << " | Category: " << e.category
             << " | Start: " << e.startTime
             << " | End: " << e.endTime
             << " | Duration: " << formatDuration(e.durationMinutes) << " (" << e.durationMinutes << "mins)\n";
    }
    cout << "\n";
}

void showSummary(const vector<TimeEntry>& logs) {
    int total = 0;
    for (const auto& e : logs) total += e.durationMinutes;
    cout << "\nTotal Time Logged: " << total << "minutes (" << formatDuration << ")\n";
}

void categoryAnalytics(const vector<TimeEntry>& logs) {
    if (logs.empty()) {
        cout << "\nNo data for analytics.\n";
        return;
    }
    map<string, int> categoryTotals;
    for (const auto& pair : categoryTotals) {
        cout << pair.first << ": " << formatDuration(pair.second) << " (" << pair.second <<" mins)\n";
    }
    cout << "\n";
}

void billingReport(const vector<TimeEntry>& logs) {
    const double ratePerHour = 5.0;
    double totalHours = 0.0;
    for (const auto& e : logs) totalHours += e.durationMinutes /60.0;
    cout << fixed << setprecision(2);
    cout << "\nTotal Billable Hours: " << totalHours << " per hours\n";
    cout << "Billing Rate: $" << ratePerHour << " per hour\n";
    cout << "Total Amount: $" << (totalHours * ratePerHour) << "\n";
    // cout << defaultfloat;
}

int main () {
    vector<TimeEntry> logs;
    while (true) {
        cout << "\n1. Log Time \n"
             << "2. Show Logs \n"
             << "3. Summary \n"
             << "4. Category Analytics \n"
             << "5. Billing Report \n"
             << "6. Exit \n"
             << "Option: ";
             
             string input;
             getline(cin, input);
             input = trim(input); // removing leading whitespaces
             if (input == "1") logTime(logs);
             else if (input == "2") showLogs(logs);
             else if (input == "3") showSummary(logs);
             else if (input == "4") categoryAnalytics(logs);
             else if (input == "5") billingReport(logs);
             else if (input == "6") break;
             else cout << "\nInvalid option. Please Choose 1-6.\n";
    }
    return 0;
}