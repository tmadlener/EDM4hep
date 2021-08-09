// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstEventHeader_H
#define EDM4HEP_ConstEventHeader_H

#include "edm4hep/EventHeaderObj.h"

#include "podio/ObjectID.h"



namespace edm4hep {


/** @class ConstEventHeader
 *  Event Header. Additional parameters are assumed to go into the metadata tree.
 *  @author: F.Gaede
 */
class ConstEventHeader {

  friend class EventHeader;
  friend class EventHeaderCollection;
  friend class EventHeaderConstCollectionIterator;

public:
  /// default constructor
  ConstEventHeader();
  ConstEventHeader(int eventNumber, int runNumber, unsigned long long timeStamp, float weight);

  /// constructor from existing EventHeaderObj
  ConstEventHeader(EventHeaderObj* obj);

  /// copy constructor
  ConstEventHeader(const ConstEventHeader& other);

  /// copy-assignment operator
  ConstEventHeader& operator=(const ConstEventHeader& other);

  /// support cloning (deep-copy)
  ConstEventHeader clone() const;

  /// destructor
  ~ConstEventHeader();


public:

  /// Access the event number
  const int& getEventNumber() const;

  /// Access the run number
  const int& getRunNumber() const;

  /// Access the time stamp
  const unsigned long long& getTimeStamp() const;

  /// Access the event weight
  const float& getWeight() const;





  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from EventHeaderObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstEventHeader& other) const { return m_obj == other.m_obj; }
  bool operator==(const EventHeader& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstEventHeader& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  EventHeaderObj* m_obj;
};

} // namespace edm4hep


#endif
