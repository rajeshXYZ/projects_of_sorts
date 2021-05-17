#ifndef subnetclassranges
#define subnetclassranges

struct subnet_classes {
    char *ipclass_A = "0.0.0.0 and 127.255.255.255";
    char *ipclass_B = "128.0.0.0 and 191.255.255.255"
    char *ipclass_c = "192.0.0.0 and 223.255.255.255"
}

#endif
