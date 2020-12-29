#ifndef UTIL_H_
#define UTIL_H_
#include <random>

inline double randomDouble(double min, double max) {
   static std::random_device seeder;
   std::default_random_engine engine(seeder());
   std::uniform_real_distribution<double> dist(min, max);
   return dist(engine);
}

inline int randomInt(int min, int max) {
   static std::random_device seeder;
   static std::default_random_engine engine(seeder());
   static std::uniform_int_distribution<> dist(min ,max);
   return dist(engine);
}

#endif /* UTIL_H_ */
