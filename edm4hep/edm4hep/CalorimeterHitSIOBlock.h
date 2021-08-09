// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CalorimeterHitSIOBlock_H
#define EDM4HEP_CalorimeterHitSIOBlock_H

#include "edm4hep/CalorimeterHitCollection.h"

#include "podio/SIOBlock.h"

#include <sio/api.h>
#include <sio/io_device.h>
#include <sio/version.h>

#include <typeindex>
#include <string>

namespace edm4hep {


class CalorimeterHitSIOBlock: public podio::SIOBlock {
public:
  CalorimeterHitSIOBlock() :
  SIOBlock("CalorimeterHit", sio::version::encode_version(0, 1)) {
    podio::SIOBlockFactory::instance().registerBlockForCollection("edm4hep::CalorimeterHit", this);
  }

  CalorimeterHitSIOBlock(const std::string& name) :
  // SIOBlock(name + "__CalorimeterHit", sio::version::encode_version(0, 1)) {}
  SIOBlock(name, sio::version::encode_version(0, 1)) {}

  // Read the particle data from the device
  virtual void read(sio::read_device& device, sio::version_type version) override;

  // Write the particle data to the device
  virtual void write(sio::write_device& device) override;

  virtual void createCollection() override {
    setCollection(new CalorimeterHitCollection);
  }

  SIOBlock* create(const std::string& name) const override { return new CalorimeterHitSIOBlock(name); }
};

static CalorimeterHitSIOBlock _dummyCalorimeterHitSIOBlock;

} // namespace edm4hep


#endif
