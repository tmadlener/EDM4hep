// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackSIOBlock_H
#define EDM4HEP_TrackSIOBlock_H

#include "edm4hep/TrackCollection.h"

#include "podio/SIOBlock.h"

#include <sio/api.h>
#include <sio/io_device.h>
#include <sio/version.h>

#include <typeindex>
#include <string>

namespace edm4hep {


class TrackSIOBlock: public podio::SIOBlock {
public:
  TrackSIOBlock() :
  SIOBlock("Track", sio::version::encode_version(0, 1)) {
    podio::SIOBlockFactory::instance().registerBlockForCollection("edm4hep::Track", this);
  }

  TrackSIOBlock(const std::string& name) :
  // SIOBlock(name + "__Track", sio::version::encode_version(0, 1)) {}
  SIOBlock(name, sio::version::encode_version(0, 1)) {}

  // Read the particle data from the device
  virtual void read(sio::read_device& device, sio::version_type version) override;

  // Write the particle data to the device
  virtual void write(sio::write_device& device) override;

  virtual void createCollection() override {
    setCollection(new TrackCollection);
  }

  SIOBlock* create(const std::string& name) const override { return new TrackSIOBlock(name); }
};

static TrackSIOBlock _dummyTrackSIOBlock;

} // namespace edm4hep


#endif
