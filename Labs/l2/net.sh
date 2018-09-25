# !/bin/bash
ifconfig | awk '/^[^ ]/{net=$1}/inet /&&net!="lo:"{print net"\t"$2}'