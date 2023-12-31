/**
 * \file
 * Functions and types for CRC checks.
 *
 * Generated on Fri Feb  3 16:16:46 2023
 * by pycrc v0.10.0, https://pycrc.org
 * using the configuration:
 *  - Width         = 16
 *  - Poly          = 0x1021
 *  - XorIn         = 0x1d0f
 *  - ReflectIn     = False
 *  - XorOut        = 0x0000
 *  - ReflectOut    = False
 *  - Algorithm     = table-driven
 *
 * This file defines the functions crc_init(), crc_update() and crc_finalize().
 *
 * The crc_init() function returns the initial \c crc value and must be called
 * before the first call to crc_update().
 * Similarly, the crc_finalize() function must be called after the last call
 * to crc_update(), before the \c crc is being used.
 * is being used.
 *
 * The crc_update() function can be called any number of times (including zero
 * times) in between the crc_init() and crc_finalize() calls.
 *
 * This pseudo-code shows an example usage of the API:
 * \code{.c}
 * crc_t crc;
 * unsigned char data[MAX_DATA_LEN];
 * size_t data_len;
 *
 * crc = crc_init();
 * while ((data_len = read_data(data, MAX_DATA_LEN)) > 0) {
 *     crc = crc_update(crc, data, data_len);
 * }
 * crc = crc_finalize(crc);
 * \endcode
 *
 * Auto converted to Arduino C++ on Fri Feb  3 16:16:46 PST 2023
 * by AceCRC (https://github.com/bxparks/AceCRC).
 * DO NOT EDIT
 */
#ifndef ACE_CRC_CRC16CCITT_BYTE_HPP
#define ACE_CRC_CRC16CCITT_BYTE_HPP

#include <stdlib.h>
#include <stdint.h>

namespace ace_crc {
namespace crc16ccitt_byte {


/**
 * The definition of the used algorithm.
 *
 * This is not used anywhere in the generated code, but it may be used by the
 * application code to call algorithm-specific code, if desired.
 */
const uint8_t CRC_ALGO_TABLE_DRIVEN = 1;


/**
 * The type of the CRC values.
 *
 * This type must be big enough to contain at least 16 bits.
 */
typedef uint16_t crc_t;


/**
 * Calculate the initial crc value.
 *
 * \return     The initial crc value.
 */
inline crc_t crc_init(void)
{
    return 0x1d0f;
}


/**
 * Update the crc value with new data.
 *
 * \param[in] crc      The current crc value.
 * \param[in] data     Pointer to a buffer of \a data_len bytes.
 * \param[in] data_len Number of bytes in the \a data buffer.
 * \return             The updated crc value.
 */
crc_t crc_update(crc_t crc, const void *data, size_t data_len);


/**
 * Calculate the final crc value.
 *
 * \param[in] crc  The current crc value.
 * \return     The final crc value.
 */
inline crc_t crc_finalize(crc_t crc)
{
    return crc;
}


/**
 * Calculate the crc in one-shot.
 * This is a convenience function added by AceCRC.
 *
 * \param[in] data     Pointer to a buffer of \a data_len bytes.
 * \param[in] data_len Number of bytes in the \a data buffer.
 */
inline crc_t crc_calculate(const void *data, size_t data_len) {
  crc_t crc = crc_init();
  crc = crc_update(crc, data, data_len);
  return crc_finalize(crc);
}

} // crc16ccitt_byte
} // ace_crc

#endif      /* ACE_CRC_CRC16CCITT_BYTE_HPP */
