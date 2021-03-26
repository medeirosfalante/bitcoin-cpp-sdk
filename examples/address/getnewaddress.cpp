#include <bitcoinapi/bitcoinapi.h>

int main()
{
    std::string username = "dev";
    std::string password = "dev";
    std::string address = "127.0.0.1";
    int port = 8332;

    try
    {
        /* Constructor to connect to the bitcoin daemon */
        BitcoinAPI btc(username, password, address, port);

        /* Example method - create a new address */
        std::cout << "New address: " << btc.getnewaddress() << std::endl;
    }
    catch (BitcoinException e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
}
// g++ getnewaddress.cpp -lbitcoinapi