#ifndef TDD_TENNIS_RESULT_KEEPER_HPP
#define TDD_TENNIS_RESULT_KEEPER_HPP

#include <string>

namespace tdd {

struct TennisResultKeeper {
  inline std::string result() const {
    std::string first, second;
    if (firstPoints == 55) {
      first = "A";
      second = "-";
    } else if (secondPoints == 55) {
      first = "-";
      second = "A";
    } else {
      first = std::to_string(firstPoints);
      second = std::to_string(secondPoints);
    }
    return "| 0 | " + std::to_string(firstGames) + " | " + first +
           " |\n| 0 | " + std::to_string(secondGames) + " | " + second + " |";
  }

  inline void pointFirstPlayer() {
    if (secondPoints == 55) {
      secondPoints = 40;
    } else {
      if (firstPoints == 40 && secondPoints != 40) {
        firstPoints = 0;
        secondPoints = 0;
        firstGames = 1;
      } else {
        firstPoints == 30 ? firstPoints = 40 : firstPoints += 15;
      }
    }
  }

  inline void pointSecondPlayer() {
    if (firstPoints == 55) {
      firstPoints = 40;
    } else {
      if (secondPoints == 40 && firstPoints != 40) {
        firstPoints = 0;
        secondPoints = 0;
        secondGames = 1;
      } else {
        secondPoints == 30 ? secondPoints = 40 : secondPoints += 15;
      }
    }
  }

  int firstPoints{0};
  int secondPoints{0};
  int firstGames{0};
  int secondGames{0};
};

}  // namespace tdd

#endif  // TDD_TENNIS_RESULT_KEEPER_HPP
