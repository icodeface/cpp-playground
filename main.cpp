#include <iostream>
#include "digestpp/digestpp.hpp"
#include "blake2b/blake2.h"
#include "pointer_struct/size_offset.h"


void hash_test() {
    digestpp::kmac256 kmac256(256);
    kmac256.set_key("nonce");
    kmac256.absorb("data");
    std::cout << kmac256.hexdigest() << '\n';

    digestpp::blake2b blake2b256(256);
    blake2b256.absorb(kmac256.hexdigest());
    std::cout << blake2b256.hexdigest() << '\n';

    uint8_t da[8];
    printf("size is %d\n", sizeof(da));

    uint8_t nonce[4];
    uint32_t firstFour = 0xFFFFFFFF/ 5;
    memcpy(nonce, &firstFour, 4);
    for (size_t i=0; i < 4; i ++) {
        printf("%02x", nonce[i]);
    }

    printf("new \n");

    uint8_t out_left[64];
    blake2b_state s;
    blake2b_init(&s, 64);

    const char *data = "data";
    blake2b_update(&s, data, 4);

    blake2b_final(&s, out_left, 64);
    for (size_t i=0; i<64; i++) {
        printf("%02x", out_left[i]);
    }

//    digestpp::blake2b left(512);
//    left.absorb("data");
//    std::cout << "left " << left.hexdigest() << '\n';
//    uint8_t out_left[64];
//    left.digest(out_left, 64);

    digestpp::sha3 right(256);
    right.absorb("data");
    right.absorb("pad8");
    std::cout << "right " << right.hexdigest() << '\n';
    uint8_t out_right[32];
    right.digest(out_right, 32);

    digestpp::blake2b hash(256);
    hash.absorb(out_left, sizeof(out_left));
    hash.absorb("pad32");
    hash.absorb(out_right, sizeof(out_right));
    std::cout << "hash2 " << hash.hexdigest() << '\n';

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    size_offset_test();
    return 0;
}