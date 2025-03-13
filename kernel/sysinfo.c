#include "types.h"
#include "riscv.h"
#include "param.h"
#include "spinlock.h"
#include "defs.h"
#include "sysinfo.h"
#include "proc.h"


uint64 systeminfo(uint64 addr) {
  struct sysinfo info;
  
  info.nopenfiles = nopenfiles();
  info.freemem = freemem();
  info.nproc = nproc();
  
  struct proc *p = myproc();
  int flag = copyout(p->pagetable, addr, (char *)&info, sizeof(info));

  if(flag < 0)
    return -1;

  return 0;
}