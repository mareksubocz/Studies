#include <omp.h>
#include <stdio.h>
#include <time.h>

class Measurement {
 private:
  double rstart, rstop;
  clock_t start, stop;

 public:
  Measurement(int n_threads) {
    printf("n_threads: %d\n", n_threads);
    start = clock();
    rstart = omp_get_wtime();
  };
  ~Measurement() {
    stop = clock();
    rstop = omp_get_wtime();

    printf("real_time: %fs\n", (rstop - rstart));
    printf(" CPU_time: %fs\n", ((double)(stop - start) / CLOCKS_PER_SEC));
  };
};
