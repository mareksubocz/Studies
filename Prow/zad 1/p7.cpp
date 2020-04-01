#include <omp.h>
#include <stdio.h>
#include <time.h>

#include "measurement.cpp"

#define LOGIC 4
#define PHYSICAL 2
#define HALF PHYSICAL / 2
#define NUM_STEPS 1000000000
#define STEP 1. / (double)NUM_STEPS
#define ARR_SIZE 50

/*
n_threads: 2
real_time: 6.794689s
 CPU_time: 12.710225s
0 1
 PI value: 3.141592653590

n_threads: 2
real_time: 6.240192s
 CPU_time: 12.139352s
1 2
 PI value: 4.428594871180

n_threads: 2
real_time: 6.166409s
 CPU_time: 12.052188s
2 3
 PI value: 4.428594871180

n_threads: 2
real_time: 7.562339s
 CPU_time: 12.718406s
3 4
 PI value: 4.428594871180

n_threads: 2
real_time: 7.414700s
 CPU_time: 12.381111s
4 5
 PI value: 4.428594871180

n_threads: 2
real_time: 6.187830s
 CPU_time: 12.058573s
5 6
 PI value: 4.428594871180

n_threads: 2
real_time: 5.967479s
 CPU_time: 11.843152s
6 7
 PI value: 4.428594871180

n_threads: 2
real_time: 5.777240s
 CPU_time: 11.451460s
7 8
 PI value: 4.428594871180

n_threads: 2
real_time: 5.800966s
 CPU_time: 11.525853s
8 9
 PI value: 4.428594871180

n_threads: 2
real_time: 6.418312s
 CPU_time: 12.040870s
9 10
 PI value: 4.428594871180

n_threads: 2
real_time: 6.957692s
 CPU_time: 12.281646s
10 11
 PI value: 4.428594871180

n_threads: 2
real_time: 6.265458s
 CPU_time: 11.834738s
11 12
 PI value: 4.428594871180

n_threads: 2
real_time: 7.170833s
 CPU_time: 12.120835s
12 13
 PI value: 4.428594871180
*/

int main(int argc, char* argv[]) {
  omp_set_num_threads(PHYSICAL);
  double pi, sum = 0.0;
  volatile double tmp_sums[ARR_SIZE];

  for (int i_arr = 0; i_arr < ARR_SIZE - 1; i_arr++) {
    pi, sum = 0.0;
    tmp_sums[i_arr] = 0;
    Measurement* measurement = new Measurement(PHYSICAL);
    // ***************** obliczenia *****************
#pragma omp parallel default(none) shared(tmp_sums, i_arr)
    {
      int my_num = omp_get_thread_num();
      double x = 0.0;
      printf("tmp_sums[%d]\n", i_arr + my_num);
#pragma omp for schedule(guided)
      for (int i = 0; i < NUM_STEPS; i++) {
        x = (i + .5) * STEP;
        tmp_sums[i_arr + my_num] += 4.0 / (1. + x * x);
      }
    }
    
    sum = tmp_sums[i_arr] + tmp_sums[i_arr + 1];
    pi = sum * STEP;
    // ***************** obliczenia *****************

    delete measurement;
    printf(" PI value:%15.12f\n\n", pi);
  }

  return 0;
}
