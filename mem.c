char HOST_HEAP8[65536];
int host_hp = 0;
char VIRT_HEAP8[65536];
int virt_hp = 0;

void *memcpy(void *src, void *dest, int len) {
    for(int offset = 0; offset < len; offset++) {
        *((char*)dest + offset) = *((char*)src + offset);
    }
    return dest;
}

void *host_malloc(int len) {
    if(host_hp + len > 65536) {
        return 0;
    }

    void *res = HOST_HEAP8 + host_hp;
    host_hp += len;

    return res;
}