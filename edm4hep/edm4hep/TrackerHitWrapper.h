#ifndef EDM4HEP_TrackerHitWrapper_H
#define EDM4HEP_TrackerHitWrapper_H

#include "edm4hep/SimpleTrackerHit.h"
#include "edm4hep/TrackerHit.h"

#include "podio/GenericWrapper.h"

#include <variant>

namespace edm4hep {

class ConstTrackerHitWrapper : public podio::GenericWrapper<edm4hep::TrackerHit, edm4hep::SimpleTrackerHit> {
  using WrapperT = podio::GenericWrapper<edm4hep::TrackerHit, edm4hep::SimpleTrackerHit>;
public:
  ConstTrackerHitWrapper() = delete;

  template<typename T,
           WrapperT::EnableWrapper<T> = false>
  ConstTrackerHitWrapper(T&& t) : WrapperT(std::forward<T>(t)) {}

  ConstTrackerHitWrapper(const ConstTrackerHitWrapper& other) : WrapperT(other.m_obj) {}

  ConstTrackerHitWrapper(WrapperT const& other) : WrapperT(other) {}

  const edm4hep::Vector3d& getPosition() const {
    // trailing return type to make sure that the auto return type deduction
    // does not strip the const ref
    return std::visit([](auto&& obj) -> edm4hep::Vector3d const& {
      return obj->data.position;
    }, m_obj);
  }

  const podio::ObjectID getObjectID() const {
    return std::visit([](auto&& obj) { return obj->id; }, m_obj);
  }

  std::ostream& print(std::ostream& os) const {
    return std::visit([&os](auto&& obj) -> std::ostream& { return os << obj; }, m_obj);
  }
};


class TrackerHitWrapper : public podio::GenericWrapper<edm4hep::TrackerHit, edm4hep::SimpleTrackerHit> {
    using WrapperT = podio::GenericWrapper<edm4hep::TrackerHit, edm4hep::SimpleTrackerHit>;
public:
  TrackerHitWrapper() = delete;

  template<typename T,
           WrapperT::EnableWrapper<T> = false>
  TrackerHitWrapper(T&& t) : WrapperT(std::forward<T>(t)) {}

  TrackerHitWrapper(const TrackerHitWrapper& other) : WrapperT(other.m_obj) {}

  const edm4hep::Vector3d& getPosition() const {
    // trailing return type to make sure that the auto return type deduction
    // does not strip the const ref
    return std::visit([](auto&& obj) -> edm4hep::Vector3d const& {
      return obj->data.position;
    }, m_obj);
  }

  void setPosition(edm4hep::Vector3d value) {
    std::visit([value](auto&& obj) { obj->data.position = value; }, m_obj);
  }

  const podio::ObjectID getObjectID() const {
    return std::visit([](auto&& obj) { return obj->id; }, m_obj);
  }

  operator edm4hep::ConstTrackerHitWrapper() const {
    return ConstTrackerHitWrapper(m_obj);
  }

};

inline std::ostream& operator<<(std::ostream& os, edm4hep::ConstTrackerHitWrapper const& hit) {
  return hit.print(os);
}

}

#endif
