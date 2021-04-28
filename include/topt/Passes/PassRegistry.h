#ifndef TOTP_PASSES_PASSREGISTRY_H
#define TOTP_PASSES_PASSREGISTRY_H
namespace llvm {
class PassBuilder;
namespace trainOpt {
void registerPasses(PassBuilder &PB);
}
} // namespace llvm
#endif // TOTP_PASSES_PASSREGISTRY_H
