

find_package(Delphes)


# build all executables and put them into bin/
add_executable(DelphesROOT_EDM4HEP DelphesROOT_EDM4HEP.cpp Delphes.cc)
target_link_libraries(DelphesROOT_EDM4HEP Delphes edm4hep edm4hepDict podio::podioRootIO ROOT::Physics)
install(TARGETS DelphesROOT_EDM4HEP DESTINATION bin)
