#include <iostream>
#include <iomanip>

void DoTowers(int circleCount, int beginPeg, int auxPeg, int endPeg);

int main(int argc, char* argv[]) {
    int circleCount;

    std::cout << "Input number of circles: ";
    std::cin >> circleCount;
    std::cout << "OUTPUT WITH " << circleCount << " CIRCLES" << std::endl;
    std::cout << "CALLED FROM #CIRCLES" << std::setw(8) << "BEGIN"
              << std::setw(8) << "AUXIL." << std::setw(5) << "END"
              << "    INSTUCTIONS" << std::endl
              << std::endl;
    std::cout << "Original   :";
    DoTowers(circleCount, 1, 2, 3);
}

void DoTowers(int circleCount,
              int beginPeg,
              int auxPeg,
              int endPeg) {
    std::cout << std::setw(6) << circleCount << std::setw(9) << beginPeg
              << std::setw(7) << auxPeg << std::setw(7) << endPeg << std::endl;
    if (circleCount > 0) {
        std::cout << "From first :";
        DoTowers(circleCount - 1, beginPeg, endPeg, auxPeg);
        std::cout << std::setw(58) << "Move circle " << circleCount
                  << " from " << beginPeg << " to " << endPeg << std::endl;
        std::cout << "From second:";
        DoTowers(circleCount - 1, auxPeg, beginPeg, endPeg);
    } 
}
