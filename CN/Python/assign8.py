def calculate_subnet_mask(subnet_bits):
    subnet_mask = [0] * 4
    for i in range(4):
        if subnet_bits >= 8:
            subnet_mask[i] = 255
            subnet_bits -= 8
        elif subnet_bits > 0:
            subnet_mask[i] = 256 - (1 << (8 - subnet_bits))
            subnet_bits = 0
        else:
            subnet_mask[i] = 0
    return subnet_mask

def print_ip(ip):
    print(".".join(map(str, ip)))

def get_ip_class(first_octet):
    if 1 <= first_octet <= 126:
        return 'A'
    elif 128 <= first_octet <= 191:
        return 'B'
    elif 192 <= first_octet <= 223:
        return 'C'
    elif 224 <= first_octet <= 239:
        return 'D'  # Multicast
    elif 240 <= first_octet <= 255:
        return 'E'  # Experimental
    else:
        return 'X'  # Invalid

def get_default_subnet_mask(ip_class):
    if ip_class == 'A':
        return [255, 0, 0, 0]
    elif ip_class == 'B':
        return [255, 255, 0, 0]
    elif ip_class == 'C':
        return [255, 255, 255, 0]
    else:
        return [0, 0, 0, 0]

def is_valid_ip(ip_str):
    parts = ip_str.strip().split(".")
    if len(parts) != 4:
        return False, []
    try:
        ip = [int(part) for part in parts]
        if all(0 <= num <= 255 for num in ip):
            return True, ip
        else:
            return False, []
    except ValueError:
        return False, []

def main():
    ip_address = input("Enter IP address: ").strip()
    valid, ip = is_valid_ip(ip_address)

    if not valid:
        print("Invalid IP address format!")
        return

    ip_class = get_ip_class(ip[0])
    print(f"IP Class: {ip_class}")

    default_mask = get_default_subnet_mask(ip_class)
    print("Default Subnet Mask: ", end="")
    print_ip(default_mask)

    subnet_bits = int(input("Enter number of subnet bits (e.g., 24): "))
    subnet_mask = calculate_subnet_mask(subnet_bits)
    print("Calculated Subnet Mask: ", end="")
    print_ip(subnet_mask)

if __name__ == "__main__":
    main()
