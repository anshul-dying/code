import socket

IP = socket.gethostbyname(socket.gethostname())
PORT = 4455
ADDR = (IP, PORT)
FORMAT = "utf-8"
SIZE = 1024  # Define a buffer size for receiving data

def main():
    print("[STARTING] Server is starting")
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(ADDR)
    server.listen()
    print("[LISTENING] Server is listening")

    while True:
        conn, addr = server.accept()
        print(f"[NEW CONNECTION] {addr} connected")

        try:
            # Receive the filename
            filename = conn.recv(SIZE).decode(FORMAT)
            print(f"[RECEIVED] Filename: {filename}")

            # Receive the file content
            file_content = conn.recv(SIZE).decode(FORMAT)
            print(f"[RECEIVED] File content received")

            # Save the file to the server's local directory
            with open(f"received_{filename}", 'w') as file:
                file.write(file_content)
            print(f"[SAVED] File saved as 'received_{filename}'")

        except Exception as e:
            print(f"[ERROR] {e}")
        finally:
            conn.close()
            print(f"[DISCONNECTED] Connection with {addr} closed")

if __name__ == "__main__":
    main()


