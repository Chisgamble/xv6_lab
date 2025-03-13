struct sysinfo {
  uint64 freemem;   // amount of free memory (bytes)
  uint64 nproc;     // number of process
  uint64 nopenfiles;// number of opening files
};

uint64 systeminfo(uint64 addr);