#include "LabWork2_No8.h"

class Graduate {
    std::string name;
    double rating;
public:
    Graduate() : name(""), rating(0) {}
    Graduate(std::string Name, double Rating) : name(Name), rating(Rating) {}

    double getRating() const { return rating; }
    std::string getName() const { return name; }

    void increaseRating(double value) {
        rating += value;
    }

    bool operator<(const Graduate& other) const {
        return rating < other.rating;
    }

    bool operator==(const Graduate& other) const {
        return rating == other.rating;
    }
};

void printGraduates(const std::vector<Graduate>& graduates) {
    for (const auto& grad : graduates) {
        std::cout << grad.getName() << " - " << grad.getRating() << std::endl;
    }
}