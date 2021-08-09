// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/ClusterSIOBlock.h"

#include <sio/block.h>
#include <sio/io_device.h>
#include <sio/version.h>


namespace edm4hep {


void ClusterSIOBlock::read(sio::read_device& device, sio::version_type) {

  auto* dataVec = static_cast<edm4hep::ClusterCollection*>(_col)->_getBuffer();

  unsigned size(0);
  device.data( size );
  dataVec->resize(size);

  podio::handlePODDataSIO(device, &(*dataVec)[0], size);

  //---- read ref collections -----
  podio::CollRefCollection* refCols = _col->referenceCollections() ;
  for( auto* refC : *refCols ){
    device.data( size ) ;
    refC->resize(size) ;
    podio::handlePODDataSIO( device ,  &((*refC)[0]), size ) ;
  }

  //---- read vector members
  podio::VectorMembersInfo * vecMemInfo = _col->vectorMembers() ;

    auto* vec0 = *reinterpret_cast<std::vector<float>**>(vecMemInfo->at(0).second);
    device.data(size);
    vec0->resize(size);
    podio::handlePODDataSIO(device, &(*vec0)[0], size);

    auto* vec1 = *reinterpret_cast<std::vector<float>**>(vecMemInfo->at(1).second);
    device.data(size);
    vec1->resize(size);
    podio::handlePODDataSIO(device, &(*vec1)[0], size);

    auto* vec2 = *reinterpret_cast<std::vector<float>**>(vecMemInfo->at(2).second);
    device.data(size);
    vec2->resize(size);
    podio::handlePODDataSIO(device, &(*vec2)[0], size);

}

void ClusterSIOBlock::write(sio::write_device& device) {
  _col->prepareForWrite() ;

  auto * dataVec = static_cast<edm4hep::ClusterCollection*>(_col)->_getBuffer() ;

  unsigned size = dataVec->size() ;
  device.data( size ) ;

  podio::handlePODDataSIO( device ,  &(*dataVec)[0], size ) ;

  //---- write ref collections -----
  podio::CollRefCollection* refCols = _col->referenceCollections() ;
  for( auto* refC : *refCols ){
    size = refC->size() ;
    device.data( size ) ;
    podio::handlePODDataSIO( device ,  &((*refC)[0]), size ) ;
  }

  //---- write vector members
  podio::VectorMembersInfo * vecMemInfo = _col->vectorMembers() ;

    auto* vec0 = *reinterpret_cast<std::vector<float>**>(vecMemInfo->at(0).second);
    size = vec0->size();
    device.data(size);
    podio::handlePODDataSIO(device, &(*vec0)[0], size);


    auto* vec1 = *reinterpret_cast<std::vector<float>**>(vecMemInfo->at(1).second);
    size = vec1->size();
    device.data(size);
    podio::handlePODDataSIO(device, &(*vec1)[0], size);


    auto* vec2 = *reinterpret_cast<std::vector<float>**>(vecMemInfo->at(2).second);
    size = vec2->size();
    device.data(size);
    podio::handlePODDataSIO(device, &(*vec2)[0], size);


}

} // namespace edm4hep
