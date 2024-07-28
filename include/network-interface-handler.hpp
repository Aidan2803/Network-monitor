#include <pcap/pcap.h>

#include <iostream>

class NetworkInterfaceHandler {
public:
  static NetworkInterfaceHandler* GetNetworkInterfaceHandlerInstance();
  void RetreiveAllInterfaces();
  pcap_if_t* GetNetworkInterfacesList() const;

private:
  NetworkInterfaceHandler() = default;
  void CountNetworkInterfaceListSize();

private:
  static NetworkInterfaceHandler* nih_;
  char errbuf_[PCAP_ERRBUF_SIZE];
  pcap_if_t* network_interfaces_list_;
  uint8_t network_interfaces_list_size_;
};