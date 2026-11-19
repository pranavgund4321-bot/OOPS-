#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

struct Student {
    int id{};
    std::string name;
    double marks{};
};

bool parseStudent(const std::string& line, Student& student) {
    std::stringstream stream(line);
    std::string idText, nameText, marksText;

    if (!std::getline(stream, idText, ',') ||
        !std::getline(stream, nameText, ',') ||
        !std::getline(stream, marksText, ',')) {
        return false;
    }

    // Reject extra CSV columns in this simple three-column format.
    std::string extra;
    if (std::getline(stream, extra, ',')) {
        return false;
    }

    try {
        std::size_t idPosition = 0;
        std::size_t marksPosition = 0;
        student.id = std::stoi(idText, &idPosition);
        student.marks = std::stod(marksText, &marksPosition);

        if (idPosition != idText.size() || marksPosition != marksText.size() ||
            nameText.empty() || student.marks < 0.0 || student.marks > 100.0) {
            return false;
        }
    } catch (const std::exception&) {
        return false;
    }

    student.name = nameText;
    return true;
}

bool writeStudents(const std::string& filename,
                   const std::vector<Student>& students) {
    std::ofstream output(filename);
    if (!output.is_open()) {
        std::cerr << "Error: could not open " << filename << " for writing.\n";
        return false;
    }

    output << "ID,Name,Marks\n";
    for (const Student& student : students) {
        output << student.id << ',' << student.name << ','
               << std::fixed << std::setprecision(2) << student.marks << '\n';
    }

    if (!output.good()) {
        std::cerr << "Error: writing to " << filename << " failed.\n";
        return false;
    }

    return true;
}

void readStudents(const std::string& filename) {
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cerr << "Error: could not open " << filename << " for reading.\n";
        return;
    }

    std::cout << "\nStudent records read from " << filename << ":\n";
    std::cout << std::left << std::setw(10) << "ID"
              << std::setw(20) << "Name" << "Marks\n";
    std::cout << "----------------------------------------\n";

    std::string line;
    std::getline(input, line); // Skip CSV header.
    int validRecords = 0;
    int lineNumber = 1;

    while (std::getline(input, line)) {
        ++lineNumber;
        if (line.empty()) {
            continue;
        }

        Student student;
        if (parseStudent(line, student)) {
            std::cout << std::left << std::setw(10) << student.id
                      << std::setw(20) << student.name
                      << std::fixed << std::setprecision(2)
                      << student.marks << '\n';
            ++validRecords;
        } else {
            std::cout << "Skipping malformed record at line "
                      << lineNumber << ".\n";
        }
    }

    std::cout << "Valid records: " << validRecords << '\n';
}

void demonstrateReadPositions(const std::string& filename) {
    std::ifstream input(filename, std::ios::binary);
    if (!input) {
        std::cerr << "Could not open file for read-position demonstration.\n";
        return;
    }

    std::cout << "\n--- Read position demonstration ---\n";
    std::cout << "Initial tellg(): " << input.tellg() << '\n';

    char firstFive[6]{};
    input.read(firstFive, 5);
    std::cout << "First five characters: " << firstFive << '\n';
    std::cout << "tellg() after reading 5 bytes: " << input.tellg() << '\n';

    input.seekg(0, std::ios::beg);
    std::cout << "After seekg(0, beg), tellg(): " << input.tellg() << '\n';

    std::string header;
    std::getline(input, header);
    std::cout << "Header after repositioning: " << header << '\n';
}

void demonstrateWritePositions() {
    const std::string filename = "position_demo.txt";
    {
        std::ofstream createFile(filename, std::ios::binary);
        if (!createFile) {
            std::cerr << "Could not create " << filename << ".\n";
            return;
        }
        createFile << "ABCDE";
    }

    std::fstream file(filename, std::ios::in | std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Could not open " << filename << " for read/write.\n";
        return;
    }

    std::cout << "\n--- Write position demonstration ---\n";
    std::cout << "Initial tellp(): " << file.tellp() << '\n';

    file.seekp(1, std::ios::beg);
    std::cout << "After seekp(1, beg), tellp(): " << file.tellp() << '\n';
    file.put('Z');
    file.flush();

    file.seekg(0, std::ios::beg);
    std::string result;
    file >> result;
    std::cout << "File content after writing at position 1: " << result << '\n';

    file.seekp(0, std::ios::end);
    std::cout << "After seekp(0, end), tellp(): " << file.tellp() << '\n';
}

int main() {
    const std::vector<Student> students{
        {1001, "Aarav Sharma", 88.50},
        {1002, "Diya Patel", 92.00},
        {1003, "Rohan Mehta", 79.25}
    };

    std::cout << "=== CSV Student Records Using File I/O ===\n";

    if (!writeStudents("students.csv", students)) {
        return 1;
    }
    std::cout << "Successfully wrote " << students.size()
              << " student records to students.csv.\n";

    readStudents("students.csv");
    demonstrateReadPositions("students.csv");
    demonstrateWritePositions();

    std::cout << "\nGenerated files: students.csv and position_demo.txt\n";
    return 0;
}
