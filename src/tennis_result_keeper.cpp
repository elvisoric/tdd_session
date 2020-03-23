#include <tennis_result_keeper.hpp>

namespace tdd {

std::string TennisResultKeeper::result() const {
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
  return "| 0 | 0 | " + first +
         " |\n"
         "| 0 | 0 | " +
         second + " |";
}
void TennisResultKeeper::pointFirstPlayer() {
  if (secondPoints == 55) {
    secondPoints = 40;
  } else {
    firstPoints == 30 ? firstPoints = 40 : firstPoints += 15;
  }
}

void TennisResultKeeper::pointSecondPlayer() {
  if (firstPoints == 55) {
    firstPoints = 40;
  } else {
    secondPoints == 30 ? secondPoints = 40 : secondPoints += 15;
  }
}
}  // namespace tdd
