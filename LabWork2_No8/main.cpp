#include "LabWork2_No8.h"
#include "Graduate.hpp"
#include "Point.hpp"

static int countWords(const std::string& text) {
    int spaces = 0;
    for (char c : text) {
        if (c == ' ') {
            spaces++;
        }
    }
    return spaces + 1;
}

static std::string removePoints(const std::string& text) {
    std::string result;
    for (char c : text) {
        if (c != '.') {
            result += c;
        }
    }
    return result;
}

static std::string removeLatinLetters(const std::string& text) {
    std::string result;
    for (char c : text) {
        if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z')) {
            result += c;
        }
    }
    return result;
}

static void printVector(const std::vector<std::string>& names, const std::vector<std::string>& numbers) {
    for (size_t i = 0; i < names.size(); ++i) {
        std::cout << names[i] << " - " << numbers[i] << std::endl;
    }
}

static void printList(const std::list<std::string>& names, const std::list<std::string>& numbers) {
    auto itNames = names.begin();
    auto itNumbers = numbers.begin();
    for (; itNames != names.end() && itNumbers != numbers.end(); ++itNames, ++itNumbers) {
        std::cout << *itNames << " - " << *itNumbers << std::endl;
    }
}

void printMap(const std::map<std::string, int>& students) {
    for (const auto& pair : students) {
        std::cout << pair.first << " - " << pair.second << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    /* Задание 1 */
    std::string text1, text2;
    std::cout << " === Задание 1 === \n";
    std::cout << "Enter the first text: ";
    std::getline(std::cin, text1);
    std::cout << "Enter the second text: ";
    std::getline(std::cin, text2);

    int wordsText1 = countWords(text1);
    int wordsText2 = countWords(text2);

    if (wordsText1 > wordsText2) {
        std::cout << "The first text has more words.\n";
    }
    else if (wordsText1 < wordsText2) {
        std::cout << "The second text has more words.\n";
    }
    else {
        std::cout << "Both texts have the same number of words.\n";
    }

    /* Задание 2 */
    std::cout << "\n === Задание 2 === \n";
    std::string text;
    std::cout << "Enter text with points: ";
    std::getline(std::cin, text);

    std::string newText = removePoints(text);
    std::cout << "Text without points: " << newText << std::endl;

    /* Задание 3 */
    std::cout << "\n === Задание 3 === \n см. файл output.txt \n";
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    std::string line;
    while (std::getline(inputFile, line)) {
        std::string newLine = removeLatinLetters(line);
        outputFile << newLine << std::endl;    
    }
    inputFile.close();
    outputFile.close();

    /* Задание 4 */
    std::cout << "\n === Задание 4 === \n";
    std::vector<std::string> names;
    std::vector<std::string> numbers;
    std::string name, number;

    while (true) {
        std::cout << "For exit enter 'end'\n";
        std::cout << "Enter name: ";
        std::cin >> name;
        if (name == "end") break;
        std::cout << "Enter phone number: ";
        std::cin >> number;

        names.push_back(name);
        numbers.push_back(number);
    }
    if (!names.empty()) {

        printVector(names, numbers);

        std::cout << "Enter name to search: ";
        std::cin >> name;
        auto it = std::find(names.begin(), names.end(), name);

        if (it != names.end()) {
            size_t index = std::distance(names.begin(), it);
            names.erase(names.begin() + index);
            numbers.erase(numbers.begin() + index);
        }
        std::cout << name << " deleted.\n";
        printVector(names, numbers);
    }
    else {
        std::cout << "Vector is empty\n";
    }

    /* Задание 5 */
    std::cout << "\n === Задание 5 === \n";
    std::vector<Graduate> graduates = {
        Graduate("Иванов", 99),
        Graduate("Петров", 430),
        Graduate("Семенов", 70),
        Graduate("Котов", 540),
        Graduate("Белых", 230),
        Graduate("Черных", 350)
    };

    printGraduates(graduates);

    auto maxIter = std::max_element(graduates.begin(), graduates.end());
    std::cout << "Graduate with highest rating: " << maxIter->getName() << " - " << maxIter->getRating() << std::endl;

    double increment;
    std::cout << "Enter increment value: ";
    std::cin >> increment;

    for (auto& grad : graduates) {
        grad.increaseRating(increment);
    }
    printGraduates(graduates);

    /* Задание 6*/
    std::cout << "\n === Задание 6 === \n";
    std::list<std::string> names1;
    std::list<std::string> numbers1;
    std::string name1, number1;

    while (true) {
        std::cout << "Enter name (or 'end' to finish): ";
        std::cin >> name1;
        if (name1 == "end") break;
        std::cout << "Enter phone number: ";
        std::cin >> number1;

        names1.push_back(name1);
        numbers1.push_back(number1);
    }
    printList(names1, numbers1);

    if (!names1.empty()){
        std::cout << "Enter name to search: ";
        std::cin >> name1;
        auto it = std::find(names1.begin(), names1.end(), name1);

        if (it != names1.end()) {
            auto numIt = numbers1.begin();
            std::advance(numIt, std::distance(names1.begin(), it));
            names1.erase(it);
            numbers1.erase(numIt);
        }
        std::cout << name1 << " deleted.\n";
        printList(names1, numbers1);
    }
    else {
        std::cout << "List is empty\n";
    }

    /* Задание 7 */
    std::cout << "\n === Задание 7 === \n";
    std::list<Point> points = {
            {1.2, 6.3},
            {4.0, 0.7},
            {7.2, 0.8},
            {5.3, 3.0},
            {4.9, 6.6},
            {9.3, 0.2}
    };

    std::cout << "Initial list of points:\n";
    printPoints(points);

    auto maxIter1 = std::max_element(points.begin(), points.end());

    if (maxIter1 != points.end()) {
        std::cout << "Point farthest from origin: (" << maxIter1->x << ", " << maxIter1->y << ")\n";
    }
    else {
        std::cerr << "Error finding the farthest point.\n";
    }

    double shift;
    std::cout << "Enter shift value: ";
    std::cin >> shift;

    for (auto& point : points) {
        point.x -= shift;
    }

    std::cout << "List after shifting:\n";
    printPoints(points);

    /* Задание 8 */
    std::cout << "\n === Задание 8 === \n";
    std::map<int, double> data;
    for (int i = 1; i <= 9; ++i) {
        data[i] = i * 100.0;
    }

    for (const auto& pair : data) {
        std::cout << pair.first << " - " << pair.second << std::endl;
    }

    double sum = 0;
    for (const auto& pair : data) {
        sum += pair.second;
    }
    std::cout << "Sum of values: " << sum << std::endl;

    for (auto& pair : data) {
        pair.second /= sum;
    }

    for (const auto& pair : data) {
        std::cout << pair.first << " - " << pair.second << std::endl;
    }

    /* Задание 9 */
    std::cout << "\n === Задание 9 === \n";
    std::map<std::string, int> students = {
        {"1а", 21}, {"1б", 20}, {"2", 25},
        {"3а", 20}, {"3б", 23}, {"4а", 25},
        {"4б", 25}, {"5а", 26}, {"5б", 25},
        {"6a", 19}, {"6б", 18}, {"7а", 26},
        {"7б", 25}, {"8", 25}, {"9", 17},
        {"10", 15}, {"11", 14}
    };

    std::cout << "Enter the year of study: ";
    int year;
    std::cin >> year;

    int totalStudents = 0;
    for (const auto& pair : students) {
        if (stoi(pair.first.substr(0, 2)) == year) {
            totalStudents += pair.second;
        }
    }

    std::cout << "Year of study: " << year << std::endl;
    std::cout << "Number of students: " << totalStudents << std::endl;
    printMap(students);

    return 0;
}
