/**
 * \file
 * Functions and types for CRC checks.
 *
 * Generated on Fri Feb  3 16:16:45 2023
 * by pycrc v0.10.0, https://pycrc.org
 * using the configuration:
 *  - Width         = 8
 *  - Poly          = 0x07
 *  - XorIn         = 0x00
 *  - ReflectIn     = False
 *  - XorOut        = 0x00
 *  - ReflectOut    = False
 *  - Algorithm     = bit-by-bit-fast
 *
 * Auto converted to Arduino C++ on Fri Feb  3 16:16:45 PST 2023
 * by AceCRC (https://github.com/bxparks/AceCRC).
 * DO NOT EDIT
 */
#include "crc8_bit.hpp" // header file converted by AceCRC
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

namespace ace_crc {
namespace crc8_bit {



crc_t crc_update(crc_t crc, const void *data, size_t data_len)
{
    const unsigned char *d = (const unsigned char *)data;
    uint8_t i;
    crc_t bit;
    unsigned char c;

    while (data_len--) {
        c = *d++;
        for (i = 0x80; i > 0; i >>= 1) {
            bit = (crc & 0x80) ^ ((c & i) ? 0x80 : 0);
            crc <<= 1;
            if (bit) {
                crc ^= 0x07;
            }
        }
        crc &= 0xff;
    }
    return crc & 0xff;
}

} // crc8_bit
} // ace_crc
