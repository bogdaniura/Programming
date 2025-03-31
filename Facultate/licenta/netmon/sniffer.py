from scapy.all import sniff

def packet_callback(packet):
    print(f"[{packet.time}] {packet.src} -> {packet.dst} | {packet.summary()}")

def start_sniffer(interface="eth0"):
    print(f"Sniffing on {interface}...")
    sniff(prn=packet_callback, store=False)
