#include "network-interface-handler.hpp"

NetworkInterfaceHandler* NetworkInterfaceHandler::nih_ = nullptr;

NetworkInterfaceHandler* NetworkInterfaceHandler::GetNetworkInterfaceHandlerInstance() {
  if (nih_ == nullptr) {
    nih_ = new NetworkInterfaceHandler();
  }

  return nih_;
}

void NetworkInterfaceHandler::RetreiveAllInterfaces() {
  pcap_findalldevs(&network_interfaces_list_, errbuf_);

  if (network_interfaces_list_ == nullptr) {
    std::cerr << "Can not find any devices to monitor\n";
  }

  CountNetworkInterfaceListSize();
}

pcap_if_t* NetworkInterfaceHandler::GetNetworkInterfacesList() const { return network_interfaces_list_; }

void NetworkInterfaceHandler::CountNetworkInterfaceListSize() {
  uint8_t counter{};
  pcap_if_t* current_node = network_interfaces_list_;

  while (current_node != nullptr) {
    counter++;
    current_node = current_node->next;
  }

  network_interfaces_list_size_ = counter;
}