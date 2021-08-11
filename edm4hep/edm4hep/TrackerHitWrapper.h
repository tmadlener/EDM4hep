#ifndef EDM4HEP_TrackerHitWrapper_H
#define EDM4HEP_TrackerHitWrapper_H

#include "edm4hep/SimpleTrackerHitObj.h"
#include "edm4hep/TrackerHitObj.h"

#include <variant>

template<class T>
struct remove_cvref {
  using type = std::remove_cv_t<std::remove_reference_t<T>>;
};

template<class T>
using remove_cvref_t = typename remove_cvref<T>::type;

template<typename T, typename ...Ts>
constexpr bool isAnyOf = (std::is_same_v<remove_cvref_t<T>, Ts> || ...);

template<typename T, typename ...Ts>
struct EnableIfAnyOf : std::enable_if<isAnyOf<T, Ts...>, bool> {};

template<typename T>
struct EnableIfAnyTrackerHit : EnableIfAnyOf<T,
                                             edm4hep::TrackerHit,
                                             edm4hep::SimpleTrackerHit,
                                             edm4hep::ConstTrackerHit,
                                             edm4hep::ConstSimpleTrackerHit> {};

template<typename T>
using EnableIfAnyTrackerHitT = typename EnableIfAnyTrackerHit<T>::type;

template<typename T>
struct EnableIfMutableTrackerHit : EnableIfAnyOf<T,
                                                 edm4hep::TrackerHit,
                                                 edm4hep::SimpleTrackerHit> {};

template<typename T>
using EnableIfMutableTrackerHitT = typename EnableIfMutableTrackerHit<T>::type;

template<typename T>
struct EnableIfTrackerHitObjPtr : EnableIfAnyOf<T,
                                                edm4hep::SimpleTrackerHitObj*,
                                                edm4hep::TrackerHitObj*> {};

template<typename T>
using EnableIfTrackerHitObjPtrT = typename EnableIfTrackerHitObjPtr<T>::type;

namespace edm4hep {

class ConstTrackerHitWrapper {
public:
  template<typename TH, EnableIfAnyTrackerHitT<TH> = false>
  ConstTrackerHitWrapper(TH&& trackerHit) : m_Hit(trackerHit.m_obj) {
    trackerHit.m_obj->acquire(); // TODO: properly do this via std::visit
  }

  template<typename ObjPtr, EnableIfTrackerHitObjPtrT<ObjPtr> = false>
  ConstTrackerHitWrapper(ObjPtr* hitObjPtr) : m_Hit(hitObjPtr) {
    hitObjPtr->acquire();
  }

  ConstTrackerHitWrapper(std::variant<edm4hep::SimpleTrackerHitObj*, edm4hep::TrackerHitObj*> var) :
    m_Hit(var) {
  }

  ~ConstTrackerHitWrapper() {
    std::visit([](auto&& obj) { if(obj) obj->release(); }, m_Hit);
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

  std::ostream& print(std::ostream& os) const {
    return std::visit([&os](auto&& obj) -> std::ostream& { return os << obj; }, m_Hit);
  }

  unsigned id() const {
    return std::visit([](auto&& obj) {
      const auto objId = obj->id;
      return objId.collectionID * 10000000 + objId.index;
    }, m_Hit);
  }

  void unlink() {
    std::visit([](auto&& obj) {
      obj = nullptr;
    }, m_Hit);
  }

private:
  std::variant<edm4hep::SimpleTrackerHitObj*,
               edm4hep::TrackerHitObj*> m_Hit;
};


class TrackerHitWrapper {
public:
  template<typename TH, EnableIfMutableTrackerHitT<TH> = false>
  TrackerHitWrapper(TH&& trackerHit) : m_Hit(trackerHit.m_obj) {
    trackerHit.m_obj->acquire(); // TODO: properly do this via std::visit
  }

  template<typename ObjPtr, EnableIfTrackerHitObjPtrT<ObjPtr> = false>
  TrackerHitWrapper(ObjPtr* hitObjPtr) : m_Hit(hitObjPtr) {
    hitObjPtr->acquire();
  }

  ~TrackerHitWrapper() {
    std::visit([](auto&& obj) { if(obj) obj->release(); }, m_Hit);
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

inline std::ostream& operator<<(std::ostream& os, edm4hep::ConstTrackerHitWrapper const& hit) {
  return hit.print(os);
}

}

#endif
