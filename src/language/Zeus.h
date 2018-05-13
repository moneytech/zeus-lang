#include "system/ZeusPlatform.h"
#include "system/ZeusFileSystem.h"
#include "system/ZeusCommandLine.h"
#include "ZeusVirtualMachine.h"

struct Zeus {
  ZeusVirtualMachine * vm;
  ZeusCommandLine * cli;
  ZeusFileSystem * fs;
  ZeusPlatform * sys;
  ZeusDaemon * daemon;
};
