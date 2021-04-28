#include "topt/Passes/PassRegistry.h"
#include "topt/DataFlow/SCCP.h"
#include "topt/DataFlow/SSCP.h"
#include "topt/SimplifyCFG/SimplifyCFG.h"

#include <llvm/Passes/PassBuilder.h>

namespace llvm {
namespace trainOpt {
void registerPasses(PassBuilder &PB) {
  PB.registerPipelineParsingCallback(
      [](StringRef Name, FunctionPassManager &PM,
         ArrayRef<PassBuilder::PipelineElement>) {
        if (Name.empty())
          return true;

#define FUNCTION_PASS(NAME, CREATE_PASS)                                       \
  if (Name == NAME) {                                                          \
    PM.addPass(CREATE_PASS);                                                   \
    return true;                                                               \
  }

#define FUNCTION_PASS_WITH_PARAMS(NAME, CREATE_PASS, PARSER, PARAMS)           \
  if (PassBuilder::checkParametrizedPassName(Name, NAME)) {                    \
    auto Opt = PassBuilder::parsePassParameters(PARSER, Name, NAME);           \
    if (!Opt) {                                                                \
      errs() << toString(Opt.takeError()) << '\n';                             \
      return false;                                                            \
    }                                                                          \
    PM.addPass(CREATE_PASS(Opt.get()));                                        \
    return true;                                                               \
  }
#include "PassRegistry.def"

        return false;
      });
}
} // namespace trainOpt
} // namespace llvm
