#include <iostream>

class User {
   public:
    std::string username;
    User(std::string username, int points)
        : username(username), points(points) {}
    int points;
};

class Algo {
    static int bonus;
    Algo();

   public:
    static int calculateBonus(User& u) {
        static std::string prev = "first";
        if (bonus == 1000) {
            std::cout << "You're the first winner!" << std::endl;
        } else {
            std::cout << "The previous winner was " << prev << ", winning "
                      << bonus + 1 << " points" << ".\n";
        }
        prev = u.username;
        u.points += bonus;
        return bonus--;
    }
};

int Algo::bonus = 1000;

int main() {
    User u1("Caleb", 500);
    User u2("Belac", 50);

    Algo::calculateBonus(u1);
    Algo::calculateBonus(u2);
    Algo::calculateBonus(u1);
    Algo::calculateBonus(u2);

    std::cout << u1.points << " " << u2.points << std::endl;
}