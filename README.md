# Bitcoin API

This is a C++ wrapper library for JSON-RPC communication with the Bitcoin daemon. It allows developers to communicate with the Bitcoin daemon without the need to pack and unpack JSON-RPC messages and thus simplifies the interaction with it.

## Building the library

[![Build Status](https://travis-ci.org/minium/bitcoin-api-cpp.svg?branch=master)](https://travis-ci.org/minium/bitcoin-api-cpp)

**Dependencies**

This library requires [CMake](http://www.cmake.org/cmake/resources/software.html), [Curl](http://curl.haxx.se/libcurl/), [libjson-cpp](https://github.com/open-source-parsers/jsoncpp) and [libjson-rpc-cpp](https://github.com/medeirosfalante/libjson-rpc-cpp) packages in order to be built. All of them, with the exception of libjson-rpc-cpp, can be installed as follows

```sh
sudo apt-get install cmake libcurl4-openssl-dev libjsoncpp-dev libjsonrpccpp-dev
```

For the libjson-rpc-cpp library the instructions on [libjson-rpc-cpp](https://github.com/medeirosfalante/libjson-rpc-cpp) must be followed.

**Build and install**

Navigate to the root directory of the library and proceed as follows:

```sh
mkdir build
cd build
cmake ..
make
sudo make install
sudo ldconfig
```

## Using the library

This example will show how the library can be used in your project.

Filename getbalance.cpp

```
#include <bitcoinapi/bitcoinapi.h>

int main()
{
    std::string username = "user";
    std::string password = "pass";
    std::string address = "127.0.0.1";
    int port = 8332;

    try
    {
        /* Constructor to connect to the bitcoin daemon */
        BitcoinAPI btc(username, password, address, port);

        /* Example method - getbalance */
        std::cout << "Wallet balance: " << btc.getbalance() << std::endl;
    }
    catch(BitcoinException e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
}
```

To successfully compile the program you need to link it with the new library:

```
g++ getbalance.cpp -lbitcoinapi
```
