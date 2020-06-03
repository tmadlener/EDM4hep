

find_package(Delphes)

# build all executables and put them into bin/
add_executable(DelphesROOT_EDM4HEP DelphesROOT_EDM4HEP.cpp Delphes.cc)
target_include_directories(DelphesROOT_EDM4HEP PRIVATE ${DELPHES_INCLUDE_DIRS})
target_link_libraries_force_dict(DelphesROOT_EDM4HEP edm4hepDict ${DELPHES_LIBRARY} edm4hep podio::podioRootIO ROOT::Physics ROOT::GenVector ROOT::MathCore)
install(TARGETS DelphesROOT_EDM4HEP DESTINATION bin)

# build all executables and put them into bin/
add_executable(DelphesHepMC_EDM4HEP DelphesHepMC_EDM4HEP.cpp Delphes.cc)
target_include_directories(DelphesHepMC_EDM4HEP PRIVATE ${DELPHES_INCLUDE_DIRS})
target_link_libraries_force_dict(DelphesHepMC_EDM4HEP edm4hepDict ${DELPHES_LIBRARY} edm4hep podio::podioRootIO ROOT::Physics  ROOT::GenVector ROOT::MathCore)
install(TARGETS DelphesHepMC_EDM4HEP DESTINATION bin)

# build all executables and put them into bin/
add_executable(DelphesSTDHEP_EDM4HEP DelphesSTDHEP_EDM4HEP.cpp Delphes.cc)
target_include_directories(DelphesSTDHEP_EDM4HEP PRIVATE ${DELPHES_INCLUDE_DIRS})
target_link_libraries_force_dict(DelphesSTDHEP_EDM4HEP edm4hepDict ${DELPHES_LIBRARY} edm4hep podio::podioRootIO ROOT::Physics  ROOT::GenVector ROOT::MathCore)
install(TARGETS DelphesSTDHEP_EDM4HEP DESTINATION bin)

find_package(Pythia8)
find_package(ROOT COMPONENTS EG Eve Geom Gui GuiHtml GenVector Hist Physics Matrix Graf RIO Tree Gpad RGL MathCore)

# build all executables and put them into bin/
add_executable(DelphesPythia8_EDM4HEP DelphesPythia8_EDM4HEP.cpp Delphes.cc)
target_include_directories(DelphesPythia8_EDM4HEP PRIVATE ${DELPHES_INCLUDE_DIRS} ${PYTHIA8_INCLUDE_DIRS})
target_link_libraries_force_dict(DelphesPythia8_EDM4HEP edm4hepDict ${DELPHES_LIBRARY}  edm4hep podio::podioRootIO ROOT::Physics  ROOT::GenVector ROOT::MathCore ROOT::EG ${PYTHIA8_LIBRARIES})
install(TARGETS DelphesPythia8_EDM4HEP DESTINATION bin)
