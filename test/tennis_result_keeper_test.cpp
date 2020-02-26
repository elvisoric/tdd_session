#include <gmock/gmock.h>

#include <tennis_result_keeper.hpp>

using namespace ::testing;

namespace {
class TennisResultKeeperTest : public testing::Test {
  protected:
  tdd::TennisResultKeeper keeper;
};

}  // namespace

TEST_F(TennisResultKeeperTest,
       ExpectsThatWhenCreatingNewResultKeeperTheSetGameAndPointsAreZero) {
  const std::string expected =
      "| 0 | 0 | 0 |\n"
      "| 0 | 0 | 0 |";
  ASSERT_THAT(keeper.result(), Eq(expected));
}

TEST_F(TennisResultKeeperTest,
       ExpectsThatAddingFirstPointForFirstPlayerIncreasesPointsTo15) {
  keeper.pointFirstPlayer();
  const std::string expected =
      "| 0 | 0 | 15 |\n"
      "| 0 | 0 | 0 |";
  ASSERT_THAT(keeper.result(), Eq(expected));
}

TEST_F(TennisResultKeeperTest,
       ExpectsThatAddingFirstPointForSecondPlayerIncreasesPointsTo15) {
  keeper.pointSecondPlayer();
  const std::string expected =
      "| 0 | 0 | 0 |\n"
      "| 0 | 0 | 15 |";
  ASSERT_THAT(keeper.result(), Eq(expected));
}

TEST_F(TennisResultKeeperTest, ExpectsToConfirmPointsOrderingForBothPlayers) {
  keeper.pointFirstPlayer();
  const std::string expected1 =
      "| 0 | 0 | 15 |\n"
      "| 0 | 0 | 0 |";
  EXPECT_THAT(keeper.result(), Eq(expected1));

  keeper.pointFirstPlayer();
  const std::string expected2 =
      "| 0 | 0 | 30 |\n"
      "| 0 | 0 | 0 |";
  EXPECT_THAT(keeper.result(), Eq(expected2));

  keeper.pointSecondPlayer();
  keeper.pointSecondPlayer();
  const std::string expected3 =
      "| 0 | 0 | 30 |\n"
      "| 0 | 0 | 30 |";
  EXPECT_THAT(keeper.result(), Eq(expected3));

  keeper.pointSecondPlayer();
  const std::string expected4 =
      "| 0 | 0 | 30 |\n"
      "| 0 | 0 | 40 |";
  EXPECT_THAT(keeper.result(), Eq(expected4));

  keeper.pointFirstPlayer();
  const std::string expected5 =
      "| 0 | 0 | 40 |\n"
      "| 0 | 0 | 40 |";
  EXPECT_THAT(keeper.result(), Eq(expected5));

  keeper.pointFirstPlayer();
  const std::string expected6 =
      "| 0 | 0 | A |\n"
      "| 0 | 0 | - |";
  EXPECT_THAT(keeper.result(), Eq(expected6));
}

namespace {

class TennisResultKeeperWithAdvantageTest : public TennisResultKeeperTest {
  public:
  void SetUp() override {
    keeper.pointFirstPlayer();
    keeper.pointFirstPlayer();
    keeper.pointFirstPlayer();
    keeper.pointSecondPlayer();
    keeper.pointSecondPlayer();
    keeper.pointSecondPlayer();
  }
};
}  // namespace

TEST_F(TennisResultKeeperWithAdvantageTest,
       ExpectsToConfirmThatFirstPlayerCanHaveAdvantage) {
  keeper.pointFirstPlayer();

  const std::string expected =
      "| 0 | 0 | A |\n"
      "| 0 | 0 | - |";
  EXPECT_THAT(keeper.result(), Eq(expected));
}

TEST_F(TennisResultKeeperWithAdvantageTest,
       ExpectsToConfirmThatSecondPlayerCanHaveAdvantage) {
  keeper.pointSecondPlayer();

  const std::string expected =
      "| 0 | 0 | - |\n"
      "| 0 | 0 | A |";
  EXPECT_THAT(keeper.result(), Eq(expected));
}

TEST_F(TennisResultKeeperWithAdvantageTest,
       ExpectsToConfirmThatResultIsDeuceWhenPlayerLosesAdvantage) {
  keeper.pointFirstPlayer();
  keeper.pointSecondPlayer();

  const std::string expected1 =
      "| 0 | 0 | 40 |\n"
      "| 0 | 0 | 40 |";
  EXPECT_THAT(keeper.result(), Eq(expected1));

  keeper.pointSecondPlayer();
  keeper.pointFirstPlayer();

  const std::string expected2 =
      "| 0 | 0 | 40 |\n"
      "| 0 | 0 | 40 |";
  EXPECT_THAT(keeper.result(), Eq(expected2));
}
