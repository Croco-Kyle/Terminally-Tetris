/// ============================================================================
/// Copyright (C) 2023 Pavol Federl (pfederl@ucalgary.ca)
/// All Rights Reserved. Do not distribute this file.
/// ============================================================================
///
/// You must modify this file and then submit it for grading to D2L.
///
/// You can delete all contents of this file and start from scratch if
/// you wish, as long as you implement the detect_primes() function as
/// defined in "detectPrimes.h".


// Student Kyle West ID 30167781

#include "detectPrimes.h"
#include <cmath>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <mutex>
#include <atomic>
#include <vector>
#include <pthread.h>
#include <unistd.h>


// Global variables 
std::vector<int64_t> result;
std::atomic<bool> found;
std::atomic<bool> global_finished;
int num_index;

pthread_barrier_t barrier;


// the data needed by our threads to function properly will be the start and
// ends of the the array it's going to work on as well was the pointer to it.
struct data{
  int64_t id;
  int num_size;
  int n_threads;
  int64_t input;
  const std::vector<int64_t> * nums;
  struct data * data_arr; // array location to modify data inside the serialization.
};


// function will be serialized and will run before distributing numbers
 bool trivial_cases(int64_t n){ 
  // handle trivial cases
  if (n < 2) return false;
  if (n <= 3) return true;
  if (n % 2 == 0) return false; // handle multiples of 2
  if (n % 3 == 0) return false; // handle multiples of 3
  return true;
}


// -----------------------------------------------------------------------------

void* thread_function(void * args){
  // loading in data from structs
  struct data * in = (struct data *) args;
  int64_t id = in->id; 
  int num_size = in ->num_size;
  int n_threads = in ->n_threads;
  int64_t input = in -> input;
  int64_t max;

  std::vector<int64_t> nums = *(in->nums);  
  struct data * data_arr = in -> data_arr; 
  input = nums[0];
  
  bool finished = false;

  
  while(1){
    // all threads will start here after initilization AKA the starting line.
    int flag = pthread_barrier_wait(&barrier); // serializing the initial input
    //--------------------------------------------------------------------------
    if(flag == PTHREAD_BARRIER_SERIAL_THREAD){
      // handles trivial cases.
      while(true){
        if (num_index >= num_size){
          global_finished.store(true);
          finished = true;
          break;
          }
        input = nums[num_index];
        if (input < 2){           // trivial case we will skip this loop and check the next number
          num_index += 1;
          continue;
          }
        if (input <= 3){          // trivial case we will add this to results and check the next number
          result.push_back(input);
          num_index += 1;
          continue;
          } else if (input % 2 == 0 || input % 3 ==0){
          num_index += 1;
          continue;
          } 
          break;}
      // we cleared any trivial input before this point.
      // the setup for our threads to run in parallel will be from here out.
      if(finished != true) {
        for (int i = 0; i < n_threads; i++){
          data_arr[i].input = input;
          }
        }
    }
    //--------------------------------------------------------------------------
    pthread_barrier_wait(&barrier); // start the multi-threading again
    // grabbing info from the structs.
    if (global_finished.load() == true){
      pthread_exit(NULL);
    } 

    input = in -> input; 
    max = sqrt(input);
    int64_t temp = int64_t(5) + (int64_t(6) * id);
    while(temp <= max){
      if (found.load()== true){
        break;
        } 
      if (input % temp == int64_t(0)){
        found.store(true);
        break;
        }
      if (input % (temp + 2) == int64_t(0)){
        found.store(true);
        break;
        }
      temp += int64_t(6) * int64_t(n_threads);      
      }
    pthread_barrier_wait(&barrier);
    int flag2 = pthread_barrier_wait(&barrier);
    if(flag2 == PTHREAD_BARRIER_SERIAL_THREAD){
      if (found.load() == false){
        result.push_back(input);
      }
      else {
        found.store(false);
      }
      num_index += 1;
    }
    pthread_barrier_wait(&barrier);
  }
}


// This function takes a list of numbers in nums[] and returns only numbers that
// are primes.
//
// The parameter n_threads indicates how many threads should be created to speed
// up the computation.
// -----------------------------------------------------------------------------
/*
detectPrimes():
prepare memory for each thread
initialize empty array result[] – this could be a global variable
set global_finished = false – make it atomic to be safe
start N threads, each runs thread_function() on its own memory
join N threads
return results
*/

// The "main function" for detect primes.
std::vector<int64_t> detect_primes(const std::vector<int64_t> & nums, int n_threads)
{
  pthread_barrier_init(&barrier, NULL, n_threads);
  pthread_t pool[n_threads];
  struct data args[n_threads];
  int num_size = int(nums.size()); 
  num_index = 0;
  result = {}; // initializing result array.
  found.store(false, std::memory_order_relaxed); 
  global_finished.store(false, std::memory_order_relaxed); 
  

  for(int i = 0; i<n_threads; i++){
    args[i].id = int64_t(i);
    args[i].nums = &nums;
    args[i].data_arr = args;
    args[i].num_size = num_size;
    //args[i].local_inputs = {};
    args[i].n_threads = n_threads;
  }

  for(int i = 0; i<n_threads; i++){
      pthread_create(&pool[i], NULL, thread_function, (void *) &args[i]);
    }
  
  for(int i = 0; i< n_threads; i++){
      pthread_join(pool[i], NULL);
    }
  
  return result;
}

