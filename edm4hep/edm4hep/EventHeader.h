// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_EventHeader_H
#define EDM4HEP_EventHeader_H

#include "edm4hep/EventHeaderConst.h"
#include "edm4hep/EventHeaderObj.h"

#include "podio/ObjectID.h"
#include <ostream>



namespace edm4hep {


/** @class EventHeader
 *  Event Header. Additional parameters are assumed to go into the metadata tree.
 *  @author: F.Gaede
 */
class EventHeader {

  friend class EventHeaderCollection;
  friend class EventHeaderCollectionIterator;
  friend class ConstEventHeader;

public:

  /// default constructor
  EventHeader();
  EventHeader(int eventNumber, int runNumber, unsigned long long timeStamp, float weight);

  /// constructor from existing EventHeaderObj
  EventHeader(EventHeaderObj* obj);

  /// copy constructor
  EventHeader(const EventHeader& other);

  /// copy-assignment operator
  EventHeader& operator=(const EventHeader& other);

  /// support cloning (deep-copy)
  EventHeader clone() const;

  /// destructor
  ~EventHeader();

  /// conversion to const object
  operator ConstEventHeader() const;

public:

  /// Access the event number
  const int& getEventNumber() const;

  /// Access the run number
  const int& getRunNumber() const;

  /// Access the time stamp
  const unsigned long long& getTimeStamp() const;

  /// Access the event weight
  const float& getWeight() const;



  /// Set the event number
  void setEventNumber(int value);

  /// Set the run number
  void setRunNumber(int value);

  /// Set the time stamp
  void setTimeStamp(unsigned long long value);

  /// Set the event weight
  void setWeight(float value);






  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from EventHeaderObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const EventHeader& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstEventHeader& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const EventHeader& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  EventHeaderObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstEventHeader& value);

} // namespace edm4hep


#endif
