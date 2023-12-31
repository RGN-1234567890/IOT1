#!/usr/bin/gawk -f
#
# Usage: generate_table.awk < ${board}.txt
#
# Takes the file generated by collect.sh and generates an ASCII
# table that can be inserted into the README.md.

BEGIN {
  record_index = 0
}
!/^END/ {
  u[record_index]["name"] = $1
  u[record_index]["micros"] = $6
  record_index++
}
END {
  TOTAL_BENCHMARKS = record_index

  printf("+-----------------------------------------------+\n")
  printf("| CRC algorithm                   |  micros/kiB |\n")
  for (i = 0; i < TOTAL_BENCHMARKS; i++) {
    name = u[i]["name"]
    if (name ~ /^crc8_bit/ \
        || name ~ /^crc16ccitt_bit/ \
        || name ~ /^crc16modbus_bit/ \
        || name ~ /^crc32_bit/ \
        || name ~ /^CRC32/) {
      printf("|---------------------------------+-------------|\n")
    }
    printf("| %-31s | %11d |\n", name, u[i]["micros"])
  }
  printf("+---------------------------------+-------------+\n")
}
