#ifndef TDD_TENNIS_RESULT_KEEPER_HPP
#define TDD_TENNIS_RESULT_KEEPER_HPP

#include <string>

namespace tdd {
struct TennisResultKeeper {
  std::string result() const;
  void pointFirstPlayer();
  void pointSecondPlayer();

  private:
  int firstPoints{0};
  int secondPoints{0};
};
}  // namespace tdd

#endif  // TDD_TENNIS_RESULT_KEEPER_HPP
