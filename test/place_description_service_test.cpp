#include <gmock/gmock.h>

#include <place_description_service.hpp>

using namespace ::testing;

namespace {

class HttpStub : public tdd::Http {
  public:
  std::string get(std::string const&) const override {
    return R"({ "address": {
                "street":"Marsala Tita",
                "city":"Tuzla",
                "code":"75000",
                "country":"BiH" }})";
  }
};

class PlaceDescriptionServiceTest : public Test {
  protected:
  const std::string validLatitude;
  const std::string validLongitude;
};

}  // namespace

TEST_F(PlaceDescriptionServiceTest, ReturnsDescriptionForValidLocation) {
  HttpStub httpStub;
  tdd::PlaceDescriptionService service{httpStub};

  const auto description =
      service.summaryDescription(validLatitude, validLongitude);
  ASSERT_THAT(description, Eq("Marsala Tita, Tuzla, 75000, BiH"));
}
