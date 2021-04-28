
add_llvm_library(TOPTSimplifyCFG
  SimplifyCFG.cpp

  DEPENDS
  intrinsics_gen

  LINK_COMPONENTS
  Analysis
  Core
  Support
)
