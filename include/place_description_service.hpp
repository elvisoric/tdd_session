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
  PlaceDescriptionService(Http& http) : http_{http} {}

  inline std::string summaryDescription(const std::string& latitude,
                                        const std::string& longitude) const {
    const auto response = http_.get("");
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
};
}  // namespace tdd

#endif  // TDD_PLACE_DESCRIPTION_SERVICE_HPP
