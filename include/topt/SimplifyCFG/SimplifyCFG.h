#ifndef TOPT_SIMPLIFYCFG_H
#define TOPT_SIMPLIFYCFG_H

#include "llvm/ADT/StringRef.h"
#include "llvm/Support/raw_ostream.h"
#include <llvm/IR/PassManager.h>

namespace llvm {
class Function;

namespace trainOpt {
struct SimplifyCFGOptions {
  bool DeadBlocksElimination = false;
  bool ConditionalBranchElimination = false;
  bool SinglePredcessorElimination = false;
};

Expected<SimplifyCFGOptions> parseSimplifyCFGOptions(StringRef Parameters);

class SimplifyCFG : public PassInfoMixin<SimplifyCFG> {
public:
  SimplifyCFG(SimplifyCFGOptions &Opt) : Opt(Opt) {}
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);

private:
  SimplifyCFGOptions &Opt;
};
} // namespace trainOpt
} // namespace llvm

#endif // TOPT_SIMPLIFYCFG_H
