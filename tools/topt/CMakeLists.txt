set(LLVM_LINK_COMPONENTS
  AllTargetsAsmParsers
  AllTargetsCodeGens
  AllTargetsInfos
  Analysis
  Support
  Core
  CodeGen
  ScalarOpts
  IRReader
  IRPrinter
  Target
  TargetParser
  TransformUtils
  Passes
)

add_llvm_tool(topt
  topt.cpp

  DEPENDS
  intrinsics_gen
  )
target_link_libraries(topt PRIVATE TOPTConstProp TOPTPasses)
export_executable_symbols(topt)
