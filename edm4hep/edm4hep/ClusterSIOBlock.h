// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ClusterSIOBlock_H
#define EDM4HEP_ClusterSIOBlock_H

#include "edm4hep/ClusterCollection.h"

#include "podio/SIOBlock.h"

#include <sio/api.h>
#include <sio/io_device.h>
#include <sio/version.h>

#include <typeindex>
#include <string>

namespace edm4hep {


class ClusterSIOBlock: public podio::SIOBlock {
public:
  ClusterSIOBlock() :
  SIOBlock("Cluster", sio::version::encode_version(0, 1)) {
    podio::SIOBlockFactory::instance().registerBlockForCollection("edm4hep::Cluster", this);
  }

  ClusterSIOBlock(const std::string& name) :
  // SIOBlock(name + "__Cluster", sio::version::encode_version(0, 1)) {}
  SIOBlock(name, sio::version::encode_version(0, 1)) {}

  // Read the particle data from the device
  virtual void read(sio::read_device& device, sio::version_type version) override;

  // Write the particle data to the device
  virtual void write(sio::write_device& device) override;

  virtual void createCollection() override {
    setCollection(new ClusterCollection);
  }

  SIOBlock* create(const std::string& name) const override { return new ClusterSIOBlock(name); }
};

static ClusterSIOBlock _dummyClusterSIOBlock;

} // namespace edm4hep


#endif
