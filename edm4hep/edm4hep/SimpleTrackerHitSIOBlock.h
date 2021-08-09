// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimpleTrackerHitSIOBlock_H
#define EDM4HEP_SimpleTrackerHitSIOBlock_H

#include "edm4hep/SimpleTrackerHitCollection.h"

#include "podio/SIOBlock.h"

#include <sio/api.h>
#include <sio/io_device.h>
#include <sio/version.h>

#include <typeindex>
#include <string>

namespace edm4hep {


class SimpleTrackerHitSIOBlock: public podio::SIOBlock {
public:
  SimpleTrackerHitSIOBlock() :
  SIOBlock("SimpleTrackerHit", sio::version::encode_version(0, 1)) {
    podio::SIOBlockFactory::instance().registerBlockForCollection("edm4hep::SimpleTrackerHit", this);
  }

  SimpleTrackerHitSIOBlock(const std::string& name) :
  // SIOBlock(name + "__SimpleTrackerHit", sio::version::encode_version(0, 1)) {}
  SIOBlock(name, sio::version::encode_version(0, 1)) {}

  // Read the particle data from the device
  virtual void read(sio::read_device& device, sio::version_type version) override;

  // Write the particle data to the device
  virtual void write(sio::write_device& device) override;

  virtual void createCollection() override {
    setCollection(new SimpleTrackerHitCollection);
  }

  SIOBlock* create(const std::string& name) const override { return new SimpleTrackerHitSIOBlock(name); }
};

static SimpleTrackerHitSIOBlock _dummySimpleTrackerHitSIOBlock;

} // namespace edm4hep


#endif
