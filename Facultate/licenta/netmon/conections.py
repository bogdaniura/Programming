import psutil

def list_connections():
    connections = psutil.net_connections(kind="inet")
    for conn in connections:
        if conn.status == "ESTABLISHED":
            print(f"{conn.laddr.ip}:{conn.laddr.port} -> {conn.raddr.ip}:{conn.raddr.port} ({conn.status})")

