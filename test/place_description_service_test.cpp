#include <gmock/gmock.h>

#include <place_description_service.hpp>

using namespace ::testing;

namespace {

const auto addressResponse = R"({ "address": {
                "street":"Marsala Tita",
                "city":"Tuzla",
                "code":"75000",
                "country":"BiH" }})";

class HttpStub : public tdd::Http {
  public:
  std::string get(std::string const&) const override { return addressResponse; }
};

class HttpMock : public tdd::Http {
  public:
  MOCK_CONST_METHOD1(get, std::string(const std::string&));
};

class PlaceDescriptionServiceTest : public Test {
  protected:
  const std::string validLatitude;
  const std::string validLongitude;
};

}  // namespace

TEST_F(PlaceDescriptionServiceTest, ReturnsDescriptionForValidLocation) {
  HttpStub httpStub;
  tdd::PlaceDescriptionService service{httpStub, ""};

  const auto description =
      service.summaryDescription(validLatitude, validLongitude);
  ASSERT_THAT(description, Eq("Marsala Tita, Tuzla, 75000, BiH"));
}

TEST_F(PlaceDescriptionServiceTest,
       ExpectsToConfirmThatUrlIsProperlyConstructed) {
  HttpMock httpMock;
  std::string baseUrl{"https://addresslocation.com"};
  std::string latitude{"44.53842"};
  std::string longitude{"18.66709"};
  tdd::PlaceDescriptionService service{httpMock, baseUrl};
  const std::string expectedUrl =
      "https://addresslocation.com/lat=44.53842&lon=18.66709";

  EXPECT_CALL(httpMock, get(expectedUrl)).WillOnce(Return(addressResponse));

  service.summaryDescription(latitude, longitude);
}
