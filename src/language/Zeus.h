#include "core/system/ZeusPlatform.h"
#include "core/system/ZeusFileSystem.h"
#include "core/system/ZeusCommandLine.h"
#include "core/ZeusVirtualMachine.h"

struct Zeus {
  struct ZeusVirtualMachine * vm;
  struct ZeusCommandLine * cli;
  struct ZeusFileSystem * fs;
  struct ZeusPlatform * sys;
  // ZeusDaemon * daemon;
};
