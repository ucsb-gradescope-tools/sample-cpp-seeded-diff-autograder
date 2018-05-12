#include <iostream>
#include <cassert>
using namespace std;



int randIntBetweenInclusive(int min, int max) {
  assert(max >= min);
  int range = (max-min + 1);
  return std::rand() % range + min;
}

int main(int argc, char * argv[]) {
  if (argc!=2) {
    cerr << "Usage: " << argv[0] << " email_address " << endl
	 << endl
	 << "Example: " << endl
      	 << "   " << argv[0] << " cgaucho@umail.ucsb.edu " << endl;
    exit(1);
  }

  std::string email = std::string(argv[1]);
  std::hash<std::string> str_hash;
  size_t hash = str_hash(email);

  int hash_size = sizeof(hash);
  int seed_size = sizeof(unsigned); // parameter to srand

  int size_diff = hash_size - seed_size;

  unsigned seed;
  if (size_diff > 0) {
    seed = unsigned(hash >> (size_diff * 8));
  } else {
    seed = hash;
  }
  
  //cout << "email: " << email << endl;
  //cout << "hash: " << std::hex << hash << endl;
  //cout << "seed: " << std::hex << seed << endl;
  //cout << "size_diff: " << std::dec << size_diff << endl;

  std::srand(seed); //use current time as seed for random generator

  int rows = randIntBetweenInclusive(3,8);
  int cols = randIntBetweenInclusive(3,8);

  for (int row=0; row<rows; row ++) {
      for (int col=0; col<cols; col ++) {
	cout << "*";	
      }
      cout << endl;
  }
  
  return 0;
}

