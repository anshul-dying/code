def check_ip(ip):
    parts = ip.split('.')
    first_octet = int(parts[0])
    second_octet = int(parts[1])
    ip_class = ""
    ip_type = "Public"
    if 0 <= first_octet <= 127:
        ip_class = "A"
        if first_octet == 10:
            ip_type = "Private"
    elif 128 <= first_octet <= 191:
        ip_class = "B"
        if first_octet == 172 and 16 <= second_octet <= 31:
            ip_type = "Private"
    elif 192 <= first_octet <= 223:
        ip_class = "C"
        if first_octet == 192 and second_octet == 168:
            ip_type = "Private"
    elif 224 <= first_octet <= 239:
        ip_class = "D (Multicast)"
        ip_type = "Public"
    elif 240 <= first_octet <= 255:
        ip_class = "E (Reserved for Future Use)"
        ip_type = "Public"
    else:
        ip_class = "Invalid IP"
        ip_type = "N/A"
    print(f"Class: {ip_class}, Type: {ip_type}")
ip = input("Enter an IP address: ")
check_ip(ip)
