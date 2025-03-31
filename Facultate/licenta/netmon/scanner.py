import socket

def scan_ports(target, ports=range(1, 1025)):
    print(f"Scanning {target}...")
    open_ports = []
    for port in ports:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.settimeout(0.5)  
        if s.connect_ex((target, port)) == 0:
            open_ports.append(port)
            print(f"[+] Port {port} is open")
        s.close()
    return open_ports
