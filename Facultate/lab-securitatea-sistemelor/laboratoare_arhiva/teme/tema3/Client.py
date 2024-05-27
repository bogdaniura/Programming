import socket

def main():
    IP = 'localhost'  
    PORT = 4444

    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((IP, PORT))

    while True:
        command = input("Enter command: ")
        if command.lower() == 'exit':
            client.send(command.encode('utf-8'))
            break
        client.send(command.encode('utf-8'))
        result = client.recv(4096).decode('utf-8')
        print(result)

    client.close()

if __name__ == "__main__":
    main()
