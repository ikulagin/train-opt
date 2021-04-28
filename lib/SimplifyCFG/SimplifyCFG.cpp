#include "topt/SimplifyCFG/SimplifyCFG.h"
#include <llvm/IR/Analysis.h>
#include <llvm/IR/Function.h>
#include <llvm/Support/Error.h>
#include <llvm/Support/FormatVariadic.h>

namespace llvm {
namespace trainOpt {

static bool eliminateDeadBlocks(Function &F) {
  /**
   *  @todo: Insert your code here!
   */
  return true;
}

static bool eliminateConditionalBranches(Function &F) {
  /**
   *  @todo: Insert your code here!
   */
  return true;
}

static bool eliminateSinglePredcessor(Function &F) {
  /**
   *  @todo: Insert your code here!
   */
  return true;
}

PreservedAnalyses SimplifyCFG::run(Function &F, FunctionAnalysisManager &AM) {
  if (Opt.ConditionalBranchElimination)
    eliminateConditionalBranches(F);
  if (Opt.SinglePredcessorElimination)
    eliminateSinglePredcessor(F);
  if (Opt.DeadBlocksElimination)
    eliminateDeadBlocks(F);
  return PreservedAnalyses::none();
}

Expected<SimplifyCFGOptions> parseSimplifyCFGOptions(StringRef Parameters) {
  SimplifyCFGOptions Opt;
  while (!Parameters.empty()) {
    StringRef Param;
    std::tie(Param, Parameters) = Parameters.split(';');
    if (Param == "c")
      Opt.ConditionalBranchElimination = true;
    else if (Param == "s")
      Opt.SinglePredcessorElimination = true;
    else if (Param == "d")
      Opt.DeadBlocksElimination = true;
    else
      return make_error<StringError>(
          formatv("invalid SimplifyCFG pass parameter '{}'", Param).str(),
          inconvertibleErrorCode());
  }
  return Opt;
}
} // namespace trainOpt
} // namespace llvm
