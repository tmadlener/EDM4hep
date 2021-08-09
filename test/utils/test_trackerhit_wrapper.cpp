#define CATCH_CONFIG_FAST_COMPILE
#include <catch2/catch_test_macros.hpp>

#include "edm4hep/TrackerHit.h"
#include "edm4hep/SimpleTrackerHit.h"
#include "edm4hep/TrackerHitWrapper.h"

#include <vector>
#include <iostream>

TEST_CASE("TrackerHitWrapper works basically") {
  std::vector<edm4hep::TrackerHitWrapper> trackerHits;

  edm4hep::TrackerHit hit1{};
  hit1.setPosition({1, 2, 3});
  trackerHits.emplace_back(hit1);

  const auto& pos = hit1.getPosition();

  REQUIRE(pos[0] == 1);
  REQUIRE(pos[1] == 2);
  REQUIRE(pos[2] == 3);

  edm4hep::SimpleTrackerHit hit2{};
  hit2.setPosition({3, 2, 1});
  trackerHits.emplace_back(hit2);

  for (const auto& hit : trackerHits) {
    REQUIRE(hit.getPosition()[1] == 2);
  }

  trackerHits[0].setPosition({0, 0, 0});
  REQUIRE(pos[0] == 0);
  REQUIRE(pos[1] == 0);
  REQUIRE(pos[2] == 0);
}
