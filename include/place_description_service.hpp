#ifndef TDD_PLACE_DESCRIPTION_SERVICE_HPP
#define TDD_PLACE_DESCRIPTION_SERVICE_HPP

#include <nlohmann/json.hpp>
#include <string>

namespace tdd {
class Http {
  public:
  virtual std::string get(const std::string& url) const = 0;
  virtual ~Http() = default;
};

class PlaceDescriptionService {
  public:
  PlaceDescriptionService(Http& http, const std::string& baseUrl)
      : http_{http}, baseUrl_{baseUrl} {}

  inline std::string summaryDescription(const std::string& latitude,
                                        const std::string& longitude) const {
    const auto url = baseUrl_ + "/lat=" + latitude + "&lon=" + longitude;
    const auto response = http_.get(url);
    const auto jsonResponse = nlohmann::json::parse(response);
    const auto jsonAddress = jsonResponse["address"];

    const std::string separator{", "};

    return jsonAddress["street"].get<std::string>() + separator +
           jsonAddress["city"].get<std::string>() + separator +
           jsonAddress["code"].get<std::string>() + separator +
           jsonAddress["country"].get<std::string>();
  }

  private:
  Http& http_;
  std::string baseUrl_;
};
}  // namespace tdd

#endif  // TDD_PLACE_DESCRIPTION_SERVICE_HPP
