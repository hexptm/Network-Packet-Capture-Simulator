#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generateRandomIP() {
    return std::to_string(rand() % 256) + "." +
           std::to_string(rand() % 256) + "." +
           std::to_string(rand() % 256) + "." +
           std::to_string(rand() % 256);
}

void packetHandler(int packetLength, const std::string& srcIP, const std::string& destIP, int srcPort, int destPort, std::string protocol) {
    const std::string resetColor = "\033[0m";
    const std::string lengthColor = "\033[1;34m";
    const std::string ipColor = "\033[1;32m";
    const std::string portColor = "\033[1;35m";
    const std::string protocolColor = protocol == "TCP" ? "\033[1;31m" : "\033[1;36m";

    std::cout << lengthColor << "Packet Captured! Packet length: " << packetLength << " bytes" << resetColor << std::endl;
    std::cout << ipColor << "Source IP: " << srcIP << resetColor << std::endl;
    std::cout << ipColor << "Destination IP: " << destIP << resetColor << std::endl;
    std::cout << portColor << "Source Port: " << srcPort << resetColor << std::endl;
    std::cout << portColor << "Destination Port: " << destPort << resetColor << std::endl;
    std::cout << protocolColor << "Protocol: " << protocol << resetColor << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "\033[1;33mStarting packet capture simulation...\033[0m" << std::endl;

    for (int i = 0; i < 10; ++i) {
        int packetLength = 40 + rand() % 100;
        std::string srcIP = generateRandomIP();
        std::string destIP = generateRandomIP();
        int srcPort = 1024 + rand() % 64511;
        int destPort = 1024 + rand() % 64511;
        std::string protocol = (rand() % 2 == 0) ? "TCP" : "UDP";

        packetHandler(packetLength, srcIP, destIP, srcPort, destPort, protocol);
    }

    std::cout << "\033[1;33mPacket capture simulation completed.\033[0m" << std::endl;
    return 0;
}
