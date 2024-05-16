g++-13 -Wall -Wextra -std=c++23 -fmodules-ts -xc++-system-header iostream 
g++-13 -Wall -Wextra -std=c++23 -fmodules-ts -xc++-system-header ostream 
g++-13 -Wall -Wextra -std=c++23 -fmodules-ts -c lib/Point.cpp -o gcm.cache/Point.o
g++-13 -Wall -Wextra -std=c++23 -fmodules-ts main.cpp gcm.cache/Point.o
./a.out