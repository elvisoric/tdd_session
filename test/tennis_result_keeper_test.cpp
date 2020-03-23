#include <gmock/gmock.h>

#include <tennis_result_keeper.hpp>

using namespace ::testing;

namespace {

class TennisResultKeeperTest : public Test {
  protected:
  tdd::TennisResultKeeper keeper;
};

}  // namespace

TEST_F(TennisResultKeeperTest,
       ExpectsToConfirmThatStartingResultIsSetToZeroOnCreation) {
  const std::string expected =
      "| 0 | 0 | 0 |\n"
      "| 0 | 0 | 0 |";

  ASSERT_THAT(keeper.result(), Eq(expected));
}

TEST_F(TennisResultKeeperTest,
       ExpectsToConfirmPointsAreProperlyUpdatedForBothPlayers) {
  keeper.pointFirstPlayer();
  std::string expected =
      "| 0 | 0 | 15 |\n"
      "| 0 | 0 | 0 |";
  EXPECT_THAT(keeper.result(), Eq(expected));

  keeper.pointSecondPlayer();
  expected =
      "| 0 | 0 | 15 |\n"
      "| 0 | 0 | 15 |";
  EXPECT_THAT(keeper.result(), Eq(expected));

  keeper.pointFirstPlayer();
  expected =
      "| 0 | 0 | 30 |\n"
      "| 0 | 0 | 15 |";
  EXPECT_THAT(keeper.result(), Eq(expected));

  keeper.pointSecondPlayer();
  expected =
      "| 0 | 0 | 30 |\n"
      "| 0 | 0 | 30 |";
  EXPECT_THAT(keeper.result(), Eq(expected));

  keeper.pointFirstPlayer();
  expected =
      "| 0 | 0 | 40 |\n"
      "| 0 | 0 | 30 |";
  EXPECT_THAT(keeper.result(), Eq(expected));

  keeper.pointSecondPlayer();
  expected =
      "| 0 | 0 | 40 |\n"
      "| 0 | 0 | 40 |";
  EXPECT_THAT(keeper.result(), Eq(expected));
}

namespace {

class TennisResultKeeperAdvantageTest : public TennisResultKeeperTest {
  protected:
  void SetUp() override {
    keeper.pointFirstPlayer();
    keeper.pointFirstPlayer();
    keeper.pointFirstPlayer();
    keeper.pointSecondPlayer();
    keeper.pointSecondPlayer();
    keeper.pointSecondPlayer();
  }
};

TEST_F(TennisResultKeeperAdvantageTest,
       ExpectsToConfirmThatFirstPlayerCanHaveAdvantage) {
  keeper.pointFirstPlayer();
  const std::string expected =
      "| 0 | 0 | A |\n"
      "| 0 | 0 | - |";
  EXPECT_THAT(keeper.result(), Eq(expected));
}

TEST_F(TennisResultKeeperAdvantageTest,
       ExpectsToConfirmThatSecondPlayerCanHaveAdvantage) {
  keeper.pointSecondPlayer();
  const std::string expected =
      "| 0 | 0 | - |\n"
      "| 0 | 0 | A |";
  EXPECT_THAT(keeper.result(), Eq(expected));
}

TEST_F(TennisResultKeeperAdvantageTest,
       ExpectsToConfirmThatDeuceIsAcheavedAfterFirstPlayerHadAdvantage) {
  keeper.pointFirstPlayer();
  keeper.pointSecondPlayer();

  const std::string expected =
      "| 0 | 0 | 40 |\n"
      "| 0 | 0 | 40 |";
  EXPECT_THAT(keeper.result(), Eq(expected));
}

TEST_F(TennisResultKeeperAdvantageTest,
       ExpectsToConfirmThatDeuceIsAcheavedAfterSecondPlayerHadAdvantage) {
  keeper.pointSecondPlayer();
  keeper.pointFirstPlayer();

  const std::string expected =
      "| 0 | 0 | 40 |\n"
      "| 0 | 0 | 40 |";
  EXPECT_THAT(keeper.result(), Eq(expected));
}

}  // namespace
