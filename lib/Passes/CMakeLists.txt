
add_llvm_library(TOPTPasses
  PassRegistry.cpp

  DEPENDS
  intrinsics_gen

  LINK_COMPONENTS
  Core
  Support
)

target_link_libraries(TOPTPasses PRIVATE TOPTConstProp TOPTSimplifyCFG)
