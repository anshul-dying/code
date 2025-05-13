import socket
import os

IP = socket.gethostbyname(socket.gethostname())
PORT = 4455
ADDR = (IP, PORT)
FORMAT = "utf-8"
BUFFER_SIZE = 1024  # Define a buffer size for sending data

def main():
    print("[STARTING] Client is starting")
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client.connect(ADDR)
        print("[CONNECTED] Connected to the server")

        # Check if the file exists
        file_path = "data/tt.txt"
        if not os.path.exists(file_path):
            print(f"[ERROR] File '{file_path}' does not exist")
            return

        # Open the file and send its content
        with open(file_path, 'r') as file:
            filename = os.path.basename(file_path)
            client.send(filename.encode(FORMAT))  # Send the filename
            print(f"[SENT] Filename '{filename}' sent to the server")

            data = file.read()
            client.send(data.encode(FORMAT))  # Send the file content
            print(f"[SENT] File content sent to the server")

    except Exception as e:
        print(f"[ERROR] {e}")
    finally:
        client.close()
        print("[DISCONNECTED] Client disconnected")

if __name__ == "__main__":
    main()
