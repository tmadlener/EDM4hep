#ifndef EDM4HEP_TrackerHitWrapper_H
#define EDM4HEP_TrackerHitWrapper_H

#include "edm4hep/SimpleTrackerHitObj.h"
#include "edm4hep/TrackerHitObj.h"

#include <variant>

namespace edm4hep {

class ConstTrackerHitWrapper {
public:
  template<typename TH>
  ConstTrackerHitWrapper(TH&& trackerHit) : m_Hit(trackerHit.m_obj) {}

  ConstTrackerHitWrapper(std::variant<edm4hep::SimpleTrackerHitObj*, edm4hep::TrackerHitObj*> var) :
      m_Hit(var) {}

  ~ConstTrackerHitWrapper() {
    std::visit([](auto&& obj) {obj->release(); }, m_Hit);
  }

  const edm4hep::Vector3d& getPosition() const {
    // trailing return type to make sure that the auto return type deduction
    // does not strip the const ref
    return std::visit([](auto&& obj) -> edm4hep::Vector3d const& {
      return obj->data.position;
    }, m_Hit);
  }

  const podio::ObjectID getObjectID() const {
    return std::visit([](auto&& obj) { return obj->id; }, m_Hit);
  }

private:
  std::variant<edm4hep::SimpleTrackerHitObj*,
               edm4hep::TrackerHitObj*> m_Hit;
};


class TrackerHitWrapper {
public:
  template<typename TH>
  TrackerHitWrapper(TH&& trackerHit) :
      m_Hit(trackerHit.m_obj) {}

  ~TrackerHitWrapper() {
    std::visit([](auto&& obj) { obj->release(); }, m_Hit);
  }

  const edm4hep::Vector3d& getPosition() const {
    // trailing return type to make sure that the auto return type deduction
    // does not strip the const ref
    return std::visit([](auto&& obj) -> edm4hep::Vector3d const& {
      return obj->data.position;
    }, m_Hit);
  }

  void setPosition(edm4hep::Vector3d value) {
    std::visit([value](auto&& obj) { obj->data.position = value; }, m_Hit);
  }

  const podio::ObjectID getObjectID() const {
    return std::visit([](auto&& obj) { return obj->id; }, m_Hit);
  }

  operator edm4hep::ConstTrackerHitWrapper() const {
    return ConstTrackerHitWrapper(m_Hit);
  }

private:
  std::variant<edm4hep::SimpleTrackerHitObj*,
               edm4hep::TrackerHitObj*> m_Hit;
};



}

#endif
